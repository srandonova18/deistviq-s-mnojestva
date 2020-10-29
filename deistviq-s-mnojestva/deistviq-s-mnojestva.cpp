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

void razlika(int a[], int n, int b[], int m)
{
	int* c = new int[n + m];
	int k = 0;
	sravnenie(a, n, b, m, "==", c, k);
	for (int i = 0; i < k; i++)
		cout << c[i] << " ";
	delete[]c;
}

void sechenie(int a[], int n, int b[], int m)
{
	int* c = new int[n + m];
	int k = 0;
	sravnenie(a, n, b, m, "!=", c, k);
	for (int i = 0; i < k; i++)
		cout << c[i] << " ";
	delete[]c;
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
	cout << "1. Sravnenie" << endl;
	cout << "2. Razlika" << endl;
	cout << "3. Sechenie" << endl;
	cout << "4. Quit " << endl << endl;
	cout << "Please choose an option: ";
	cout << endl;
}

void mainmenu()
{
	int choice;
	const int obedinenie_choice = 1, sechenie_choise = 2, razlika_choise = 3, QUIT_CHOICE = 4;
	showWelcome();
	showMenu();
	do
	{
		cin >> choice;
		while (choice < obedinenie_choice || choice > QUIT_CHOICE)
		{
			cout << "Please enter a valid menu choice: ";
			cin >> choice;
		}

		if (choice != QUIT_CHOICE)
		{
			switch (choice)
			{
			case 1:
				int obedinenie();
				break;

			case 2:
				int sechenie();
				break;

			case 3:
				int razlika();
				break;
			case QUIT_CHOICE:
				cout << "Exiting....\n";
				break;
			}
		}
	} while (choice != QUIT_CHOICE);
}



int main()
{
	int a[10] = { 3,5,6,11,9,23,7,21,18,0 };
	int b[10] = { 4,8,9,0,13,22,34,11,1,45 };
	system("Color 5");
	mainmenu();
}