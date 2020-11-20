#include <stdlib.h>
#include <stdio.h>
#include "tab.h"
#define TAILLE 10


int initTab(int* tab, int size) {

	if (tab == NULL || size < 0) { return -1; }
	else {
		for (int i = 0; i < size; i++) {
			*(tab + i) = 0;
		}
	}

}

int afficheTab(int* tab, int size, int nbElts) {

	if (tab == NULL || size < 0 || size < nbElts) {
		printf("-1");									 //affiche -1 car avec un return -1;, la console n'affiche rien.
	}
	else{
		for (int i = 0; i < nbElts; i++) {
			printf("%d ", *(tab + i));
		}
	}

}


int main() {

	int myTab1[TAILLE];
	initTab(myTab1, TAILLE);
	afficheTab(myTab1, TAILLE, 12);

}