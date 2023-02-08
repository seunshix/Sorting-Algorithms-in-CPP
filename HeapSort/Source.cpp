#include <iostream>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include <vector>
#include <random>
#include <string>
#include <cmath>
#include <chrono>

using namespace std;

void printv(vector<unsigned int>& v1) {
    for (int i = 0; i < v1.size(); ++i) {

        cout << v1[i] << endl;;
    }
}

void heapify(std::vector<unsigned int>& v, int size, int i) {
    int max = i; // initialize max as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // if left child is larger than root
    if (left < size && v[left] > v[max])
        max = left;

    // if right child is larger than max
    if (right < size && v[right] > v[max])
        max = right;

    // if max is not root
    if (max != i) {
        // swap
        int temp = v[i];
        v[i] = v[max];
        v[max] = temp;

        // recursively heapify the affected sub-tree
        heapify(v, size, max);
    }
}

void heapSort(std::vector<unsigned int>& v) {
    int size = v.size();

    // build heapSort (revange vay)
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(v, size, i);
    }

    // one by one extract an element from heapSort
    for (int i = size - 1; i >= 0; i--) {
        // move current root to end
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;

        // call max heapify on the reduced heapSort
        heapify(v, i, 0);
    }
}


int main()
{
    unsigned int ya;
    vector<unsigned int> instance;
    fstream inFile;
    inFile.open("HeapSort.inputFile.txt", ios_base::out | ios_base::in); // Open for OUTPUT and input!

    if (!inFile) {
        cout << "The file can't be opened" << endl;
        return -1; // Error - no point continuing!
    }

    std::mt19937_64 generator;
    generator.seed(std::time(0));
    uniform_int_distribution<unsigned int>randomNumber(0, 4294967295); //4294967295
  
    for (int i = 0; i < 100000; i++) {
        unsigned int number = randomNumber(generator); // Save the number so same is displayed and stored!
        inFile << number << "\n ";
    }

    // We shouldn't need this check, because of the earlier " if (!inFile) " check.

    if (inFile.is_open()) {
       // cout << "File contents:" << endl;
        inFile.seekg(0); // REWIND the file before reading its contents!
       // cout << inFile.rdbuf();
        inFile.close();
    }

    else {
        cout << "file is not open";
    }

    inFile.open("HeapSort.inputFile.txt");
    while (inFile >> ya) {
        instance.push_back(ya);
    }
    inFile.close();


    cout << endl;
    cout << "+++++++++++++++++++++++++++++SORTED++++++++++++++++++++++++++++++" << endl;


    int d = instance.size();
    auto start = std::chrono::high_resolution_clock::now();
    heapSort(instance);
    printv(instance);
    cout << endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
    cout << endl;

   
    return 0;
}
