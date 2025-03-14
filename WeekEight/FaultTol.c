// Simulate Distributed Bank Transaction where nodes must agree before transaction is committed
// If a node fails, transaction is aborted

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
int node1_ready = 1, node2_ready = 1;

// Extended With Node
int node3_ready = 1;

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

    pthread_t thread;
    pthread_mutex_init(&lock, NULL);

    printf("Simulating node readiness: Node 1 [%s], Node 2 [%s]\n",
           node1_ready ? "Ready" : "Not Ready", node2_ready ? "Ready" : "Not Ready");

    pthread_create(&thread, NULL, prepare_phase, NULL);
    pthread_join(thread, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}