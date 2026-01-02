#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int src = open("input1.txt", O_RDONLY);
    int dest = open("part.txt", O_WRONLY | O_CREAT, 0644);
    char buffer[6];

    lseek(src, 14, SEEK_SET);   // move to 15th character (index starts at 0)
    read(src, buffer, 6);       // read 15th–20th characters
    write(dest, buffer, 6);

    close(src);
    close(dest);

    return 0;
}
