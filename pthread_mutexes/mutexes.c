#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 3        // Size of shared buffer.

int buff[BUFF_SIZE];       // Shared buffer.
int add = 0;                   // Place to add the next element in the buffer.
int rem = 0;                   // Place to remove the next element from the buffer.
int num = 0;                   // The number of elements in the buffer.

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;      // mutex lock for buffer.
pthread_cond_t c_cons = PTHREAD_COND_INITIALIZER;       // Consumer waiting on cv.
pthread_cond_t c_prod = PTHREAD_COND_INITIALIZER;       // producer waiting on cv.

void *producer(void *param);
void *consumer(void *param);

int main(int argc, char *argv[])
{
    pthread_t tid1, tid2;       // Thread identifiers.

    if (pthread_create(&tid1, NULL, producer, NULL) != 0)
    {
        fprintf(stderr, "Unable to create producer thread.\n");
        exit(1);
    }

    if (pthread_create(&tid2, NULL, consumer, NULL) != 0)
    {
        fprintf(stderr, "Unable to create consumer thread.\n");
        exit(1);
    }

    pthread_join(tid1, NULL);       // Wait for producer to exit.
    pthread_join(tid2, NULL);       // Wait for consumer to exit.

    printf("Parent quiting.\n");

    return 0;
}


void *producer(void *param)
{
    int i;
    
    for (i = 1; i <= 20; i++)
    {
        pthread_mutex_lock(&m);

        if (num > BUFF_SIZE)        // Buffer overflow.
        {
            exit(1);
        }

        while (num == BUFF_SIZE)    // Block if buffer is full.
        {
            pthread_cond_wait(&c_prod, &m);
        }

        buff[add] = i;              // Buffer isn't full, so add element. 
        add = (add + 1) % BUFF_SIZE;
        num++;

        pthread_mutex_unlock(&m);

        pthread_cond_signal(&c_cons);

        printf("Producer: inserted %d\n", i);
        fflush(stdout);
    }

    printf("producer quiting.\n");

    return 0;
}

void *consumer(void *param)
{
    int i;

    for (int j = 0; j < 20; j++)
    {
        pthread_mutex_lock(&m);

        if (num < 0)        // Underflow.
        {
            exit(1);
        }

        while (num == 0)       // Block if buffer is empty.
        {
            pthread_cond_wait(&c_cons, &m);
        }

        i = buff[rem];      // Buffer isn't empty, so remove element.
        rem = (rem + 1) % BUFF_SIZE;
        num--;

        pthread_mutex_unlock(&m);

        pthread_cond_signal(&c_prod);

        printf("Consume value is %d\n", i);
        fflush(stdout);
    }
}