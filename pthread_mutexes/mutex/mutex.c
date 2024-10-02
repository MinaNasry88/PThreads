#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 3

int buff[BUFF_SIZE];
int add = 0;
int rem = 0;
int num = 0;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c_prod = PTHREAD_COND_INITIALIZER;
pthread_cond_t c_cons = PTHREAD_COND_INITIALIZER;

void *producer(void *param);
void *consumer(void *param);

int main(int argc, char *argv[])
{
    pthread_t tid1, tid2;
    
    if (pthread_create(&tid1, NULL, producer, NULL) != 0)
    {
        fprintf(stderr, "Unable to create producer thread.\n");
    }

    if (pthread_create(&tid2, NULL, consumer, NULL) != 0)
    {
        fprintf(stderr, "Unable to create consumer thread.\n");
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("Parent quiting.\n");
}

void *producer(void *param)
{
    int i;

    for (i = 1; i <= 20; i++)
    {
        pthread_mutex_lock(&m);

        if (num > BUFF_SIZE)
        {
            exit(1);
        }

        while (num == BUFF_SIZE)
        {
            pthread_cond_wait(&c_prod, &m);
        }

        buff[add] = i;
        add = (add + 1) % BUFF_SIZE;
        num++;

        pthread_mutex_unlock(&m);

        pthread_cond_signal(&c_cons);

        printf("Producer: inserted %d\n", i);
        fflush(stdout);
    }

    printf("Producer quiting.\n");
    fflush(stdout);

    return 0;
}

void *consumer(void *param)
{
    int i;

    for (i = 1; i <= 20; i++)
    {
        pthread_mutex_lock(&m);

        if (num < 0)
        {
            exit(1);
        }

        while (num == 0)
        {
            pthread_cond_wait(&c_cons, &m);
        }

        i = buff[rem];
        rem = (rem + 1) % BUFF_SIZE;
        num--;

        pthread_mutex_unlock(&m);

        pthread_cond_signal(&c_prod);

        printf("Consumer value: %d\n", i);
        fflush(stdout);
    }

    printf("Consumer quiting.\n");
    fflush(stdout);

    return 0;
}