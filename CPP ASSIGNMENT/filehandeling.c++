/*Write a function in C++ to count and display the number of lines not starting with alphabet 'A' present in a text file "STORY.TXT".*/

#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin;
    fin.open("STORY.txt");
   
    char str[100];
    int count=0;
    int count1=0;
   
    while(!fin.eof())
    {
        fin.getline(str,100);
        if(str[0]!='A')
        {
            count++;
        }
    }
   
    cout<<"The count is: "<<count<<"\n";
   
    fin.close();
    return 0;
}