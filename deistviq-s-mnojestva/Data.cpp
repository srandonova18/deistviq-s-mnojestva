#include <iostream>
#include "Data.h"
#include "Presentation.h"
using namespace std;

//function that checks if the value entered is an integer
int readInt() {

	int number;

	//while loop until the value entered is an integer
	while (!(cin >> number)) {

		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << endl;
		cout << "There seems to be a problem with your input. " << endl;
		cout << "Please keep in mind that you have to enter a whole number (int). Try again: ";
	}

	return number;
}

//function that sorts the elements of an array
void sort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}


/*
function that compares the elements of the first
array with the elements of the second array
*/
int* comparison(int a[], int n, int b[], int m, string sign, int* c, int& k)
{
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j])
			{
				count++;
			}
		}

		if (sign == "==")
		{
			if (count == 0)
			{
				c[k] = a[i];
				k++;
			}
		}

		else if (sign == "!=")
		{
			if (count != 0)
			{
				c[k] = a[i];
				k++;
			}
		}

		count = 0;
	}

	return c;
}

//function that finds the union of two arrays
void unionOfSets(int a[], int n, int b[], int m)
{
	int* c = new int[(double)n + m];
	int k = 0;

	for (int i = 0; i < n; i++) {
		c[k] = a[i];
		k++;
	}

	comparison(b, m, a, n, "==", c, k);

	sort(c, k);

	for (int i = 0; i < k; i++)
		cout << c[i] << " ";

	delete[]c;

}

//function that finds the intersection of two arrays
void intersectionOfSets(int a[], int n, int b[], int m)
{
	int* c = new int[(double)n + m];
	int k = 0;

	comparison(a, n, b, m, "!=", c, k);

	sort(c, k);

	for (int i = 0; i < k; i++)
		cout << c[i] << " ";

	delete[]c;
}

//function that finds the symmetrical subtraction of two arrays
void symmetricalSubtractionOfSets(int a[], int n, int b[], int m)
{
	int* c = new int[(double)n + m];
	int k = 0;

	comparison(a, n, b, m, "==", c, k);

	comparison(b, m, a, n, "==", c, k);

	sort(c, k);

	for (int i = 0; i < k; i++)
		cout << c[i] << " ";

	delete[]c;
}