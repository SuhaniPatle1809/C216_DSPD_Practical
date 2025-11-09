#include<stdio.h>

struct Student{
    int roll;
    char name[50];
    int age;
    float avgMark;
};

int main(){
    int n, i, j;
    struct Student s[100], temp;
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    // Input student details
    for(i = 0; i < n; i++)
    {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Age: ");
        scanf("%d", &s[i].age);
        printf("Average Marks: ");
        scanf("%f", &s[i].avgMark);
    }
    
    // Bubble sort by average marks in descending order
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(s[j].avgMark < s[j + 1].avgMark)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\nSorted students (by descending average marks):\n");
    printf("Roll\tName\tAge\tAverage Marks\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%s\t%d\t%.2f\n", s[i].roll, s[i].name, s[i].age, s[i].avgMark);
    }
    return 0;
}