
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

/*
				 Universidad Tecnológica de Panamá
			 Facultad de Ingeniería en Sistemas Computacionales
			Licenciatura en Ingeniería en Sistema y Computación
					Estructura de Datos
				     Métodos de ordenamiento
					  Integrantes:
				    Espinosa, Angel 8-905-1352
				    Miranda, Heidys 4-777-1515
				    Rodriguez, Maria 8-900-1207
				 Profesora Doris Gutierrez
				       Grupo:1IL-121
					  I Semestre
					     2015
*/


//#define clrscr() system("clear")
//#define getch() system("read")
#define TAM 10
int * burbuja(int * array, int o);
int * gen(int * array, int o);
int *insercion(int * array, int o);
int *shell(int * array, int o);
int *shell1(int * array, int o);
int *selection( int * array, int o);
int *quicksort( int *array, int o);
void menu();
void menu1(int *array);
void print();


int main()//función principal
{
   menu();//llamada a la función que contiene el menú
   return 0;
}
void menu()//función que contiene el menú
{
    int n,m=0,u=0, cont=1;//declaración de variables
    int * array=malloc(TAM*sizeof(int));
    clrscr();

    do//ciclo que permite repetir el menú
   {
     if(u)//condición que permite volver al menú luego de ingresar a las opciones
     clrscr();
      //impresión del menú
     printf("\n                MENU\n");
     printf("      METODOS DE ORDENAMIENTO \n");
     printf("      1.Cargar arreglo\n");
     printf("      2.Ordenacion burbuja\n");
     printf("      3.Ordenacion de insercion\n");
     printf("      4.Ordenacion shell\n");
     printf("      5.Ordenacion selection sort\n");
     printf("      6.Ordenacion quicksort\n");
     printf("      7.Ordenacion Mergesort\n");
     printf("      8.Salir\n");
    printf("       Escoja una opcion\n");
    scanf("%d",&n);//lectura del numero insertado
    switch(n)
{
    case 1://permite generar los números

	    array=gen(array);//llamada de la función que permite generar los números
	    //print(array);
	    m=1;//variable que guarda y envía este número para indicar si el usuario ingreso a la opción uno y cargó el arreglo
	    u=0;
	    getch();
	    break;
    case 2:
	  if(m)//condición que permite acceder al método de ordenamiento
	{
	     print(array);//impresión del arreglo desordernado
	     array=burbuja(array,1);//llamada de la función burbuja
	     print(array);//impresión del arreglo ordenado
	     u=0;

	}
	else //este bucle envia un mensaje al usuario indicandole que el arreglo no ha sido cargado
	{
	printf("No ha cargado el arreglo");
	}
	  getch();
	  break;
   case 3:
	   if(m)//condición que permite acceder al método de ordenamiento
	   {
	    print(array);//impresión del arreglo desordernado
	     array=insercion(array,0);//llamada de la función inserción
	     print(array);//impresión del arreglo ordenado
	     u=0;

	   }
	   else//este bucle envia un mensaje al usuario indicandole que el arreglo no ha sido cargado
	    {
		printf("No ha cargado el arreglo\n");
	    }
	  getch();
	  break;


 case 4:  if(m)//condición que permite acceder al método de ordenamiento
	  {
	   menu1(array);//llamada de la función que contiene el submenú del shell sort
	   u=0;
	  }
	  else//este bucle envia un mensaje al usuario indicandole que el arreglo no ha sido cargado
	  {
		printf("No ha cargado el arreglo\n");
	  }
	   getch();
	  break;
case 5:
	  if(m)//condición que permite acceder al método de ordenamiento
	   {
	  print(array);//impresión del arreglo desordernado
	  array=selection(array,0);//llamada de la función inserción
	  print(array);//impresión del arreglo ordernado
	  u=0;
	   }
	   else//este bucle envia un mensaje al usuario indicandole que el arreglo no ha sido cargado
	    {
	      printf("No ha cargado el arreglo\n");
	    }
	  getch();
	  break;


case 6:
	if(m)//condición que permite acceder al método de ordenamiento
	 {
	  print(array);//impresión del arreglo desordernado
	  //array=   (array); ingresar el metodo
	   u=0;
	  }

	  else//este bucle envia un mensaje al usuario indicandole que el arreglo no ha sido cargado
	   {
	    printf("No ha cargado el arreglo\n");
	    }
	  getch();
	  break;

case 7:
	if(m)//condición que permite acceder al método de ordenamiento
	 {
	  print(array);//impresión del arreglo desordernado
	  array=quicksort(array,1)
          u=0;
          }

          else//este bucle envia un mensaje al usuario indicandole que el arreglo no ha sido cargado
           {
            printf("No ha cargado el arreglo\n");
            }
          getch();
	  break;


case 8: cont=0; break;//este case permite al usuario salir del programa
	default: printf("Escriba una opcion correcta\n"); //se envía un mensaje al usuario indicandole si la opción introducida es inválida
        break;

}
}while(cont);//permite mantener el ciclo

}
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
//Generador de Array
int * gen(int * array)//función que permite generar los elementos del arreglo
{
    int i,j,val,igual;
    srand(time(NULL));
    for(i=0;i<TAM;i++)//ciclo que permite asignar los elementos al arreglo
    {
	 array[i]=1+rand()%((TAM+1)-1);//se genera un número random
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


void menu1( int * array)//menu de shell sort
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
      case 1://está primera opción permite ordenar los número de mayor a menor
	     
             printf("Mayor a menor\n");
             print(array);//imprime el arreglo desordenado
	     array=shell1(array);//llamada de la función que ordena los números de mayor a menor
	     print(array);//imprime el arreglo ordenado
	     u=0;
             break;
       case 2://está segunda opción permite ordenar los número de menor a mayor
	     printf("Menor a mayor\n");
             print(array);//imprime el arreglo desordenado
	     array=shell(array);//llamada de la función que ordena los números de menor a mayor
	     print(array);//imprime el arreglo ordenado
	     u=0;
             break;
     case 3: cont=0;//está tercera opción permite al usuario volver al menú principal
             break;
     default: printf("Escriba una opcion correcta\n");//envía un mensaje indicandole al usuario si la opción ingresada es inválida
              break;
      }
    }while(cont);//mantiene el ciclo repetitivo


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

void print(int * array)//Metodo para imprimir los elementos del arreglo
{
    int i;
    printf("[");
    for(i=0;i<TAM;i++)
    {
	printf("%d,",array[i]);
    }
    printf("\b]\n");
}
