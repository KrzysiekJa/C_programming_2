#include "drzewoBTS.h"
// popatrzyc na strukture kompilacji do makefile

int main(){
	int tab[12]={15,5,16,20,3,12,18,23,10,13,6,7};
	node * root = NULL;
	
	
	for( int i = 0; i < 12; i++){
		add_leaf( tab[i], &root, NULL);
	}
	
	
	print_tree_in_order( root);
	
	print_tree_post_order( root);
	
	printf("\nMinimum: %d\n", tree_min( root));
	
	node * x = tree_max( root);
	printf("Maksimum: %d\n\n", x ->value);
	
	
	for( int i = 0; i < 13; i++){
		node * temp = search(root, i);
		if( temp){
			printf("%d znaleziono pod adresem: %p\n", i, temp);
		}
	}
	
	
	for( int i = 0; i < 12; i++){
		node * temp = search( root, tab[i]);
		node * y = succesor( temp);
		printf("Poprzednikiem %d jest %d pod adresem: %p", tab[i], y -> value, y);
	}
	
	
	free_tree( root);
	
	
	return 0;
}
