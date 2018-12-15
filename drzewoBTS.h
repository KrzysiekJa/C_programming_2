#ifndef _TREE_H_
#define _TREE_H_
#include <stdio.h>
#include <stdlib.h>


#define zal( a, b) (a)>(b) ? (1) : (0)

typedef struct tnode
{
      int value;
      struct tnode * left;
      struct tnode * right;
      struct tnode * parent;
}node;


node * create_leaf(int war, node * root);

void add_leaf( int r, node ** tr, node * parent);

void print_tree_in_order( const node *tr);

void print_tree_post_order( const node *tr);

void free_tree( node *tr);

int tree_min( node *tr);

node * tree_max( node *tr);

node * search( node * tr, int war);

node * succesor( node * tr);


#endif
