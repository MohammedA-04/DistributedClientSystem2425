/* Bank Account System

* Two threads perform deposits and withdrawl safely using mutex
* Withdrawl: check money ? with input amount : reject
* Deposit: amount we have -> input adds to the amount we have
*/

// Task
#include <stdio.h>
#include <pthread.h>
#include <assert.h>

int money = 100;
pthread_mutex_t lock;

void *withdrawl(void *arg)
{

    int amount = *(int *)arg;
    pthread_mutex_lock(&lock);

    if (money < amount)
    {
        printf("Cannot Withdrawn %d from %d", amount, money);
    }
    else
    {
        money = money - amount;
    }

    pthread_mutex_unlock(&lock);
    return NULL;
}

void *deposit(void *arg)
{
    int amount = *(int *)arg;
    pthread_mutex_lock(&lock);
    money = money + amount;
    pthread_mutex_unlock(&lock);
}

int main()
{
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);

    int depositAmount = 100;
    int withdrawnAmount = 50;

    pthread_create(&t1, NULL, deposit, &depositAmount);
    pthread_create(&t2, NULL, withdrawl, &withdrawnAmount);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock); // Destroy mutex

    printf("New Balance After Operations: %d", money);

    return 0;
}