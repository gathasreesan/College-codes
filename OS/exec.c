#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        // Child process
        printf("Child executing exec() system call\n");

        execl("/bin/ls", "ls", "-l", NULL);

        // Executes only if exec() fails
        printf("exec() failed\n");
    }
    else
    {
        // Parent process
        printf("Parent process continues execution\n");
    }

    return 0;
}
