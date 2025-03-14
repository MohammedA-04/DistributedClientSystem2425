// Implementing BZT algorithm in Distributed System

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
int node1_ready = 1, node2_ready = 1, node3_ready = 0;

void *prepare_phase(void *arg)
{

    pthread_mutex_lock(&lock);
    printf("Coordinaot: Checking if node are ready\n");

    if (node1_ready && node2_ready && node3_ready)
    {
        printf("Coordinator: Nodes are ready\n");
        printf("Transaction Comitted\n");
    }
    else
    {
        printf("Coordinator: Nodes are not ready\n");
        printf("Transaction Aborted\n");
    }

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{

    pthread_mutex_t lock;

    // TODO: Randomise Node 3 readiness by either setting it to 0 or 1

    return 0;
}