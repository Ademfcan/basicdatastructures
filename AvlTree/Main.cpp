#include "AVLTree.h"
#include <iostream>
#include <vector>

int main(){
    AVLTree* tree = new AVLTree;
    for(int i = 20;i>=1;i--){
        tree->add(i);
        std::cout << "Count tree: " << tree->getCount() << std::endl;
        std::vector<int> out = std::move(tree->inOrderTraversal());
        std::cout << "Tree depth : " << tree->getTreeDepth() << std::endl;
        for(int i = 0; i<out.size();i++){
            std::cout << out[i] << " : ";
        }

        getchar();
    }
    
    return 0;
}