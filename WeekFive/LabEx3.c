/* Protect Shared Resource

* Modify prev program so that instead of incrementing single var
* each thread writes to shared array
* filling an array with numbers to 1...10,000
* Use mutex to prevent race condition
*/

// Task
#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#define SIZE 10000
#define N_THREADS 2

int shareArr[SIZE];
int index_counter = 0; // Array Position Tracker
pthread_mutex_t lock;

void *modifyArray(void *arg)
{

    // SIZE/N_THREADS says each pthread_t 5,000 elements per thread
    for (int i = 0; i < SIZE / N_THREADS; i++)
    {

        // thread one normally append
        pthread_mutex_lock(&lock);
        shareArr[index_counter] = index_counter + 1; // puts 1 in 0th place etc.. 1...100000
        index_counter++;
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL); // Initialize mutex

    pthread_create(&t1, NULL, modifyArray, NULL);
    pthread_create(&t2, NULL, modifyArray, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock); // Destroy mutex

    printf("first 20 elements of array with share t's");
    for (int i = 9990; i < 10000; i++)
    {
        printf("%d ", shareArr[i]);
    }
    printf("\n");

    return 0;
}