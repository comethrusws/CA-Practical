#include <stdio.h>
#include <string.h>

void onesComplement(char binary[], int n) {
    for (int i = 0; i < n; i++) {
        binary[i] = (binary[i] == '0') ? '1' : '0';
    }
}

char* binarySubtraction(char binary1[], char binary2[], int n) {
    static char difference[100];
    int carry = 0;

    // subtrahend ko complement
    onesComplement(binary2, n);

    for (int i = n - 1; i >= 0; i--) {
        if (binary2[i] == '0') {
            binary2[i] = '1';
            break;
        } else {
            binary2[i] = '0';
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        int sum = (binary1[i] - '0') + (binary2[i] - '0') + carry;
        difference[i] = sum % 2 + '0';
        carry = sum / 2;
    }

    return difference;
}

int main() {
    char binary1[100], binary2[100];
    printf("Enter the first binary number: ");
    scanf("%s", binary1);
    printf("Enter the second binary number: ");
    scanf("%s", binary2);

    int n = strlen(binary1);

    // dubai num ko same length
    while (strlen(binary2) < n) {
        strcat(binary2, "0");
    }

    char* difference = binarySubtraction(binary1, binary2, n);
    printf("subtraction result is: %s\n", difference);

    return 0;
}
