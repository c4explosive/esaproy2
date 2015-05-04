#include<stdio.h>
#include<conio.h>
void merge(int [],int ,int ,int );
void part(int [],int ,int );
int main()
{
 int arr[100];
 int i;
 printf("\n\t------- Metodo de ordenamiento por mezcla -------\n\n");
 for(i=0; i<100; i++)
 {
   arr[i]=rand()%100+1;   //carga de vector con variables aleatorias.
 }
 part(arr,0,99);
 printf("\n\t------- Mezclar elementos... -------\n\n");
 for(i=0; i<100;i++)
 printf("%d ",arr[i]);
 getch();
 return 0;
}


void part(int arr[],int min,int max)
{
 int mid;
 if(min<max)
 {
   mid=(min+max)/2;   //creaci¢n del pivote
   part(arr,min,mid);   //funci¢n recursiva
   part(arr,mid+1,max);
   merge(arr,min,mid,max);
 }
}


void merge(int arr[],int min,int mid,int max)//funcion de mezcla
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

