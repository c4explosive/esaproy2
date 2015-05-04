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
int *shell1(int * array);
int *selection( int * array);
void menu();
void menu1(int *array);

void print();


int main()
{
   menu();
   return 0;
}
void menu()
{
    int n,m=0,u=0, cont=1;
    int * array=malloc(TAM*sizeof(int));
    clrscr();

    do
   {
     if(u)
     clrscr();
     printf("\n                MENU\n");
     printf("      1.Cargar arreglo\n");
     printf("      2.Ordenacion burbuja\n");
     printf("      3.Ordenacion de insercion\n"); 
     printf("      4.Ordenacion shell\n");
     printf("      5.Ordenacion selection sort\n");
     printf("      6.Salir\n");
    printf("       Escoja una opcion\n");
    scanf("%d",&n);
    switch(n)
{
    case 1:
	    
            array=gen(array);
	    //print(array);
	    m=1;
            u=0;
            getch();
	    break;
    case 2:
	  if(m)
	{ 
	 print(array);
	     array=burbuja(array);
	     print(array);
	     u=0; 
          
	}
	else
	{
	printf("No ha cargado el arreglo");
	}
	  getch();
	  break;
   case 3:
	   if(m)
           {
            print(array);
	     array=insercion(array);
	     print(array);
	     u=0;
	  
           }
           else
	    {
		printf("No ha cargado el arreglo\n");
            }
	  getch();
	  break;
   

 case 4:  if(m)
          {
	   menu1(array);
           
          }
          else
	  {
		printf("No ha cargado el arreglo\n");
	  }
	   getch();
	  break;
case 5:
          if(m)
           {
	  print(array);
	  array=selection(array);
	  print(array);
           }
           else
	    {
              printf("No ha cargado el arreglo\n");
            }
          getch();
	  break;
case 6: cont=0; break;
	default: printf("Escriba una opcion correcta\n"); 
        break;

}
}while(cont);

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
  int h=(TAM/2);// permite dividir el arreglo en sub-arreglos
  int i=0,j=0,k=0, var;//declaración de variables
while(h>0)// permite ingresar al ciclo siempre y cuando el salto sea mayor a cero
{
    for(i=h;i<TAM;i++)// nos permite recorrer el arreglo
	{
	  j=i-h;// guarda una nueva posición
           while(j>=0)//se entra al bucle si j es mayor o igual a cero, de esa manera se puede la ordenación
		{
			k=j+h;//posición que va tomar el sub-arreglo
			if(array[j]<=array[k])//compara si el elemento es igual o menor al sub-array creado
				{
				  j--;//el indice de posición disminuye
				}
			else
				{
				  var=array[j];//si es menor en este bucle se guarda el elemento menor de la comparación 
				  array[j]=array[k];//se guarda el elemento mayor para compararlo en el if
				  array[k]=var;//se lleva a cambio el intercambio
				  j=j-h;//disminuye la posición
				 }
		    }
		 }
	     h=h/2;//permite crear el siguiente salto
}
return array;
}

// metodo de shell mayor a menor


int *shell1(int * array)
{
  int h=(TAM/2);// permite dividir el arreglo en sub-arreglos
  int i=0,j=0,k=0, var;//declaración de variables
while(h>0) // permite ingresar al ciclo siempre y cuando el salto sea mayor a cero
{
    for(i=h;i<TAM;i++)// nos permite recorrer el arreglo
	{
	  j=i-h;// guarda una nueva posición
          
           while(j>=0)//se entra al bucle si j es mayor o igual a cero, de esa manera se puede la ordenación
		{
			k=j+h;//posición que va tomar el sub-arreglo
			if(array[j]>=array[k])//compara si el elemento es igual o mayor al sub-array creado
				{
				  j--;//el indice de posición disminuye
				}
			else
				{
				  var=array[j];//si es menor en este bucle se guarda el elemento mayor de la comparación 
				  array[j]=array[k];//se guarda el elemento menor para compararlo en el if
				  array[k]=var;//se lleva a cambio el intercambio
				  j=j-h;//disminuye la posición
				 }
		    }
		 }
	     h=h/2;//permite crear el siguiente salto
}
return array;
}

//metodo selection sort

int *selection(int * array)
{
   int i, j,k,var;
   for(i=0;i<TAM;i++)//recorrido del arreglo
     {
      j=i;//se asigna a j la posicion i
      
       for(j=i;j<TAM;j++)//permite recorrer en busca del elemento menor
          {
	    if(array[j]<array[i])//compara si el elemento es menor
 		{
		 var=array[j];//se guarda el elemento menor
		 array[j]=array[i];// se guarda el elemento mayor para compararlo en el if
                 array[i]=var;//se guarda la modificación hecha en el arreglo
                
   		}
	}
        

      }
return array;
}	
//menu de shell

void menu1( int * array)
{
  int n,u=0, cont=1;
  

  do
  {
   if(u)
  clrscr();
  printf("\n MENU SHELL SORT\n");
  printf("1.Mayor a Menor\n");
  printf("2.Menor a mayor\n");
  printf("3. Salir\n");
  printf("Escoja una opcion");
  scanf("%d", &n);
  switch(n)
     {
      case 1:
	     
             printf("Mayor a menor\n");
             print(array);
	     array=shell1(array);
	     print(array);
	     u=0;
             break;
       case 2:
	     printf("Menor a mayor\n");
             print(array);
	     array=shell(array);
	     print(array);
	     u=0;
             break;
     case 3: cont=0;
             break;
     default: printf("Escriba una opcion correcta\n");
              break;
      }
    }while(cont);


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
