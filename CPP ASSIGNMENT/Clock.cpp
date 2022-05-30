#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<windows.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int hh=0,mm=0,ss=0;
    while(true)
    {
        system("cls");
        cout<<hh<<" : "<<mm<<" : "<<ss<<endl;
        ss++;
        if(ss==60)
        {
            mm++;
            ss=0;
            if(mm==60)
            {
                hh++;
                mm=0;
                if(hh==60)
                {
                    hh=0;
                }
            }
        }
        Sleep(1000);
    }
    return 0;
}
