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
    void build();
    void printTheTree();
}tree;


#endif
