#ifndef TREE_HEADFILE
#define TREE_HEADFILE

#include <string>
#include <vector>
using namespace std;

struct binaryTreeNode
{
public:
	string person_num;  //本人编号
	string person_name;  //本人姓名
	string person_sex;  //本人的性别
	string partner_name;  //伴侣的名字
	string partner_sex;  //伴侣的性别
	binaryTreeNode *first_child,*next_sibling,*front_parent,*front_sibling;  
	//first_child和next_sibling分别是左节点和右节点，后面的front_parent和front_sibling是储存父母和哥哥姐姐信息的，只是两条线索而已
};

class binaryTree
{
public:
   	binaryTreeNode *root;
	binaryTree();
	void creat_binary_tree(binaryTreeNode *&root);  //创建新的家谱，要输入祖先的信息，并且可以按顺序增加后代
	void show_binary_tree(binaryTreeNode *&root,int i);  //打印树，并且将家谱存入文件中，family.txt
	void search_all_information1(string num,binaryTreeNode *&root); //按照编号搜索孩子，每个人都有一个编号
	void search_all_information2(string name,binaryTreeNode *&root);  //按照名字搜素孩子
	void add_child(string num,binaryTreeNode *&root);  //增加孩子，输入要增加孩子那个人的序号
	int is_rename(string name,binaryTreeNode *&root,int i); // 检查是否重名，返回1则重名
};


#endif
