#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

/*
	Imprime la lisa
*/

static void print_dlist (const DList *dlist) {
	DListNode *node;
	int *data, i;
	//Imprime el tamaño de la lista
	fprintf(stdout, "List size is %d\n", dlist_size(dlist));

	i = 0;
	node=dlist_head(dlist);

	while (1) {
		data = dlist_data(node);
		// imprime el nodo, data, el puntero del nodo yy el puntero al siguiente nodo, asi como el anterior
		fprintf(stdout, "Dlist_node[%03d]=%03d, %p -> %p -> %p \n", i,*data, node->prev, node, node->next);
		
		i++;
		if (dlist_is_tail(node))
			break;
		else
			node =dlist_next(node);
	}

	return;
}
/*
	Programa principal
*/



int main (int argc, char **argv){
	DList dlist;
	DListNode *node;

	int *data, i;

	//Incializando la lista doble mente ligada
	dlist_init(&dlist, free);

	//LLenando la lista doblemente ligada
	node = dlist_head(&dlist);
	for (i = 30; i > 20; i--) {

		if ((data=(int *)malloc(sizeof(int))) == NULL){
			fprintf(stdout, "1");
			return 1;
		}

		*data = i;

		if (dlist_ins_next(&dlist, NULL, data) != 0)
			return 1;
	}

	print_dlist(&dlist);
/*
	//iniciando a navegar por la lista doblemente ligada
	node= dlist_head(&dlist);

	for (i - 0; i<7; ++i)
		node =dlist_next(node);

	data = dlist_data(node);
	//fprintf (stdout)


*/

	// Destruyendo la lista doblemente ligada
    fprintf(stdout, "\nDestroying the list\n");
    dlist_destroy(&dlist);
}