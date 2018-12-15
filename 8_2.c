#include <stdio.h>
#include <stdlib.h>

// operacje na strukturze poprzez wskazniki


struct zxy{
	char znak;
	struct zxy * wsk;
};



int main()
{
	struct zxy a;
	struct zxy b;
	struct zxy c;
	
	a.wsk = & b;
	b.wsk = & c;
	c.wsk = & a;
	
	a.znak = 'a';
	a.wsk -> znak = 'b';
	a.wsk -> wsk -> znak = 'c';
	printf("\n%c %c %c\n", a.znak, b.znak, c.znak);
	
	printf("\n%c %c %c\n", b.wsk -> wsk -> znak, b.znak, b.wsk -> znak);
	
	c.znak = 'C';
	c.wsk -> znak = 'A';
	c.wsk -> wsk -> znak = 'B';
	printf("\n%c %c %c\n", a.znak, b.znak, c.znak);        
	                                            
	return 0;
}
