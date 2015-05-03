#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#define clrscr() system("clear")
#define getch() system("read")
#define TAM 0x0A
//Limites o rango
#define LIMS 0x4A
#define LIMF 0x01
//Metodos para ordenar//////////
///////////Quicksort///////////////////////////////////
void quicksort(int * array,int prin, int fin,  int o);
int particionar(int * array,int ipiv,int prin, int fini,int o);
void swap(int* array, int num1, int num2);
///////////////////////////////////////////////////////
int * gen(int * array);
void print();
void main()
{
    int * array=malloc(TAM*sizeof(int));
    srand(time(NULL));
    clrscr(); 
    array=gen(array); 
    print(array);
    quicksort(array,0,TAM-1,1); //1 when is normal and 0 when is reverse
    print(array);
    array=gen(array); 
    print(array);
    quicksort(array,0,TAM-1,1); //1 when is normal and 0 when is reverse
    print(array);
    getch();

}
void quicksort(int * array,int prin, int fin,  int o)
{
    int ipiv=fin,pix;
    if (prin<fin)
    {
    	pix=particionar(array,ipiv,prin,fin,o);
	quicksort(array,prin,pix-1,o);
	quicksort(array,pix+1,fin,o);
    }
}
int particionar(int * array,int ipiv,int prin, int fin,int o)
{
    int i,pix,mode;
    pix=prin;
    for (i=prin;i<fin;i++)
    {
	if (o)
	    mode=array[i] <= array[ipiv];
	else
	    mode=array[i] >= array[ipiv];	
	if (mode)
	{
	     swap(array,i,pix);
	     pix++;
	}
    }
    swap(array,pix,fin);
    return pix;
}
void swap(int *array, int num1, int num2)
{
    int aux;
    aux=array[num1];
    array[num1]=array[num2];
    array[num2]=aux;
}
//Generador de Array
int * gen(int * array)
{
    int i,j,val,igual;
    for(i=0;i<TAM;i++)
    {
    	 array[i]=LIMF+rand()%((LIMS+1)-LIMF);
    }
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
