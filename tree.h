#ifndef TREE_HEADFILE
#define TREE_HEADFILE

#include <string>
#include <vector>
using namespace std;
class TreeNode
{
public:
    string name;
    string sponge_name;
    TreeNode *lChild;
    TreeNode *rChild;
};

class TreeMethod
{
public:
    TreeNode *root;
    void build();
    void printTheTree();
};


#endif