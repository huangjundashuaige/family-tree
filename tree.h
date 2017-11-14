#ifndef TREE_HEADFILE
#define TREE_HEADFILE

#include<string>
#include "name.h"
#include "produceName.h"
#include <iostream>
#include<random>
using namespace std;
extern int volumeForGeneration;
extern int volumeForBrother;
extern std::default_random_engine generator;
extern string familyName;

struct binaryTreeNode
{
public:
	string person_num;
	string person_name;
	string person_sex;
	string partner_name;
	string partner_sex;
	binaryTreeNode *first_child,*next_sibling,*front_parent,*front_sibling;
};

class binaryTree
{
public:
	binaryTreeNode *root;
public:
	binaryTree();
	void creat_binary_tree(binaryTreeNode *&root);
	void show_binary_tree(binaryTreeNode *&root,int i);
	void search_all_information1(string num,binaryTreeNode *&root);
	void search_all_information2(string name,binaryTreeNode *&root);
	void add_child(string name,binaryTreeNode *&root);
	int is_rename(string name,binaryTreeNode *&root,int i);
	bool is_name(string name, binaryTreeNode *&root);
	bool is_num(string name, binaryTreeNode *&root);
	void creat_binary_tree_auto(binaryTreeNode *&root);

};



#endif
