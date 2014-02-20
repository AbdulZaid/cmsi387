/**
 * This program demonstrates invocation of the sysinfo
 * system call (116) using the syscall function.  Some
 * of its output is then displayed.
 */
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/unistd.h>
#include <unistd.h> 
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // The sysinfo structure is in kernel.h.

  // We keep the hardcoded system call numbers to illustrate
  // that they are still just that: numbers.
    int result = syscall(33, argv[1], R_OK);

  if (result == 0) {
    // Don't use this error message in "real" programs. O_o
    char *successMessage = "Read Access is Granted\n";
    syscall(4, 2, successMessage, strlen(successMessage));
  } else if (result == -1 ){
     char *failMessage = "Read Access is denied\n";
     syscall (4, 2, failMessage, strlen(failMessage));
  }
}
