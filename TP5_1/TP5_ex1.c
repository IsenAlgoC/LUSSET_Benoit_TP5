#include <stdlib.h>
#include <stdio.h>
#include "tab.h"
#define TAILLE 10
#define TAB2SIZE 100


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
		return -1;
	}
	else{
		for (int i = 0; i < nbElts; i++) {
			printf("%d ", *(tab + i));
		}
	}

}

int remplirTab_1_a_20(int* tab, int size) {

	if (tab == NULL || size < 0 ) {
		return -1;
	}
	else {
		for (int i = 0;i < 20; i++) {
			*(tab + i) = i + 1;
		}
	}
}


int main() {

	int myTab1[TAILLE];
	
	int* myTab2 = NULL;
	int tabSize = TAB2SIZE;
	int nbElts = 0;
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));

	if (myTab2 != NULL) { 
		initTab(myTab2, tabSize);
		remplirTab_1_a_20(myTab2, tabSize); 
		for (int i = 0; i < 20; i++) {
			printf("%d ", *(myTab2 + i));
		}
	}
	else{ printf("Memoire insuffisante"); }

	free(myTab2);
}