#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void suma (float t[], int n, float b[]); // zapisuje kolejno w tablicy : minimum, maksimum, 									 // srednia, maksymalne i minimalne odchylenie od sr
void bubble_s(float * t, int n, char z);


int main(){
	float a,c;
	float tab[10];
	srand(time(NULL));
	
	printf("Podaj I liczbe:");
	scanf("%f",&a);
	printf("Podaj II liczbe:");
	scanf("%f",&c);
	
	for(int i=0; i<10; i++){
		tab[i] = (rand() % (int)( c-a ))+a; //losowanie liczb miedzy a a c
	}
	
	printf("\nWylosowane liczby: \b");
	 for(int i=0; i<10; i++){
		printf(" %f", * (tab + i));
	 }
	printf("\n");

		
	float b[5]= {0};
	suma(tab, 10, b);
	
	printf("\nKolejno: minimum, maksimum, srednia, maksymalne i minimalne odchylenie od sredniej:");
	 for(int i=0; i<5; i++){
		printf(" %f", * (b + i));
	 }
	printf("\n");
	
	
	printf("\nCzy wyswietlac zawartosc tablicy po kazdej iteracji podczas sortowania h = [log2n]?");
	char z;
	float * t = &tab[0];
	scanf("%s",&z);
	bubble_s( t, 10, z);
	
	return 0;
}


void suma (float t[], int n, float b[]){
	
	float min = t[0], max = t[0];
	
	for( int i = 0; i < n; i++){
		b[0] += t[i];
		
		if(t[i] < min ){
			min = t[i];
		}
		if(t[i] > max ){ 
			max = t[i];
		}
	}

	b[0] = min;
	b[1] = max;
	b[2] = b[0]/n;
	b[3] = fabs(max -b[2]);
	b[4] = fabs(min -b[2]);

}


void bubble_s(float * t, int n, char z){
	float temp;
	int change;
	
	for(int i = 0; i < n-1; i++)
	{
		change = 0;
		for(int j = 0; j < n-1-i; j++){ 
			if( * (t+j) > * (t+j+1)){
				temp = * (t+j+1);
				* (t+j+1) = * (t+j);
				* (t+j) = temp;
				change = 1;
			}
		}
		if(!change) break;
		switch(z){
				case 'y': 
					for(int k=0; k<10; k++){
							printf(" %f", * (t+k));
	 				}
						
					printf("\n");
					break;
				case 'n': 
					break;
		}
	}
}
