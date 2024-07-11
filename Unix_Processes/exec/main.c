#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //<process.h> for windows
#include <errno.h>

int main (int argc, char* argv[], char* envp[]) {
    char* arr[] = {
        "ping",
        "google.com",
        NULL
    };
    char* env[] = {
        "TEST=environment variable",
        NULL
    };

    execvpe(
        "ping",
        arr,
        env
    );

    int err = errno;

    printf("Ping finished executing\n");
    return 0;
}