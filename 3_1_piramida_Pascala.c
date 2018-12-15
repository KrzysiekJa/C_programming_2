#include <stdio.h>
#include <stdlib.h>


int main(){
	int N;
	printf("Podaj wielkosc:");
	scanf("%d",&N);
	N = N + 2;
	
	int *tab1 = {0}, *tab2 = {0};
	tab1 = (int*) malloc(N * sizeof(*tab1));
	tab2 = (int*) malloc(N * sizeof(*tab2));

	tab1[1] = 1;
	
	for(int j = 1; j < N ; j++){
		
		for(int k = N-j; k > 0; k--)printf(" ");
		
		for(int i = 0; i < N; i++){
			tab2[i+1] = tab1[i+1] + tab1[i];
			if(tab1[i]>0){
				printf("%d ", tab1[i]);
			}
		}
		for(int k = N-j; k > 0; k--)printf(" ");
		
		printf("\n");
		for(int i = 1; i < N; i++){
			tab1[i] = tab2[i];
		}
	}
	
	return 0;
}
