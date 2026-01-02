#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int src = open("input.txt", O_RDONLY);
    int dest = open("output.txt", O_WRONLY | O_CREAT, 0644);
    char buffer[100];
    int n;

    while ((n = read(src, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, n);
    }

    close(src);
    close(dest);

    return 0;
}
