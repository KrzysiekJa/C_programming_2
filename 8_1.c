#include <stdio.h>
#include <stdlib.h>

// program liczy sume wektorow, ich iloczyn skalarny, wektorowy

struct wektor{
	float x;
	float y;
	float z;
};

struct wektor suma_w(struct wektor w1, struct wektor w2);

void iloczyn_s(struct wektor w1, struct wektor w2, double * iloczyn);

void iloczyn_w(struct wektor w1, struct wektor w2, struct wektor * multi);



int main()
{
	struct wektor w;
	struct wektor v;
	
	
	printf("\nPodaj współrzedne wektora w :");
	scanf("%f", &w.x);
	scanf("%f", &w.y);
	scanf("%f", &w.z);
	
	printf("\nPodaj współrzedne wektora v :");
	scanf("%f", &v.x);
	scanf("%f", &v.y);
	scanf("%f", &v.z);
	
	printf("\nw = [%f, %f, %f] v = [%f, %f, %f]\n", w.x, w.y, w.z, v.x, v.y, v.z);
	printf("\nIch suma: [%f % f %f]\n", suma_w(w,v).x, suma_w(w,v).y, suma_w(w,v).z);
	
	double iloczyn;
	iloczyn_s( w, v,& iloczyn);
	printf("Ich iloczyn skalarny: %f\n", iloczyn);
	
	struct wektor multi;
	iloczyn_w( w, v, & multi);
	printf("\nIch iloczyn wektorowy: [%f % f %f]\n", multi.x, multi.y, multi.z);
		
	
	return 0;
}



struct wektor suma_w(struct wektor w1, struct wektor w2){
	struct wektor w_sumy;
	
	w_sumy.x = w1.x + w2.x;
	w_sumy.y = w1.y + w2.y;
	w_sumy.z = w1.z + w2.z;
	
	return w_sumy;
}


void iloczyn_s(struct wektor w1, struct wektor w2, double * iloczyn){
	
	* iloczyn = w1.x * w2.x + w1.y * w2.y + w1.z * w2.z;
	
}


void iloczyn_w(struct wektor w1, struct wektor w2, struct wektor * multi){
	
	multi -> x = w1.y * w2.z - w1.z * w2.y;
	multi -> y = w1.z * w2.x - w1.x * w2.z;
	multi -> z = w1.x * w2.y - w1.y * w2.x;

}
