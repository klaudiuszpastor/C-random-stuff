#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int id = fork();
    if (id == 0) {
        sleep(1);
    }
    // printf("%d\n",getpid());
    printf("Current ID: %d, parent ID: %d \n",
        getpid(),getppid());

    int res = wait(NULL);
    if (res == -1) {
        printf("No children to wait for \n");
    } else {
        printf("%d finished execution\n",res);
    }

    return 0;
}