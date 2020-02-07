#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


void main() {
    vfork();
    printf("DONE@@@@\n");
}
