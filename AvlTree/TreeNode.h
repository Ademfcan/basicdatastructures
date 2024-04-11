#ifndef TreeNode_H
#define TreeNode_H
class TreeNode
{
private:
    /* data */
    TreeNode* parent;
    TreeNode* leftChild;
    TreeNode* rightChild;
    int value;
    int balanceFactor = 0;
public:
    TreeNode(int Value, TreeNode* parent);
    ~TreeNode();
    void setLeft(TreeNode* child);
    void setRight(TreeNode* child);
    void setParent(TreeNode* parent);
    TreeNode* getLeft();
    TreeNode* getRight();
    TreeNode* getParent();
    int getValue();
    int getBalanceFactor();
    void updateBalanceFactor(bool isIncrease);

};


#endif