#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * This program demonstrates the use of the fork() and exec()
 * functions.
 */
int main() {
    /* String to hold the command to run. */
    char command[256];
    char *args[256];
    int i;
    int lengthOfCommand = strlen(command);

    do {
        const char *delimiter = " ";
        const char *ampersandChar = "&";
        bool waitCharacterPresent = false;
        char *argument;
        char *context;
        printf("Please Enter the command you want to run: ");
        fgets(command, 256, stdin);


        // Change newline to terminating 0
        command[lengthOfCommand - 1] = 0;

        // Remove any trailing spaces
        while(strcmp(&command[lengthOfCommand - 2], delimiter) == 0) {

            command[lengthOfCommand - 2] = 0;
            lengthOfCommand--;

        }

        // Check if we need to strip off the "&" from the command or last argument
        if(strcmp(&command[lengthOfCommand - 2], ampersandChar) == 0) {

            command[lengthOfCommand - 2] = 0;
            waitCharacterPresent = true;

        }
        //"strtok_r" recommended to be used by Dondi. To extract tokens from strings.
        for(argument = strtok_r(command, delimiter, &context), 
            i;
            argument;  
        	argument = strtok_r(NULL, delimiter, &context), i++){
                // Save command and arguments, the command will be in args[0]
                args[i] = argument;
        }

        //match args[0] with the command  "cd".
        if (strcmp(args[0], "cd") == 0) {

            chdir(args[1]);

        } else if (strcmp(args[0], "secret-system-call") == 0) {  
            // We have Easter egg - if we match the command "secret-system-call".
            syscall(351);

        } else { //The same as Dondi's code.

            args[i] = NULL;

            /* Variable that will store the fork result. */
            pid_t pid;

            /* Perform the actual fork. */
            pid = fork();
            if (pid < 0) {
                /* Error condition. */
                fprintf(stderr, "Fork failed\n");
                return -1;

            } else if (pid == 0) {
                /* Child process. */
                printf("Running...\n");
                execvp(args[0], args);

            } else {
                /* Parent process. */
                int result;
                if (!waitCharacterPresent) {
                    wait(&result);
                }
                printf("All done; result = %d\n", result);
            }
        }
    } while (!feof(stdin));
    return 0;
}