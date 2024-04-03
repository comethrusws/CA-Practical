#include <stdio.h>
#include <stdlib.h>
void getdata(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] != 1 && arr[i] != 0)
        {
            printf("Invalid input");
            exit(1);
        }
    }
}
int main()
{
    int size, sign = 0, i = 0;
    printf("Enter the size and sign (1->'-',0->'+')of binary number: ");
    scanf("%d %d", &size, &sign);
    int arr[size];
    printf("Enter %d binary bit: ", size);
    getdata(arr, size);
    printf("The num is:%d", sign);
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
    char choice = '\0';
    while (choice != 'X')
    {
        printf("\nEnter 'R'to shift right,'L'to shift left and 'X' to close: ");
        scanf(" %c", &choice);
        switch (choice) 
        {
        case 'R':
        {
            printf("arithmetic shift right: ");
            for (int i = size; i > 0; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[0] = 0;
            printf("%d", sign);
            for (int i = 0; i < size; i++)
            {
                printf("%d", arr[i]);
            }
            break;
        }
        case 'L':
        {
            printf("arithmetic shift left: ");
            for (int i = 0; i < size; i++)
            {
                arr[i] = arr[i + 1];
            }
            arr[size] = 0;
            printf("%d", sign);
            for (int i = 0; i < size; i++)
            {
                printf("%d", arr[i]);
            }
            break;
        }
        case 'X':
        {
            exit(0);
        }
        }
    }
    return 0;
}