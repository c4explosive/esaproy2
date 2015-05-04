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


#define clrscr() system("clear")
#define getch() system("read")
#define TAM 0x0A
//Limites o rango
#define LIMS 0xAA
#define LIMF 0x01
int * burbuja(int * array, int o);
int * gen(int * array);
int *inserccion(int * array, int o);
int *shell(int * array);
int *shell1(int * array);
int *selection( int * array);
////////////////////Quicksort///////////////////////////////////
void quicksort(int * array,int prin, int fin,  int o);
int particionar(int * array,int ipiv,int prin, int fin,int o);
void swap(int* array, int num1, int num2);
///////////////////////////////////////////////////////////////
void merge(int [],int ,int ,int );
void part(int [],int ,int );
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
     clrscr();
      //impresión del menú
     array=gen(array);//llamada de la función que permite generar los números
     printf("\n                MENU\n");
     printf("      METODOS DE ORDENAMIENTO \n");
     printf("      1.Ordenacion burbuja\n");
     printf("      2.Ordenacion de insercion\n");
     printf("      3.Ordenacion shell\n");
     printf("      4.Ordenacion selection sort\n");
     printf("      5.Ordenacion quicksort\n");
     printf("      6.Ordenacion Mergesort\n");
     printf("      7.Salir\n");
    printf("       Escoja una opcion: ");
    scanf("%d",&n);//lectura del numero insertado
    switch(n)
{
    case 1:
	     printf("Arreglo desordenado: \n");
	     print(array);//impresión del arreglo desordernado
	     array=burbuja(array,1);//llamada de la función burbuja
	     printf("Arreglo ordenado: \n");
	     print(array);//impresión del arreglo ordenado
	     u=0;
	  getch();
	  break;
   case 2:
	    printf("Arreglo desordenado: \n");
	    print(array);//impresión del arreglo desordernado
	    array=inserccion(array,0);//llamada de la función inserción
	    printf("Arreglo ordenado: \n");
	    print(array);//impresión del arreglo ordenado
	  getch();
	  break;


 case 3: 
	   menu1(array);//llamada de la función que contiene el submenú del shell sort
	   getch();
	  break;
case 4:
	  printf("Arreglo desordenado: \n");
	  print(array);//impresión del arreglo desordernado
	  array=selection(array);//llamada de la función inserción
	  printf("Arreglo ordenado: \n");
	  print(array);//impresión del arreglo ordernado
	  getch();
	  break;


case 5: //quicksort
          printf("Arreglo desordenado: \n");
	  print(array);//impresión del arreglo desordernado
	  quicksort(array,0,TAM-1,0); //llamada de la función inserción
	  printf("Arreglo ordenado: \n");
	  print(array);//impresión del arreglo ordernado
	  getch();
	  break;

case 6: //mergesort
	  printf("Arreglo desordenado: \n");
	  print(array);//impresión del arreglo desordernado
 	  part(array,0,TAM-1);
       	  printf("Arreglo ordenado: \n");
	  print(array);//impresión del arreglo ordernado
          getch();
	  break;

case 7: cont=0; break;//este case permite al usuario salir del programa
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



//metodo de inserccion

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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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


//Quicksort cuenta de dos métodos, principales; uno recursivo y otro que se encarga de partir el arreglo hasta su mínima expresión.
void quicksort(int * array,int prin, int fin,  int o) //Al ser recursivo, el método principal de quicksort, tiene que poseer los parámetros de cuando comienza y termina cada pedazo del al arreglo, por eso se usa prin y fin como los índices que se recibirán como límites.
{
    int ipiv=fin,pix; //Se define ipiv como la posición de un pivote, o sea un elemento que se utilizará para comparar con los demás en el método particionar. En el caso de pix es el índice que tomará los futuros pivotes después de pasar el proceso de particionado.
    if (prin<fin) //Quicksort sólo funciona si el principio es menor que el fin, sino termina y devuelve el array órdenada.
    {
    	pix=particionar(array,ipiv,prin,fin,o); //Aquí se define el próximo valor de pix.
	quicksort(array,prin,pix-1,o); //Es esta sentencias se llama dos veces a quicksort, uno para trabajar con los elementos de la izquierda y el otro para la derecha. Con lo que el array se procesará en arrays más pequeñas hasta que la condición principal no se cumpla.
	quicksort(array,pix+1,fin,o);
    }
}
int particionar(int * array,int ipiv,int prin, int fin,int o) //En este método es donde se encuentra el verdadero secreto de quicksort. Es el que decide enviar los elementos menores a un lado del pivote y los mayores al otro lado, como resultado, retorna el índice del próximo pivote y quicksort se encarga del resto.
{
    int i,pix,mode;
    pix=prin;
    for (i=prin;i<fin;i++) //Se toma los parámetros pasados por quicksort y se comienza la iteración.
    {
	if (o)
	    mode=array[i] <= array[ipiv];
	else
	    mode=array[i] >= array[ipiv];	
	if (mode) //Dependiendo de la manera como se vaya ordenar, el compara el elemento de índice i con el del pivote, si se cumple será enviado al lado del pivote.
	{
	     swap(array,i,pix);  //Aquí intercambia el elemento con el proximo pivote que se genera.
	     pix++; //El índice del próximo pivote aumenta en uno si la condición se cumple.
	}
    }
    swap(array,pix,fin); //Al final de la iteración se intercambian el elemento (pix) con el fin, pero no intercambian de índice.
    return pix; //Se retorna el próximo valor de pix.
}
void swap(int *array, int num1, int num2) //Método adicional, para facilitar el intercambio de elementos de un arreglo.
{
    int aux; //Variable auxiliar que almacena el elemento uno y evitar que se pierda.
    aux=array[num1];
    array[num1]=array[num2]; //Reemplazo de elementos del segundo al primero.
    array[num2]=aux; // y por último el segundo toma el valor auxiliar, que era el contenido del primero.
}
/* Cabe destacar que ni quicksort ni swap retornan nada, la razón de esto es porque como se trabaja con direcciones de memorias, internamente la dirección de memoria de un elemento del arreglo es la misma en todos los lados del programa, por lo que no es necesario hacerlo saber a las demás partes del programa.*/

void part(int * arr,int min,int max)
{
 int mid;
 if(min<max)
 {
   mid=(min+max)/2;   //creación del pivote
   part(arr,min,mid);   //función recursiva
   part(arr,mid+1,max);
   merge(arr,min,mid,max);
 }
}


void merge(int arr[],int min,int mid,int max)//función de mezcla
{
  int tmp[100];
  int i,j,k,m;
  j=min;
  m=mid+1;
  for(i=min; j<=mid && m<=max ; i++)
  {
     if(arr[j]<=arr[m]) //sorteo de variables.
     {                 //menores a la izquierda del pivote
	 tmp[i]=arr[j];
	 j++;
     }
     else
     {
	 tmp[i]=arr[m]; //uso de vector auxiliar
	 m++;
     }
  }
  if(j>mid)
  {
     for(k=m; k<=max; k++)   //mayores a la derecha del pivote
     {
	 tmp[i]=arr[k];
	 i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
	tmp[i]=arr[k];
	i++;
     }
  }
  for(k=min; k<=max; k++)
     arr[k]=tmp[k];
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
