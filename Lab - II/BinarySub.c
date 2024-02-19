#include <stdio.h>

// Function to perform binary subtraction
void binarySubtraction(char binaryNum1[], char binaryNum2[], char result[]) {
    int borrow = 0;

    for (int i = 3; i >= 0; i--) {
        int bit1 = binaryNum1[i] - '0';
        int bit2 = binaryNum2[i] - '0';

        // Perform subtraction
        int diff = bit1 - bit2 - borrow;

        // If the difference is negative, borrow 1 from the next bit
        if (diff < 0) {
            diff += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }

        // Store the result bit in the result array
        result[i] = diff + '0';
    }
}

int main() {
    char binaryNum1[5], binaryNum2[5], result[5];

    // Input two 4-bit binary numbers
    printf("Enter the first 4-bit binary number: ");
    scanf("%s", binaryNum1);

    printf("Enter the second 4-bit binary number: ");
    scanf("%s", binaryNum2);

    // Perform binary subtraction
    binarySubtraction(binaryNum1, binaryNum2, result);

    // Display the result
    printf("Result of subtraction: %s\n", result);

    return 0;
}
