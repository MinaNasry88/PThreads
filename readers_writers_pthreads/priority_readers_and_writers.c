#include "PRIORITY_READERS_AND_WRITERS_H_"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_READERS 5
#define NUM_READS 5
#define NUM_WRITERS 5
#define NUM_WRITES 5


unsigned int gSharedValue = 0;
pthread_mutex_t gSharedMemoryLock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t gReadPhase = PTHREAD_COND_INITIALIZER;
pthread_cond_t gWritePhase = PTHREAD_COND_INITIALIZER;
int gWaitingReaders, gReaders = 0;

int main(int argc, char **argv)
{
    return 0;
}

void *readerMain(void *threadArgument)
{
    return 0;
}

void *writerMain(void *threadArgument)
{
    return 0;
}