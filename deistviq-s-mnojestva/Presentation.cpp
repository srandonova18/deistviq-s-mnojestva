#include <iostream>
#include "Header.h"
using namespace std;

/*
function that returns the user's choice
(1 is for the first array and 2 is for the second array)
*/
int whichArray()
{
	int choice;

	cout << "Enter an option: ";
	choice = readInt();

	while (choice < 1 or choice > 2) {
		cout << "\nYour input has to be either 1 or 2! Try again: ";
		choice = readInt();
	}

	return choice;
}

/*function that prompts the user to input a size number and
elements for each of the two arrays*/
void enterArrayElements(int array[], int& size, string number)
{
	cout << "Enter the size of the " << number << " array: ";

	size = readInt();

	while (size < 1) {
		cout << "\nYour input has to be a whole positive number! Try again: ";
		size = readInt();
	}
	cout << endl;

	cout << "Enter the elements of the " << number << " array: ";
	for (int i = 0; i < size; i++)
	{
		array[i] = readInt();
	}
	cout << endl << endl;
}

/*
function that finds the substraction of the first and
second array or vice versa
*/
void subtractionOfSets(int a[], int n, int b[], int m)
{
	int* c = new int[(double)n + m];
	int k = 0;

	cout << "Which array do you want to subtract from?" << endl;
	cout << "1. The first one (A) - A \\ B" << endl;
	cout << "2. The second one (B) - B \\ A" << endl;

	if (whichArray() == 1) {
		cout << endl;
		cout << "- - - - - The subtraction of the sets (A \\ B) is: ";
		comparison(a, n, b, m, "==", c, k);
	}
	else
	{
		cout << endl;
		cout << "- - - - - The subtraction of the sets (B \\ A) is: ";
		comparison(b, m, a, n, "==", c, k);
	}

	sort(c, k);

	for (int i = 0; i < k; i++)
		cout << c[i] << " ";

	cout << "- - - - -";

	delete[]c;
}

/*
function that finds if the first array is a
subset of the second or vice versa
*/
void isSubset(int a[], int n, int b[], int m)
{
	int count = 0;

	cout << "Which set do you want to check if it is a subset of the other set?" << endl;
	cout << "1. The first one (A)" << endl;
	cout << "2. The second one (B)" << endl;


	if (whichArray() == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] == b[j]) {
					count++;
				}
			}
		}

		cout << endl;

		if (count == n) {
			cout << "- - - - - A is a subset of B - - - - -" << endl;
		}
		else {
			cout << "- - - - - A is not a subset of B - - - - -" << endl;
		}
	}
	else {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (b[i] == a[j]) {
					count++;
				}
			}
		}

		cout << endl;

		if (count == m) {
			cout << "- - - - - B is a subset of A - - - - -" << endl;
		}
		else {
			cout << "- - - - - B is not a subset of A - - - - -" << endl;
		}
	}
}

//function that prints a welcoming message
void showWelcome()
{
	cout << "WELCOME TO OUR PROGRAM!" << endl;
	cout << "To try it, you'll have to enter two sets of whole numbers" << endl << endl;
}

//function that prints the menu
void showMenu()
{

	cout << "+---------------------------+" << endl;
	cout << "|                           |" << endl;
	cout << "|            MENU           |" << endl;
	cout << "|                           |" << endl;
	cout << "+---------------------------+" << endl;

	cout << endl;
	cout << "1. Union" << endl;
	cout << "2. Intersection" << endl;
	cout << "3. Subtraction (difference)" << endl;
	cout << "4. Symmetrical subtraction" << endl;
	cout << "5. Subset" << endl;
	cout << "6. Quit " << endl << endl;
	cout << "Please enter an option: ";
}

//function that displays the menu options, prompts the user to input data and prints the result
void mainMenu()
{
	showWelcome();

	int a[100], b[100], n, m;

	enterArrayElements(a, n, "first");

	enterArrayElements(b, m, "second");

	int choice;


	do
	{
		showMenu();

		choice = readInt();

		while ((choice < 1) or (choice > 6))
		{
			cout << "\nYour input has to be a whole number between 1 and 6! Try again: ";
			choice = readInt();
		}

		cout << endl;

		switch (choice)
		{
		case 1:
			cout << "- - - - - The union of the sets (A U B) is: ";
			unionOfSets(a, n, b, m);
			cout << "- - - - -";
			break;

		case 2:
			cout << "- - - - - The intersection of the sets (A  B) is: ";
			intersectionOfSets(a, n, b, m);
			cout << "- - - - -";
			break;

		case 3:
			subtractionOfSets(a, n, b, m);
			break;

		case 4:
			cout << "- - - - - The symmetrical subtraction of the sets is: ";
			symmetricalSubtractionOfSets(a, n, b, m);
			cout << "- - - - -";
			break;

		case 5:
			isSubset(a, n, b, m);
			break;

		case 6:
			cout << "Exiting....\n";
			exit(0);
			break;
		}

		cout << endl << endl << endl;

	} while (choice != 6);
}