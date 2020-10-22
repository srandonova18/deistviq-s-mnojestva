#include <iostream>
using namespace std;

int* sravnenie(int a[], int n, int b[], int m, string sign, int* c, int& k) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                count++;
            }
        }

        if (sign == "==") {
            if (count == 0)
            {
                c[k] = a[i];
                k++;
            }
        }

        else if (sign == "!=") {
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

void razlika(int a[], int n, int b[], int m) {
    int* c = new int[n + m];
    int k = 0;
    sravnenie(a, n, b, m, "==", c, k);
    for (int i = 0; i < k; i++)
        cout << c[i] << " ";

    delete[]c;
}

void sechenie(int a[], int n, int b[], int m) {
    int* c = new int[n + m];
    int k = 0;
    sravnenie(a, n, b, m, "!=", c, k);
    for (int i = 0; i < k; i++)
        cout << c[i] << " ";

    delete[]c;
}



int main() {
    int a[10] = { 3,5,6,11,9,23,7,21,18,0 };
    int b[10] = { 4,8,9,0,13,22,34,11,1,45 };

    sechenie(b, 10, a, 10);
}
