#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define LOG_FILE "transaction.log"

pthread_mutex_t lock;
int node1_ready = 1, node2_ready = 0; // node2 defaulted to failed node

void write_log(const char *status)
{
    FILE *log = fopen(LOG_FILE, "w");
    if (log)
    {
        fprintf(log, "%s", status);
        fclose(log);
    }
}

char *read_log()
{
    static char status[20];
    FILE *log = fopen(LOG_FILE, "r");
    if (log)
    {
        fscanf(log, "%19s", status);
        fclose(log);
    }
    else
    {
        strcpy(status, "UNKNOWN");
    }
    return status;
}

void *prepare_phase(void *arg)
{
    pthread_mutex_lock(&lock);
    printf("Coordinator: Checking if nodes are ready\n");

    if (node1_ready && node2_ready)
    {
        write_log("COMMIT");
        printf("Coordinator: Nodes are ready\n");
        printf("Transaction Committed\n");
    }
    else
    {
        write_log("ABORT");
        printf("Coordinator: One or more Nodes are not ready\n");
        printf("Retrying Transaction In 5s\n");
        sleep(5);
        node2_ready = 1;
        write_log("RETRY");
        pthread_mutex_unlock(&lock);
        prepare_phase(NULL);
        return NULL;
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

void recover_transaction()
{
    char *status = read_log();
    printf("Recovery: Last recorded transaction status: %s\n", status);

    if (strcmp(status, "RETRY") == 0 || strcmp(status, "ABORT") == 0)
    {
        printf("Recovery: Retrying transaction...\n");
        prepare_phase(NULL);
    }
    else if (strcmp(status, "COMMIT") == 0)
    {
        printf("Recovery: Transaction was already committed. No action needed.\n");
    }
    else
    {
        printf("Recovery: Unknown transaction state. Starting new transaction...\n");
        prepare_phase(NULL);
    }
}

int main()
{
    pthread_t thread;
    pthread_mutex_init(&lock, NULL);
    printf("Initial node readiness: Node 1 [%s], Node 2 [%s]\n",
           node1_ready ? "READY" : "FAILED",
           node2_ready ? "READY" : "FAILED");

    recover_transaction();

    pthread_create(&thread, NULL, prepare_phase, NULL);
    pthread_join(thread, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}
