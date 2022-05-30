/*Problem Statement -: Atulya is the judge of a competition. There are two players participating in this competition — Alice and Bob.
The competition consists of N races. For each i (1 ≤ i ≤ N), Alice finished the i-th race in Ai minutes, while Bob finished it in Bi minutes. The player with the smallest sum of finish times wins. If this total time is the same for Alice and for Bob, a draw is declared.
The rules of the competition allow each player to choose a race which will not be counted towards their total time. That is, Alice may choose an index x and her finish time in the race with this index will be considered zero; similarly, Bob may choose an index y and his finish time in the race with this index will be considered zero. Note that x can be different from y; the index chosen by Alice does not affect Bob’s total time or vice versa.

Atulya, as the judge, needs to announce the result of the competition. He knows that both Alice and Bob play optimally and will always choose the best option. Please help Atulya determine the result!

Sample Input :

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1, A2, …, AN.
The third line contains N space-separated integers B1, B2, …, BN.
Sample Output:

For each test case, print a single line containing the string “Alice” if Alice wins, “Bob” if Bob wins or “Draw” if the result is a draw (without quotes).
Constraints:

1 ≤ T ≤ 100
2 ≤ N ≤ 100
1 ≤ Ai ≤ 1000 for each valid i
1 ≤ Bi ≤ 1000 for each valid i
SAMPLE INPUT :

    3

    5

    3 1 3 3 4

    1 6 2 5 3

    5

    1 6 2 5 3

    3 1 3 3 4

    3

    4 1 3

    2 2 7

SAMPLE OUTPUT :

    Alice

    Bob

    Draw

EXPLANATION :

Example case 1: Alice will choose the finish time in the last race to be considered zero, which means her sum of finish times is 3 + 1 + 3 + 3 + 0 = 10, while Bob will choose the finish time of his second race to be considered zero, so his total sum of finish times is 1 + 0 + 2 + 5 + 3 = 11. Since Alice’s sum is smaller, she is considered the winner.
 Example case 2: We’re dealing with the same situation as in the previous case, but finish times for the players are swapped, so Bob wins this time.
Example case 3: Alice will choose the finish time of the first race to be considered zero, which means her total time is 0 + 1 + 3 = 4. Bob will choose the finish time of his last race to be considered zero, which makes his total time 2 + 2 + 0 = 4. The competition is considered a draw because both players have equal sums of finish times.*/



#include <bits/stdc++.h>

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
            cin>>a[i];
        }

        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }

        sort(a, a + n, greater<int>());
        sort(b, b + n, greater<int>());

        int s1=0,s2=0;

        for(int i=1;i<n;i++)
        {
            s1=s1+a[i];
            s2=s2+b[i];
        }

        if(s1<s2)
        cout<<"Alice"<<endl;
        if(s2>s1)
        cout<<"Bob"<<endl;
        if(s1==s2)
        cout<<"draw"<<endl;

    }
    return 0;
}
