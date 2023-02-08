#include<iostream>
#include<conio.h>
#include <ctime>
#include<fstream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include <vector>
#include <random>
#include <string>
#include <chrono>

using namespace std;

//void QuickSort(vector<unsigned long long>&, int&, unsigned long long&);
//unsigned long long Partition(vector<unsigned long long>&, unsigned long long &, unsigned long long &);

void printv(vector<unsigned long long>& v1) {

    for (int i = 0; i < v1.size(); ++i) {

        cout << v1[i] << endl;
    }
}

void swap(unsigned long long* a, unsigned long long* b) {
    int s = *a;
    *a = *b;
    *b = s;
}

int Partition(vector<unsigned long long>& v1, int p, int r) {
    
    int i, j;
    i = p - 1;
    unsigned long long x;
    x = v1[r];
    // x = rand() % (r - p + 1) + p;

    for (j = p; j <= r - 1; j++) {
        if (v1[j] <= x) {
            i++;
            swap(v1[i], v1[j]);
        }
    }
    swap(v1[i + 1], v1[r]);

    return i + 1;
}

void QuickSort(vector<unsigned long long>& v1, int p, int r) {
    if (p < r) {
        unsigned long long q = Partition(v1, p, r);
        QuickSort(v1, p, q - 1);
        QuickSort(v1, q + 1, r);
    }
 }


int main()
{
    unsigned long long ya;
    vector<unsigned long long> instance;
    fstream inFile;
    inFile.open("QuickSort.inputFile.txt", ios_base::out | ios_base::in); // Open for OUTPUT and input!

    if (!inFile) {
        cout << "The file can't be opened" << endl;
        return -1; // Error - no point continuing!
    }

    std::mt19937_64 generator;
    generator.seed(std::time(0));
    uniform_int_distribution<unsigned long long>randomNumber(0, 4294967295); //4294967295
    /*cout << "How many instances?" << endl;
    int n;
    cin >> n;*/

    for (int i = 0; i < 100000; i++) {
        unsigned long long number = randomNumber(generator); // Save the number so same is displayed and stored!
        inFile << number << "\n ";
    }

    // We shouldn't need this check, because of the earlier " if (!inFile) " check.

    if (inFile.is_open()) {
        //cout << "File contents:" << endl;
        inFile.seekg(0); // REWIND the file before reading its contents!
        //cout << inFile.rdbuf();
        inFile.close();
    }

    else {
        cout << "file is not open";
    }

    inFile.open("QuickSort.inputFile.txt");
    while (inFile >> ya) {
        instance.push_back(ya);
    }
    inFile.close();
    cout << "" << endl;
    cout << "+++++++++++++++++++++++++++++SORTED++++++++++++++++++++++++++++++" << endl;
    
  
    int d = instance.size();
    auto start = std::chrono::high_resolution_clock::now();
    QuickSort(instance,0, d-1);
    printv(instance);
    cout << endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
   
   
   
    
    cout << "" << endl; cout << "" << endl; cout << "" << endl;
    return 0;
}
