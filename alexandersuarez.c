#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int factorial(int input){                  //Compute factorial
    if (input == 0 || input == 1)
        return 1;
    return input * factorial(input - 1);
}

int 

int main() {
    pid_t child_pid;

    // Fork a new process
    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // This code will be executed by the child process

        // Execute a new program using execl
        execl("/bin/ls", "ls", "-l", NULL);

        // If execl fails, this code will be reached
        perror("Execl failed");
        exit(EXIT_FAILURE);
    } else {
        // This code will be executed by the parent process

        printf("Parent: Child process created with PID %d\n", child_pid);

        // Wait for the child process to finish
        wait(NULL);

        printf("Parent: Child process finished\n");
    }

    return 0;
}