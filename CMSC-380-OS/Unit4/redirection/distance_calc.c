/*
    Reads the coordinates of points on the plane and outputs the distance of each point from the origin. The input and output streams
    are redirected to files named on the command line.
*/

#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    // redirect the standard input and standard output streams
    int in = open(argv[1], O_RDONLY, 0666);
    
    close(0); // close stdin
    int dup1 = dup(in);
    close(in);

    int out = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0666);
    close(1);
    int dup2 = dup(out);
    close(out);

    if (dup1 < 0 || dup2 < 0) {
        perror("Could not redirect input and output streams.");
        
        return 1;
    }

    // read number of points
    int num_points;

    printf("Enter number of points: ");
    
    if (scanf("%d", &num_points) != 1) {
        printf("Error reading number of points.\n");

        return 1;
    }

    // read coordinates
    while (num_points-- > 0) {
        int x, y;

        printf("\nEnter coordinates: ");
        
        if (scanf("%d %d", &x, &y) != 2) {
            printf("Error reading number of coordinates.\n");

            return 1;
        }

        float dist = sqrt(x * x + y * y);
        printf("Distance from the origin to (%d, %d): %f\n", x, y, dist);
    }

    return 0;
}
