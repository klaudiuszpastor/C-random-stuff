#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //<process.h> for windows
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    int pid = fork();
    if (pid == -1) {
        return 1;
    }
    if (pid == 0) {
        // Child process
        int file = open("pingResults.txt", O_WRONLY | O_CREAT, 0777);
        if (file == -1) {
            return 2;
        }

        printf("The fd to  pingResults: %d\n",file);
        dup2(file, STDOUT_FILENO); //new file descriptor overwritten on 1
        close(file);

        int err = execlp("ping","ping","-c","3","google.com",NULL);
        if (err == -1) {
            printf("Could not find program to execute\n");
            return 2;
        }
        
    } else {
        int wstatus;
        // Parent process
        wait(&wstatus);
        if (WIFEXITED(wstatus)) {
            int statusCode = WEXITSTATUS(wstatus);
            if (statusCode == 0) {
                printf("Success!\n");
            } else {
                printf("Failure %d status code\n",statusCode);
            }
        }
        printf("Some post processing goes here\n");
    }
    
    return 0;
}