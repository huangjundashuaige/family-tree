#ifndef TREE_HEADFILE
#define TREE_HEADFILE

#include <string>
#include <vector>
using namespace std;

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
	binaryTree();
	void creat_binary_tree(binaryTreeNode *&root);
	void show_binary_tree(binaryTreeNode *&root,int i);
	void search_all_information1(string num,binaryTreeNode *&root);
	void search_all_information2(string name,binaryTreeNode *&root);
	void search_all_height1(string num,binaryTreeNode *&root);
	void search_all_height2(string name,binaryTreeNode *&root);
	void add_child(string num,binaryTreeNode *&root);  
	int is_rename(string name,binaryTreeNode *&root,int i); // check whether there are new member renamed
}tree;


#endif
