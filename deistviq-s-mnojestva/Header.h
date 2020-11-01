#pragma once
using namespace std;
int readInt();
void sort(int arr[], int n);
int whichArray();
void enterArrayElements(int array[], int& size, string number);
int* comparison(int a[], int n, int b[], int m, string sign, int* c, int& k);
void unionOfSets(int a[], int n, int b[], int m);
void intersectionOfSets(int a[], int n, int b[], int m);
void subtractionOfSets(int a[], int n, int b[], int m);
void symmetricalSubtractionOfSets(int a[], int n, int b[], int m);
void isSubset(int a[], int n, int b[], int m);
void showWelcome();
void showMenu();
void mainMenu();
