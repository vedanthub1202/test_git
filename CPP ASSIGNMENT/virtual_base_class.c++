#include<iostream>
using namespace std;

class student{
    protected:
    int roll_no;
    public: 
        void set_number(int a)
        {
            roll_no =a;
        }
        void print(void)
        {
            cout<<"your Roll no. is "<<roll_no<<endl;
        }
};

class Test : virtual public student{
    protected: 
    float maths, physics;
    public:
    void set_marks(float m1, float m2)
    {
        maths = m1;
        physics = m2;
    }
    void print_marks()
    {
        cout<<"your Result is :\n";
        cout<<"Maths: "<<maths<<endl;
        cout<<"Physics: "<<physics<<endl;
    }
};

class Sports : virtual student
{
    protected:
    float score;
    public:
    void set_score(float sc)
    {
        score =sc;
    } 
    void print_score()
    {
        cout<<"Your sports score is: "<<score<<endl;
    }
};

class Result : public Sports, public Test
{
    private:
    float total;
    public:
    void show()
    {
        total = maths+ physics+ score;
        print();
        print_marks();
        print_score();
        cout<<"Your total score is: "<<total<<endl;
    }
};

int main(int argc, char const *argv[])
{
    Result ved;
    ved.set_number(19);
    ved.set_marks(80, 78);
    ved.set_score(88);
    ved.show();
    return 0;
}
