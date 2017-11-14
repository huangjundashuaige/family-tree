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
//		cout << "���������������ɵļ��׵Ĵ���" << endl;
//		cin >> volumeForGeneration;
//		cout << "���������������ɵļ��׵��ֵܸ���" << endl;
//		cin >> volumeForBrother;
//		cout << "����������" << endl;
//		cin >> familyName;
//		cout << "���ɼ���ͼ���£�" << endl;
//	
//		family_tree.creat_binary_tree_auto(family_tree.root);
//		//family_tree.show_binary_tree(family_tree.root, i);
//
//}


int main()
{
	string operate;


	while (true) {

		cout<< "  ��ӭ�������׹���ϵͳ������������ʾ������������ֲ���"  << "\n\n"
			<< "  ========================================================" << "\n"
			<< " ||           1. ��������				||"				    << "\n"
			<< " ||           2. �����������                           ||" << "\n"
			<< " ||           3. ��ӡ����ͼ                             ||" << "\n"
			<< " ||           4. ���Ҽ��׳�Ա��ͨ����ţ�               ||" << "\n"
			<< " ||           5. ���Ҽ��׳�Ա��ͨ�����֣�               ||" << "\n"
			<< " ||           6. ���Ӽ��׳�Ա����������                 ||" << "\n"
			<< " ||           0. �˳�����                               ||" << "\n"
			<< "  ========================================================" << endl;


		cout <<"�������������" << endl;
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
			cout << " ��������ȷ���֣���" << endl;	
		}
	}
	return 0;


}

void creat_family_tree () {
	family_tree.creat_binary_tree(family_tree.root);
}

void print_family_tree() {
	int i = 0;
	cout << "����ͼ���£�" << endl;
	family_tree.show_binary_tree(family_tree.root, i);
}

void serch_family_mumber_byId() {
	string id;
	cout << "ʹ�ñ��Ѱ�Ҽ��׳�Ա����������" << endl;
	cin >> id;
	cout << "���ҽ������" << endl;
	cout << "======================================================" << endl;
	if (!family_tree.is_num(id, family_tree.root)) {
		cout << "û�б��Ϊ" << id << "�ļ��׳�Ա" << endl;
	}
	else {
		family_tree.search_all_information1(id, family_tree.root);
	}
	cout << "======================================================" << endl;
}

void serch_family_mumber_byName() {
	string name;
	cout << "ʹ������Ѱ�Ҽ��׳�Ա������������" << endl;
	cin >> name;
	cout << "���ҽ������" << endl;
	
	
	if (!family_tree.is_name(name, family_tree.root)) {
		cout << "û������Ϊ" << name << "�ļ��׳�Ա" << endl;
	}
	else {
		family_tree.search_all_information2(name, family_tree.root);
	}

}

void family_member_add () {
	string name;
	cout << "����������Ӽ����³�Ա,�������³�Ա�ĸ��׻�ĸ�����֣�������������ڼ����еģ�" << endl;
	cin >> name;
	if (!family_tree.is_num(name, family_tree.root)) {
		cout << "û������Ϊ" << name << "�ļ��׳�Ա, ���ʧ��" << endl;
	}
	else {
		family_tree.add_child(name, family_tree.root);
	}
}

void creat_family_tree_auto() {
	int i = 0;
	srand((unsigned)time(NULL));
	cout << "���������������ɵļ��׵Ĵ���" << endl;
	cin >> volumeForGeneration;
	cout << "���������������ɵļ��׵��ֵܸ���" << endl;
	cin >> volumeForBrother;
	cout << "����������" << endl;
	cin >> familyName;
	cout << "���ɼ���ͼ���£�" << endl;

	family_tree.creat_binary_tree_auto(family_tree.root);
	family_tree.show_binary_tree(family_tree.root, i);
}

