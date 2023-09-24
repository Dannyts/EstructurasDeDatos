#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 10

int LecturaeImpresion(int vec[n])
{
	for(int i =0;i<n;i++)
	{
		vec[i]=(i+1)*2;
		fprintf(stdout,"%d ",vec[i]);
	}
	fprintf(stdout,"\n");
}

int Reemplazar(int vec[n],int indice)
{
	vec[indice-1]=-1;
	for(int i=0;i<n;i++)
		fprintf(stdout,"%d ",vec[i]);
	fprintf(stdout,"\n");
}
int main (int argc,char * argv[])
{
	char *NUMC=argv[argc-1];
	int indice,vec[n];
	for( int i=0;i<=strlen(argv[argc-1]);i++)
	{
		if(i==strlen(NUMC))
			indice=NUMC[i-1]-'0';
	}	
	LecturaeImpresion(vec);
	Reemplazar(vec,indice);
	return 0;
}	


