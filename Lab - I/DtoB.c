#include <stdio.h>

void decimalToBinary(int decimal) {
    int binary[32], index = 0;

    while (decimal > 0) {
        binary[index++] = decimal % 2;
        decimal /= 2;
    }

    printf("Binary equivalent: ");
    
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }

    printf("\n");
}

int main() {
    int decimalNumber;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    decimalToBinary(decimalNumber);

    return 0;
}
