#include <iostream>
using namespace std;


int* sravnenie(int a[], int n, int b[], int m, string sign, int* c, int& k)
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

void obedinenie(int a[], int n, int b[], int m) {
	int* c = new int[(double)n + m];
	int k = 0;

	for (int i = 0; i < n; i++) {
		c[k] = a[i];
		k++;
	}

	sravnenie(b, m, a, n, "==", c, k);

	for (int i = 0; i < k; i++)
		cout << c[i] << " ";

	delete[]c;

}

void sechenie(int a[], int n, int b[], int m)
{
	int* c = new int[(double)n + m];
	int k = 0;

	sravnenie(a, n, b, m, "!=", c, k);

	for (int i = 0; i < k; i++)
		cout << c[i] << " ";

	delete[]c;
}

void razlika(int a[], int n, int b[], int m)
{
	int* c = new int[(double)n + m];
	int k = 0;

	sravnenie(a, n, b, m, "==", c, k);

	for (int i = 0; i < k; i++)
		cout << c[i] << " ";

	delete[]c;
}

void simetrichnaRazlika(int a[], int n, int b[], int m) {
	int* c = new int[(double)n + m];
	int k = 0;

	sravnenie(a, n, b, m, "==", c, k);

	sravnenie(b, m, a, n, "==", c, k);

	for (int i = 0; i < k; i++)
		cout << c[i] << " ";

	delete[]c;
}

bool isPodmnojestwo(int a[], int n, int b[], int m) {
	int count = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i] == b[j]) {
				count++;
			}
		}
	}

	if (count == n)
		return true;

	return false;
}

void showWelcome()
{
	cout << "Welcome to our program" << endl << endl;
}

void showMenu()
{

	cout << "+---------------------------+" << endl;
	cout << "|                           |" << endl;
	cout << "|            MENU           |" << endl;
	cout << "|                           |" << endl;
	cout << "+---------------------------+" << endl;

	cout << endl;
	cout << "1. Obedinenie" << endl;
	cout << "2. Sechenie" << endl;
	cout << "3. Razlika" << endl;
	cout << "4. Simetrichna razlika" << endl;
	cout << "5. Quit " << endl << endl;
	cout << "Please choose an option: ";
}

void mainMenu(int a[], int n, int b[], int m)
{
	int choice;
	const int obedinenieChoice = 1, sechenieChoice = 2, razlikaChoice = 3, simetrichnaRazlikaChoice=4, quitChoice = 5;
	showWelcome();
	
	do
	{
		showMenu();
		cin >> choice;
		while (choice < obedinenieChoice || choice > quitChoice)
		{
			cout << "Please enter a valid menu choice: ";
			cin >> choice;
		}

		if (choice != quitChoice)
		{
			switch (choice)
			{
			case 1:
				obedinenie(a,n,b,m);
				cout << endl;
				break;

			case 2:
				sechenie(a, n, b, m);
				cout << endl;
				break;

			case 3:
				razlika(a, n, b, m);
				break;
			case 4:
				simetrichnaRazlika(a, n, b, m);
				cout << endl;
				break;
			case 5:
				cout << "Exiting....\n";
				break;
			}

			cout << endl << endl;
		}
	} while (choice != quitChoice);
}


int main()
{
	int a[10] = { 3,5,6,11,9,23,7,21,18,0 };
	int b[10] = { 4,8,9,0,13,22,34,11,1,45 };
	system("Color 5");
	mainMenu(a,10,b,10);
}