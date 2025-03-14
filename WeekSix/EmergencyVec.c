#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
char lights[4] = {'G', 'R', 'R', 'R'}; // NS, EW, SN, WE
int car_count[4] = {0, 0, 0, 0};
int current_road = 0; // 0: NS, 1: EW, 2: SN, 3: WE
int last_index = -1;
int e_road = -1;

void *control_lights(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&lock);

        if (e_road != -1)
        {
            for (int i = 0; i < 4; i++)
            {
                lights[i] = 'R';
            }

            lights[e_road] = 'G';

            printf("Emergency Vec detected!, Giviing priority to %d\n", e_road);
            printf("NS: %c, EW: %c, SN: %c, WE: %c\n", lights[0], lights[1], lights[2], lights[3]);
            sleep(5);

            lights[e_road] = 'Y';
            printf("NS: %c, EW: %c, SN: %c, WE: %c\n", lights[0], lights[1], lights[2], lights[3]);
            sleep(2);

            e_road = -1;
        }
        else
        {

            // Randomly generate car counts for each road (0-10 cars)
            for (int i = 0; i < 4; i++)
            {
                car_count[i] = rand() % 11;
            }

            printf("Cars on NS: %d, EW: %d, SN: %d, WE: %d\n", car_count[0], car_count[1], car_count[2], car_count[3]);

            // Determine road with the most cars
            int max_index = 0;
            for (int i = 1; i < 4; i++)
            {
                if (car_count[i] > car_count[max_index])
                    max_index = i;
            }

            // If the max_index is the same as the last one, switch to the next road in order
            if (max_index == last_index)
                max_index = (last_index + 1) % 4;

            last_index = max_index; // Update last used road

            // Set all lights to red first
            for (int i = 0; i < 4; i++)
                lights[i] = 'R';

            // Give green to the selected road
            lights[max_index] = 'G';
            printf("NS: %c, EW: %c, SN: %c, WE: %c\n", lights[0], lights[1], lights[2], lights[3]);
            sleep(5);

            // Change to yellow before stopping
            lights[max_index] = 'Y';
            printf("NS: %c, EW: %c, SN: %c, WE: %c\n", lights[0], lights[1], lights[2], lights[3]);
            sleep(2);
        }

        pthread_mutex_unlock(&lock);
        sleep(1); // Small delay before switching
    }
    return NULL;
}

void *ambulance(void *arg)
{

    while (1)
    {
        pthread_mutex_lock(&lock);
        e_road = rand() % 4;
        pthread_mutex_unlock(&lock);
        sleep(10);
    }

    return NULL;
}

int main()
{
    pthread_t traffic_thread, ambulance_thread;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&traffic_thread, NULL, control_lights, NULL);
    pthread_create(&ambulance_thread, NULL, ambulance, NULL);

    pthread_join(traffic_thread, NULL);
    pthread_join(ambulance_thread, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}