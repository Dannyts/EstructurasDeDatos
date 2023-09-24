#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10
#define m 10

//primero llenamos la matriz con numeros aleatorios entre 0 y 10
int LLM(int Mat[n][m], int c, int f)
{
	srand(time(NULL));
	for(int i=0;i<f;i++)
		for(int j=0;j<c;j++)
			Mat[i][j]=rand()%10;
}
//por fines de hacer mas facil la revision, imprimiremos la matriz de forma "normal"
int IN(int Mat[n][m],int c, int f)
{
	fprintf(stdout,"Matriz original\n");
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
			fprintf(stdout," %d ", Mat[i][j]);
		fprintf(stdout,"\n");
	}
}
//La primera impresion sera empezando por la entrada (1,m) recorriendo de a uno
//hasta (1,1) y asi sucesivamente hasta llegar a la fila
//(n,m) hasta (n,1)
void IDIB(int Mat[n][m], int c, int f)
{
	int cent=0;
	fprintf(stdout,"Primera impresion \n");
	//el ciclo for hace que la impresion inicie por el elemento (1,n),
	//es decir el elemento superior derecho
	for(int i=0;i<f;i++)
		for(int j=c-1;j>=0;j--)
		{
			//agregamos un centinela para que la impresion de los terminos sea mas legible
			cent++;
			if(cent==20)
			{
				fprintf(stdout," %d \n",Mat[i][j]);
				cent=0;
			}
			else
				fprintf(stdout," %d ",Mat[i][j]);
		}
}
//La segunda impresion se hara del elemento (n,m) de la matriz
//hasta el elemento (1,m) y recorriendo columnas hacia la izquierda
//hasta la columna qe va de (n,1) a (1,1) 
void IAAI(int mat[n][m], int c, int f)
{
	int cent=0;
	fprintf(stdout,"\nSegunda impresion\n");
	//el ciclo for hace que inicie la impresion por el termino (n,n),
	//es decir la esquina inferior derecha
	for(int j=c-1;j>=0;j--)
		for(int i=f-1;i>=0;i--)
		{
			//agregamos un centinela para que la impresion de los terminos sea mas legible
			cent++;
			if(cent==20)
			{
				fprintf(stdout," %d \n",mat[i][j]);
				cent=0;
			}
			else
				fprintf(stdout," %d ",mat[i][j]);
		}
}
//para la 3ra impresion, solo se mostraran los elementos de la diagonal
void ID(int Mat[n][m], int c,int f)
{
	fprintf(stdout,"\nTercera impresion\n");
	//busca la dimension mas pequeña de ambas
	if(f>c)
	{
	//de ser la primera entrada la mas pequeña la usa de referencia para buscar la diagonal
	//que seran la misma cantidad que el valor de dicha dimension
	for(int i=0;i<c;i++)
		fprintf(stdout," %d ", Mat[i][i]);
	}
	else
	//en caso contrario o si se trata de una matriz cuadrada
	//se ara uso de este ciclo for
		for(int j=0;j<f;j++)
			fprintf(stdout," %d ",Mat[j][j]);
	fprintf(stdout,"\n");
}
//la funcion main para usar todas las funciones
int main(int argc, char *argv[])
{
	int I=atoi(argv[1]), J=atoi(argv[2]);
	int Mat[n][m];
	if(I<=10 && J<=10)
	{
		LLM(Mat,I,J);
		IN(Mat,I,J);
		IDIB(Mat,I,J);
		IAAI(Mat,I,J);
		ID(Mat,I,J);
	}
	else
		fprintf(stdout,"Error, dimensiones excedidas");
	return 0;
}
