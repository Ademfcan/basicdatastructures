#include"TreeNode.h"

TreeNode::TreeNode(int Value, TreeNode* parent) : value(Value), parent(parent)
{
    leftChild = nullptr;
    rightChild = nullptr;
}

TreeNode::~TreeNode()
{
}

void TreeNode::setLeft(TreeNode* Child)
{
    leftChild = Child;
    
}

void TreeNode::setRight(TreeNode* Child)
{
   rightChild = Child;
    
}

void TreeNode::setParent(TreeNode* Parent)
{
   parent = Parent;
    
}

TreeNode* TreeNode::getLeft(){
    return leftChild;
   
}

TreeNode* TreeNode::getRight(){
    return rightChild;
}


TreeNode* TreeNode::getParent(){
    return parent;
}

int TreeNode::getValue(){
    return value;
}

int TreeNode::getBalanceFactor(){
    return this->balanceFactor;
}

void TreeNode::updateBalanceFactor(bool isIncrease){
    if(isIncrease){
        balanceFactor++;
    }
    else{
        balanceFactor--;
    }
}
