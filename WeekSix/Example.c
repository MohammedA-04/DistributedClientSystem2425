#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
char light_NS = 'G';
char light_EW = 'R';

void *control_NS(void *arg)
{

    while (1)
    {
        pthread_mutex_lock(&lock);
        light_NS = 'G';
        light_EW = 'R';
        printf("NS: Green, EW: Red\n");
        sleep(5);

        light_NS = 'Y';
        printf("NS: Yellow, EW: Red\n");
        sleep(2);

        light_NS = 'R';
        light_EW = 'G';
        printf("NS: Red, EW: Green\n");
        pthread_mutex_unlock(&lock);
        sleep(5);
    }
    return NULL;
}

void *control_EW(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&lock);
        if (light_EW == 'G')
        {
            light_EW = 'Y';
            printf("NS: RED, EW: YELLOW\n");
            sleep(2);
            light_EW = 'R';
            light_NS = 'G';
            printf("NS: GREEN, EW: RED\n");
        }
        pthread_mutex_unlock(&lock);
        sleep(5);
    }
    return NULL;
}

int main()
{

    pthread_t t_NS, t_EW;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&t_NS, NULL, control_NS, NULL);
    pthread_create(&t_EW, NULL, control_EW, NULL);

    pthread_join(t_NS, NULL);
    pthread_join(t_EW, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}