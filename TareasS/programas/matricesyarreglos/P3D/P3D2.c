#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 10

int main (int argc, char *argv[])
{
	char *Num=argv[1];
	int digito;
	int **jarray=(int**) malloc (strlen(Num)*sizeof(int));
	for(int i=0; i< strlen(Num);i++){
		digito=Num[i]-'0';
		fprintf(stdout,"[%d}->",digito);
		if(digito==0){

			jarray[i]= NULL;
			fprintf(stdout,"NULL \n");
		}
		else {
			jarray[i]=(int*)malloc(digito*sizeof(int));
			for (int j=0;j<digito;j++){

				jarray[i][j]=digito;
				fprintf(stdout,"|%d",jarray[i][j]);
			}
			fprintf(stdout,"|\n");
		}
	}
	for (int i=0;i<strlen(Num);i++)
		free(jarray[i]);
	free(jarray);
	return 0;

}
