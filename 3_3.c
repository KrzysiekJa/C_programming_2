#include <stdio.h>
#include <time.h>
#include <stdlib.h>


const int H = 5; 
const int W = 5;
void srednie (float * p, int t[H][W]); //liczy srednie dla wierszy




int main ()
{
	int tab[H][W];
	srand(time(NULL));
	float sw[H] = {0};
	float sk[W] = {0};
	
	
	for(int i=0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			tab[i][j] = rand() % 21 + 10; //wypelnia macierz
			printf(" %d", tab[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	
	
	srednie(&sw[0], &tab[0][0]); // srednie dla wierszy
	
	printf("Wartosci srednie kolejno z wierszy:\n");

	for(int i = 0; i < H; i++) {
		printf("%3.4f ", sw[i]);
    }
	printf("\n\n");
	
	
	
	
	for(int i = 0; i < H; i++){
		for(int j = i; j < W; j++){
			int temp;
			temp = tab[i][j];
			tab[i][j] = tab[j][i]; //traspozycja macierzy
			tab[j][i] = temp;
		}
	}
	
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++){
            printf(" %d", tab[i][j]);
        }
		printf("\n");
	}
	printf("\n");
	
	
	
	
	srednie (&sk[0], &tab[0][0]); // srednie dla kolumn
	
	printf("Wartosci srednie kolejno z kolumn:\n");
	
	for(int i = 0; i < H; i++) {
		printf("%3.4f ", sk[i]);
    }
	printf("\n");
	
	
	return EXIT_SUCCESS;
}




void srednie (float * p, int t[H][W]){
	
	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			
			p[i] += t[i][j]; // sumowanie elementow macierzy
		}
	}
	
	for (int i = 0; i < H; ++i){
		
		p[i] = p[i] / H; // wyliczanie sredniej
	}
}
