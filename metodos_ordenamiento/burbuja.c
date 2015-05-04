#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#define clrscr() system("clear")
#define getch() system("read")
#define TAM 0x06
//Limites o rango
#define LIMS 0x0A
#define LIMF 0x01
////////////////
//Metodos para ordenar//////////
int * burbuja(int * array,int o);
int * inserccion(int * array, int o);
///////////Quicksort////////////////
int * quicksort(int * array, int o);
//int cpivot(int len);
/////////////////////////////////////

///////////////////////////////
int * gen(int * array);
void print();
void main()
{
    int * array=malloc(TAM*sizeof(int));
    clrscr();
    array=gen(array); 
    print(array);
    //array=inserccion(array,1); //1 when is normal and 0 when is reverse
    //array=burbuja(array,1); //1 when is normal and 0 when is reverse
    //array=quicksort(array,1); //1 when is normal and 0 when is reverse
    //print(array);
    //array=inserccion(array,0); //1 when is normal and 0 when is reverse
    //array=burbuja(array,0); //1 when is normal and 0 when is reverse
    array=quicksort(array,0); //1 when is normal and 0 when is reverse
    //quicksort(array,0); //1 when is normal and 0 when is reverse
    //print(array);
    getch();
}
int * burbuja (int * array, int o)
{
    int i,j,aux,mode;
    for(i=0;i<TAM;i++)
    {
	for(j=0;j<TAM-1;j++)
	{
	    if(o)
	        mode=array[j] > array[j+1];
	    else
	        mode=array[j] < array[j+1];
	    if(mode)
	    {
		aux=array[j];
		array[j]=array[j+1];
		array[j+1]=aux;
	    }
	    //print(array); 
	}
    }
    return array;
}
int * inserccion(int * array, int o)
{
    int i,j,m,elem,mode;
    for (i=0;i<TAM-1;i++)
    {
	m=i+1;
	elem=array[m];
	for (j=m;j>0;j--)
	{
	    if(o)
	        mode=elem < array[j-1];
	    else
	        mode=elem > array[j-1];
	    if (mode)
	    {
		array[j]=array[j-1];
		array[j-1]=elem;
	    }
	    else
		break;
	//printf("elem: %d; ",elem); print(array); 
	}
    }
    return array;
}
/*//Quicksort method////////////////
int * quicksort(int * array, int o)
{
    int ipivot=
    
}*/
/*int cpivot(int len)
{
    int pivot;
    srand(time(NULL));
    pivot=1+rand()%((len+1)-1);  
    return pivot;  
}*/
//////////////////////////////////
//Generador de Array
int * gen(int * array)
{
    int i,j,val,igual;
    srand(time(NULL));
    for(i=0;i<TAM;i++)
    {
    	 array[i]=LIMF+rand()%((LIMS+1)-LIMF);
    }
    //print(array); //Esto esta para posible eliminación
    /*//Verificar si se repiten los elementos
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
    	 	    array[i]=LIMF+rand()%((LIMS+1)-LIMF);
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
    } while(igual);*/
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
