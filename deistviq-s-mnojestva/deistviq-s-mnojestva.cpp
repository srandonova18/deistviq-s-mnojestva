#include <iostream>
using namespace std;

void enterArrayElements(int array[], int& size, string number) {
	cout << "Enter the size of the "<<number<<" array: ";
	cin >> size;
	cout << endl;

	cout << "Enter the elements of the " << number << " array: ";
	for (int i = 0; i < size; i++)
		cin >> array[i];
	cout << endl << endl;
}

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

int whichArray() {
	int choice;

	cout << "Razlikata na koi masiw iskate da namerite?" << endl;
	cout << "1. The first one (A) - A \\ B" << endl;
	cout << "2. The second one (B) - B \\ A" << endl;

	cout << "Enter an option: ";
	cin >> choice;

	while (choice < 1 or choice > 2) {
		cout << "Enter a valid option: ";
		cin >> choice;
	}

	return choice;
}

void razlika(int a[], int n, int b[], int m)
{
	int* c = new int[(double)n + m];
	int k = 0;


	if (whichArray() == 1) {
		cout << endl;
		cout << "Razlikata na mnojestwata (A \\ B) e: ";
		sravnenie(a, n, b, m, "==", c, k);
	}
	else
	{
		cout << endl;
		cout << "Razlikata na mnojestwata (B \\ A) e: ";
		sravnenie(b, m, a, n, "==", c, k);
	}

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
	cout << "WELCOME TO OUR PROGRAM!" << endl << endl;
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

void mainMenu()
{
	showWelcome();

	int a[100], b[100], n, m;

	enterArrayElements(a, n, "first");

	enterArrayElements(b, m, "second");

	int choice;
	const int obedinenieChoice = 1, sechenieChoice = 2, razlikaChoice = 3, simetrichnaRazlikaChoice=4, quitChoice = 5;
	
	do
	{
		showMenu();

		cin >> choice;

		cout << endl;

		while ((choice < obedinenieChoice) or (choice > quitChoice))
		{
			cout << "Please enter a valid menu option: ";
			cin >> choice;
		}

		
		switch (choice)
		{
			case 1:
				cout << "Obedinenieto na mnojestwata (A U B) e: ";
				obedinenie(a,n,b,m);
				break;

			case 2:
				cout << "Sechenieto na mnojestwata (A  B) e: ";
				sechenie(a, n, b, m);
				break;

			case 3:
				razlika(a, n, b, m);
				break;

			case 4:
				cout << "Simetrichnata razlika na mnojestwata e: ";
				simetrichnaRazlika(a, n, b, m);
				break;

			case 5:
				cout << "Exiting....\n";
				exit(0);
				break;
		}

		cout << endl << endl<<endl;
		
	} while (choice != quitChoice);
}


int main()
{
	mainMenu();
}