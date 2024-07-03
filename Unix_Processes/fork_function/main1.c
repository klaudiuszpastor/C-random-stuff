#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int id = fork();
    if (id != 0) {
        fork();
    }
    printf("Hello world\n");
}