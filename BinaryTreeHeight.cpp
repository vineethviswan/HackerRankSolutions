
/*
The height of a binary tree is the number of edges between the tree's root and its furthest leaf.
*/

#include <iostream>
#include <thread>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        }
        else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else {
                cur = insert(root->right, data);
                root->right = cur;
            }
            return root;
        }
    }
    
    int height(Node* root) 
    {            
        if (root == nullptr)
            return -1 ;
        else
        {
            int ht_left = 1 + height(root->left);
            int ht_right = 1 + height(root->right);
            return std::max(ht_left, ht_right);
        }       
    }

};

int main()
{
    Solution myTree;
    Node* root = NULL;

    root = myTree.insert(root, 30);
    root = myTree.insert(root, 20);
    root = myTree.insert(root, 40);
    root = myTree.insert(root, 10);
    root = myTree.insert(root, 50);
    
    int height = myTree.height(root);
    std::cout << height;       

}