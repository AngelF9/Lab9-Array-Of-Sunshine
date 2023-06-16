/** Header file for statistics.cpp. Do not alter this file.
@file statistics.h
@author Hong Tai Wei
*/

#include <iostream>

#ifndef STATISTICS_H
#define STATISTICS_H

const int SIZE = 20;

// Returns the smallest of the first n elements in a sorted array.
int minimum(const int a[], int n);

// Returns the largest of the first n elements in a sorted array.
int maximum(const int a[], int n);

// Returns the average of the first n elements in an unsorted array.
int average(const int a[], int n);

// Returns the median of the first n elements in a sorted array.
int median(const int a[], int n);

// Compute the min, max, median and average of an unsorted array.
void all_stats(const int a[SIZE], int n, int& min, int& max, int& med,
               int& avg);

#endif  // STATISTICS_H
