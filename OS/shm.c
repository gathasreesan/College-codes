#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int shmid;
    char *str;

    shmid = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);

    str = (char*) shmat(shmid, NULL, 0);

    if(fork() == 0)
    {
        sleep(1);
        printf("Child read: %s\n", str);
    }
    else
    {
        strcpy(str, "Hello from Parent using Shared Memory");
        printf("Parent wrote message\n");
    }

    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
