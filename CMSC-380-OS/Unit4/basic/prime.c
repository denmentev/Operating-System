/*

*/

// <> include are for files in the c stdlib that are known on disk, "" are used for ones in local directory

#include <stdlib.h>
#include "prime.h"

int is_prime(int n) {
    if (n < 2) {
        return 0;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int get_prime(int n) {
    while (1) {
        int k = rand() % n;
        
        if (is_prime(k)) {
            return k;
        }
    }
}
