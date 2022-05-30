/*Problem Statement – : Ramu has N dishes of different types arranged in a row: A1,A2,…,AN where Ai denotes the type of the ith dish. He wants to choose as many dishes as possible from the given list but while satisfying two conditions:
He can choose only one type of dish.
No two chosen dishes should be adjacent to each other.
Ramu wants to know which type of dish he should choose from, so that he can pick the maximum number of dishes.
Example :
Given N= 9 and A= [1,2,2,1,2,1,1,1,1]
For type 1, Ramu can choose at most four dishes. One of the ways to choose four dishes of type 1 is A1,A4, A7 and A9.
For type 2, Ramu can choose at most two dishes. One way is to choose A3 and A5.
So in this case, Ramu should go for type 1, in which he can pick more dishes. INPUT FORMAT:
The first line contains T, the number of test cases. Then the test cases follow.
For each test case, the first line contains a single integer
The second line contains N integers A1,A2,…,AN.
OUTPUT FORMAT  :
For each test case, print a single line containing one integer ― the type of the dish that Ramu should choose from. If there are multiple answers, print the smallest one.
CONSTRAINTS :
1 <= T <= 10^3
1 <= N <= 10^3
1 <= Ai <= 10^3
Sample Input : 
3 5 1 2 2 1 2 6 1 1 1 1 1 1 8 1 2 2 2 3 4 2 1
Sample Output :
            1 1 2
EXPLANATION :
Test case 1:
For both type 1 and type 2, Ramu can pick at most two dishes. In the case of multiple answers, we pick the smallest one. Hence the answer will be 1
Test case 2:
There are only dishes of type 1. So the answer is 1.
Test case 3:
For type 1, Ramu can choose at most two dishes. For type 2, he can choose three dishes. For type 3 and type 4, Ramu can choose the only dish available. Hence the maximum is in type 2 and so the answer is 2*/


#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n],b[n];

        for(int i=0;i<n;i++)
        {
            b[i]=0;
        }

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)

            {
                if(a[i]==a[j] && j!=i+1)
                b[i]++;
            }
        }

        int max=0,x;

        for(int i=0;i<n;i++)
        {
            if(b[i]>max)
            {max=b[i];
            x=a[i];}
        }

        cout<<x<<endl;
    }
    return 0;
}































// #include <iostream>
// using namespace std;
// int main() 
// {
//        int t,n,i,max,x;
//        cin>>t;
//        while(t--)
//         {
//              cin>>n;
//              int arr[n];
//              max=0;
//             for(i=0;i<n;i++)
//              {
//                       cin>>arr[i];
//              }
//              int b[1001]={0};
//              for(i=0;i<n;i++)
//               {
//                      b[arr[i]]++;
//                      if(arr[i]==arr[i+1])
//                               i++;
//         }
//         for(i=1;i<=1000;i++)
//           {
//                  if(b[i]>max)
//                  {
//                       max=b[i];
//                       x=i;
//                   }
//         }
//         cout<<x<<endl;
//     }
// 	return 0;
// }