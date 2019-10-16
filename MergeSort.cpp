#include <iostream>

using namespace std;

void merge(int[], int, int, int);
void mergeSort(int[], int, int);

int main(){
	int size = 8;
	int A[8] = {27,14,3,8,17,5,21,1};
	int low = 0;
	int high = size - 1;
	mergeSort(A, low, high);
	for (int i = 0; i < size; i++)
	{
		cout << A[i] << "\n";
	}
}


void mergeSort(int A[], int low, int high) {// se subdivide 
	if (low < high) {
		int mid;
		mid = (low + high) / 2; //formula matematica separo el arreglo
		mergeSort(A, low, mid); // la altura cambia conforme al parametro que le mando de mid
		mergeSort(A, mid + 1, high); //aqui aumenta la posicion, asimismo mid sirve para 
		merge(A, low, high, mid);//ordenar el arreglo
	}
	return;
}


void merge(int A[], int low, int high, int mid)
{
	int i, j, k, c[10];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high)// si es menor a la primer separacion y a la altura 
	{
		if (A[i] < A[j]) //si el primer valor es menor al segundo
		{
			c[k] = A[i];//copio el primero valor al arreglo auxiliar, termina la condicion
			k++;
			i++;
		}
		else
		{
			c[k] = A[j];//si no se cumple la primer condicion 
			k++;		//copio el segundo valor al arreglo auxiliar, termina la condicion
			j++;
		}
	}
	while (i <= mid) //copio el primer valor de la condicion al arreglo auxiliar 
	{					// "i" es la primer posicion del valor a comparar ya que es mayor al segundo
		c[k] = A[i]; 
		k++;
		i++;
	}
	while (j <= high)//copio el segundo valor de la condicion al arreglo auxiliar 
	{					// "j" es la segunda posicion del valor a comparar ya que es mayor al primero 
		c[k] = A[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++)// luego de ordenar la primer separacion de la matriz original y guardarlo en la matriz
	{ //auxiliar los copio en la matriz original
		A[i] = c[i];
 	}
}
