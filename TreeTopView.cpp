
/*
Given a pointer to the root of a binary tree, print the top view of the binary tree.
The tree as seen from the top the nodes, is called the top view of the tree
*/

#include <iostream>
#include <queue>
#include <map>

using namespace std;

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

    void printTree(Node* root) {

        if (root == nullptr)
            return;
       
        std::cout << root->data << " ";
        printTree(root->left);             
        printTree(root->right);
        
    }

    void topView(Node* root) {

        //level, Node*
        std::queue<std::pair<int, Node*>> q;        
        q.push(std::make_pair(0, root));
        std::map<int, Node*> result;

        while (!q.empty()) {

            std::pair<int, Node*> current = q.front();
            if (current.second != nullptr) {
                result.insert(current);
                q.push(std::make_pair(current.first + 1, current.second->right));
                q.push(std::make_pair(current.first - 1, current.second->left));
            }
            q.pop();
        }       
        for (const auto& elt : result)
            std::cout << elt.second->data << " ";
    }

}; //End of Solution

//int main() {
//
//    Solution myTree;
//    Node* root = NULL;
//
//   /* root = myTree.insert(root, 1);
//    root = myTree.insert(root, 14);
//    root = myTree.insert(root, 3);
//    root = myTree.insert(root, 7);
//    root = myTree.insert(root, 4);
//    root = myTree.insert(root, 5);
//
//    root = myTree.insert(root, 15);
//    root = myTree.insert(root, 6);
//    root = myTree.insert(root, 13);
//    root = myTree.insert(root, 10);
//    root = myTree.insert(root, 11);
//    root = myTree.insert(root, 2);
//
//    root = myTree.insert(root, 12);
//    root = myTree.insert(root, 8);
//    root = myTree.insert(root, 9);*/
//
//    root = myTree.insert(root, 10);
//    root = myTree.insert(root, 4);
//    root = myTree.insert(root, 18);
//    root = myTree.insert(root, 2);
//    root = myTree.insert(root, 5);
//    root = myTree.insert(root, 15);
//    root = myTree.insert(root, 20);
//    root = myTree.insert(root, 1);
//    root = myTree.insert(root, 3);
//    
//    myTree.topView(root);
//
//    return 0;
//}


