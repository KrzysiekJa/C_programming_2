#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// program porzadkuje liste osob we wczytywanym pliku, zwracajac ja w nowym pliku


struct klient{
		char imie[20]; 
		char nazwisko[32];
		char kod_pocztowy[10];
		int wiek;
	};
	
int imie( const void *n1, const void *n2){
	return strcmp(((struct klient *) n1) -> imie,((struct klient *) n2) -> imie);
}

int nazwisko( const void *n1, const void *n2){
	int a = *(char *) n1;
	int b = *(char *) n2;
	const void * tab[10] = { n1, n2};
	
	if( a < b){
		return -1;
	}
	else{
		if( a == b){
			qsort(tab, 2, sizeof(struct klient),imie);
			return 0;
		}
		else{
			return 1;
		}
	}
}


	
int main(){
	
	struct klient tab[5];
	FILE *plik = fopen("klient.txt","r");
	
	
	for(int i = 0; i < 5; i++){
		fscanf(plik,"%s",tab[i].imie);
		fscanf(plik,"%s",tab[i].nazwisko);
		fscanf(plik,"%s",tab[i].kod_pocztowy);
		fscanf(plik,"%d",&tab[i].wiek);
	}
	
	
	qsort(tab, 5, sizeof(struct klient),nazwisko);
	for(int i = 0; i < 5; i++){
		printf("%s ",tab[i].imie);
		printf("%s ",tab[i].nazwisko);
		printf("%s ",tab[i].kod_pocztowy);
		printf("%d ",tab[i].wiek);
		printf("\n");
	}
	printf("\n");
	
	
	fclose(plik);
	
	return 0;
}
