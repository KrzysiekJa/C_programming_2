#include <stdio.h>
#include "kolejka.h"

#define ENQUEUE insert_item_end
#define DEQUEUE pop


int main(int argc, char *argv[])
{
	node * root = NULL;
	printf("Wstawiam elementy do kolejki\n");
	
	root = ENQUEUE( &root, 8);
	root = ENQUEUE( &root, 23);
	root = ENQUEUE( &root, 123);
	root = ENQUEUE( &root, 423);
	
	printf("Wypisuje elementy kolejki\n");
	print_list( root);
	
	printf("Usuwam elementy z kolejki\n");
	DEQUEUE( &root);
	DEQUEUE( &root);
	
	printf("Wypisuje elementy kolejki\n");
	print_list( root); 
	
	root = ENQUEUE( &root, 3);
	root = ENQUEUE( &root, 45);
	DEQUEUE( &root);
	
	printf("Wypisuje elementy kolejki\n");
	print_list( root); 
	
	return 0;
}
