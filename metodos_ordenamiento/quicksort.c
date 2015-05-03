#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#define clrscr() system("clear")
#define getch() system("read")
#define TAM 0x06
//Limites o rango
#define LIMS 0x0A
#define LIMF 0x01
//Metodos para ordenar//////////
///////////Quicksort////////////////
int * quicksort(int * array, int o);
/////////////////////////////////////
int * gen(int * array);
void print();
void main()
{
    int * array=malloc(TAM*sizeof(int));
    clrscr();
    array=gen(array); 
    print(array);
    array=quicksort(array,0); //1 when is normal and 0 when is reverse
    getch();

}
int * quicksort(int * array, int o)
{
    //int ipivot=
    
}
//Generador de Array
int * gen(int * array)
{
    int i,j,val,igual;
    srand(time(NULL));
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
