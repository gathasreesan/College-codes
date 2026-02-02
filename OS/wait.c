#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        // Child process
        printf("Child process is running\n");
        sleep(2);   // simulate some work
        printf("Child process completed\n");
    }
    else
    {
        // Parent process
        wait(NULL); // wait for child to finish
        printf("Parent resumes after child termination\n");
    }

    return 0;
}
