#include <iostream>
using namespace std;

class student
{
    public:
    int roll;
    string name;
    void get_data()
    {
        cin>>roll;
        cin>>name;
    }
    void display()
    {
        cout<<"Roll no: "<<roll<<'\n';
        cout<<"Student name: "<<name<<"\n";
    }
};

class result: public student
{
    public:
    int m1,m2,m3,m4,m5;
    void get_marks()
    {
        cin>>m1>>m2>>m3>>m4>>m5;
    }
    int display_avg()
    {
        return (m1+m2+m3+m4+m5)/5;
    }
};

int main(int argc, char const *argv[])
{
    int avg;
    class student s1;
    class result r1;
    cout<<"enter Roll no. and name respectively\n";
    s1.get_data();
    cout<<"enter marks of student out of 100\n";
    r1.get_marks();
    s1.display();
    avg = r1.display_avg();
    avg>50? cout<<"PASS\n" :cout<<"FAIL\n";
    return 0;
}
