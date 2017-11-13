
#include "produceName.h"
#include "name.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;;;;;

int main()
{
	string operate;
	binaryTree family_tree;

	while (true) {

		cout << "娆㈣繋鏉ュ埌瀹惰氨绠＄悊绯荤粺" << endl;
			<< "op" << endl;
			<< " ||           1. add operation			 " << "\n"
			<< " ||           2. decrease operation        " << "\n"
			<< " ||           3. multiply operation        " << "\n"
			<< " ||           4. count polynomial operation" << "\n"
			<< " ||           5. derivation                " << "\n"
			<< " ||           6. calculus                " << "\n"
			<< " ||           7. is equal                  " << "\n"
			<< " ||           8. show_poly_list            " << "\n"
			<< " ||           9. input_poly                " << "\n"
			<< " ||           0. exit                      " << endl;

		cout <<"please input operate_num" << endl;
		cin >> operate;
		if (operate == "1") {
			creat_binary_tree();         //杩涜锛屽椤瑰紡鍔犳硶鎿嶄綔
		}
		else if (operate == "2") {
			show_binary_tree();  //杩涜澶氶」寮忓噺娉曟搷浣?
		}
		else if (operate == "3") {
			search_all_information1();     //杩涜澶氶」寮忕浉涔樻搷浣滐紝
		}
		else if (operate == "4") {
			count_polynomial();      //杩涜澶氶」寮忔眰鍊兼搷浣?
		}
		else if (operate == "5") {
			derivation();           //瀵瑰椤瑰紡杩涜姹傚
		}
		else if (operate == "6") {
			calculus();           //瀵瑰椤瑰紡杩涜姹傚
		}
		else if (operate == "7") {
			is_equal();            //鍒ゆ柇涓や釜澶氶」寮忔槸鍚︾浉绛?
		}
		else if (operate == "8") {
			show_poly_list();         //灞曠ず鐩墠澶氶」寮忓垪琛?
		}
		else if (operate == "9") {

			input_poly();              //鍐嶆杩涜澶氶」寮忕殑杈撳叆锛?
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

}

void print_family_tree() {

}

void serch_family_mumber_byId() {

}

void serch_family_mumber_byName() {

}

void family_member_add () {
	
}
