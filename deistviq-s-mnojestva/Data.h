#pragma once
#include <string>
using namespace std;

int readInt();
void sort(int arr[], int n);
int* comparison(int a[], int n, int b[], int m, string sign, int* c, int& k);
void unionOfSets(int a[], int n, int b[], int m);
void intersectionOfSets(int a[], int n, int b[], int m);
void symmetricalSubtractionOfSets(int a[], int n, int b[], int m);