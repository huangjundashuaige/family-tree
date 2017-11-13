#include<iostream>
#include<ctime>
using namespace std;
int main()
{
    srand(static_cast<unsigned>(time(0)));
    for(int i=0;i<10;i++)
    cout<<rand()%10<<endl;
}