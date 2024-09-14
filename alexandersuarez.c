#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//compute factorial
int factorial(int input){
    if (input == 0 || input == 1)
        return 1;
    return input * factorial(input - 1);
}

//Checking if a number is prime
int isPrime(int num){
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;

    //Checking for prime numbers above 2
    for (int i = 3; i <= num; i += 2){
        if (num % i == 0)
            return 0;
    }

    return 1; 
}

//Calculate area of a square
int squareArea(int num){
    return num * num;
}



int main() {
    //Get legal number of children from input
    int children;
    printf("Enter the number of child processes you would like to create (1-4):");
    scanf("%d", &children);
    if (children <= 0 || children > 4){
        printf("Illegal amount of child processes. \n");
        return 1;
    }

    printf("Parent process (PID: %d) is creating %d child processes.\n", getpid(), children);

    //Create child processes
    for (int i = 1; i <= children; i++){
        pid_t child_pid = fork();

        if (child_pid < 0){
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0){
            
        }
    }

    return 0;
}