/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
struct node * reverse(struct node * head, struct node *pre);
struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head){
		head = reverse(head, NULL);
		return head;
	}
	return NULL;
}
struct node * reverse(struct node * head, struct node *pre){
	if (head->next){
		struct node *new_head = reverse(head->next, head);
		head->next = pre;
		return new_head;
	}
	else{
		head->next = pre;
		return head;
	}
}