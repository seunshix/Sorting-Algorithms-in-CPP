## QuickSort Algorithm
This code implements the QuickSort algorithm in C++. QuickSort is an efficient sorting algorithm, with an average time complexity of O(n log n).

## Dependencies
The code requires the following libraries:

- iostream
- conio.h
- ctime
- fstream
- cstdlib
- iomanip
- math.h
- vector
- random
- string
- chrono

## Usage
1. Run the code using a C++ compiler.
2. The code will create a file named "QuickSort.inputFile.txt" containing 100000 random numbers, which will be sorted using the QuickSort algorithm.
3. The sorted numbers will be displayed on the console and the time taken to sort the numbers will be displayed in seconds.

## QuickSort Algorithm Implementation
The implementation of the QuickSort algorithm is done using the function QuickSort(vector<unsigned long long> &v1, int p, int r). The algorithm works by dividing the array into two parts based on a pivot element, such that elements less than the pivot are to the left and elements greater than the pivot are to the right. The same process is repeated on the left and right partitions until the entire array is sorted. The pivot element is selected using the function Partition(vector<unsigned long long> &v1, int p, int r).

## Output
The code will output the sorted numbers and the time taken to sort the numbers in seconds.