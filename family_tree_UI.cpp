#include "tree.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;
void creat_family_tree ();
void print_family_tree() ;
void serch_family_mumber_byId();
void serch_family_mumber_byName() ;
void family_member_add ();


binaryTree family_tree;

int main()
{
	string operate;


	while (true) {

		cout<< "  ��ӭ�������׹���ϵͳ������������ʾ������������ֲ���"  << "\n\n"
			<< "  ========================================================" << "\n"
			<< " ||           1. ��������				||"				    << "\n"
			<< " ||           2. ��ӡ����ͼ                             ||" << "\n"
			<< " ||           3. ���Ҽ��׳�Ա��ͨ����ţ�               ||" << "\n"
			<< " ||           4. ���Ҽ��׳�Ա��ͨ�����֣�               ||" << "\n"
			<< " ||           5. ���Ӽ��׳�Ա����������                 ||" << "\n"
			<< " ||           0. �˳�����                               ||" << "\n"
			<< "  ========================================================" << endl;


		cout <<"�������������" << endl;
		cin >> operate;
		if (operate == "1") {
			creat_family_tree();
		}
		else if (operate == "2") {
			print_family_tree();  
		}
		else if (operate == "3") { 
			serch_family_mumber_byId();
		}
		else if (operate == "4") {
			serch_family_mumber_byName();
		}
		else if (operate == "5") {
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
	
	
	if (!family_tree.is_num(name, family_tree.root)) {
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
