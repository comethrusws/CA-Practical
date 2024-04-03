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
        printf("Number of bits to shift: ");
        scanf("%d", &num);
        
        switch (choice) {
            case 'R': {
                printf("Logical shift right: ");
                for (int i = size - 1; i >= num; i--) {
                    arr[i] = arr[i - num];
                }
                for (int i = 0; i < num; i++) {
                    arr[i] = 0;
                }
                show(size, arr);
                break;
            }
            case 'L': {
                printf("Logical shift left: ");
                for (int i = 0; i < size - num; i++) {
                    arr[i] = arr[i + num];
                }
                for (int i = size - num; i < size; i++) {
                    arr[i] = 0;
                }
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
