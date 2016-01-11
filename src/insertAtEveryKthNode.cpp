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
struct node * insert(struct node * head, int data);
void insertAtCurrent(struct node *cur, int data);
struct node* insertAtHead(struct node*head, int data);
struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head){
		return insert(head, K);
	}
	return NULL;
}
struct node * insert(struct node * head, int data){
	struct node *cur;
	cur = (struct node *)malloc(sizeof(struct node));
	cur = head;
		do{
			if (cur->num == data){
				insertAtCurrent(cur, data);
				break;
			}
			else if (head->num > data){
				head = insertAtHead(head, data);
				break;
			}
			else if ((cur->next != NULL) && (cur->num<data) && (cur->next->num>data)){
				insertAtCurrent(cur, data);
				break;
			}
			else if (cur->next != head){
				cur = cur->next;
			}
			else if ((cur->num < data) && (cur->next == head)){
				insertAtCurrent(cur, data);
				break;
			}
		} while (cur != head);
		return head;
}
void insertAtCurrent(struct node *cur, int data){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->num = data;
	temp->next = cur->next;
	cur->next = temp;
}
struct node* insertAtHead(struct node*head, int data){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->num = data;
	temp->next = head;
	head = temp;
	return head;
}
