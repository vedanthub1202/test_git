#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    fstream my_file;
    my_file.open("my file.txt\n", ios::out);
    if(!my_file)
    {
        cout<<"file not created\n";
    }
    else
    {
        cout<<"file created successfully!\n";
        my_file<<"WCE 2021\n";
        my_file.close();
    }
    return 0;
}
