
/*
	Huffman coding assigns variable length codewords to fixed length input characters based on their frequencies. 
	More frequent characters are assigned shorter codewords and less frequent characters are assigned longer codewords. 
	All edges along the path to a character contain a code digit. If they are on the left side of the tree, they will be a 0 (zero). 
	If on the right, they'll be a 1 (one). Only the leaves will contain a letter and its frequency count. 
	All other nodes will contain a null instead of a character, and the count of the frequency of all of it and its descendant characters.
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

typedef struct node {
    int freq;
    char data;
    node* left;
    node* right;
} node;

struct deref :public std::binary_function<node*, node*, bool> {
    bool operator()(const node* a, const node* b)const {
        return a->freq > b->freq;
    }
};

typedef std::priority_queue<node*, std::vector<node*>, deref> spq;

node* huffman_hidden(std::string s) {

    spq pq;
    std::vector<int>count(256, 0);

    for (int i = 0; i < s.length(); i++) {
        count[s[i]]++;
    }

    for (int i = 0; i < 256; i++) {

        node* n_node = new node;
        n_node->left = NULL;
        n_node->right = NULL;
        n_node->data = (char)i;
        n_node->freq = count[i];

        if (count[i] != 0)
            pq.push(n_node);

    }

    while (pq.size() != 1) {

        node* left = pq.top();
        pq.pop();
        node* right = pq.top();
        pq.pop();
        node* comb = new node;
        comb->freq = left->freq + right->freq;
        comb->data = '\0';
        comb->left = left;
        comb->right = right;
        pq.push(comb);

    }
    return pq.top();
}

void print_codes_hidden(node* root, std::string code, std::map<char, std::string>& mp) {

    if (root == NULL)
        return;

    if (root->data != '\0') {
        mp[root->data] = code;        
    }

    print_codes_hidden(root->left, code + '0', mp);
    print_codes_hidden(root->right, code + '1', mp);

}


void decode_huff(node* root, std::string s) {

    std::string decoded_str = "";    
    node* current = root;
    for (auto& chr : s) {
        if (chr == '1')
            current = current->right;
        else
            current = current->left;

        if (current != nullptr && (current->left == nullptr && current->right == nullptr)) {
            decoded_str += current->data;
            current = root;
        }
    }   
    std::cout << decoded_str << "\n";
}

int main() {

    std::string s = "ABRACADABRA";
    //std::string s = "ABACA";

    std::cout << "String : " << s << "\n";
    node* tree = huffman_hidden(s);
    std::string code = "";
    std::map<char, std::string>mp;

    print_codes_hidden(tree, code, mp);

    std::string coded;
    for (int i = 0; i < s.length(); i++) {
        coded += mp[s[i]];
    }
    
    std::cout << "Encoded String : " << coded << "\n";

    decode_huff(tree, coded);

    return 0;
}