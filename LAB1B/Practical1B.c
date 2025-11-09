#include<stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int start = 0, end = n - 1;
    while(start <= end)
    {
        int mid = (start + end) / 2;
        printf("Checking index %d with value %d\n", mid, arr[mid]);
        if(arr[mid] == key)
        {
            printf("Value found at index %d \n", mid);
            return mid;
        }
        else if(arr[mid] < key)
        {
            printf("Moving right from index %d \n", mid);
            start = mid + 1;
        }
        else
        {
            printf("Moving left from index %d\n", mid);
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value to search: ");
    scanf("%d", &key);
    
    int result = binarySearch(arr, n, key);
    if(result == -1)
    {
        printf("Value not found.\n");
    }
    else
    {
        printf("Value %d found at position %d.\n", key, result);
    }
    return 0;
}