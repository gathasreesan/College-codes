#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2];
    pid_t pid;
    char write_msg[] = "Hello from Parent";
    char read_msg[100];

    pipe(fd);   // create pipe

    pid = fork();

    if(pid > 0)   // Parent process
    {
        close(fd[0]); // close read end
        write(fd[1], write_msg, strlen(write_msg)+1);
        printf("Parent sent: %s\n", write_msg);
    }
    else          // Child process
    {
        close(fd[1]); // close write end
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
    }

    return 0;
}
