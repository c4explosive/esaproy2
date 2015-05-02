#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#define clrscr() system("clear")
#define getch() system("read")
#define TAM 10
//Metodos para ordenar//////////
int * burbuja(int * array);
int * inserccion(int * array);

///////////////////////////////
int * gen(int * array);
void print();
void main()
{
    int * array=malloc(TAM*sizeof(int));
    array=gen(array);
    print(array);
    array=burbuja(array);
    print(array);
}
int * burbuja (int * array)
{
    int i,j,aux;
    for(i=0;i<TAM;i++)
    {
	for(j=0;j<TAM-1;j++)
	{
	    if(array[j]>array[j+1])
	    {
		aux=array[j];
		array[j]=array[j+1];
		array[j+1]=aux;
	    }
	}
    }
    return array;
}
int * inserccion()
{

}

//Generador de Array
int * gen(int * array)
{
    int i,j,val,igual;
    srand(time(NULL));
    for(i=0;i<TAM;i++)
    {
    	 array[i]=1+rand()%((TAM+1)-1);
    }
    //Verificar si se repiten los elementos
    do
    {
    	for (i=0;i<TAM;i++)
    	{
	    for (j=0;j<TAM;j++)
	    {
		if (array[i]==array[j] && (i != j) )
		{
		    igual=1;
		    //printf("P:%d; true %d || %d; ",i,array[i],array[j]);
    		    array[i]=1+rand()%((TAM+1)-1);
		    //printf("replaced by: %d\n",array[i]);
		    i=0; j=0;
		    break;
		}
		else
		{
		    igual=0;
		}
	    }
    	}
    } while(igual);
    return array;
}
//Metodo para imprimir
void print(int * array)
{
    int i;
    printf("[");
    for(i=0;i<TAM;i++)
    {
	printf("%d,",array[i]);
    }
    printf("\b]\n");
}
