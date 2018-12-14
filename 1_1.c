#include<stdio.h>
#include<ctype.h>
// program liczy samogloski poszczegolne, sumarycznie, spolgloski, wyrazy


int main(void){
	

  char tekst[] = "Ile i które z samoglosek znajdziesz w tym zdaniu ?";
  int x=sizeof(tekst)/sizeof(char);
  int k=0, l=0;
  int tab[7]= {0};
	  
  while( k < x){
	  
	  if (isalpha(tekst[k])) l++;
	  
  	switch(tekst[k]){
  		case 'a':tab[0]++;
			break;
	  	case 'e':tab[1]++;
			break;
	  	case 'i':tab[2]++;
			break;
	  	case 'o':tab[3]++;
			break;
	  	case 'u':tab[4]++;
			break;
	  	case 'y':tab[5]++;
			break;
		case ' ':tab[6]++;
			break;
		default: break;
  	}
	
	k++;
	}
	
	char samo[]="aeiouy";
	int sam = 0, spl;
	
  for(int i=0; i < sizeof(samo)/sizeof(char) - 1 ; i++){
	  
          printf("%c -> %d razy\n", samo[i], tab[i]);
		  sam= sam + tab[i];
	  }
  
	  spl= l - sam;
  printf("Samogloski -> %d razy\n", sam);
  printf("Spolgloski -> %d razy\n", spl);
  printf("Wyrazy -> %d \n", tab[6]+1);
  
  return 0;
}
