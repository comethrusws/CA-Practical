#include <stdio.h>
#include <stdlib.h>

void getdata(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] != 1 && arr[i] != 0) {
            printf("Invalid input");
            exit(1);
        }
    }
}

void show(int size, int arr[]) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
    }
}

int main() {
    int size, num;
    printf("Enter the size of binary number: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d binary bits: ", size);
    getdata(arr, size);
    show(size, arr);

    char choice = '\0';
    while (choice != 'X') {
        printf("\nEnter 'R' to shift right, 'L' to shift left, and 'X' to close: ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'R': {
                printf("Circular shift right: ");
                int temp = arr[size - 1];
                for (int i = size - 1; i > 0; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[0] = temp;
                show(size, arr);
                break;
            }
            case 'L': {
                printf("Circular shift left: ");
                int temp = arr[0];
                for (int i = 0; i < size - 1; i++) { // Corrected loop condition
                    arr[i] = arr[i + 1];
                }
                arr[size - 1] = temp;
                show(size, arr);
                break;
            }
            case 'X': {
                exit(0);
            }
        }
    }

    return 0;
}