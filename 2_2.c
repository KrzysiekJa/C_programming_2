#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N1 15
#define N2 20

void bubble_s(float * t, int n);
void zamiana(float * t, int a, int b); // zamienia wartosci o pozycjach a i b w tablicy
void odwroci(float * t, int n);        // dokonuje odwrocenia tablicy


int main(void){
	srand(time(NULL));
	float n1[N1], n2[N2];
	
	
	for(int i = 0; i < N1; i++){
		n1[i] = (rand()% 100)/(float)100;
	}
	
	for(int i = 0; i < N2; i++){
		n2[i] = (rand()% 100)/(float)100;
	}
	
	bubble_s(n1, N1);
	bubble_s(n2, N2);
	
	
	zamiana(n1, 9, 14);
	printf("\n");
	
	odwroci(n2, N2);
	printf("\n");
	for(int k=0; k<N2; k++){
		printf("%f ", n2[k]);
	}
	printf("\n");
	
	
	
	return 0;
}



void bubble_s(float * t, int n){
	int change;
	
	for(int i = 0; i < n-1; i++)
	{
		change = 0;
		for(int j = 0; j < n-1-i; j++){ 
			if( * (t+j) > * (t+j+1)){
				float temp = * (t+j+1);
				* (t+j+1) = * (t+j);
				* (t+j) = temp;
				change = 1;
			}
		}
		if(!change){
			break;
		}
	}
	for(int k=0; k<n; k++){
		printf("%f ", * (t+k));
	}
	printf("\n\n");
}


void zamiana(float * t, int a, int b){
	
	printf("Wyrazy przed zamiana:\n %d. %f \n %d. %f \n", a, * (t+a-1), b, * (t+b-1));
	
	float temp = * (t+a-1);
	* (t+a-1) = * (t+b-1);
	* (t+b-1) = temp;
	
	printf("Wyrazy po zamiana:\n %d. %f \n %d. %f \n", a, * (t+a-1), b, * (t+b-1));
	
}


void odwroci(float * t, int n){
	
	
	for(int i = 1; i <= ceil( n / (float)2); i++){
		zamiana( t, i, n - i + 1);
	}
	
}
