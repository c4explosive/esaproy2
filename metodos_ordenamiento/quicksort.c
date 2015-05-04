#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#define clrscr() system("clear")
#define getch() system("read")
#define TAM 0x0A
//Limites o rango
#define LIMS 0xAA
#define LIMF 0x01
//Metodos para ordenar//////////
////////////////////Quicksort///////////////////////////////////
void quicksort(int * array,int prin, int fin,  int o);
int particionar(int * array,int ipiv,int prin, int fin,int o);
void swap(int* array, int num1, int num2);
///////////////////////////////////////////////////////////////
int * gen(int * array);
void print();
void main()
{
    int * array=malloc(TAM*sizeof(int));
    clrscr(); 
    array=gen(array); 
    print(array);
    quicksort(array,0,TAM-1,0); //1 when is normal and 0 when is reverse
    print(array);
    getch();

}

//////////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////
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
