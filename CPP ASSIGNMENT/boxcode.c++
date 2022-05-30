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

    box operator +(box b2)
    {
        box b3;
        b3.vol= vol + b2.vol;
        return b3;
    }

    box operator -(box b2)
    {
        box b4;
        b4.vol= vol - b2.vol;
        return b4;
    }
};

int main(int argc, char const *argv[])
{
    class box b1,b2,b3,b4;
    cout<<"Enter length, breadth and height of the first box: ";
    b1.input();
    b1.volume();
    cout<<"volume of box 1: "; b1.display();

    cout<<"\n\nEnter length, breadth and height of the second box: ";
    b2.input();
    b2.volume();
    cout<<"volume of box 2: "; b2.display();
    

    b3 = b1 + b2;
    cout<<"\n\n\nAddition of volumes of box 1 and box 2: "; b3.display();
    
    b4 = b1 - b2;
    cout<<"\nSubstraction of volumes of box 1 and box 2: "; b4.display();
    
    return 0;
}
