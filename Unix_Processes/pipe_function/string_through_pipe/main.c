#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int fd[2];
    if (pipe(fd) == -1) {
        return 1;
    }

    int pid = fork();
    if (pid < 0) {
        return 2;
    }

    if (pid == 0) {
        // Child process
        close(fd[0]);
        char str[200];
        printf("Input string: \n");
        fgets(str, 200, stdin);
        str[strlen(str) - 1] = '\0';

        int n = strlen(str) +1;
        write(fd[1], &n, sizeof(int));

        if (write(fd[1], str, sizeof(char) * n) < 0) {
            return 3;
        }
        close(fd[1]);
    } else {
        // Parent process
        close(fd[1]);
        char str[200];
        int n;
        read(fd[0], n, sizeof(int));
        read(fd[0], str, sizeof(char) * n );
        printf("Received: %s\n",str);
        close(fd[0]);
        wait(NULL);
    }

    return 0;
}