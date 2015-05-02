#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
//#define clrscr() system("clear")
//#define getch() system("read")
#define TAM 10
int * burbuja(int * array);
int * gen(int * array);
int *insercion(int * array);
int *shell(int * array);
void print();

void main()
{
    int n;
    int * array=malloc(TAM*sizeof(int));
    clrscr();

    printf("Escoja una opcion");
    scanf("%d",&n);
    switch(n)
{
    case 1:
	    array=gen(array);
	    print(array);
	    break;
    case 2:
	  print(array);
	  array=burbuja(array);
	  print(array);
	  break;
   case 3:
	  print(array);
	  array=insercion(array);
	  print(array);
	  break;
    case 4:
          print(array);
	  array=shell(array);
	  print(array);
	  break;

}
    getch();
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
    //getch();
    return array;
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
   // getch();
    return array;
}

//metodo de insercion

int * insercion(int * array)
{
int i,j,var;
for (i=0;i<TAM;i++)
	{
		
		var=array[i];
		for(j=i;(j>0) && (var<array[j-1]);j--)
		  {
			array[j]=array[j-1];
			array[j-1]=var;
		   }
		   
		  }

return array;


}
//metodo shell

int *shell(int * array)
{
  int h=(TAM/2);
  int i=0,j=0,k=0, var;
while(h>0)
{
    for(i=h;i<TAM;i++)
	{
	  j=i-h;
           while(j>=0)
		{
			k=j+h;
			if(array[j]<=array[k])
				{
				  j--;
				}
			else
				{
				  var=array[j];
				  array[j]=array[k];
				  array[k]=var;
				  j=j-h;
				 }
		    }
		 }
	     h=h/2;
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
