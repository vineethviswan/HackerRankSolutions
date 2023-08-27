
/*
    A linked list is said to contain a cycle if any node is visited more than once while traversing the list. 
    For example, in the following graph there is a cycle formed when node 5 points back to node 3.

    1 --> 2 --> 3 --> 4 --> 5 --> 3
*/

#include <iostream>
#include <string>
#include <fstream>

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    SinglyLinkedListNode* insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        }
        else {
            this->tail->next = node;
        }

        this->tail = node;
        return node;
    }
};

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

bool has_cycle(SinglyLinkedListNode* head) {

    SinglyLinkedListNode* slowPtr = head, * fastPtr = head;

    while (slowPtr && fastPtr && fastPtr->next) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr) {
            return true;
        }
    }
    return false;    
}

int main()
{
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    SinglyLinkedListNode* a = llist1->insert_node(1);
    SinglyLinkedListNode* b = llist1->insert_node(2);
    SinglyLinkedListNode* c = llist1->insert_node(3);
    SinglyLinkedListNode* d = llist1->insert_node(4);
    SinglyLinkedListNode* e = llist1->insert_node(5);
    SinglyLinkedListNode* f = llist1->insert_node(3);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = c;

    std::cout << "Cycle present in the list : " << has_cycle(llist1->head);
	
	free_singly_linked_list(llist1);

}