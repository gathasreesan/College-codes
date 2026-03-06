#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/shm.h>
#include <unistd.h>

#define N 5

sem_t fork_sem[N];
int *state;

void* philosopher(void *num)
{
    int id = *(int*)num;

    printf("Philosopher %d is thinking\n", id);
    sleep(1);

    sem_wait(&fork_sem[id]);              // pick left fork
    sem_wait(&fork_sem[(id+1)%N]);        // pick right fork

    state[id] = 1;
    printf("Philosopher %d is eating\n", id);
    sleep(2);

    sem_post(&fork_sem[id]);              // put left fork
    sem_post(&fork_sem[(id+1)%N]);        // put right fork

    state[id] = 0;
    printf("Philosopher %d finished eating\n", id);

    return NULL;
}

int main()
{
    pthread_t phil[N];
    int id[N];

    int shmid = shmget(1234, N*sizeof(int), IPC_CREAT | 0666);
    state = (int*) shmat(shmid, NULL, 0);

    for(int i=0;i<N;i++)
        sem_init(&fork_sem[i],0,1);

    for(int i=0;i<N;i++)
    {
        id[i]=i;
        pthread_create(&phil[i],NULL,philosopher,&id[i]);
    }

    for(int i=0;i<N;i++)
        pthread_join(phil[i],NULL);

    for(int i=0;i<N;i++)
        sem_destroy(&fork_sem[i]);

    shmdt(state);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
