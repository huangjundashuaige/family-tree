#include"tree.h"
#include<vector>
#include<string>
#include<iostream>
#include<ctime>
#include"produceName.h"
#include"tree.h"
#include<random>
using namespace std;

using pNode=TreeNode*;
static int volume;
static std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1,20000);
int count1=10;
int count2=10;
void traverse(pNode node)
{
    
    CName name;
    node->name=name.GetName();
    //cout<<node->name<<endl;
    int prob=distribution(generator)%13;
    cout<<prob<<" ";
    if(count1>=prob)
    {
        node->lChild=new TreeNode;
        count1--;
        traverse(node->lChild); 
        //cout<<"l ";
    }
    
    prob=distribution(generator)%13;
    cout<<prob<<" ";
    //cout<<rand()<<" ";
    if(count2>=prob)
    {
        node->rChild=new TreeNode;
        count2--;
        traverse(node->rChild);
        //cout<<"r ";
    }

}

void TreeMethod::build()
{
    
    root=new TreeNode;
    traverse(root);
    cout<<endl;
}