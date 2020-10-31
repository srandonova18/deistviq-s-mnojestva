#include <iostream>
using namespace std;

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

int whichArray() {
	int choice;

	cout << "Enter an option: ";
	cin >> choice;

	while (choice < 1 or choice > 2) {
		cout << "Enter a valid option: ";
		cin >> choice;
	}

	return choice;
}

void enterArrayElements(int array[], int& size, string number) {
	cout << "Enter the size of the "<<number<<" array: ";
	cin >> size;
	cout << endl;

	cout << "Enter the elements of the " << number << " array: ";
	for (int i = 0; i < size; i++)
		cin >> array[i];
	cout << endl << endl;
}

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

void unionOfSets(int a[], int n, int b[], int m) {
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

void subtractionOfSets(int a[], int n, int b[], int m)
{
	int* c = new int[(double)n + m];
	int k = 0;

	cout << "Which array do you want to subtract from?" << endl;
	cout << "1. The first one (A) - A \\ B" << endl;
	cout << "2. The second one (B) - B \\ A" << endl;

	if (whichArray() == 1) {
		cout << endl;
		cout << "The subtraction of the sets (A \\ B) is: ";
		comparison(a, n, b, m, "==", c, k);
	}
	else
	{
		cout << endl;
		cout << "The subtraction of the sets (B \\ A) is: ";
		comparison(b, m, a, n, "==", c, k);
	}

	sort(c, k);

	for (int i = 0; i < k; i++)
		cout << c[i] << " ";

	delete[]c;
}

void symmetricalSubtractionOfSets(int a[], int n, int b[], int m) {
	int* c = new int[(double)n + m];
	int k = 0;

	comparison(a, n, b, m, "==", c, k);

	comparison(b, m, a, n, "==", c, k);

	sort(c, k);

	for (int i = 0; i < k; i++)
		cout << c[i] << " ";

	delete[]c;
}

void isPodmnojestwo(int a[], int n, int b[], int m) {
	int count = 0;

	cout << "Koe mnojestwo iskate da prowerite dali se sydyrja w drugoto?" << endl;
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
			cout << "A e podmnojestwo na B" << endl;
		}
		else {
			cout << "A ne e podmnojestwo na B" << endl;
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

		if (count == n) {
			cout << "B e podmnojestwo na A" << endl;
		}
		else {
			cout << "B ne e podmnojestwo na A" << endl;
		}
	}

	
		
}

void showWelcome()
{
	cout << "WELCOME TO OUR PROGRAM!" << endl;
	cout << "To try it, you'll have to enter two sets of whole numbers" << endl<<endl;
}

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
	cout << "5. Podmnojestwo" << endl;
	cout << "6. Quit " << endl << endl;
	cout << "Please choose an option: ";
}

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

		cin >> choice;

		cout << endl;

		while ((choice < 1) or (choice > 6))
		{
			cout << "Please enter a valid menu option: ";
			cin >> choice;
		}

		
		switch (choice)
		{
			case 1:
				cout << "The union of the sets (A U B) is: ";
				unionOfSets(a,n,b,m);
				break;

			case 2:
				cout << "The intersection of the sets (A  B) is: ";
				intersectionOfSets(a, n, b, m);
				break;

			case 3:
				subtractionOfSets(a, n, b, m);
				break;

			case 4:
				cout << "The symmetrical subtraction of the sets is: ";
				symmetricalSubtractionOfSets(a, n, b, m);
				break;

			case 5:
				isPodmnojestwo(a, n, b, m);
				break;

			case 6:
				cout << "Exiting....\n";
				exit(0);
				break;
		}

		cout << endl << endl<<endl;
		
	} while (choice != 6);
}


int main()
{
	system("color 5");
	mainMenu();
}