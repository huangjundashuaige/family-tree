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
	cout<<"是否编辑下一代(Y/N)：";  //在祖先的基础上增加子孙
	char is_continue;
	cin >> is_continue;
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
		cout<<"创建"<<p->person_name<<"的子女请按1"<<endl;                //继续增加祖先的子女
		cout<<"创建"<<p->person_name<<"的兄弟请按2"<<endl;		   //增加祖先的兄弟姐妹
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

void binaryTree::show_binary_tree(binaryTreeNode *&root,int i) //显示二叉树，并将家谱写入文件中
{
	fstream file("family.txt",ios::app);
	if(!file)
	{
		cerr<<"文件没打开！"<<endl;
	}
	if(root)
	{
		int j;
		for( j=i; j>0; j--)
		{
			cout<<"   ";
			file<<"   ";
		}
        cout<<root->person_name<<endl;
		file<<root->person_name<<endl;
		show_binary_tree( root->first_child, i+1 );
		show_binary_tree( root->next_sibling, i );
	}
}

void binaryTree::search_all_information1(string num,binaryTreeNode *&root)//使用编号搜索，并显示详细信息
{
	if(root)
	{
		if(root->person_num==num)
		{
			binaryTreeNode *cur;
			cur=root;
			cout<<"-------------------------------------"<<endl;  //个人信息
		    	cout<<"此人已找到，详细信息如下："<<endl;
			cout<<"编号："<<root->person_num<<endl;
			cout<<"姓名："<<root->person_name<<endl;
			cout<<"性别："<<root->person_sex<<endl;
			cout<<"配偶："<<root->partner_name<<endl;
			cout<<"-------------------------------------"<<endl;   //父母信息
			if(cur->front_parent==NULL&&cur->front_sibling==NULL)
				cout<<root->person_name<<"为祖先，没有双亲！"<<endl;
			else
			{
				while(cur->front_sibling)
					cur=cur->front_sibling;
				cout<<root->person_name<<"的双亲为："<<endl;
			    if(cur->front_parent->person_sex=="nan")
			    {  
				    cout<<root->person_name<<"的父亲："<<cur->front_parent->person_name<<endl;
				    cout<<root->person_name<<"的母亲："<<cur->front_parent->partner_name<<endl;
			    }
			    else
			    {
				    cout<<root->person_name<<"的父亲："<<cur->front_parent->partner_name<<endl;
				    cout<<root->person_name<<"的母亲："<<cur->front_parent->person_name<<endl;
			    }
		     }
			cout<<"-------------------------------------"<<endl; //子女信息
			cur=root;
			if(cur->first_child==NULL)
				cout<<root->person_name<<"没有子女!"<<endl;
			else
			{
				cout<<root->person_name<<"的所有子女："<<endl;
				cur=root->first_child;
				cout<<cur->person_name<<endl;
				cur=cur->next_sibling;//防止只有一个孩子
				while(cur)
				{
					cout<<cur->person_name<<endl;
					cur=cur->next_sibling;
				}
			}
			cout<<"-------------------------------------"<<endl; //兄弟姐妹信息
			cur=root;
			if(root->front_sibling==NULL&&root->next_sibling==NULL)
			{
				if(root->front_parent==NULL)
					cout<<root->person_name<<"为祖先，没有兄弟！"<<endl;
				else
				    cout<<root->person_name<<"为独生子，没有兄弟"<<endl;
			}
			else
			{
				cout<<root->person_name<<"的所有兄弟："<<endl;
				while(cur->front_sibling)
				{
					cur=cur->front_sibling;
					cout<<cur->person_name<<endl;
				}
				cur=root;
				while(cur->next_sibling)
				{
					cur=cur->next_sibling;
					cout<<cur->person_name<<endl;
				}
			}
			cout<<"-------------------------------------"<<endl;
			return;
		}
		search_all_information1(num,root->first_child);
		search_all_information1(num,root->next_sibling);
	}
}

void binaryTree::search_all_information2(string name,binaryTreeNode *&root)//使用姓名搜索，类似上个函数
{
	if(root)
	{
		if(root->person_name==name)
		{
			binaryTreeNode *cur;
			cur=root;
			cout<<"-------------------------------------"<<endl;
			cout<<"此人已找到，详细信息如下："<<endl;
			cout<<"编号："<<root->person_num<<endl;
			cout<<"姓名："<<root->person_name<<endl;
			cout<<"性别："<<root->person_sex<<endl;
			cout<<"配偶："<<root->partner_name<<endl;
			cout<<"-------------------------------------"<<endl;
			if(cur->front_parent==NULL&&cur->front_sibling==NULL)
				cout<<root->person_name<<"为祖先，没有双亲！"<<endl;
			else
			{
				while(cur->front_sibling)
					cur=cur->front_sibling;
				cout<<root->person_name<<"的双亲为："<<endl;
				if(cur->front_parent->person_sex=="nan")
				{  
					cout<<root->person_name<<"的父亲："<<cur->front_parent->person_name<<endl;
					cout<<root->person_name<<"的母亲："<<cur->front_parent->partner_name<<endl;
				}
				else
				{
					cout<<root->person_name<<"的父亲："<<cur->front_parent->partner_name<<endl;
					cout<<root->person_name<<"的母亲："<<cur->front_parent->person_name<<endl;
				}
			}
			cout<<"-------------------------------------"<<endl;
			cur=root;
			if(cur->first_child==NULL)
				cout<<root->person_name<<"没有子女!"<<endl;
			else
			{
				cout<<root->person_name<<"的所有子女："<<endl;
				cur=root->first_child;
				cout<<cur->person_name<<endl;
				cur=cur->next_sibling;//防止只有一个孩子
				while(cur)
				{
					cout<<cur->person_name<<endl;
					cur=cur->next_sibling;
				}
			}
			cout<<"-------------------------------------"<<endl;
			cur=root;
			if(root->front_sibling==NULL&&root->next_sibling==NULL)
			{
				if(root->front_parent==NULL)
					cout<<root->person_name<<"为祖先，没有兄弟！"<<endl;
				else
					cout<<root->person_name<<"为独生子，没有兄弟"<<endl;
			}
			else
			{
				cout<<root->person_name<<"的所有兄弟："<<endl;
				while(cur->front_sibling)
				{
					cur=cur->front_sibling;
					cout<<cur->person_name<<endl;
				}
				cur=root;
				while(cur->next_sibling)
				{
					cur=cur->next_sibling;
					cout<<cur->person_name<<endl;
				}
			}
			cout<<"-------------------------------------"<<endl;
			return;
		}
		search_all_information2(name,root->first_child);
		search_all_information2(name,root->next_sibling);
	}
}

void binaryTree::add_child(string num,binaryTreeNode *&root) //增加孩子,必须输入其父或母的编号增加孩子
{
	if(root)
	{
		if(root->person_num==num)
		{
			binaryTreeNode *cur,*child;
			child=new binaryTreeNode;
			cur=root;
			if(cur->first_child==NULL)//如果该人没有孩子，则直接创建其子女
			{	
				cur->first_child=child;
				child->next_sibling=NULL;
				child->front_parent=root;
				child->front_sibling=NULL;
				child->first_child=NULL;
				cout<<"输入孩子编号：";
				cin>>child->person_num;
				cout<<"输入孩子姓名：";
				cin>>child->person_name;
				cout<<"输入孩子性别：";
				cin>>child->person_sex;
		        cout<<root->partner_name<<"的孩子添加完毕"<<endl;
			}
			else//否则，直到cur->next_sibing=NULL时（即在最后一个孩子的后面增加孩子）
			{
				cur=cur->first_child;
				while(cur->next_sibling)
					cur=cur->next_sibling;
				cur->next_sibling=child;
				child->first_child=NULL;
				child->next_sibling=NULL;
				child->front_sibling=cur;
				cout<<"输入孩子编号：";
				cin>>child->person_num;
				cout<<"输入孩子姓名：";
				cin>>child->person_name;
				cout<<"输入孩子性别：";
				cin>>child->person_sex;
				cout<<root->partner_name<<"的孩子添加完毕"<<endl;
			}
			return;
		}
		add_child(num,root->first_child);
		add_child(num,root->next_sibling);
	}
}
