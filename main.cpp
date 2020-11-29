#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
const double eps = 0.00001;
void g(double** a, int n) {
    int i, j, k, l;
    double r = 0.0;
    i = 0; j = 0;
    while (i < n && j < n) {
        for (k = i; k < n; k++) {
            if (abs(a[k][j]) > r) {
                l = k;
                r = abs(a[k][j]);
            }
        }

        if (r <= eps) {
            for (k = i; k < n; k++) {
                a[k][j] = 0.0;
            }
            j++;
            continue;
        }
        if (l != i && l != n) {
            for (k = j; k < n; k++) {
                r = a[i][k];
                a[i][k] = a[l][k];
                a[l][k] = (-r);
            }
        }
        r = a[i][j];
        for (k = i + 1; k < n; ++k)
        {
            double c = (-a[k][j]) / r;
            a[k][j] = 0.0;
            for (l = j + 1; l < n; ++l)
            {
                a[k][l] += c * a[i][l];
            }
        }
        i++;
        j++;
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    double d = 1.0;
    cout << "¬ведите размер матрицы: ";
    cin >> n;
    double **a= new double *[n];
    for (int i = 0; i < n; i++)
        a[i] = new double[n];
    cout << "¬ведите элементы матрицы: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a [i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cout << fixed  << a[i][j] << " ";
        }
        cout << endl;
    }
    g(a, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cout << fixed  << a[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(a[i][j]) < eps) {
                a[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        d *= a[i][i];
    }
    cout << "ќпределитель матрицы = " << d;
    return 0;
}
