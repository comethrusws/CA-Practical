#include <stdio.h>

void calculateComplements(int binary[], int size) {
    int onesComplement[size];
    int twosComplement[size];

    // Calculate ones' complement
    for (int i = 0; i < size; i++) {
        onesComplement[i] = (binary[i] == 0) ? 1 : 0;
    }

    // Calculate twos' complement
    int carry = 1;
    for (int i = size - 1; i >= 0; i--) {
        twosComplement[i] = (onesComplement[i] + carry) % 2;
        carry = (onesComplement[i] + carry) / 2;
    }

    printf("Original Binary: ");
    for (int i = 0; i < size; i++) {
        printf("%d", binary[i]);
    }

    printf("\nOnes' Complement: ");
    for (int i = 0; i < size; i++) {
        printf("%d", onesComplement[i]);
    }

    printf("\nTwos' Complement: ");
    for (int i = 0; i < size; i++) {
        printf("%d", twosComplement[i]);
    }

    printf("\n");
}

int main() {
    int size;

    printf("Enter the size of the binary number: ");
    scanf("%d", &size);

    int binary[size];

    printf("Enter the binary number (enter each digit separated by a space): ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &binary[i]);
    }

    calculateComplements(binary, size);

    return 0;
}
