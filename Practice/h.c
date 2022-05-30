#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char s[1000]; 
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    int i,j,l,c;
	printf("input");
    for(i=0;s[i]!='\0';i++)
    scanf("%s",s);
      l=strlen(s);
      for(i=0;i<10;i++)
      {
          c=0;
          for(j=0;j<l;j++)
          {
              if(a[i]==s[j])
              c=c+1;
          }
          printf("%d ",c);
      }
    return 0;
}


