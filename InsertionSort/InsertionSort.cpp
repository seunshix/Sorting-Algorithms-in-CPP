#include <iostream>
#include <conio.h>
#include <ctime>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include <vector>
#include <random>
#include <string>

using namespace std;

void printv(vector<unsigned long long>& v1) {

    for (int i = 0; i < v1.size(); ++i) {

        cout << v1[i] << endl;
    }
}
void InsertionSort(vector<unsigned long long>&v1, int &vsize) {
    
    int i, j;
    unsigned long long key;
    for (j = 0; j < vsize; ++j) {
        key = v1[j];
        i = j - 1 ;
       
        while (i >= 0 && (v1[i] > key)) {
            v1[i + 1] = v1[i];
            i = i - 1;
        }
        v1[i + 1] = key;
    }
    cout << "Sorted" << endl;
    printv(v1);
}

int main()
{
    unsigned long long ya;
    vector<unsigned long long> instance;
    fstream inFile;
    inFile.open("InsertionSort.inputFile.txt", ios_base::out | ios_base::in); // Open for OUTPUT and input!
    
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
        inFile << number << "\n";
    }

    // We shouldn't need this check, because of the earlier " if (!inFile) " check.
   
    if (inFile.is_open()) {
       // cout << "File contents:" << endl;
        inFile.seekg(0); // REWIND the file before reading its contents!
        //cout << inFile.rdbuf();
        inFile.close();
    }

    else {
        cout << "file is not open";
    }

    inFile.open("InsertionSort.inputFile.txt");
    while (inFile >> ya) {
         instance.push_back(ya);
    }
    inFile.close();

   
    cout << endl;
   
    int d = instance.size();
   

       
        auto start = std::chrono::high_resolution_clock::now();
        InsertionSort(instance, d);
        cout << endl;
        auto stop = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
       



    
    cout << endl;
    
    return 0;
}
