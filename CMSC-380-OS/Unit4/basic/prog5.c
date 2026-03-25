/*
    How many processes are created?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    fork();
    fork();

    printf("%d\n", getpid());

    return 0;
}
