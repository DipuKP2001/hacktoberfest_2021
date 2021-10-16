#include <stdio.h>
int mod(int a);
int fcfs(int n, int pos, int arr[]);
int scan(int n, int pos, int maxno, int arr[]);
int cscan(int n, int pos, int maxno, int arr[]);
int main(void)
{
    int ch, maxno, n, arr[100], pos, seekt;
    printf("Enter the maximum number of cylinders : ");
    scanf("%d", &maxno);
    printf("Enter number of queue elements : ");
    scanf("%d", &n);
    printf("Enter the work queue\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    while (1)
    {
        printf("1. FCFS\n2. SCAN\n3. C-SCAN\n4. EXIT\n");
        scanf("%d", &ch);
        printf("Enter the disk head starting position: ");
        scanf("%d", &pos);
        if (ch == 1)
            seekt = fcfs(n, pos, arr);
        else if (ch == 2)
            seekt = scan(n, pos, maxno, arr);
        else if (ch == 3)
            seekt = cscan(n, pos, maxno, arr);
        else if (ch == 4)
            break;
        printf("Total seek time : %d\n", seekt);
    }
}
int mod(int a)
{
    if (a >= 0)
        return a;
    else
        return (-1 * a);
}

int fcfs(int n, int pos, int arr[])
{
    int seekt = mod(arr[0] - pos);
    for (int i = 1; i < n; i++)
        seekt += mod(arr[i] - arr[i - 1]);
    return seekt;
}

int scan(int n, int pos, int maxno, int arr[])
{
    int max = -1, seekt = pos;
    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    seekt += max;
    return seekt;
}

int cscan(int n, int pos, int maxno, int arr[])
{
    int max = -1, seekt = 2 * (maxno - 1) - pos;
    for (int i = 0; i < n; i++)
        if (arr[i] > max && arr[i] < pos)
            max = arr[i];
    seekt += max;
    return seekt;
}