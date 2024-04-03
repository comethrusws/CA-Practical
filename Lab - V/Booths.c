#include <stdio.h>
#include <math.h>

#define maxsize 4

void dectobin(int arr[], int dec);
void arithmeticright(int arr1[], int arr2[], int q);
void putval(int arr[]);
void increment(int arr[]);
void putcal(int count, int A[], int Q[], int qo, int M[], int mcomp[], int num);
int greater(int num);
int  updateqo(int arr[])
{
    int q = arr[maxsize - 1];
    return q;
}

int main()
{
    int multiplicand, multiplier;

    printf("Enter the multiplier Q<16: ");
    scanf("%d", &multiplier);
    printf("Enter the multiplicand M<16: ");
    scanf("%d", &multiplicand);

    int num = (multiplicand > 0) ? 1 : 0;
    if (num == 0)
    {
        multiplicand *= -1;
    }
    int qo = 0;
    int count = maxsize;

    int M[maxsize] = {0};
    int A[maxsize] = {0};
    int Q[maxsize] = {0};

    dectobin(Q, multiplier);
    dectobin(M, multiplicand);

    int mcomp[maxsize];
    if (num == 0)
    {
        for (int i = maxsize - 1; i >= 0; i--)
        {
            mcomp[i] = M[i] == 1 ? 0 : 1;
        }
        increment(mcomp);
    }

    printf("C\tA\tQ\tq-\tM\n");

    for (int count = maxsize; count >= 0; count--)
    {
        putcal(count, A, Q, qo, M, mcomp, num);
        if (count == 0)
        {
            break;
        }
        if (qo == Q[maxsize - 1])
        {
            arithmeticright(A, Q, qo);
            printf("\tshift\n");
        }
        else if (qo == 1 && (Q[maxsize - 1] == 0))
        {
            int carry = 0;
            for (int i = maxsize - 1; i >= 0; i--)
            {
                int temp = A[i] + mcomp[i] + carry;
                A[i] = temp % 2;
                carry = temp / 2;
            }
            putcal(888, A, Q, qo, M, mcomp, num);
            printf("\tshift\n");
            arithmeticright(A, Q, qo);
        }
        else if (qo == 0 && Q[maxsize - 1] == 1)
        {
            int carry = 0;
            for (int i = maxsize - 1; i >= 0; i--)
            {
                int temp = A[i] + M[i] + carry;
                A[i] = temp % 2;
                carry = temp / 2;
            }
            putcal(999, A, Q, qo, M, mcomp, num);
            printf("\tshift\n");
            arithmeticright(A, Q, qo);
        }
    }
    printf("\nFinal result is:");
    while (num == 0)
    {
        printf("-");
        break;
    }
    putval(A);
    putval(Q);
    return 0;
}

void dectobin(int arr[], int dec)
{
    int i = maxsize - 1;
    while (dec != 0 && i >= 0)
    {
        arr[i] = dec % 2;
        dec = dec / 2;
        i--;
    }
    while (i > 0)
    {
        arr[i] = 0;
        i--;
    }
}

void increment(int arr[])
{
    int carry = 1;
    for (int i = maxsize - 1; i >= 0; i--)
    {
        int temp = arr[i] + carry;
        arr[i] = temp % 2;
        carry = temp / 2;
    }
}

void arithmeticright(int arr1[], int arr2[], int q)
{
    int temp = q;
    q = arr2[maxsize - 1];
    for (int i = maxsize - 1; i > 0; i--)
    {
        arr2[i] = arr2[i - 1];
    }
    arr2[0] = arr1[maxsize - 1];
    for (int i = maxsize - 1; i > 0; i--)
    {
        arr1[i] = arr1[i - 1];
    }
    arr1[0] = temp;
}

void putval(int arr[])
{
    for (int i = 0; i < maxsize; i++)
    {
        printf("%d", arr[i]);
    }
}

void putcal(int count, int A[], int Q[], int qo, int M[], int mcomp[], int num)
{
    if (count == 999)
    {
        printf("\nA-M\t");
        putval(A);
        printf("\t");
        putval(Q);
        printf("\t%d\t", qo);
        if (num == 1)
        {
            putval(M);
        }
        else if (num == 0)
        {
            putval(mcomp);
        }
        printf("\t");
    }
    else if (count == 888)
    {
        printf("\nA+M\t");
        putval(A);
        printf("\t");
        putval(Q);
        printf("\t%d\t", qo);
        if (num > 0)
        {
            putval(M);
        }
        else
        {
            putval(mcomp);
        }
        printf("\t");
    }
    else
    {
        printf("%d\t", count);
        putval(A);
        printf("\t");
        putval(Q);
        printf("\t%d\t", qo);
        if (num > 0)
        {
            putval(M);
        }
        else
        {
            putval(mcomp);
        }
        printf("\t");
    }
}

int greater(int num)
{
    int count = 0;
    while (num)
    {
        count++;
        num >>= 1;
    }
    return count;
}