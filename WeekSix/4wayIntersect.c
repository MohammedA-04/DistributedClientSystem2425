#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
char lights[4] = {'G', 'R', 'R', 'R'}; // NS, EW, SN, WE
int current_road = 0;                  // 0: NS, 1: EW, 2: SN, 3: WE

void *control_lights(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&lock);

        // Set all to red first
        for (int i = 0; i < 4; i++)
            lights[i] = 'R';

        // Current road gets green
        lights[current_road] = 'G';
        printf("NS: %c, EW: %c, SN: %c, WE: %c\n", lights[0], lights[1], lights[2], lights[3]);
        sleep(5);

        // Change to yellow
        lights[current_road] = 'Y';
        printf("NS: %c, EW: %c, SN: %c, WE: %c\n", lights[0], lights[1], lights[2], lights[3]);
        sleep(2);

        // Move to next road in round-robin fashion
        current_road = (current_road + 1) % 4;

        pthread_mutex_unlock(&lock);
        sleep(1); // Small delay before switching
    }
    return NULL;
}

int main()
{
    pthread_t traffic_thread;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&traffic_thread, NULL, control_lights, NULL);
    pthread_join(traffic_thread, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}