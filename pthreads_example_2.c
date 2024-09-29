#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 4


void *threadFunc(void *pArg)
{
    int *p = (int *)pArg;
    int myNum = *p;
    printf("Thread number: %d\n", myNum);
    return 0;
}

int main(void)
{
    int i;
    pthread_t tid[NUM_THREADS];
    pthread_attr_t attr;

    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&tid[i], NULL, threadFunc, &i);
    }

    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tid[i], NULL);
    }

    return 0;
}