#ifndef AVLTree_H
#define AVLTree_H
#include "TreeNode.h"
#include <vector>
class AVLTree
{
private:
    TreeNode* root;
    int treeDepth;
    int count;
    int balanceFactor = 1;
    int getBalance(TreeNode* node);
    void balanceTree(TreeNode* node);
    void leftRotation(TreeNode* node);
    void rightRotation(TreeNode* node);
    void leftRightRotation(TreeNode* node);
    void rightLeftRotation(TreeNode* node);
    void inOrderTraversalHelper(TreeNode* node,std::vector<int>& arr);
    void preOrderTraversalHelper(TreeNode* node,std::vector<int>& arr);
    void postOrderTraversalHelper(TreeNode* node,std::vector<int>& arr);
    void add(int value, TreeNode* node);
    int getTreeDepth(TreeNode* node);


public:
    AVLTree(/* args */);
    ~AVLTree();
    void add(int value);
    void remove(int value);
    bool checkIfContains(int value);
    std::vector<int> inOrderTraversal();
    std::vector<int> preOrderTraversal();
    std::vector<int> postOrderTraversal();
    int getMin();
    int getMax();
    int getTreeDepth();
    int getCount();
    int getBalanceFactor();
    void setBalanceFactor(int balanceFactor);


};

#endif