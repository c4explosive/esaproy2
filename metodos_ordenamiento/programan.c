#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

/*
				 Universidad Tecnol�gica de Panam�
			 Facultad de Ingenier�a en Sistemas Computacionales
			Licenciatura en Ingenier�a en Sistema y Computaci�n
					Estructura de Datos
				     M�todos de ordenamiento
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


int main()//funci�n principal
{
   menu();//llamada a la funci�n que contiene el men�
   return 0;
}
void menu()//funci�n que contiene el men�
{
    int n,m=0,u=0, cont=1;//declaraci�n de variables
    int * array=malloc(TAM*sizeof(int));
    clrscr();

    do//ciclo que permite repetir el men�
   {
     clrscr();
      //impresi�n del men�
     array=gen(array);//llamada de la funci�n que permite generar los n�meros
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
	     print(array);//impresi�n del arreglo desordernado
	     array=burbuja(array,1);//llamada de la funci�n burbuja
	     printf("Arreglo ordenado: \n");
	     print(array);//impresi�n del arreglo ordenado
	     u=0;
	  getch();
	  break;
   case 2:
	    printf("Arreglo desordenado: \n");
	    print(array);//impresi�n del arreglo desordernado
	    array=inserccion(array,0);//llamada de la funci�n inserci�n
	    printf("Arreglo ordenado: \n");
	    print(array);//impresi�n del arreglo ordenado
	  getch();
	  break;


 case 3: 
	   menu1(array);//llamada de la funci�n que contiene el submen� del shell sort
	   getch();
	  break;
case 4:
	  printf("Arreglo desordenado: \n");
	  print(array);//impresi�n del arreglo desordernado
	  array=selection(array);//llamada de la funci�n inserci�n
	  printf("Arreglo ordenado: \n");
	  print(array);//impresi�n del arreglo ordernado
	  getch();
	  break;


case 5: //quicksort
          printf("Arreglo desordenado: \n");
	  print(array);//impresi�n del arreglo desordernado
	  quicksort(array,0,TAM-1,0); //llamada de la funci�n inserci�n
	  printf("Arreglo ordenado: \n");
	  print(array);//impresi�n del arreglo ordernado
	  getch();
	  break;

case 6: //mergesort
	  printf("Arreglo desordenado: \n");
	  print(array);//impresi�n del arreglo desordernado
 	  part(array,0,TAM-1);
       	  printf("Arreglo ordenado: \n");
	  print(array);//impresi�n del arreglo ordernado
          getch();
	  break;

case 7: cont=0; break;//este case permite al usuario salir del programa
	default: printf("Escriba una opcion correcta\n"); //se env�a un mensaje al usuario indicandole si la opci�n introducida es inv�lida
        break;

}
}while(cont);//permite mantener el ciclo

}
int * burbuja (int * array, int o) //en este m�todo o funci�n se reciben dos par�metros, uno que es la array a modificar y el otro que dice el tipo de orden que va manejar. Sea ascendente o descendente.
{
    int i,j,aux,mode; //Se declaran cuatro variables, i y j para contadores; aux para trabajar un intercambio y mode que es lo que decide si el se compara para orden descendente o descendente seg�n la variable o.
    for(i=0;i<TAM;i++) //En estos bucles se comienza a comparar un elemento con todos.
    {
	for(j=0;j<TAM-1;j++) //En este bucle se ver� la comparaciones de un elemento con otro.
	{
	    if(o) //Aqu� se ve de que modo se ordenar�.
	        mode=array[j] > array[j+1];
	    else
	        mode=array[j] < array[j+1];
	    if(mode) //Si se cumple la condici�n seg�n sea el caso, el elemento actual se intercambiar� con el siguiente.
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

int * inserccion(int * array, int o) //Lo mismo que en los dem�s m�todos, se recibe un array (arreglo) y un indicador de la forma a ordenar.
{
    int i,j,m,elem,mode; 
    for (i=0;i<TAM-1;i++) //Muy similar al m�todo burbuja, se comienza con un bucle principal.
    {
	m=i+1;
	elem=array[m]; //En esta parte del m�todo, se utiliza una adaptaci�n de insertar elementos en un arreglo, sin embargo hay condiciones.
	for (j=m;j>0;j--)
	{
	    if(o)
	        mode=elem < array[j-1];
	    else
	        mode=elem > array[j-1];
	    if (mode)
	    {
		array[j]=array[j-1]; //Dependiendo del caso, los elementos se correr�n hacia la derecha y se ingresar� el elemento de �ndice m.
		array[j-1]=elem;
	    }
	    else
		break; //Si no cumple la condici�n, se rompe con ese elemento y no se hace nada, procede al siguiente �ndice m.
	}
    }
    return array;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//metodo shell

int *shell(int * array)
{
  int h=(TAM/2);// permite dividir el arreglo en sub-arreglos
  int i=0,j=0,k=0, var;//declaraci�n de variables
while(h>0)// permite ingresar al ciclo siempre y cuando el salto sea mayor a cero
{
    for(i=h;i<TAM;i++)// nos permite recorrer el arreglo
	{
	  j=i-h;// guarda una nueva posici�n
           while(j>=0)//se entra al bucle si j es mayor o igual a cero, de esa manera se puede la ordenaci�n
		{
			k=j+h;//posici�n que va tomar el sub-arreglo
			if(array[j]<=array[k])//compara si el elemento es igual o menor al sub-array creado
				{
				  j--;//el indice de posici�n disminuye
				}
			else
				{
				  var=array[j];//si es menor en este bucle se guarda el elemento menor de la comparaci�n 
				  array[j]=array[k];//se guarda el elemento mayor para compararlo en el if
				  array[k]=var;//se lleva a cambio el intercambio
				  j=j-h;//disminuye la posici�n
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
  int i=0,j=0,k=0, var;//declaraci�n de variables
while(h>0) // permite ingresar al ciclo siempre y cuando el salto sea mayor a cero
{
    for(i=h;i<TAM;i++)// nos permite recorrer el arreglo
	{
	  j=i-h;// guarda una nueva posici�n
          
           while(j>=0)//se entra al bucle si j es mayor o igual a cero, de esa manera se puede la ordenaci�n
		{
			k=j+h;//posici�n que va tomar el sub-arreglo
			if(array[j]>=array[k])//compara si el elemento es igual o mayor al sub-array creado
				{
				  j--;//el indice de posici�n disminuye
				}
			else
				{
				  var=array[j];//si es menor en este bucle se guarda el elemento mayor de la comparaci�n 
				  array[j]=array[k];//se guarda el elemento menor para compararlo en el if
				  array[k]=var;//se lleva a cambio el intercambio
				  j=j-h;//disminuye la posici�n
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
      case 1://est� primera opci�n permite ordenar los n�mero de mayor a menor
	     
             printf("Mayor a menor\n");
             print(array);//imprime el arreglo desordenado
	     array=shell1(array);//llamada de la funci�n que ordena los n�meros de mayor a menor
	     print(array);//imprime el arreglo ordenado
	     u=0;
             break;
       case 2://est� segunda opci�n permite ordenar los n�mero de menor a mayor
	     printf("Menor a mayor\n");
             print(array);//imprime el arreglo desordenado
	     array=shell(array);//llamada de la funci�n que ordena los n�meros de menor a mayor
	     print(array);//imprime el arreglo ordenado
	     u=0;
             break;
     case 3: cont=0;//est� tercera opci�n permite al usuario volver al men� principal
             break;
     default: printf("Escriba una opcion correcta\n");//env�a un mensaje indicandole al usuario si la opci�n ingresada es inv�lida
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
                 array[i]=var;//se guarda la modificaci�n hecha en el arreglo
                
   		}
	}
        

      }
return array;
}


//Quicksort cuenta de dos m�todos, principales; uno recursivo y otro que se encarga de partir el arreglo hasta su m�nima expresi�n.
void quicksort(int * array,int prin, int fin,  int o) //Al ser recursivo, el m�todo principal de quicksort, tiene que poseer los par�metros de cuando comienza y termina cada pedazo del al arreglo, por eso se usa prin y fin como los �ndices que se recibir�n como l�mites.
{
    int ipiv=fin,pix; //Se define ipiv como la posici�n de un pivote, o sea un elemento que se utilizar� para comparar con los dem�s en el m�todo particionar. En el caso de pix es el �ndice que tomar� los futuros pivotes despu�s de pasar el proceso de particionado.
    if (prin<fin) //Quicksort s�lo funciona si el principio es menor que el fin, sino termina y devuelve el array �rdenada.
    {
    	pix=particionar(array,ipiv,prin,fin,o); //Aqu� se define el pr�ximo valor de pix.
	quicksort(array,prin,pix-1,o); //Es esta sentencias se llama dos veces a quicksort, uno para trabajar con los elementos de la izquierda y el otro para la derecha. Con lo que el array se procesar� en arrays m�s peque�as hasta que la condici�n principal no se cumpla.
	quicksort(array,pix+1,fin,o);
    }
}
int particionar(int * array,int ipiv,int prin, int fin,int o) //En este m�todo es donde se encuentra el verdadero secreto de quicksort. Es el que decide enviar los elementos menores a un lado del pivote y los mayores al otro lado, como resultado, retorna el �ndice del pr�ximo pivote y quicksort se encarga del resto.
{
    int i,pix,mode;
    pix=prin;
    for (i=prin;i<fin;i++) //Se toma los par�metros pasados por quicksort y se comienza la iteraci�n.
    {
	if (o)
	    mode=array[i] <= array[ipiv];
	else
	    mode=array[i] >= array[ipiv];	
	if (mode) //Dependiendo de la manera como se vaya ordenar, el compara el elemento de �ndice i con el del pivote, si se cumple ser� enviado al lado del pivote.
	{
	     swap(array,i,pix);  //Aqu� intercambia el elemento con el proximo pivote que se genera.
	     pix++; //El �ndice del pr�ximo pivote aumenta en uno si la condici�n se cumple.
	}
    }
    swap(array,pix,fin); //Al final de la iteraci�n se intercambian el elemento (pix) con el fin, pero no intercambian de �ndice.
    return pix; //Se retorna el pr�ximo valor de pix.
}
void swap(int *array, int num1, int num2) //M�todo adicional, para facilitar el intercambio de elementos de un arreglo.
{
    int aux; //Variable auxiliar que almacena el elemento uno y evitar que se pierda.
    aux=array[num1];
    array[num1]=array[num2]; //Reemplazo de elementos del segundo al primero.
    array[num2]=aux; // y por �ltimo el segundo toma el valor auxiliar, que era el contenido del primero.
}
/* Cabe destacar que ni quicksort ni swap retornan nada, la raz�n de esto es porque como se trabaja con direcciones de memorias, internamente la direcci�n de memoria de un elemento del arreglo es la misma en todos los lados del programa, por lo que no es necesario hacerlo saber a las dem�s partes del programa.*/

void part(int * arr,int min,int max)
{
 int mid;
 if(min<max)
 {
   mid=(min+max)/2;   //creaci�n del pivote
   part(arr,min,mid);   //funci�n recursiva
   part(arr,mid+1,max);
   merge(arr,min,mid,max);
 }
}


void merge(int arr[],int min,int mid,int max)//funci�n de mezcla
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
