#include <stdio.h>
#include "stos.h"

#define PUSH insert_item_begin

int main(int argc, char *argv[]){
	node * top = NULL;

	printf("Wstawiam elementy na stos.\n");
	top = PUSH(top, 8);
	top = PUSH(top, 23);
	top = PUSH(top, 123);
	printf("Wypisuje zawartosc stosu.\n");
	
	print_list(top);
	
	
	pop(&top);
	pop(&top);
	
	
	printf("Wstawiam elementy na stos.\n");
	top = PUSH(top, 1223);
	top = PUSH(top, 12);
	top = PUSH(top, 787);
	printf("Wypisuje zawartosc stosu.\n");
	
	print_list(top);
		
	return 0;
}
