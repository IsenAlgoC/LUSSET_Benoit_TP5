#include <stdlib.h>
#include <stdio.h>
#include "tab.h"
#define TAILLE 10
#define TAB2SIZE 100


int initTab(int* tab, int size) {										//initialise le tableau avec des 0

	if (tab == NULL || size < 0) { return -1; }
	else {
		for (int i = 0; i < size; i++) {
			*(tab + i) = 0;
		}
	}

}

int afficheTab(int* tab, int size, int nbElts) {						//Affiche les nbElts premiers termes du tableau

	if (tab == NULL || size < 0 || size < nbElts) {
		return -1;
	}
	else{
		for (int i = 0; i < nbElts; i++) {
			printf("%d ", *(tab + i));
		}
	}

}

int remplirTab_1_a_20(int* tab, int size,int* nbElts) {								//Remplis les 20 premier termes du tableau de 1 à 20

	if (tab == NULL || size < 0 ) {
		return -1;
	}
	else {
		for (int i = 0;i < 20; i++) {
			*(tab + i) = i + 1;
			*nbElts += 1;
		}
	}
}

int remplirTab_1_a_n(int* tab, int size, int *nbElts, int n) {						//Remplis les n premiers termes du tableau de 1 à n

	if (tab == NULL || size < 0) {
		return -1;
	}
	else {
		for (int i = 0; i < n; i++) {
			*(tab + i) = i + 1;
			*nbElts += 1;
		}
	}
}


//On ajoute un élément au tableau en augmentant sa taille si nécessaire. renvoie NULL si l'agrandissement échoue

int* ajouteElementDansTableau(int* tab, int* size, int* nbElts, int element) {

	if (tab == NULL || size < 0 || nbElts < 0) { return NULL; }
	
	else{
		if (*size == *nbElts) {
			*size += 1;
			int* tabSave = tab;
			tab = (int*)realloc(tab, *size * sizeof(int));
			if (tab == NULL) { tab = tabSave; return NULL; }
			*(tab + *nbElts) = element;
			*nbElts += 1;
			return tab;
		}
		else {
			*(tab + *nbElts) = element;
			*nbElts += 1;
			return tab;
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
		remplirTab_1_a_n(myTab2, tabSize, &nbElts,tabSize);						//On remplit le tableau entièrement (de 1 à 100)
		for (int i = 0; i < tabSize; i++) {
			printf("%d ", *(myTab2 + i));
		}

		printf("\n\n");
		
		ajouteElementDansTableau(myTab2, &tabSize, &nbElts, 101);				//On augmente la taille du tableau de 1 puis on ajoute 101
		for (int i = 0; i < tabSize; i++) {
			printf("%d ", *(myTab2 + i));
		}

		printf("\n\n");

		ajouteElementDansTableau(myTab2, &tabSize, &nbElts, 563);				//On augmente la taille du tableau de 1 puis on ajoute 563
		for (int i = 0; i < tabSize; i++) {
			printf("%d ", *(myTab2 + i));
		}


	}
	else{ printf("Memoire insuffisante"); }

	free(myTab2);
}