#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int N;
	
	printf("Prosze podac wielkosc: ");
	scanf("%d", &N);
	if(N > 100000){
		printf("Za duza wielkosc.");
		exit(EXIT_FAILURE);
	}
	
	
	int tab[N];
	for(int i = 0; i < N; i++){
		tab[i] = 0;
	}
	int b =  sqrt(N);
	tab[0] = tab[1] = 1;
	for(int i = 2; i < b; i++){
			int j = 2;
			while( i * j < N){
				int a = i * j;
				tab[a] = 1;
				j++;
			}

	}
	
	for(int i = 2; i < N; i++){
		if(tab[i] == 0){
			printf("%d ", i);
		}
	}
	printf("\n ");
	
	
	return 0;
}
