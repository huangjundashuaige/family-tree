#include "tree.h"
#include "name.h"
#include "produceName.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include<ctime>
#include<random>

int volumeForGeneration;
int volumeForBrother;
std::default_random_engine generator;
string familyName;

using namespace std;
void creat_family_tree ();
void creat_family_tree_auto();
void print_family_tree() ;
void serch_family_mumber_byId();
void serch_family_mumber_byName() ;
void family_member_add ();


binaryTree family_tree;
//
//int main() {
//		int i = 0;
//		srand((unsigned)time(NULL));
//		cout << "请输入你期望生成的家谱的代数" << endl;
//		cin >> volumeForGeneration;
//		cout << "请输入你期望生成的家谱的兄弟个数" << endl;
//		cin >> volumeForBrother;
//		cout << "请输入姓氏" << endl;
//		cin >> familyName;
//		cout << "生成家谱图如下：" << endl;
//	
//		family_tree.creat_binary_tree_auto(family_tree.root);
//		//family_tree.show_binary_tree(family_tree.root, i);
//
//}


int main()
{
	string operate;


	while (true) {

		cout<< "  欢迎来到家谱管理系统，按照下列提示，输入操作数字操作"  << "\n\n"
			<< "  ========================================================" << "\n"
			<< " ||           1. 建立家谱				||"				    << "\n"
			<< " ||           2. 建立随机家谱                           ||" << "\n"
			<< " ||           3. 打印家谱图                             ||" << "\n"
			<< " ||           4. 查找家谱成员（通过编号）               ||" << "\n"
			<< " ||           5. 查找家谱成员（通过名字）               ||" << "\n"
			<< " ||           6. 增加家谱成员（新生儿）                 ||" << "\n"
			<< " ||           0. 退出程序                               ||" << "\n"
			<< "  ========================================================" << endl;


		cout <<"请输入操作数字" << endl;
		cin >> operate;
		if (operate == "1") {
			creat_family_tree();
		}
		else if (operate == "2") {
			creat_family_tree_auto();
		}
		else if (operate == "3") {
			print_family_tree();  
		}
		else if (operate == "4") { 
			serch_family_mumber_byId();
		}
		else if (operate == "5") {
			serch_family_mumber_byName();
		}
		else if (operate == "6") {
			family_member_add();  
		}
		else if (operate == "0") {
			break;
		} else {
			cout << " 请输入正确数字！！" << endl;	
		}
	}
	return 0;


}

void creat_family_tree () {
	family_tree.creat_binary_tree(family_tree.root);
}

void print_family_tree() {
	int i = 0;
	cout << "家谱图如下：" << endl;
	family_tree.show_binary_tree(family_tree.root, i);
}

void serch_family_mumber_byId() {
	string id;
	cout << "使用编号寻找家谱成员，请输入编号" << endl;
	cin >> id;
	cout << "查找结果如下" << endl;
	cout << "======================================================" << endl;
	if (!family_tree.is_num(id, family_tree.root)) {
		cout << "没有编号为" << id << "的家谱成员" << endl;
	}
	else {
		family_tree.search_all_information1(id, family_tree.root);
	}
	cout << "======================================================" << endl;
}

void serch_family_mumber_byName() {
	string name;
	cout << "使用名字寻找家谱成员，请输入名字" << endl;
	cin >> name;
	cout << "查找结果如下" << endl;
	
	
	if (!family_tree.is_name(name, family_tree.root)) {
		cout << "没有名字为" << name << "的家谱成员" << endl;
	}
	else {
		family_tree.search_all_information2(name, family_tree.root);
	}

}

void family_member_add () {
	string name;
	cout << "用名字来添加家谱新成员,请输入新成员的父亲或母亲名字（输入的名字是在家谱中的）" << endl;
	cin >> name;
	if (!family_tree.is_num(name, family_tree.root)) {
		cout << "没有名字为" << name << "的家谱成员, 添加失败" << endl;
	}
	else {
		family_tree.add_child(name, family_tree.root);
	}
}

void creat_family_tree_auto() {
	int i = 0;
	srand((unsigned)time(NULL));
	cout << "请输入你期望生成的家谱的代数" << endl;
	cin >> volumeForGeneration;
	cout << "请输入你期望生成的家谱的兄弟个数" << endl;
	cin >> volumeForBrother;
	cout << "请输入姓氏" << endl;
	cin >> familyName;
	cout << "生成家谱图如下：" << endl;

	family_tree.creat_binary_tree_auto(family_tree.root);
	family_tree.show_binary_tree(family_tree.root, i);
}

