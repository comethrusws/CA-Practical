#include <stdio.h>
#include <string.h>

// Function to perform bitwise NOT operation on a binary string
void bitwiseNOT(char binary[]) {
    int i;
    int len = strlen(binary);

    for (i = 0; i < len; i++) {
        if (binary[i] == '0')
            binary[i] = '1';
        else
            binary[i] = '0';
    }
}

// Function to add 1 to a binary string
void addOne(char binary[]) {
    int i;
    int len = strlen(binary);
    int carry = 1;

    for (i = len - 1; i >= 0; i--) {
        if (binary[i] == '0' && carry == 1) {
            binary[i] = '1';
            carry = 0;
        } else if (binary[i] == '1' && carry == 1) {
            binary[i] = '0';
        }
    }
}

// Function to perform binary subtraction using 2's complement
void binarySubtraction(char minuend[], char subtrahend[], char result[]) {
    int i;
    int borrow = 0;
    int len = strlen(minuend);

    for (i = len - 1; i >= 0; i--) {
        if (minuend[i] == '1' && subtrahend[i] == '0') {
            if (borrow == 1) {
                result[i] = '0';
            } else {
                result[i] = '1';
            }
        } else if (minuend[i] == '0' && subtrahend[i] == '1') {
            if (borrow == 1) {
                result[i] = '1';
                borrow = 1;
            } else {
                result[i] = '0';
                borrow = 1;
            }
        } else if (minuend[i] == '1' && subtrahend[i] == '1') {
            if (borrow == 1) {
                result[i] = '1';
            } else {
                result[i] = '0';
                borrow = 1;
            }
        } else if (minuend[i] == '0' && subtrahend[i] == '0') {
            if (borrow == 1) {
                result[i] = '1';
                borrow = 0;
            } else {
                result[i] = '0';
            }
        }
    }
}

int main() {
    char minuend[33], subtrahend[33], result[33];

    printf("Enter minuend (binary): ");
    scanf("%s", minuend);
    printf("Enter subtrahend (binary): ");
    scanf("%s", subtrahend);

    // Ensure both binary strings are of equal length by padding zeros if necessary
    int len_minuend = strlen(minuend);
    int len_subtrahend = strlen(subtrahend);
    int max_len = (len_minuend > len_subtrahend) ? len_minuend : len_subtrahend;

    if (len_minuend < max_len)
        strcpy(minuend + (max_len - len_minuend), minuend);
    if (len_subtrahend < max_len)
        strcpy(subtrahend + (max_len - len_subtrahend), subtrahend);

    // Perform 2's complement on subtrahend
    bitwiseNOT(subtrahend);
    addOne(subtrahend);

    // Perform binary subtraction
    binarySubtraction(minuend, subtrahend, result);

    printf("Result of subtraction (binary): %s\n", result);

    return 0;
}