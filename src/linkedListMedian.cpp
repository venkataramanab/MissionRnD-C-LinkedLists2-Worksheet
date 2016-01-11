/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
int median(struct node *head, struct node *ptr1, struct node *ptr2);
int linkedListMedian(struct node *head) {
	if (head){
		return median(head, head, head);
	}
	return -1;
}
int median(struct node *head, struct node *ptr1, struct node *ptr2){
	if (ptr2->next){
		if (ptr2->next->next){
			return median(head, ptr1->next, ptr2->next->next);
		}
		else{
			return (ptr1->num + ptr1->next->num) / 2;
		}
	}
	else{
		return ptr1->num;
	}
}
