/** Driver for statistics program. Do not alter this file.
@file main.cpp
@author Hong Tai Wei
*/

#include <ios>
#include <iostream>
#include <limits>
#include "statistics.h"
using namespace std;

/**
@brief Main function for statistics program

Prompts user for number of elements in array.
Waits for that many inputs.
Prints out the array and the min/max/median/average value in it.

@return Exit code 0
*/
int main() {
  int a[SIZE];
  int n;

  do {
    cout << "Enter the number of elements (1-20):" << endl;
    cin >> n;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  } while (n < 1 || n > 20);

  for (int i = 0; i < n; i++) {
    cout << "Enter " << n << " numbers separated by spaces" << endl;
    cin >> a[i];
  }

  int min, max, med, avg;
  all_stats(a, n, min, max, med, avg);

  cout << "Your array:\n{";
  for (int i = 0; i < n - 1; i++) {
    cout << a[i] << ", ";
  }
  cout << a[n - 1] << "}" << endl;

  cout << "Minimum value: " << min << endl;
  cout << "Maximum value: " << max << endl;
  cout << "Median value: " << med << endl;
  cout << "Average value: " << avg << endl;

  return 0;
}
