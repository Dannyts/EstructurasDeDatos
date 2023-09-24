#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 10 

int main(int argc, char * argv[])
{
	char *NumeroDeCuenta=argv[argc-1];
	int NumeroDeCuentaEnteros[strlen(NumeroDeCuenta)];
	int i,j;
	for(i=0;i<strlen(NumeroDeCuenta);i++)
	{
		NumeroDeCuentaEnteros[i]=NumeroDeCuenta[i]-'0';
		fprintf(stdout, "%d %c \n",NumeroDeCuentaEnteros[i],NumeroDeCuenta[i]);
	}
	int **mat=(int**)malloc(strlen(NumeroDeCuenta)*sizeof(int));
	for(j=0;j<strlen(NumeroDeCuenta);j++)
	{
		if(NumeroDeCuentaEnteros[j]==0)
			mat[j]=NULL;
		mat[j]=(int*)malloc((NumeroDeCuentaEnteros[j])*sizeof(int));
		
	}
	for(i=0;i<strlen(NumeroDeCuenta);i++)
	{
			if(NumeroDeCuentaEnteros[i]==0)
			{
				fprintf(stdout,"NULL");				
			}
			else if (NumeroDeCuentaEnteros[i]>0)
			{
				for(j=1;j<=NumeroDeCuentaEnteros[i];j++)
				{
						mat[i][j]=0;
						mat[i][j]=NumeroDeCuenta[i]-48;
						fprintf(stdout,"%d",mat[i][j]);
				}
			}
		fprintf(stdout,"\n");
	}
	for(i=0; i<strlen(NumeroDeCuenta);i++)
		free(mat[i]);
	free(mat);
	return 0;
}
