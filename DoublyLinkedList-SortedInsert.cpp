
/*
Given a reference to the head of a doubly-linked list and an integer, "data".
Create a new DoublyLinkedListNode object having data value "data" and insert it at the proper location to maintain the sort.
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

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) 
{      
    if (llist == nullptr)
    {
        DoublyLinkedList* llist = new DoublyLinkedList();
        llist->insert_node(data);
        return llist->head;
    }    
    else 
    {
        DoublyLinkedListNode* ptr = llist;
        while (ptr->next)
        {
            if (ptr->data < data)
                ptr = ptr->next;
            else
                break;
        }

        DoublyLinkedListNode* node = new DoublyLinkedListNode(data);
        if (ptr->prev == nullptr && data <= ptr->data)
        {           
            node->next = ptr;
            ptr->prev = node;
            llist = node;
        }
        else if (ptr->next == nullptr && data >= ptr->data )
        {
            ptr->next = node;
            node->prev = ptr;
        }
        else
        {
            node->next = ptr;
            ptr->prev->next = node;
            ptr->prev = node;
        }        
    }     
    return llist;
}

void swap(DoublyLinkedListNode** next, DoublyLinkedListNode** prev)
{
    DoublyLinkedListNode* tmp;
    tmp = *next;
    *next = *prev;
    *prev = tmp;
}

int main()
{
    DoublyLinkedList* llist = new DoublyLinkedList();
    llist->insert_node(1);
    llist->insert_node(2);
    llist->insert_node(3);
    llist->insert_node(4);

    DoublyLinkedListNode* llist1 = sortedInsert(llist->head, 7);
    print_doubly_linked_list(llist1, " ");

    print_doubly_linked_list(llist1, " ");
    free_doubly_linked_list(llist1);

    return 0;
}