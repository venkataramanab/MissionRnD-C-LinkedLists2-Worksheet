/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
void insertAtCurrent(struct node *cur, int data);
struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head&&(K>0)){
		struct node *cur;
		cur = (struct node *)malloc(sizeof(struct node));
		cur = head;
		do{
			int tempK = K;
			while (cur->next && (tempK>1)){
				tempK--;
				cur = cur->next;
			}
			if (cur->next && (tempK == 1)){
				insertAtCurrent(cur, K);
				cur = cur->next;
			}
			else if (cur && (tempK == 1)){
				insertAtCurrent(cur, K);
				break;
			}
			cur = cur->next;
		} while (cur);
		return head;
	}
	return NULL;
}
void insertAtCurrent(struct node *cur, int K){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->num = K;
	temp->next = cur->next;
	cur->next = temp;
}

