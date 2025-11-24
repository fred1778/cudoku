#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void validateInput(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    printf("%i\n", argc);
    validateInput(argc, argv);


    return 0;
}



void validateInput(int argc, char *argv[]) {
    if (argc != 2) {
        EXIT_FAILURE;
    }
    
   
}