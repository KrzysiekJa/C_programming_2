#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float suma (float * TAB, int n, int l);


int main(void){
	srand(time(NULL));
	float T_1[4], T_2[6], T_3[3], T_4[2], T_5[4];
	
	
	for(int i=0; i < 6; i++){		// generacja tablic
		T_2[i] = (rand()% 100) / (float)10;
		if( i < 4){
			T_1[i] = (rand()% 100) / (float)10;
			T_5[i] = (rand()% 100) / (float)10;
		}
		if( i < 3){
			T_3[i] = (rand()% 100) / (float)10;
		}
		if( i < 2){
			T_4[i] = (rand()% 100) / (float)10;
		}
	}
	
	float * TAB[5] = {T_1, T_2, T_3, T_4, T_5};		// tablica wskaznikow
	
	for( int i = 0; i < 6; i++){	// wypisanie wybranych tablic
		printf("%f ",T_2[i]);
	}
	printf("\n");
	
	for( int i = 0; i < 4; i++){ 
		printf("%f ",T_5[i]);
	}
	printf("\n\nTablica wskaznikow:\n");
	
	for( int i = 0; i < 5; i++){	// wypisanie tablicy wskaznikow
		printf("%f ", * TAB[i]);
	}
	printf("\n");
	
	
	float a = suma( TAB[1], 2, sizeof(T_2)/sizeof(float));// operacje przez tablice wskaznikow
	printf("Suma elementow z 2 tablicy: %f\n", a);
	
	float b = suma( TAB[4], 5, sizeof(T_5)/sizeof(float));
	printf("Suma elementow z 5 tablicy: %f\n", b);
	
	return 0;
}



float suma (float * TAB, int n, int l){
	
	float s = 0;
	for( float *i = TAB; i < TAB + l; i++){
			s += *i;
		}

		return s;
}
