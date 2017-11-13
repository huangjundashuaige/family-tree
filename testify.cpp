#include"produceName.h"
#include"tree.h"
#include<iostream>
#include<ctime>
#include<random>

using namespace std;

std::default_random_engine generator;
int volume;
int main()
{
    cout<<"what's the number of generation"
    srand(static_cast<unsigned>(time(NULL)));
    TreeMethod tree;
    tree.build();
    return 0;
}