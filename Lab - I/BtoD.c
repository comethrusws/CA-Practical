#include <stdio.h>

int binaryToDecimal(int binary) {
    int decimal = 0, base = 1, remainder;

    while (binary > 0) {
        remainder = binary % 10;
        decimal += remainder * base;
        binary /= 10;
        base *= 2;
    }

    return decimal;
}

int main() {
    int binaryNumber;

    printf("Enter a binary number: ");
    scanf("%d", &binaryNumber);

    int decimalNumber = binaryToDecimal(binaryNumber);

    printf("Decimal equivalent: %d\n", decimalNumber);

    return 0;
}
