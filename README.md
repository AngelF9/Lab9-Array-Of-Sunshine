# Lab 9: Array Of Sunshine

In this lab, you will learn how to:
- use pass-by-value arguments in functions
- use pass-by-reference arguments in functions
- use 1-dimensional arrays
- call functions from external libraries

For this assignment, you will write a series of functions that calculate basic statistics based on the values in an `int` array, then practice testing them via the GoogleTest framework.

## File structure

* `Makefile` - Configuration for `make`, which you will be using instead of `g++` to compile code today.
* `statistics.cpp` - Your code goes here.
* `statistics_test.cpp` - Your tests go here.
* `statistics.h` - Header file for `statistics.cpp`, already written for you.
* `main.cpp` - Contains main function if you want to run the functions in `statistics.cpp`.
* `googletest/` - Contains code for the GoogleTest framework.

**Do not change any files other than `statistics.cpp` and `statistics_test.cpp`!**

**Changes to any other files will create a giant mess for you and will also be ignored by the autograder.**

## Make commands

You have the same `make` commands as last time. **Don't use g++**.
* make format
* make test
* make build
* make all
* make clean

## Program specifications

These are the 5 functions you will be working with for this assignment (defined in statistics.h):
* `int minimum(const int a[], int n);`
* `int maximum(const int a[], int n);`
* `int average(const int a[], int n);`
* `int median(const int a[], int n);`
* `void all_stats(const int a[SIZE], int n, int& min, int& max, int& med, int& avg);`

Also, in `statistics.h`, there is a constant called `SIZE`. It's a global constant. You're allowed to use it.

**Read the function specifications in the next section.** Don't write these functions yet.

The specifications will talk about sorted arrays. What is a sorted array?
* All the numbers in the array are in increasing order.
* In other words, a number is never followed by a number smaller than it.
* But it is okay for a number to be followed by the same number.

Examples of sorted/unsorted arrays:

* `{1, 2, 3}` is sorted because the numbers go from low to high
* `{3, 1, 2}` is not sorted because 3 is followed by 1 which is smaller than it, so the numbers don't go from low to high
* `{1, 2, 2}` is sorted because it's okay if two numbers are the same as long as they're next to each other.
* `{2, 1, 2}` is not sorted because the first 2 is followed by a 1, which is smaller than it. 

## Function specifications

### `int minimum(const int a[], int n)`

**Input:** a sorted array of ints and an int representing how much of the array to look at. (Note: when something says the input is "a sorted array", this means you can just assume the array is sorted). You can assume that `n` is a valid input.

**Function behavior:** Return the value of the smallest thing in the first n elements of the input array.
This function should not modify the values in the array or print anything out.

Examples:
* `minimum({0, 3, 100}, 3)` is 0
* `minimum({-10, -3, 0, 5}, 4)` is -10
* `minimum({-10, -3, 0, 5}, 3)` is also -10
* You can assume your function will never receive an array like `{3, 1, 2}` as an input because that's not sorted.

### `int maximum(const int a[], int n)`

**Input:** a sorted array of ints and an int representing how much of the array to look at.
You can assume that `n` is a valid input.

**Function behavior:** Return the value of the biggest thing in the first n elements of the input array.
This function should not modify the values in the array or print anything out.

Examples:
* `maximum({0, 3, 100}, 3)` is 100
* `maximum({-10, -3, 0, 5}, 4)` is 5
* `maximum({-10, -3, 0, 5}, 3)` is 0 because even though the array has more than 3 elements, the function only returns the biggest thing in the first 3 elements.
* You can assume your function will never receive an array like `{3, 1, 2}` as an input because that's not sorted.

### `int average(const int a[], int n)`

**Definition of average:** The average of a group of `n` numbers is the sum of those numbers divided by `n`. Examples:
* The average of `1 3 10 100` is `(1 + 3 + 10 + 100) / 4` (sum all the numbers, then divide by 4 since there's 4 of them)
* The average of `8 4 1 10 8` is `(8 + 4 + 1 + 10 + 8) / 5` (sum all numbers, then divide by 5 since there's 5 of them)
* The average of `7` is `7 / 1` since there's only one number

**Input:** an array of ints and an int representing how much of the array to look at.
You can assume that `n` is a valid input. Note that this array doesn't have to be sorted.

**Function behavior:** Return the value of the average the first n elements of the input array, rounded down to an integer number if necessary.
This function should not modify the values in the array or print anything out.

Examples:
* `average({1, 3, 10, 100}, 4)` is `(1 + 3 + 10 + 100) / 4`. This is `28` in integer arithmetic
* `average({8, 4, 1, 10, 8}, 5)` is `(8 + 4 + 1 + 10 + 8) / 5`. This is `6` in integer arithmetic
* `average({7}, 1)` is `7`
* `average({3, 1, 2}, 3)` is `(3 + 1 + 2) / 3`. This is `2`. Remember, the array doesn't have to be sorted for this function.

### `int median(const int a[], int n)`

**Definition of median:** The median of a group of numbers is the number that is in "the middle" of them when they are put in sorted order.
* If the number of numbers is odd, then it's simply the middle number. Examples:
    * The median of the numbers `1 5 7 30 100` is 7 because there are 5 numbers so it's the value of the third number since that's the middle
    * The median of the numbers `8 8 8` is 8 because there are 3 numbers so it's the value of the second number since that's the middle
* If the number of numbers is even, then it's the average of the middle two numbers. Examples:
    * The median of the numbers `2 5 7 10` is 6 because there are 4 numbers so it's the average of the 2nd and 3rd values (since those are the middle values), and the average of 5 and 7 is 6.
    * The median of the numbers `-10 -5 -5 5 6 7` is 0 because there are 6 numbers so it's the average of the 3rd and 4th values (since those are the middle values), and the average of -5 and 5 is 0.

**Input:** a sorted array of ints and an int representing how much of the array to look at.
You can assume that `n` is a valid input.

**Function behavior:** Return the value of the median of the first n elements of the input array, rounded down to an integer number if necessary.
This function should not modify the values in the array or print anything out.

Examples (see definition of median, above, for explanation):
* `median({1, 5, 7, 30, 100}, 5)` is 7
* `median({8, 8, 8}, 3)` is 8
* `median({2, 5, 7, 10}, 4)` is 6
* `median({-10, -5, -5, 5, 6, 7}, 6)` is 0
* `median({1, 2}, 2)` is 1 because it's the average of 1 and 2 and this needs to be rounded down to an integer.
* You can assume your function will never receive an array like `{3, 1, 2}` as an input because that's not sorted.

### `void all_stats(const int a[SIZE], int n, int& min, int& max, int& med, int& avg)`

For this function, writing `const int a[SIZE]` for the argument instead of just `const int a[]` makes the compiler enforce that the size of the input array is equal to the value of the global constant `SIZE`.
It wasn't needed in the other functions for Part 1, but it's needed for this one. (If you're not sure why, maybe you'll understand why after implementing it.)

**Input:** an array of ints and an int representing how much of the array to look at.
You can also assume that n is greater than 0 and less than `SIZE`. Note that this array doesn't have to be sorted.

**Function behavior:** The return type is void so the function should not return anything. 
However, it should update the values of the variables given to it as the arguments `min, max, med, avg` to be the value of the minimum, maximum, median, and average of the numbers in the first n elements of the array.
This function should not modify the values in the array or print anything out.

Example:
Calling `all_stats({5, 1, 3, 7, 9}, 5, a, b, c, d);` should result in changes to the following variables:
* The value of `a` becomes the minimum value in the array, `1`
* The value of `b` becomes the maximum value in the array, `9`
* The value of `c` becomes the median value of the array, `5` (because 5 is the middle value when the array is sorted)
* The value of `d` becomes the average value of the array, `5` (because `(5 + 1 + 3 + 7 + 9) / 5` is `5`)

## Write test cases

Test cases are located in `statistics_test.cpp`.

Now that we have arrays, the format of your test cases has changed a little so that you don't have to copy and paste the same array over and over again to test each function.

Come up with 5 good test cases, or 5 arrays that you want to give as inputs. 
For each test case array, you need its length and the expected results for minimum, maximum, median, and average.

Near the top of the test case file, there is something that looks like this:

```c++
class StatisticsTest : public ::testing::Test {
  protected:
    int array1[SIZE] = {0};
    int n1 = 0;
    int expected_min1 = 0;
    int expected_max1 = 0;
    int expected_med1 = 0;
    int expected_avg1 = 0;
    
    int array2[SIZE] = {0};
    int n2 = 0;
    int expected_min2 = 0;
    int expected_max2 = 0;
    int expected_med2 = 0;
    int expected_avg2 = 0;
    
    // And so on for 3, 4, and 5
};
```

Fill in the values for those variables based on your test cases. Don't touch anything else in the file. 

The test cases will use these values, so you don't have to keep typing the same array a bunch of times to test the different functions.

You can use unsorted arrays and the test cases will make sure to sort the array if needed before testing the `minimum()`, `maximum()`, and `median()` functions.

### Example test case

For the array `{5, 1, 3, 7, 9}`, the value of `n` is 5 because that's the length.
The minimum is 1, the maximum is 9, and the median and average are both 5.

If this is my first test case, then I would change these lines in the test case file to say:

```
int array1[SIZE] = {5, 1, 3, 7, 9};
int n1 = 5;
int expected_min1 = 1;
int expected_max1 = 9;
int expected_med1 = 5;
int expected_avg1 = 5;
```

Don't change anything else in the file because the code that runs the test cases will just make sure that everything is tested properly based on this, and it's okay that the array is unsorted because the test cases will handle it for the `minimum()`, `maximum()`, and `median()` functions.

## Implement the functions

Now that you have written the test cases, you can implement the functions.

You can write them in whatever order you want.

### Allowed library functions: sort() and copy()

The C++ standard library provides a function called `sort()` that you can use to sort an array and a function called `copy()` that you can use to copy the contents of one array to another. In order to use these functions, you have to say `#include <algorithm>` at the start of the file (already done for you in the starter code). 

Then you can sort an array by saying something like `sort(array, array + n);` where `array` is the array you want to sort, and `n` is the number of elements you want to sort.
`sort()` has return type `void` so it doesn't return a value. However, when the function returns, the first `n` elements of `array` will be in sorted order.

You can copy the first `n` elements of `array1` into `array2` by saying `copy(array1, array1 + n, array2);`. When the function returns, the first `n` elements of `array2` will now have the same values as the first `n` elements of `array1` and `array1` won't be changed at all. This function also has return type `void`.

For this lab, you are allowed to call the `sort()` and `copy()` functions to help you out. You may not call other external library functions.

### Hints and reminders

* If a function specification says you can assume the array is sorted, you should try to take advantage of that fact somehow.
* If you are copying and pasting similar code a lot of times, you should look to see if you can use an existing function, or consider writing an extra function that you can call. You are always allowed to write extra helper functions of your own, or to declare any extra variables that you want.
* For the `all_stats()` function, the code should be very simple and should call the other 4 functions. But wait! Some of those functions assume the input array is sorted, and the `all_stats()` function doesn't get to assume that.
* Speaking of sorted arrays, good thing there's that allowed library function, right?
* If a function specification says you're not allowed to modify the input array, but you really want to do something that modifies it, perhaps you should make a copy of the array. Then you can do whatever you want to the copy.
* Be careful not to try to access an element that is outside of the bounds of the array!

### Test your code

Run `make test` to test your implementation. Fix your code if necessary
