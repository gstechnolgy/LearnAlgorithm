/*
Function to find the power of given number 
*/
#include <stdio.h>
int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
/* recursive implementation */
int powerRecursive(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return base * powerRecursive(base, exponent - 1);
}

int main() {
    int base = 2;
    int exponent = 3;
    printf("Iterative: %d^%d = %d\n", base, exponent, power(base, exponent));
    printf("Recursive: %d^%d = %d\n", base, exponent, powerRecursive(base, exponent));
    return 0;
}
