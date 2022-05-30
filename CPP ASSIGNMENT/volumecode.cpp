#include<iostream>
using namespace std;

class volume
{
    private:
    int side,l,b,h,vol,r;
    public:
    volume(int side)
    {
        cout<<"Volume of square:"<<side*side*side<<"\n";
    }
    volume(int r,int h)
    {
        cout<<"Volume of cylinder:"<<(3.14*r*r*h)<<"\n";
    }
    volume(int l, int b, int h)
    {
        cout<<"Volume of box:"<<l*h*b<<"\n";
    }
};

int main(int argc, char const *argv[])
{
    class volume v1(3),v2(3,4),v3(8,2,7);
    
    return 0;
}
