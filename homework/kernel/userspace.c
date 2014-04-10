#include <unistd.h>
#include <stdio.h>
int main() {
	syscall(351, "here the new syscall I struggled creating.");
	return 0;
}
