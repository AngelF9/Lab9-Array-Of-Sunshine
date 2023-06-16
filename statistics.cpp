/** Implementation for statistics related functions.
@file statistics.cpp
@author Angel Fuentes
*/

#include "statistics.h"
#include <algorithm>
#include <iostream>
using namespace std;

int minimum(const int a[], int n) { return a[0]; }

int maximum(const int a[], int n) { return a[n - 1]; }

int average(const int a[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  return sum / n;
}

int median(const int a[], int n) {
  if (n % 2 == 0) {
    return (a[n / 2] + a[n / 2 - 1]) / 2;
  }
  return a[n / 2];
}

void all_stats(const int a[SIZE], int n, int& min, int& max, int& med,
               int& avg) {
  int b[SIZE];

  copy(a, a + n, b);
  sort(b, b + n);

  min = minimum(b, n);
  max = maximum(b, n);
  med = median(b, n);
  avg = average(b, n);
  return;
}
