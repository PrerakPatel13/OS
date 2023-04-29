#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int buffer_index,block_p_index=-1,block_c_index=-1;
int block_p[100],block_c[100];
sem_t empty;
sem_t full;
sem_t mutex;
void insert_item(int item) {
 buffer[buffer_index++] = item;
 printf("Producer produced item %d\n", item);
}
int remove_item() {
 int item = buffer[--buffer_index];
 printf("Consumer consumed item %d\n", item);
 return item;
}
void *producer(void *param) {
 int item;
 while (1) {
 item = rand() % 10;
 sem_wait(&empty); 
 while(block_p_index!=-1)
 {
 sem_wait(&mutex);
 buffer[buffer_index++] = block_p[block_p_index];
 printf("Producer added item from blocked %d\n", block_p[block_p_index]);
to buffer
 block_p_index--;
 sem_post(&mutex);
 }
 sem_wait(&mutex); 
 insert_item(item); 
 sem_post(&mutex); 
 sem_post(&full);
 if(buffer_index==BUFFER_SIZE-1)
 {
 printf("Buffer full.Process blocked\n");
 block_p_index++;
 block_p[block_p_index] = item;
 }
 sleep(rand() % 3);
 }
}
void *consumer(void *param) {
 int item;
 while (1) {
 sem_wait(&full); 
 sem_wait(&mutex); 
 item = remove_item(); 
 sem_post(&mutex); 
 sem_post(&empty); 
 
 sleep(rand() % 3);
 }
}
int main(int argc, char *argv[]) {
 sem_init(&empty, 0, BUFFER_SIZE);
 sem_init(&full, 0, 0);
 sem_init(&mutex, 0, 1);
 buffer_index = 0;
 pthread_t producer_thread, consumer_thread;
 pthread_create(&producer_thread, NULL, producer, NULL);
 pthread_create(&consumer_thread, NULL, consumer, NULL);
 pthread_join(producer_thread, NULL);
 pthread_join(consumer_thread, NULL);
 sem_destroy(&empty);
 sem_destroy(&full);
 sem_destroy(&mutex);
 return 0;
}
