#ifndef _KOLEJKA_H_
#define _KOLEJKA_H_
#include <stdio.h>
#include <stdlib.h>


typedef struct _node{
	int value;
	struct _node * next;
}node;


node * insert_item_end( node ** top, int war)
{	
	node * tmp = ( node * ) malloc( sizeof( node));
	
	if( !tmp){
		printf( "Brak pamieci!\n");
		exit(1);
	}
	
	tmp -> value = war;
	tmp -> next = NULL;
	printf("Wsztwiam element do kolejki; element: %d.\n", war);
	
	if( * top ){
		node * elem = * top;
		for(; elem -> next; elem = elem -> next);
		elem -> next = tmp;
	}
	else{
		* top = tmp;
	}
	
	return * top;
}


void print_list( node * head)
{
	node * tmp = head;
	
	if( tmp){
		printf("Lista od poczatku -> {");
		for(; head; head = head -> next){
			printf("%d, ", head -> value);
		}
		printf("\b\b}\n");
	}
	else{
		printf("\n");
	}
}


int pop ( node ** head)
{	
	int x = ( * head) -> value;
	printf("Dequeue() = %d\n", x);
	
	node * tmp = * head;
	* head = ( * head) -> next;
	
	free( tmp);
	
	return x;
}

#endif
