/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
void merge(struct node *head1, struct node *head2, struct node *cur);
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1&&head2){
		if (head1->num < head2->num){
			merge(head1->next, head2, head1);
			return head1;
		}
		else{
			merge(head1, head2->next, head2);
			return head2;
		}
	}
	else if (head1){
		return head1;
	}
	else if (head2){
		return head2;
	}
	return NULL;
}
void merge(struct node *head1, struct node *head2, struct node *cur){
	if ((head1 != NULL) && (head2 != NULL)){
		if ((head1->num) <= (head2->num)){
			cur->next = head1;
			merge(head1->next, head2, cur->next);
		}
		else{
			cur->next = head2;
			merge(head1, head2->next, cur->next);
		}
	}
	else if (head1 != NULL){
		cur->next = head1;
	}
	else if (head2 != NULL){
		cur->next = head2;
	}
}
