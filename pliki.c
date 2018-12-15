#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10

int main(void)
{
	int tab[SIZE];
	int i,y;
	FILE *fp;
	
	srand(time(NULL));
	
	for(i=0;i<SIZE;i++)
		tab[i] = rand()%200;
	
	
	fp = fopen("dane.dat","w");	  // tworzenie pliku
	
	if(fp==NULL)
	{
		printf("BLAD\n");
		exit(-1);
	}
	
	for(i=0;i<SIZE;i++)
		fprintf(fp,"%d) %d\n",i,tab[i]);   // tworzy dane.dat
	
	fclose(fp); // zamyka plik dane.dat
	
	fp = fopen("dane.dat","r");  // otwiera dane.dat dla odczytu
	
	if(fp==NULL)
	{
		printf("BLAD\n");
		exit(-1);
	}
	
	for (i = 0;i<SIZE;i++)  // output na ekran
	{
		fscanf(fp,"%d) %d",&tab[i],&y);
		printf("tab[%d] = %d\n",tab[i],y);
	}
	return 0;
}
