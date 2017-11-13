#include"produceName.h"
#include"tree.h"
#include<iostream>
#include<ctime>
#include<random>

using namespace std;

std::default_random_engine generator;
int volumeForGeneration,volumeForBrother;
string familyName;
int main()
{
    //for(int i=0;i<10;i++)cout<<rand()%10<<endl;
    srand( ( unsigned )time( NULL ) );
    cout<<"what's the number of generation you expect for"<<endl;
    cin>>volumeForGeneration;
    cout<<"what's the number of brothers you expect for"<<endl;
    cin>>volumeForBrother;
    cout<<"key in the family name"<<endl;
    cin>>familyName;
    binaryTree tree;
    tree.creat_binary_tree(tree.root);
    return 0;
}