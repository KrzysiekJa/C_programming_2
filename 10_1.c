#include <stdio.h>
#include <stdlib.h>

// lista jednokierunkowa


typedef struct tnode{
	int value;
	struct tnode * next;
} node;


node * dodaj_na_poczatek( node * head, int val);

void dodaj_na_koniec(node ** head, int val);

void wypisz_liste( const node * ilosc);

node * wstawianie_sortowanie( node * head, int klucz);

void * zwolnij_pamiec( node * head);



int main()
{	
	node * head = dodaj_na_poczatek( NULL, 23);
		head = dodaj_na_poczatek( head, 13);
		head = dodaj_na_poczatek( head, 67);
		head = dodaj_na_poczatek( head, 3);
		head = dodaj_na_poczatek( head, 123);
	
		wypisz_liste( head);
		printf("\n");
		
		dodaj_na_koniec(& head, 22);
		
		wypisz_liste( head);
		printf("\n");
		
		zwolnij_pamiec( head);
		
		wstawianie_sortowanie( head, 23);
		wstawianie_sortowanie( head, 13);
		wstawianie_sortowanie( head, 67);
		wstawianie_sortowanie( head, 3);
		wstawianie_sortowanie( head, 123);
		
		wypisz_liste( head);
		printf("\n");
	
		zwolnij_pamiec( head);
		
	return 0;
}



node * dodaj_na_poczatek( node * head, int val){
	node * tmp = malloc( sizeof( node));
	
	if ( !tmp){
		printf( "Blad alokacji!\n");
		return head;
	}
	
	tmp -> value = val;
	tmp -> next = head;
	return tmp;
}


void dodaj_na_koniec(node ** head, int val){
	node * tmp = malloc( sizeof( node));
	
	if( ! tmp){
		printf( "Blad alokacji!\n");
		return;
	}
	
	tmp -> value = val;
	tmp -> next = NULL;
	
	if( * head){
		node * ilosc  = * head;
		for(; ilosc -> next; ilosc = ilosc -> next);
		
		ilosc -> next = tmp;
	}
	else{
		* head = tmp;
	}
}


void wypisz_liste( const node * ilosc){
	
	if( !ilosc){
		printf("Lista jest pusta.\n");
		return;
	}
	
	for(; ilosc; ilosc = ilosc -> next){
		printf("(%p) -> %d, next: %p\n", ilosc, ilosc -> value, ilosc -> next);
	}
}


node * wstawianie_sortowanie( node * head, int klucz){
	node * ilosc = malloc( sizeof( node));
	
	if( !ilosc){
		printf( "Blad alokacji!\n");
		return head;
	}
	
	ilosc -> value = klucz;
	ilosc -> next = NULL;
	
	if( head){
		if( head -> value > klucz){
			ilosc -> next = head;
			head = ilosc;
		}
		else{
			node * tmp = head;
			for(; tmp -> next && tmp -> next -> value < klucz; tmp = tmp -> next);
			ilosc -> next = tmp -> next;
			tmp -> next = ilosc;
		}
	}
	else{
		head = ilosc;
	}
	
	return head;
}


void * zwolnij_pamiec( node * head)
{
	if ( !head){
		printf( "Blad!\n");
		head -> value = 0;
		head -> next = NULL;
	}
	
	if( head){
		node * ilosc = head;
		for(; ilosc -> next; ilosc = ilosc -> next){
			free(head);
		}
		head -> value = 0;
		head -> next = NULL;
	}
}
