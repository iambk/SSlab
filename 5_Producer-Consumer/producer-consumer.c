#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

pthread_t *producers;
pthread_t *consumers;

sem_t buf_mutex, empty_count, fill_count;

int *buf, buf_pos=-1, prod_count, con_count, buf_len;

int produce(pthread_t self){
	int i = 0;
	int p = 1 + rand()%40;
	while(!pthread_equal(*(producers+i),self) && i < prod_count){
		i++;
	}
	printf("\nProducer %d produced %d \n", i+1, p);
	return p;
}


void consume(int p,pthread_t self){
	int i = 0;
	while(!pthread_equal(*(consumers+i),self) && i < con_count){
		i++;
	}

	printf("\n\tConsumer %d consumed %d \n", i+1, p);

}


void* producer(void *args){

	while(1){
		int p = produce(pthread_self());
		sem_wait(&empty_count);
		sem_wait(&buf_mutex);
		++buf_pos;			// critical section
		*(buf + buf_pos) = p; 
		sem_post(&buf_mutex);
		sem_post(&fill_count);
		sleep(1 + rand()%3);
	}
	
	return NULL;
}


void* consumer(void *args){
	int c;
	while(1){
		sem_wait(&fill_count);
		sem_wait(&buf_mutex);
		c = *(buf+buf_pos);
		consume(c,pthread_self());
		--buf_pos;
		sem_post(&buf_mutex);
		sem_post(&empty_count);
		sleep(1+rand()%5);
	}

	return NULL;
}

int main() {
	
	srand(time(NULL));

	sem_init(&buf_mutex, 0, 1);
	sem_init(&fill_count, 0, 0);

	printf("Enter the number of Producers: ");
	scanf("%d",&prod_count);
	producers = (pthread_t*) malloc(prod_count*sizeof(pthread_t));

	printf("Enter the number of Consumers: ");
	scanf("%d", &con_count);
	consumers = (pthread_t*) malloc(con_count*sizeof(pthread_t));

	printf("Enter buffer capacity: ");
	scanf("%d", &buf_len);
	buf = (int*) malloc(buf_len*sizeof(int));

	sem_init(&empty_count, 0, buf_len);

	for(int i=0; i<prod_count; i++) {
		pthread_create(producers+i, NULL, &producer, NULL);
	}

	for(int i=0; i<con_count; i++){
		pthread_create(consumers+i, NULL, &consumer, NULL);
	}

	for(int i=0; i<prod_count; i++){
		pthread_join(*(producers+i), NULL);
	}
	for(int i=0; i<con_count; i++){
		pthread_join(*(consumers+i), NULL);
	}

	return 0;
}
