/*
*   As you noticed Dondi, I used C++ cmpiler for this ;)
*/
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

    //"feof", checks whether the end-of-File indicator associated with stream is set, 
    //returning a value different from zero if it is.
    while (!feof(stdin)) {
        const char *delim = " ";
        const char *ampersandChar = "&";
        bool ampersandPresent = false;
        char *argument; 
        char *saveptr; // The saveptr argument is a pointer to a char * variable that is used internally by strtok_r()
        printf("Please Enter the command you want to run: ");
        
        //reads a line from the specified stream "stdin" and stores it into the string pointed to by command.
        fgets(command, 256, stdin);

        int lengthOfCommand = strlen(command);

        // places zero to end newline.
        command[lengthOfCommand - 1] = 0;

        // Removes the trailing spaces from the passed in command.
        while (strcmp(&command[lengthOfCommand - 2], delim) == 0) {
            command[lengthOfCommand - 2] = 0;
            lengthOfCommand -= 1;

        }

        // Check if we need to remove the "&" from the passed in command or from the last argument
        if (strcmp(&command[lengthOfCommand - 2], ampersandChar) == 0) {

            command[lengthOfCommand - 2] = 0;
            ampersandPresent = true;

        }
        //"strtok_r" recommended to be used by Dondi. To extract tokens from strings.
        for (argument = strtok_r(command, delim, &saveptr), 
            i = 0;
            argument;  
        	argument = strtok_r(NULL, delim, &saveptr), i++){
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
                if (!ampersandPresent) {
                    wait(&result);
                }
                printf("All done; result = %d\n", result);
            }
        }
    } 
    return 0;
}