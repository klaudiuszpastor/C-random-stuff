/*Number Guessing Game*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // seed the random number generator to ensure pseudorandom number
    srand(time(NULL));

    // generate a random number between 1-100
    int number = (rand() % 100) +1;
    int guess = 0;

    do {
        printf("Eneter a number between 1-100:\n");
        scanf("%d",&guess);

        if (guess == number) printf("You got it\n");
        else if (guess < number) printf("Guess higher\n");
        else printf("Guess lower\n");
    } while (guess != number);

    return 0;
}