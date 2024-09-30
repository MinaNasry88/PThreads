#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 4

void *threadsFunc(void *pArg)
{
    int myNum = *((int *)pArg);
    printf("Thread number: %d\n", myNum);
    return 0;
}

int main(void)
{
    int i;
    pthread_t tid[NUM_THREADS];
    int tNum[NUM_THREADS];

    for (i = 0; i < NUM_THREADS; i++)
    {
        tNum[i] = i;
        pthread_create(&tid[i], NULL, threadsFunc, &tNum[i]);
    }

    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tid[i], NULL);
    }

    return 0;
}