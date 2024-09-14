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

//Print primes
void printPrimes(int num){
    for (int i = 2; i <= num; i++){
        if (isPrime(i)){
            printf("%d ", i);
        }
    }
    printf("\n");
}

//Calculate two to the power of n
int twoPower(int n){
    if (n == 0)
        return 1;
    else {
        return 2 * twoPower(n - 1);
    }
}

//Calculate perimiter of a rectangle
int perimiter(int l, int w){
    return l * 2 + w * 2;
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
            printf("Child %d (PID: %d) created.\n", i, getpid());

            if (i == 1){
                //Compute factorial of a random number between 1 and 8
                int factor = rand() % 9;
                printf("Child %d (PID: %d) is computing the factorial of %d.\n", i, getpid(), factor);
                int result = factorial(factor);
                printf("Child %d (PID: %d) completed its task of finding the factorial of %d = %d", i, getpid(), factor, result);
            }
            else if (i == 2){
                //print prime numbers up to 20
                printf("Child %d (PID: %d) is computing prime numbers up to 20.\n", i, getpid());
                printf("Child %d (PID: %d) finished computing, prime numbers up to 20: ", i, getpid());
                printPrimes(20);
            }
            else if (i == 3){
                int power = rand() % 10;
                printf("Child %d (PID: %d) is computing two to the power of %d. \n", i, getpid(), power);
                int result = twoPower(power);
                printf("Child %d (PID: %d) finished computing 2 to the power of %d: %d.\n", i, getpid(), power, result);
            }
            else if (i == 4){
                int length = rand() % 100;
                int width = rand() % 50;
                printf("Child %d (PID: %d) is calculating the perimiter of a rectangle of length %d, and width %d.\n", i, getpid(), length, width);
                int result = perimiter(length, width);
                printf("Child %d (PID: %d) finished its task, resulting perimiter: %d.\n", i, getpid(), result);
            }

            exit(0);
        }
    }

    for (int i = 1; i <= children; i++){
        wait(NULL);
    }

    printf("All child processes have finished. Parent (PID: %d) is displaying the final message.\n", getpid());

    return 0;
}