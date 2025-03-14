/* Concept of Mutex
* one thread can acquire a lock a time;
* other threads must wait until lock is released

Why Mutex?
Without it, threads modify shared data simultaneously causing race condition
causes incorrect or unpredictable results

How it works?
Thread_1 locks pthread_mutex_lock() and starts modifying data
Thread_2 ltries to acess fields but has to wait until Thread_1 unlocks
pthread_mutex_unlock
*/

// Example
#include <pthread.h>
#include <stdio.h>

int counter = 0;
void *increment(void *arg)
{
    for (int i = 0; i < 1000000; i++)
    {
        counter++;
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    // Creates two threads t1,t2 while both executing increment() at the same time
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    // Main thread, ensures that MT waits for t1/2 to execute before proceeding
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Expect 2000000 returns incorrect
    printf("Final Counter Val: %d\n", counter);
    return 0;
}