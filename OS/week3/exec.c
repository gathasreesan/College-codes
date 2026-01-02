#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-l", NULL};
    execvp("ls", args);

    printf("This line prints only if exec fails!\n");
    return 0;
}
