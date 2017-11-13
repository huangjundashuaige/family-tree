#include "tree.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
bool findIdSuccess = false;
bool findNameSuccess = false;
bool addChildSuccess = false;


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

		cout << "" 
			<< "op"  << "\n"
			<< " ||           1. add operation			 " << "\n"
			<< " ||           2. decrease operation        " << "\n"
			<< " ||           3. multiply operation        " << "\n"
			<< " ||           4. count polynomial operation" << "\n"
			<< " ||           5. derivation                " << "\n"
			<< " ||           0. exit                      " << endl;

		cout <<"please input operate_num" << endl;
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
			cout << "    please input right num!" << endl;	
		}
	}
	return 0;


}

void creat_family_tree () {
	family_tree.creat_binary_tree(family_tree.root);
}

void print_family_tree() {
	int i = 0;
	cout << "tree are as follows" << endl;
	family_tree.show_binary_tree(family_tree.root, i);
}

void serch_family_mumber_byId() {
	string id;
	cout << "use num to find member"
		 << "please input num" << endl;
	cin >> id;
	cout << "find answer is" << endl;
	cout << "======================================================" << endl;
	family_tree.search_all_information1(id, family_tree.root);
	if (!findIdSuccess) {
		cout << "not exist" << endl;
	}
	cout << "======================================================" << endl;
}

void serch_family_mumber_byName() {
	string name;
	cout << "use name to find member"
		 << "please input name" << endl;
	cin >> name;
	cout << "find answer is" << endl;
	cout << "======================================================" << endl;
	family_tree.search_all_information2(name, family_tree.root);
	if (!findNameSuccess) {
		cout << "not exist" << endl;
	}
	cout << "======================================================" << endl;
}

void family_member_add () {
	string name;
	cout << "use name to add child"
		 << "please input name" << endl;
	cin >> name;
	family_tree.add_child(name, family_tree.root);
	if (!addChildSuccess) {
		cout << "no such name" << endl;
	}
}
