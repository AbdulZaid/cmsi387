/**
 * Abdul Alzaid.
 * CMSI387: Operating System
 * This program demonstrates invocation of the rmdir
 * system call (40) using the syscall function.
 * Contributions made by Abdul Alzaid, Carlos Agudo, and Jonathan Piatos.
 */
#include <linux/types.h>
#include <linux/unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {

  int result = syscall(40, argv[1]);

  // A result of -1 means that something went wrong.  Otherwise, 0 means success.
  if (result == 0) {
    char *successMessage = "You are Successful\n";
    syscall(4, 2, successMessage, strlen(successMessage));
  } if (result == -1) {
    char *errorMessage = "You are wrond my friend.\n";
    syscall(4, 2, errorMessage, strlen(errorMessage));
  }

}
