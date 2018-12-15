#include "drzewoBTS.h"


node * create_leaf(int war, node * root){
	node * t = malloc(sizeof(node));
	
	if( !t){
		printf("Brak pamieci!\n");
		return NULL;
	}
	
	t ->value = war;
	t ->left = t ->right = NULL;
	t ->parent = root;
	
	return t;
}

void add_leaf( int r, node ** tr, node * parent){
	if(*tr){
		if( zal((*tr) ->value, r)){
			add_leaf( r, &( *tr) ->left, *tr);
		}
		else{
			add_leaf( r, &( *tr) ->right, *tr);
		}
	}
	else{
		* tr = create_leaf( r, parent);
	}
}

void print_tree_in_order( const node *tr){
	if(tr){
		print_tree_in_order( tr ->left);
		
		printf("adress: %p, key: %d, left -> %p, right -> %p, parent -> %p\n", tr, tr ->value, tr ->left, tr ->right, tr ->parent);
		
		print_tree_in_order( tr ->right);
	}
}

void print_tree_post_order( const node *tr){
	if(tr){
		print_tree_post_order( tr ->right);
		
		printf("adress: %p, key: %d, left -> %p, right -> %p, parent -> %p\n", tr, tr ->value, tr ->left, tr ->right, tr ->parent);
		
		print_tree_post_order( tr ->left);
	}
}

void free_tree( node *tr){
	
	if( tr == NULL) {
	    return;
	}
	    free_tree( tr ->left);
	    free_tree( tr ->right);
	    free(tr);
}

int tree_min( node *tr){ 
	while( tr -> left != NULL){
		tr = tr ->left; 
	}
	
	return tr ->value;
}

node * tree_max( node *tr){
	if( tr == NULL){
		return tr;
	}
	if( tr ->right == NULL){
		return tr;
	}
	
	return tree_max( tr ->right);
}

node * search( node * tr, int war){
	while( tr && war != tr ->value){
		if( war < tr ->value){
			tr = tr ->left;
		}
		else{
			tr = tr ->right;
		}
	}
	return tr;
}

node * succesor( node * tr){
	if( tr ->right ){
		int a = tree_min( tr ->right);
		return search( tr, a);
	}
	
	node * y = tr ->parent;
	
	while( y && tr == y ->right){
		tr = y;
		y = y ->parent;
	}
	
	return y;
}
