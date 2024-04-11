#include "AVLTree.h"
#include "TreeNode.h"
#include <vector>
#include <iostream>
#include <math.h>

AVLTree::AVLTree()
{
    this->root = nullptr;
    this->count = 0;
}

AVLTree::~AVLTree()
{
}

int AVLTree::getBalance(TreeNode *node)
{
    int leftBalance = getTreeDepth(node->getLeft());
    int rightBalance = getTreeDepth(node->getRight());
    return leftBalance - rightBalance;
}

void AVLTree::balanceTree(TreeNode *node)
{
    int balanceFactor = node->getBalanceFactor();
    if(balanceFactor > 1){
        // left heavy
        if(node->getLeft()->getBalanceFactor() > 0){
            rightRotation(node);
        }
        else{
            leftRightRotation(node);
        }

    }
    else if(balanceFactor < -1){
        if(node->getRight()->getBalanceFactor() < 0){
            leftRotation(node);
        }
        else{
            rightLeftRotation(node);
        }
    }
}

void AVLTree::leftRotation(TreeNode *node)
{
    std::cout << "Performing left rotation" << std::endl;
    
    TreeNode *child = node->getRight();
    // if not root change parent aswell
    if(node->getParent() != nullptr){
        TreeNode* parentVal = node->getParent();
        if(child->getValue() < parentVal->getValue()){
            node->getParent()->setLeft(child);
        }   
        else{
            node->getParent()->setRight(child);
        }
        child->setParent(parentVal);
    }
    else{
        root = child;
        child->setParent(nullptr);
    }
    node->setRight(child->getLeft());
    node->setParent(child);
    child->setLeft(node);



}

void AVLTree::rightRotation(TreeNode *node)
{
    std::cout << "Performing right rotation" << std::endl;
    TreeNode *child = node->getLeft();
    // if not root change parent aswell
    if(node->getParent() != nullptr){
        TreeNode* parentVal = node->getParent();
        if(child->getValue() < parentVal->getValue()){
            node->getParent()->setLeft(child);
        }   
        else{
            node->getParent()->setRight(child);
        }
        child->setParent(parentVal);

    }
    else{
        root = child;
        child->setParent(nullptr);

    }
    node->setLeft(child->getRight());
    node->setParent(child);
    child->setRight(node);
}

void AVLTree::leftRightRotation(TreeNode *node)
{
    leftRotation(node->getLeft());
    rightRotation(node);
    


}

void AVLTree::rightLeftRotation(TreeNode *node)
{
    rightRotation(node->getRight());
    leftRotation(node);
}

void AVLTree::add(int val, TreeNode *parent)
{
    

    if (val < parent->getValue())
    {
        // adding to the left side
        
        if(parent->getLeft() == nullptr){
            parent->setLeft(new TreeNode(val, parent));
        }
        else{
            
            add(val, parent->getLeft());

        }
        parent->updateBalanceFactor(true);
        if(parent->getBalanceFactor() > abs(this->balanceFactor)){
            balanceTree(parent);
        }
    }
    else
    {
        // right side
        
        if(parent->getRight() == nullptr){
            parent->setRight(new TreeNode(val, parent));
        }
        else{
           
            add(val, parent->getRight());


        }
        parent->updateBalanceFactor(false);
        if(parent->getBalanceFactor() > abs(this->balanceFactor)){
            balanceTree(parent);
        }
    }
    
}

void AVLTree::add(int val){
    if(root == nullptr){
        root = new TreeNode(val,nullptr);
    }
    else{
        add(val,root);

    }
    count++;

}

void AVLTree::remove(int val)
{
}

bool AVLTree::checkIfContains(int val)
{
}
// every traversal this array will point to a new array
// this way my recursive methods will be able to access the same array
std::vector<int> AVLTree::inOrderTraversal()
{
    std::vector<int> tempArray;
    inOrderTraversalHelper(root,tempArray);
    return tempArray;
    
    
}

std::vector<int> AVLTree::preOrderTraversal()
{
}
std::vector<int> AVLTree::postOrderTraversal()
{
}
// recursive methods below
// they will recursively add to an array
void AVLTree::inOrderTraversalHelper(TreeNode *node,std::vector<int>& arr)
{
    if(node == nullptr){
        return;
    }
    std::cout << "Node value: "  << node->getValue() << std::endl;
    inOrderTraversalHelper(node->getLeft(),arr);
    arr.push_back(node->getValue());
    inOrderTraversalHelper(node->getRight(),arr);
}
void AVLTree::preOrderTraversalHelper(TreeNode *node,std::vector<int>& arr)
{
}
void AVLTree::postOrderTraversalHelper(TreeNode *node,std::vector<int>& arr)
{
}

int AVLTree::getMin()
{
}
int AVLTree::getMax()
{
}
int AVLTree::getTreeDepth()
{

    return getTreeDepth(root);

}
int AVLTree::getTreeDepth(TreeNode* node)
{
    if(node == nullptr){
        return 0;
    }
    return std::max(1+getTreeDepth(node->getLeft()),1+getTreeDepth(node->getRight()));
}

int AVLTree::getCount(){
    return this->count;
}

void AVLTree::setBalanceFactor(int BalanceFactor){
    this->balanceFactor = BalanceFactor;
}

int AVLTree::getBalanceFactor(){
    return balanceFactor;
}
