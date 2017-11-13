#ifndef TREE_HEADFILE
#define TREE_HEADFILE

#include <string>
#include <vector>
using namespace std;

struct TreeNode
{
public:
	string person_num;
	string person_name;
	string person_sex;
	string partner_name;
	string partner_sex;
	binaryTreeNode *first_child,*next_sibling,*front_parent,*front_sibling;
};

class TreeMethod
{
public:
    TreeNode *root;
	TreeMethod();
	void creat_binary_tree(TreeNode *&root);
	void show_binary_tree(TreeNode *&root,int i);
	void search_all_information1(string num,TreeNode *&root);
	void search_all_information2(string name,TreeNode *&root);
	void search_all_height1(string num,TreeNode *&root);
	void search_all_height2(string name,TreeNode *&root);
	void add_child(string num,TreeNode *&root);
	int is_rename(string name,TreeNode *&root,int i);
}tree;


#endif
