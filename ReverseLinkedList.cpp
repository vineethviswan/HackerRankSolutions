
/*
Given the pointer to the head node of a linked list, change the next pointers of the nodes so that their order is reversed.
The head pointer given may be null meaning that the initial list is empty.

Example
"head" references the list 1 --> 2 --> 3 --> NULL

Manipulate the "next" pointers of each node in place and return "head", which now referencing the head of the list.

*/

#include <iostream>

struct Node {

	int value;
	struct Node* next;

	Node(int v): value(v), next(nullptr) {}
};

void PrintList(Node* head) {
	
	if (head == nullptr) return;
	std::cout << head->value << " ";
	PrintList(head->next);
}

Node* ReverseList(Node* head) {

	Node* prev = nullptr;
	Node* current = head;
	
	while (current) {

		Node* next = current->next;
		current->next = prev;		
		prev = current;
		current = next;
	}
	return prev;
}

Node* ReverseListRec(Node* head, Node* prev) {
	
	if (head == nullptr) return prev;
	Node* next = head->next;
	head->next = prev;

	return ReverseListRec(next, head);
}

int main() {

	Node* a = new Node(1);
	Node* b = new Node(2);
	Node* c = new Node(3);
	Node* d = new Node(4);
	Node* e = new Node(5);
	Node* f = new Node(6);
	Node* g = new Node(7);
	Node* h = new Node(8);
	Node* i = new Node(9);
	Node* j = new Node(10);

	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = g;
	g->next = h;
	h->next = i;
	i->next = j;

	PrintList(a);
	std::cout << "\nReversed List \n";
	PrintList(ReverseList(a));

	std::cout << "\nReversed List - Recursion\n";
	PrintList(ReverseListRec(a, nullptr));

	return 0;
}