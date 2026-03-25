/*

*/

#include <sys/types.h> // pid_t
#include <unistd.h> // fork, exexclp
#include <sys/wait.h> // wait
#include <stdlib.h> // exit
#include <stdio.h>

int main() {
    int x = 0;
    pid_t pid = fork();

    if (pid == 0) {
        x++;
    } else {
        wait(NULL);
        printf("%d\n", x);
    }

    printf("%d\n", x);

    return 0;
}
