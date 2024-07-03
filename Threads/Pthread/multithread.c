#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // header file for sleep()
#include <pthread.h>

void* myThreadFun(void *vargp) {
    sleep(1);
    printf("Printing from Thread\n ");
    return NULL;
}

int main() {
    pthread_t thread_id; // declare a variable of type pthread_t which is an integer used to 
                         // identify the thread the system
    printf("Before Thread\n ");
    pthread_create(&thread_id,NULL,myThreadFun,NULL);
    // 1st arg. is a pointer to thread_id which is set by this function
    // 2nd arg. specifies attrubytes NULL - default attrubytes shall be used
    // 3rd arg. name of function to be executed for the thread to be created
    // 4th arg. is used to pass arguments to the function
    pthread_join(thread_id, NULL); // equivalent of wait()/blocks the calling thread until 
                                   // the thread with identifier equal to the first argument terminates
    printf("After Thread\n");
    exit(0);
}