#include <stdlib.h>
#include <stdio.h>
#include "tab.h"


TABLEAU newArray() {										//créé un tableau de taille TAILLEINITIALE qui renvoie NULL si allocation échouée

	TABLEAU tab;
	tab.size = TAILLEINITIALE;
	tab.eltsCount = 0;
	tab.elt = NULL;
	tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));
	initTab(tab.elt, tab.size);
	return tab;

}

int incrementArraySize(TABLEAU* tab, int incrementValue) {				//on augmente la taille du tableau de incrementValue

	if (tab->elt == NULL||tab->size<0) { return -1; }

	tab->size += incrementValue;
	return tab->size;

}

int setElement(TABLEAU* tab, int pos, int element) {

	if (tab->elt == NULL || tab->size <0 || pos<1) { return 0; }

	if (pos-1<tab->size) {
		*(tab->elt + pos - 1) = element;
		tab->eltsCount = max(pos, tab->eltsCount);
	}

	if (incrementArraySize(tab, pos - tab->size) != 1) {
		*(tab->elt + tab->size - 1) = element;
		tab->eltsCount = pos;
		return pos;												//renvoie la position telle que première valeur est position 1, sinon mettre return pos-1 pour avoir le vrai rang
	}

	return 0;

}

int main() {

	TABLEAU tab = newArray();

	printf("%d\n", tab.size);

	printf("%d\n", incrementArraySize(&tab, 2));

	printf("%d\n", setElement(&tab, 56, 32));

	

}