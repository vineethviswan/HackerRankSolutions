
/*
Given a pointer to the root of a binary tree, you need to print the level order traversal of this tree. 
In level-order traversal, nodes are visited level by level from left to right. 
Complete the function "levelOrder" and print the values in a single line separated by a space.
*/

#include <iostream>
#include <queue>

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
    void levelOrder(Node* root) {

        if (root == nullptr) return;

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            std::cout << current->data << " ";

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        std::cout << "\n";
    }

}; 

int main() {

    Solution myTree;
    Node* root = NULL;
    
    root = myTree.insert(root, 1);
    root = myTree.insert(root, 2);
    root = myTree.insert(root, 5);
    root = myTree.insert(root, 3);
    root = myTree.insert(root, 6);
    root = myTree.insert(root, 4);

    myTree.levelOrder(root);
    return 0;
}