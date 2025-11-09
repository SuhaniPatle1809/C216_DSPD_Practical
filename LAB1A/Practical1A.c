#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    int sumOdd = 0;
    int sumEven = 0;
    printf("Enter %d elements: \n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++)
    {
        if((i + 1) % 2 == 0)
        {
            sumEven += arr[i];
        }
        else
        {
            sumOdd += arr[i];
        }
    }
    printf("Sum of numbers at odd positions = %d\n", sumOdd);
    printf("Sum of numbers at even positions = %d\n", sumEven);
    return 0;
}