## MergeSort
A C++ program that implements the merge sort algorithm and measures its performance.

## Input
The program generates a text file named "MergeSort.inputFile.txt" with 100,000 random integers ranging from 0 to 4294967295. The input file is then used by the program as the data to be sorted.

## Output
The program outputs the sorted integers and the time taken to sort the data.

## Libraries Used
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
- cmath
- chrono

## Usage
Compile the program and run it. The program will generate the input file, sort the data, and print the sorted data and the time taken to sort the data.

## Code structure
1. The program generates a text file with 100,000 random integers using the fstream library.
2. The data from the text file is stored in a vector instance.
3. The merge sort algorithm is implemented in the merge and mergeSort functions.
4. The main function calculates the time taken to sort the data and outputs the sorted data and the time taken.

## Time Complexity
The time complexity of the merge sort algorithm is O(n*log(n)).