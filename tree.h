#ifndef TREE_HEADFILE
#define TREE_HEADFILE

#include<string>
#include<vector>
using namespace std;
class TreeNode
{
public:
    string data;
    TreeNode *lChild;
    TreeNode *rChild;
};

class TreeMethod
{
public:
    TreeNode *root;
    void build(vector<int> v);
    void deleteTreeNodeByPosition(vector<int> position);
    void deleteTreeNodeByName(string name);
    vector<int> searchTreeNodeByPosition(vector<int> position);
    vector<int> searchTreeNodeByName(string name);
    vector<string> measure();
    void printTheTree();
}tree;


#endif