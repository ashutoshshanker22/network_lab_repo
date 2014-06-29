#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>


struct argument {
    char *device;
    int max_ttl;
    char proto[100];
    int debug;
    int options; // socket options
};

void usage(void);
void print_arg(struct argument *arg);