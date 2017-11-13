#include<vector>
#include<string>
#include<iostream>
#include<ctime>
#include"produceName.h"
#include"tree.h"
#include<random>
using namespace std;

using pNode=binaryTreeNode*;
extern int volumeForGeneration;
extern int volumeForBrother;
extern std::default_random_engine generator;
extern string familyName;
void traverse(pNode node,int depth,int restGeneration,int restBrother,string familyName)
{
    //std::poisson_distribution<int> distribution(15);    
    CName name;
    
    //cout<<node->partner_name<<" ";
    
    if(rand()%2)
    {
        string nameForPerson(name.GetName(),3,6);
        node->person_name=familyName+nameForPerson;//need to consider about female and male focus on the first name
        cout<<node->person_name<<" ";
        node->person_sex="male";
        node->partner_name=name.GetName();
        if(rand()%10)
        node->partner_sex="female";
        else
        node->partner_sex="male";
    }
    else
    {
        string nameForPerson(name.GetName(),3,6);
        node->person_name=familyName+nameForPerson;//need to consider about female and male focus on the first name
        cout<<node->person_name<<" ";
        node->person_sex="female";
        node->partner_name=name.GetName();
        string firstName(node->partner_name,0,3);
        familyName=firstName;
        if(rand()%10)
        node->partner_sex="male";
        else
        node->partner_sex="female";
    }
    if(restGeneration>0)
    {
        //cout<<"l ";
        node->first_child=new binaryTreeNode;
        node->first_child->front_parent=node;
        node->first_child->front_sibling=nullptr;
        std::poisson_distribution<int> distribution1(volumeForBrother);
        traverse(node->first_child,depth+1,restGeneration-1,distribution1(generator),familyName); 
    }
    if(restBrother>0)
    {
        //cout<<"r ";
        node->next_sibling=new binaryTreeNode;
        node->next_sibling->front_parent=node->front_parent;
        node->next_sibling->front_sibling=node;
        std::poisson_distribution<int> distribution1(volumeForGeneration-depth);
       // cout<<distribution1(generator)<<" ";
        traverse(node->next_sibling,depth+1,distribution1(generator),restBrother-1,familyName);
    }

}

void binaryTree::creat_binary_tree(binaryTreeNode *&root)
{
    root=new binaryTreeNode;
    int restGeneration,restBrother;
   // cout<<volumeForGeneration<<endl;
    std::poisson_distribution<int> distribution1(volumeForGeneration-1);
    for(;rand()%100;)distribution1(generator);
    restGeneration=distribution1(generator);
   // cout<<restGeneration<<endl;
    std::poisson_distribution<int> distribution2(volumeForBrother-1);
    for(;rand()%100;)distribution2(generator);
    restBrother=distribution2(generator);
    traverse(root,1,restGeneration,restBrother,familyName);
    cout<<endl;
}