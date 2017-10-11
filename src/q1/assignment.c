#include <stdio.h>

int main(int arg, char* argc[]){
    printf(" Calculating the Size of Data Types in C");
    printf("int: %u\r\n", sizeof(int));
    printf("int*: %u\r\n", sizeof(int*));
    printf("Long: %u\r\n", sizeof(long));
    printf("Double*: %u\r\n", sizeof(double*));
	printf("Char**: %u\r\n", sizeof(char**));
}

