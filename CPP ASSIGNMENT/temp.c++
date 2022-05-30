#include<iostream>
using namespace std;
class box{
    private:
    int l,b,h,vol;
    public:
    void input(){
        cin>>l>>b>>h;
    }
    int volume(){
        vol=l*b*h;
        return vol;
    }
    void display(){
        cout<<"\n"<<vol;
    }
};

int main(int argc, char const *argv[])
{
    class box b1;
    cout<<"enter length, breadth and height of the box: ";
    b1.input();
    b1.volume();
    b1.display();
    return 0;
}
