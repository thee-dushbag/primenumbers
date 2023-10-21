#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "depc/mystr.h"
#include "depc/util.h"
#include "depc/primefunctions.h"
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Syntax: %s <number>\n", argv[0]);
        return 1;
    }
    int q = atoi(argv[1]);
    // int q = 20000;
    int store[q];
    struct bundle bud[5];
    bud[0].func = &get_primes_all;
    bud[0].funcname = "get_primes_all";
    bud[0].q = q;
    bud[0].store = store;
    bud[1].func = &get_primes_odd;
    bud[1].funcname = "get_primes_odd";
    bud[1].q = q;
    bud[1].store = store;
    bud[2].func = &get_primes_half_odd;
    bud[2].funcname = "get_primes_half_odd";
    bud[2].q = q;
    bud[2].store = store;
    bud[3].func = &get_primes_half_primes;
    bud[3].funcname = "get_primes_half_primes";
    bud[3].q = q;
    bud[3].store = store;
    speedtest(bud, 4);
}