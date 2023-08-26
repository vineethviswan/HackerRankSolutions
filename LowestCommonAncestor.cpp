
/*
You are given pointer to the root of the binary search tree and two values v1 and v2. 
You need to return the lowest common ancestor (LCA) of v1 and v2 in the binary search tree.
*/

#include <iostream>

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
  
    Node* lca(Node* root, int v1, int v2) {
        
        int largest = (v1 > v2) ? v1 : v2;
        int smallest = (v1 < v2) ? v1 : v2;

        Node* current = root;
        while (current) {

            if (current->data > smallest && current->data < largest || current->data == smallest || current->data == largest)
                return current;

            if (current->data > largest)
                current = current->left;
            else
                current = current->right;                
        }
        return root;
    }

};


int main() {

    Solution myTree;
    Node* root = NULL;
    
    root = myTree.insert(root, 8);
    root = myTree.insert(root, 4);
    root = myTree.insert(root, 9);
    root = myTree.insert(root, 1);
    root = myTree.insert(root, 2);
    root = myTree.insert(root, 3);
    root = myTree.insert(root, 6);
    root = myTree.insert(root, 5);
   
    Node* ans = myTree.lca(root, 1, 2);
    std::cout << "Lowest Common Ancestor : " << ans->data;

    return 0;
}
