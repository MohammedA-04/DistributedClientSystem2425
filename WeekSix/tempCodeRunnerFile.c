#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
char lights[4] = {'G', 'R', 'R', 'R'}; // NS, EW, SN, WE
int current_road = 0;                  // 0: NS, 1: EW, 2: SN, 3: WE
