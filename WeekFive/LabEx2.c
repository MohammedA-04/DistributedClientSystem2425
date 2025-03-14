/* Fixing the Race Condition with Mutex

Results
* Here we are modifiying the program to use a mutex lock
* Observe the output it should match the expected:2000000
*/

// Task
#include <stdio.h>
#include <pthread.h>
#include <assert.h>

int counter = 0;
pthread_mutex_t lock; // Mutex Var

void *increment(void *arg)
{
    for (int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    // Start (intialise) mutex
    pthread_mutex_init(&lock, NULL);

    // Thread Creation and Wait Until Processed
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroy mutex
    pthread_mutex_destroy(&lock);

    printf("Final Counter Val: %d\n", counter);
    assert(counter == 2000000);

    return 0;
}