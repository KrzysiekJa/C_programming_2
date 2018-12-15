#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int s_rekur(int a);
int s_iter(int a);


int main(int arg, char * argv[]){
	int (*wsk_rekur)(int a);
    wsk_rekur = s_rekur;
    int (*wsk_iter)(int b);
    wsk_iter = s_iter;
	int c;
	
	if(arg < 1){
		printf("Zle wywolanie funckcji. Przy wywolaniu nalezy podac liczbe oraz typ liczenia silni :)\n");
		exit(EXIT_FAILURE);
	}
	
	char s1[11] = "rekurencja" , s2[9] = "iteracja";
	if(strcmp(argv[2],s1) == 0){
		c = wsk_rekur( atoi( argv[1]));
	}
		
	if(strcmp(argv[2],s2) == 0){
		c = wsk_iter( atoi( argv[1]));
	} 
	
	printf("\n\n%d\n",c);
	
	return 0;
}


int s_rekur(int a){
	int b = 1;
		
	if(a == 0){
		return b;
	}
	else{
		printf("wartosc k = %d, adres k= %p\n", a, (void *)&a);
		b = a * s_rekur(a - 1);
		printf("wartosc k = %d, adres k= %p", a, (void *)&a);
		printf("wartosc wyn = %d, adres wyn= %p\n", b, (void *)&b);
	}
	
	return b;
}


int s_iter(int a){
	int w = 1;
	
	for(int i = 1; i <= a; i++){
		w *= i;
		printf("wartosc k = %d, adres k= %p", i, (void *)&i);
		printf("wartosc wyn = %d, adres wyn= %p\n", w, (void *)&w);
	}
	
	return w;
}
