#include <stdio.h>
int main(int argc, char const *argv[])
{
  int n,a[100],j,i;
  a[j]=0;
  printf("enter a no. \n");
  scanf("%d",&n);
  for(int i=2;i<n;i++)
  {
    if(n%i!=0)
    {
      a[j]=i;
      j++;
    }
  }
  for(int j=0;j<'\0';j++)
  printf("%d ",a[j]);
  return 0;
}
