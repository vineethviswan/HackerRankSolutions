
/*
Given the pointer to the head node of a doubly linked list, reverse the order of the nodes in place. 
That is, change the next and prev pointers of the nodes so that the direction of the list is reversed. 
Return a reference to the head node of the reversed list.

Note: The head node might be NULL to indicate that the list is empty.
*/

#include <iostream>
#include <string>

class DoublyLinkedListNode {
public:
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;

    DoublyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* tail;

    DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        }
        else {
            this->tail->next = node;
            node->prev = this->tail;
        }

        this->tail = node;
    }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, std::string sep) {
    while (node) {
        std::cout << node->data;

        node = node->next;

        if (node) {
            std::cout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

void swap(DoublyLinkedListNode** next, DoublyLinkedListNode** prev)
{
    DoublyLinkedListNode* tmp;
    tmp = *next;
    *next = *prev;
    *prev = tmp;
}

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) 
{
    if (llist == nullptr)
        return nullptr;
    else if (llist->next == nullptr && llist->prev == nullptr)
        return llist;

    DoublyLinkedListNode* next = llist->next;
    DoublyLinkedListNode* itr = llist;
    bool swapped = false;

    while (itr && !swapped)
    {
        swap(&(itr->next), &(itr->prev));    
        swapped = true;
        if (next)
        {
            itr = next;
            next = next->next;
            swapped = false;
        }
    }
    return itr;
}

int main()
{
    DoublyLinkedList* llist = new DoublyLinkedList();
    llist->insert_node(1);
    llist->insert_node(2);
    llist->insert_node(3);
    llist->insert_node(4);
    
    DoublyLinkedListNode* llist1 = reverse(llist->head);
    print_doubly_linked_list(llist1, " ");
    free_doubly_linked_list(llist1);

    return 0;
}