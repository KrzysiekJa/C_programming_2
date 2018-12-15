#ifndef _STOS_H_
#define _STOS_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
	int value;
	struct tnode * next;
} node;


node * insert_item_begin( node * top, int war){
	node * tmp = malloc( sizeof( node));
	
	if ( !tmp){
		printf( "Blad alokacji!\n");
		return top;
	}
	
	tmp -> value = war;
	tmp -> next = top;
	printf("Wsztwiam element na stos; element: %d.\n", war);
	
	return tmp;
	
}


void print_list(const node * ilosc){
	
	if( !ilosc){
		printf("Lista jest pusta.\n");
		return;
	}
	
	printf("Lista od poczatku -> {");
	for(; ilosc; ilosc = ilosc -> next){
		printf("%d, ", ilosc -> value);
	}
	printf("}\n");
}


int pop (node ** top){
	printf("Usuwam elementy ze stosu.\n");
	
	int x = ( * top) -> value;
	
	printf("Pop() = %d\n", x);
	node * tmp = * top;
	* top = ( * top) -> next;
	
	free(tmp);
	
	printf("Wypisuje zawartosc stosu.\n");
	print_list(*top);
	
	return x;
}


#endif
