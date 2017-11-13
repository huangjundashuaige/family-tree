#include"tree.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

binaryTree::binaryTree()
{
    root = NULL;
}

void binaryTree::creat_binary_tree(binaryTreeNode *&root)//创建二叉树,有四个指针，有两个指针是用于线索（front_sbliding,frong_parent）
{
	root=NULL;
	binaryTreeNode *t = NULL,*p = NULL;//t指针为new出来的，p为跟随指针
	t=new binaryTreeNode;
	if(root==NULL)
	{
		cout<<"请输入祖先编号：";
		cin>>t->person_num;
		cout<<"请输入祖先姓名：";
		cin>>t->person_name;
		cout<<"请输入祖先性别：(male or female)";
		cin>>t->person_sex;
		cout<<"输入其配偶姓名：";
		cin>>t->partner_name;
		if(t->person_sex=="male")
		    t->partner_sex="female";
		else
			t->partner_sex="male";
		root=t;
		root->next_sibling=NULL;
		root->first_child=NULL;
		root->front_parent=NULL;
		root->front_sibling=NULL;
		p=t;
	}
	cout<<"是否编辑下一代(Y/N)：";
	char is_continue;
	cin>>is_continue;
	if(is_continue=='Y'||is_continue=='y')
	{
		t=new binaryTreeNode;
		cout<<"输入"<<p->person_name<<"子女编号:";
		cin>>t->person_num;
		cout<<"输入"<<p->person_name<<"子女姓名:";
		cin>>t->person_name;
		if(is_rename(t->person_name,root,0)==1)
		{
			cout<<"有重复，请重新输入"<<p->person_name<<"子女姓名:";
			cin>>t->person_name;
		}
		cout<<"输入"<<p->person_name<<"子女性别:";
		cin>>t->person_sex;
		cout<<"输入"<<t->person_name<<"配偶姓名:";
		cin>>t->partner_name;
		if(t->partner_sex=="male")
			t->partner_sex="female";
		else
			t->partner_sex="male";
		p->first_child=t;
		t->front_parent=p;
		t->front_sibling=NULL;
		p=t;
		p->first_child=NULL;
		p->next_sibling=NULL;
	}
	else return;
	char choose;
	while(1)
	{
		cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※"<<endl;
		cout<<"创建"<<p->person_name<<"的子女请按1"<<endl;
		cout<<"创建"<<p->person_name<<"的兄弟请按2"<<endl;
		cout<<"不再创建请按3"<<endl;
		cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※"<<endl;
		cin>>choose;
		switch(choose)
		{
		case '1':
			{
				t=new binaryTreeNode;
				cout<<"输入"<<p->person_name<<"子女编号:";
				cin>>t->person_num;
				cout<<"输入"<<p->person_name<<"子女姓名:";
				cin>>t->person_name;
				if(is_rename(t->person_name,root,0)==1)
				{
					cout<<"有重复，请重新输入"<<p->person_name<<"子女姓名:";
					cin>>t->person_name;
				}
				cout<<"输入"<<p->person_name<<"子女性别:";
				cin>>t->person_sex;
				cout<<"输入"<<t->person_name<<"配偶姓名:";
				cin>>t->partner_name;
				if(t->partner_sex=="male")
					t->partner_sex="female";
				else
					t->partner_sex="male";
				p->first_child=t;
				t->front_parent=p;
				t->front_sibling=NULL;
				p=t;
				p->first_child=NULL;
				p->next_sibling=NULL;
				break;
			}
		case '2':
			{
				t=new binaryTreeNode;
				cout<<"输入"<<p->person_name<<"兄弟编号:";
				cin>>t->person_num;
				cout<<"输入"<<p->person_name<<"兄弟姓名:";
				cin>>t->person_name;
				if(is_rename(t->person_name,root,0)==1)
				{
					cout<<"有重复，请重新输入"<<p->person_name<<"子女姓名:";
				    cin>>t->person_name;
				}
				cout<<"输入"<<p->person_name<<"兄弟性别:";
				cin>>t->person_sex;
				cout<<"输入"<<t->person_name<<"配偶姓名:";
				cin>>t->partner_name;
				if(t->partner_sex=="male")
					t->partner_sex="female";
				else
					t->partner_sex="male";
				p->next_sibling=t;
				t->front_sibling=p;
				p=t;
				p->next_sibling=NULL;
				p->first_child=NULL;
				break;
			}
		case '3':
			{
				cout<<"家谱树创建完毕……"<<endl;
				return;
			}
		}
	}
}
