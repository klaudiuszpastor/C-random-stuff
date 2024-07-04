#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd[2];
    // fd[0] - read
    // fd[1] - write
    if (pipe(fd) == -1) {
        printf("Error ocurred with opening the pipe\n");
        return 1;
    }
    int id = fork();
    if (id == -1) {
        printf("Error occured with fork\n");
        return 4;
    }
    if (id == 0) {
        close(fd[0]);
        int x;
        printf("Input a number: ");
        scanf("%d",&x);
        if (write(fd[1],&x,sizeof(int)) == -1) {
            printf("Error ocurred while writing to the pipe\n");
            return 2;
        } 
        close(fd[1]);
    } else {
        int y;
        if (read(fd[0], &y, sizeof(int)) == -1) {
            printf("Error ocurred while reading the pipe\n");
            return 3;
        }
        close(fd[0]);
        printf("Got from child process %d\n",y);
    }


    return 0;
}