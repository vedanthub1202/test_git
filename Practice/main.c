#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n,a[10],i,j,r=0;
    printf("enter a no: \n");
    scanf("%d",&n);
    while (n)
    {
        r=n%2;
        n=n/2;
        a[i]=r;
        i++;
    }
    for (int j = i-1; j >=0; j--)
    {
        printf("%d",a[j]);
    }
    return 0;
}
