#include <stdlib.h>
#include <stdio.h>

/**
	Reading and writing data
 */
void read_data( FILE *datain, int **dataout, int *n, int *k ) {
	int *data;
	
	fscanf(datain, "%d", n);
	fscanf(datain, "%d", k);
	*dataout = (int *)malloc( (*n) * sizeof(int) );
	data=*dataout;
	
	for ( int i=0; i< *n; ++i, ++data )
		fscanf( datain, "%d", data );
}

void print_data(int *tableau, int taille) {
        for( int i=0; i<taille; ++i)
		printf( "%d ", tableau[i] );
	printf("\n");
}
		
/* écrire une fonction qui traite un tableau*/

int main( int argc, char **argv ) {
	int *data;
	int n, k;
	FILE *f_in;
 
	if ( argc > 1 )
		f_in = fopen(argv[1], "r");
	else
		f_in = stdin;
	
	/* lecture des donnees */
	read_data( f_in, &data, &n, &k );

	/* affichage du tableau lu */
	print_data(data,n);
	
	/* utiliser une fonction qui modifie data*/

	/* output result. */
        /* à écrire */ 
	 free(data);
	return 0;
}


