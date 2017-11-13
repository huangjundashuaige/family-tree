# family-tree
##关于creat binarytree函数功能使用和随机生成名字的接口


###creatbinarytree函数
这个函数主要的作用就是为了能够方便展示，不必事先写好家谱然后再show给大家看，而且因为是随机产生的可以体现出show的效率和状态
要使用这个函数首先需要把我在testify.cpp里面的几个全局变量拷贝到main函数所在文件的上面，至于如何初始化这些全局变量也可以看testify.CPP里面的初始化方法，
放在ui里的话应该是要先进行对全局变量的初始化再调用函数不然会报错
```
std::default_random_engine generator;
int volumeForGeneration,volumeForBrother;
string familyName;
int main()
{
    //for(int i=0;i<10;i++)cout<<rand()%10<<endl;
    srand( ( unsigned )time( NULL ) );
    cout<<"what's the number of generation you expect for"<<endl;
    cin>>volumeForGeneration;
    cout<<"what's the number of brothers you expect for"<<endl;
    cin>>volumeForBrother;
    cout<<"key in the family name"<<endl;
    cin>>familyName;
    binaryTree tree;
    tree.creat_binary_tree(tree.root);
    return 0;
}
```
对了还要在main函数里面加上必要的头文件

接下来说一下这个函数的亮点，第一个就是随机生成中文的名字，名字的数据库是我在网上找的带有古风的名字但是有一点不好就是男女有些分不开，不过也没什么关系这个我之后会说。生成名字的主要方式就是把所有名字都放在一个字符串里面然后通过生成随机数来随机取得这些名字。

还有就是因为这个家谱树的定义的时候定义成了男女都可以写进家谱，但是根据中国传统文化的影响孩子应该是要和父亲姓的，所以上面用到的不带姓氏的名字生成再加上一开始初始化的姓氏不能够继续适用，所以我又想办法重新生成了姓氏，如果家谱上写的是female那么孩子就应该和配偶姓，所以展示的时候可以看到在几层子孙后大部分都是别的姓氏的名字了

最后是随机的时候我实现的方法，确定性别的时候的用的是rand（）随机，一半一半的概率，确定配偶的属性的时候我加了一个彩蛋就是有十分之一的概率会是同性恋
然后是最核心的算法，如果一开始随机初始化会要求输入一个预期的子孙辈数和兄弟数目，在具体实现的时候
```
if(restGeneration>0)
    {
        //cout<<"l ";
        node->first_child=new binaryTreeNode;
        node->first_child->front_parent=node;
        node->first_child->front_sibling=nullptr;
        std::poisson_distribution<int> distribution1(volumeForBrother);
        traverse(node->first_child,depth+1,restGeneration-1,distribution1(generator),familyName); 
    }
    if(restBrother>0)
    {
        //cout<<"r ";
        node->next_sibling=new binaryTreeNode;
        node->next_sibling->front_parent=node->front_parent;
        node->next_sibling->front_sibling=node;
        std::poisson_distribution<int> distribution1(volumeForGeneration-depth);
       // cout<<distribution1(generator)<<" ";
        traverse(node->next_sibling,depth+1,distribution1(generator),restBrother-1,familyName);
    }
```
  在具体的时候的时候因为为了要达到预期是这么多的辈数而且要在每一代都随机生成，分布是只能是泊松分布，用的是<random>这个库，具体随机的时间点是在进入左child之前随机出左child的兄弟数，在进入右孩子之前先随机出子孙还应该有多少代，这样做就可以顺利保存平均值会是预期而且没有冗余,也就是说每个二叉树（或者以二叉树中节点为root的子集的二叉树）的最左边的分支的后代辈数一定不是一开始就固定的，而是要等有了根节点或sibling才能确定下来，这样才能保证每一个最左的节点的后代数提前确定，而兄弟的个数是第一个孩子产生的时候确定的保证了进入到sibling的次数可以保证不会有冲突。
