#include <stdio.h>
#include <string.h>

void ones_complement(char binary[], int length) {
    for (int i = 0; i < length; i++) {
        binary[i] = (binary[i] == '0') ? '1' : '0';
    }
}

void add_binary(char x[], char y[], char result[], int length) {
    int carry = 0;
    for (int i = length - 1; i >= 0; i--) {
        int sum = (x[i] == '1') + (y[i] == '1') + carry;
        result[i + 1] = (sum % 2) + '0';
        carry = sum / 2;
    }
    result[0] = carry + '0';    
}

int main() {
    char minuend[33], subtrahend[33], result[34];
    int length;

    printf("Enter the binary minuend: ");
    scanf("%s", minuend);

    printf("Enter the binary subtrahend: ");
    scanf("%s", subtrahend);

    length = strlen(minuend);

    ones_complement(subtrahend, length);

    add_binary(minuend, subtrahend, result, length);

    printf("Result: %s\n", result + 1);

    return 0;
}