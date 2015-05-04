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
//int * quicksort(int * array, int o);
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
    array=inserccion(array,1); //1 when is normal and 0 when is reverse
    //array=burbuja(array,1); //1 when is normal and 0 when is reverse
    //array=quicksort(array,0); //1 when is normal and 0 when is reverse
    //quicksort(array,0); //1 when is normal and 0 when is reverse
    print(array);
    getch();
}

/*****************************************************/

int * burbuja (int * array, int o) //en este método o función se reciben dos parámetros, uno que es la array a modificar y el otro que dice el tipo de orden que va manejar. Sea ascendente o descendente.
{
    int i,j,aux,mode; //Se declaran cuatro variables, i y j para contadores; aux para trabajar un intercambio y mode que es lo que decide si el se compara para orden descendente o descendente según la variable o.
    for(i=0;i<TAM;i++) //En estos bucles se comienza a comparar un elemento con todos.
    {
	for(j=0;j<TAM-1;j++) //En este bucle se verá la comparaciones de un elemento con otro.
	{
	    if(o) //Aquí se ve de que modo se ordenará.
	        mode=array[j] > array[j+1];
	    else
	        mode=array[j] < array[j+1];
	    if(mode) //Si se cumple la condición según sea el caso, el elemento actual se intercambiará con el siguiente.
	    {
		aux=array[j];
		array[j]=array[j+1];
		array[j+1]=aux;
	    }
	}
    } 
    return array;
}


int * inserccion(int * array, int o) //Lo mismo que en los demás métodos, se recibe un array (arreglo) y un indicador de la forma a ordenar.
{
    int i,j,m,elem,mode; 
    for (i=0;i<TAM-1;i++) //Muy similar al método burbuja, se comienza con un bucle principal.
    {
	m=i+1;
	elem=array[m]; //En esta parte del método, se utiliza una adaptación de insertar elementos en un arreglo, sin embargo hay condiciones.
	for (j=m;j>0;j--)
	{
	    if(o)
	        mode=elem < array[j-1];
	    else
	        mode=elem > array[j-1];
	    if (mode)
	    {
		array[j]=array[j-1]; //Dependiendo del caso, los elementos se correrán hacia la derecha y se ingresará el elemento de índice m.
		array[j-1]=elem;
	    }
	    else
		break; //Si no cumple la condición, se rompe con ese elemento y no se hace nada, procede al siguiente índice m.
	}
    }
    return array;
}

/************************************************/

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
