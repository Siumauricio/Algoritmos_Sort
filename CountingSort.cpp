#include <iostream>

void countingSort(int* A, int length, int k)
{
	int* B, * C, i = 0;
	B = new int[length];
	C = new int[k];
	for (i = 0; i < k; i++)
		C[i] = 0;
	for (i = 0; i < length; i++)
		C[A[i]]++;		//now C[i] contains the number of elements qual to i.
	for (i = 1; i < k; i++)
		C[i] += C[i - 1];		//now C[i] contains the number of elements less than or equal to i.
	for (i = length - 1; i >= 0; i--)
	{
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}
	for (i = 0; i < length; i++)
		A[i] = B[i];
}

int main()
{
	int a[] = { 2,5,3,0,2,3,0,3 };
	int i = 0;
	countingSort(a, 8, 6);
	while (i < 8)
		std::cout << a[i++] << std::endl;
	return 0;
}
