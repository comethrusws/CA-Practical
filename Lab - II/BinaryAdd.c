#include <stdio.h>

// Function to add two 4-bit binary numbers
void addBinary4Bit(char binary1[], char binary2[], char result[]) {
    int carry = 0;

    for (int i = 3; i >= 0; i--) {
        int bit1 = binary1[i] - '0';
        int bit2 = binary2[i] - '0';

        int sum = bit1 ^ bit2 ^ carry;

        result[i] = sum + '0';

        carry = (bit1 & bit2) | (bit2 & carry) | (carry & bit1);
    }

    // If there is a carry after the addition, set the most significant bit
    if (carry)
        result[0] = '1';
}

int main() {
    char binary1[5], binary2[5], result[5];

    // Input two 4-bit binary numbers
    printf("Enter the first 4-bit binary number: ");
    scanf("%s", binary1);

    printf("Enter the second 4-bit binary number: ");
    scanf("%s", binary2);

    // Perform binary addition
    addBinary4Bit(binary1, binary2, result);

    // Display the result
    printf("The sum of %s and %s is: %s\n", binary1, binary2, result);

    return 0;
}
