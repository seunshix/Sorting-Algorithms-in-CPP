## Insertion Sort
A C++ program that performs insertion sort on 100,000 randomly generated numbers and measures the time it takes to sort the numbers.

## Requirements
1. C++ compiler
2. Standard Libraries:
    - iostream
    - conio.h
    - ctime
    - chrono
    - fstream
    - cstdlib
    - iomanip
    - math.h
    - vector
    - random
    - string

## Input
The input is a text file named InsertionSort.inputFile.txt that contains 100,000 randomly generated numbers.

## Output
The output is the sorted list of numbers and the time it takes to sort the numbers in seconds.

## Running the code
To run the code, compile it using your preferred C++ compiler and run the executable file.

## Functionality
The program performs the following steps:

1. Generates 100,000 random numbers and saves them in a text file InsertionSort.inputFile.txt
2. Reads the contents of the text file and stores the numbers in a vector
3. Sorts the numbers using the insertion sort algorithm
4. Prints the sorted numbers and the time it took to sort them

### Time Complexity
The time complexity of the insertion sort algorithm is O(n^2) in the worst-case scenario, making it inefficient for large data sets. However, it is efficient for small data sets and is easy to understand and implement.