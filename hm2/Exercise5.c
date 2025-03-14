#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define ROWS 800
#define COLS 800
#define DEPTH 800
#define NUM_THREADS 4

double matrixA[ROWS][COLS], matrixB[COLS][DEPTH], matrixC[ROWS][DEPTH], matrixC_seq[ROWS][DEPTH];

typedef struct {
    int startRow;
    int endRow;
    double elapsedTime;
} ThreadArgs;

void *multiplyPartialMatrix(void *args) {
    ThreadArgs *threadData = (ThreadArgs *)args;
    struct timeval startTime, endTime;
    gettimeofday(&startTime, NULL);
    for(int i = threadData->startRow; i < threadData->endRow; i++) {
        for(int j = 0; j < DEPTH; j++) {
            matrixC[i][j] = 0.0;
            for(int k = 0; k < COLS; k++)
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
        }
    }
    gettimeofday(&endTime, NULL);
    threadData->elapsedTime = (endTime.tv_sec - startTime.tv_sec) * 1e6 + (endTime.tv_usec - startTime.tv_usec);
    pthread_exit(NULL);
}

int main() {
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            matrixA[i][j] = (double)(rand()%10);

    for(int i = 0; i < COLS; i++)
        for(int j = 0; j < DEPTH; j++)
            matrixB[i][j] = (double)(rand()%10);

    struct timeval seqStart, seqEnd;
    gettimeofday(&seqStart, NULL);
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < DEPTH; j++) {
            double tempSum = 0.0;
            for(int k = 0; k < COLS; k++)
                tempSum += matrixA[i][k] * matrixB[k][j];
            matrixC_seq[i][j] = tempSum;
        }
    gettimeofday(&seqEnd, NULL);
    double sequentialTime = (seqEnd.tv_sec - seqStart.tv_sec)*1e6 + (seqEnd.tv_usec - seqStart.tv_usec);

    pthread_t threads[NUM_THREADS];
    ThreadArgs threadArgs[NUM_THREADS];
    int rowsPerThread = ROWS / NUM_THREADS;
    int extraRows = ROWS % NUM_THREADS;

    gettimeofday(&seqStart, NULL);
    int rowPointer = 0;
    for(int i = 0; i < NUM_THREADS; i++) {
        threadArgs[i].startRow = rowPointer;
        threadArgs[i].endRow = rowPointer + rowsPerThread + (i < extraRows ? 1 : 0);
        rowPointer = threadArgs[i].endRow;
        pthread_create(&threads[i], NULL, multiplyPartialMatrix, &threadArgs[i]);
    }
    for(int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);
    gettimeofday(&seqEnd, NULL);
    double parallelTime = (seqEnd.tv_sec - seqStart.tv_sec)*1e6 + (seqEnd.tv_usec - seqStart.tv_usec);

    for(int i = 0; i < NUM_THREADS; i++)
        printf("Thread %d time (us): %.2f\n", i, threadArgs[i].elapsedTime);

    printf("Sequential time (us): %.2f\n", sequentialTime);
    printf("Parallel total time (us): %.2f\n", parallelTime);

    return 0;
}
