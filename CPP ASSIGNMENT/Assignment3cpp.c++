/*PRN: 2020BTEIT00045*/

#include<iostream>
using namespace std;
class Time
{
    private:
    int hr,min,sec;
    public:
        void get_time()
        {
            cout<<"Enter time(hours:mins:seconds) : ";
            cin>>hr>>min>>sec;
        }

        void display_time()
        {
            cout<<"\n"<<hr<<":"<<min<<":"<<sec;
        }

        Time operator +(Time t2)
        {
            Time t3;
            t3.sec=sec+t2.sec;
            t3.min=min+t2.min+(t3.sec/60);
            t3.sec=t3.sec%60;
            t3.hr=hr+t2.hr+(t3.min/60);
            t3.min=t3.min%60;
            return t3;
        }

        Time operator -(Time t2)
        {
            Time t4;
            t4.sec=sec-t2.sec;
            t4.min=min-t2.min-(t4.sec/60);
            t4.sec=t4.sec%60;
            t4.hr=hr-t2.hr-(t4.min/60);
            t4.min=t4.min%60;
            return t4;
        }
};
int main()
{
    Time t1,t2,t3,t4;
    t1.get_time();
    t2.get_time();
    t1.display_time();
    t2.display_time();
    t3=t1+t2;
    t4=t1-t2;
    t3.display_time();
    t4.display_time();
    return 0;
}