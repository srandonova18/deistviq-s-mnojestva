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

int main() {

   
}
