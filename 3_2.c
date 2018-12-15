#include <stdio.h>

void swap(int *x, int *y);


int main(){					//program porzadkuje ciag 3 liczb
	int a = 15, b = 6, c = 3;
	
	printf("1. a = %d, b = %d, c = %d\n", a, b, c); 
	if(a > b){ 
		swap(&a,&b);
		printf("2. a = %d, b = %d, c = %d\n", a, b, c);
	}
	if (b > c){ 
		swap(&b,&c);
	if(a > b){ 
		swap(&a,&b);
	}
	printf("3. a = %d, b = %d, c = %d\n", a, b, c); }
	else {
	printf("4. a = %d, b = %d, c = %d\n", a, b, c); }
	
	return 0;
}


void swap(int *x, int *y){
	int temp;
	
	temp = *x;
	*x   = *y;
	*y   = temp;
}
