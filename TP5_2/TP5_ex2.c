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

int displayElements(TABLEAU* tab, int startPos, int endPos) {
	if (tab->elt == NULL ||  startPos < 0 || endPos<0) { return 0; }

	if (endPos < startPos) {
		int buffer = endPos;
		endPos = startPos;
		startPos = buffer;
	}

	for (int i = startPos-1; i <= endPos-1; i++) {				//On reste sur l'hypothèse selon laquelle le 1er élément est à la position 1
		printf("%d ", *(tab->elt + i));
	}
	return 0;
}

int main() {

	TABLEAU tab = newArray();

	printf("%d\n", tab.size);

	printf("%d\n", incrementArraySize(&tab, 2));

	printf("%d\n", setElement(&tab, 56, 32));				//Va inclure 32 au rang 56 (en supposant que la première valeur est au rang 1)

	for (int i = 0; i < 100; i++) {
		printf("%d ", *(tab.elt + i));
	}

	printf("\n");

	displayElements(&tab, 54, 58);			//va donner du rang 54 au rang 58 (où le premier élément est au rang 1)

}