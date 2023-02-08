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
#include <cmath>
#include <chrono>

using namespace std;

void printv(vector<unsigned int>& v1) {
        for (int i = 0; i < v1.size(); ++i) {

        cout << v1[i] << endl;
    }
}
vector<unsigned int> mergeSort(vector<unsigned int> l, vector<unsigned int> r)
{

    vector<unsigned int> A;

    int i = 0;
    int j = 0;
    while (i != l.size() && j != r.size())
    {
        if (l[i] <= r[j])
        {
            A.push_back(l[i++]);
        }
        else
        {
            A.push_back(r[j++]);
        }
    }

    while (i != l.size())
        A.push_back(l[i++]);

    while (j != r.size())
        A.push_back(r[j++]);

    return A;
}


vector<unsigned int> merge(vector<unsigned int>& A, unsigned int s, unsigned int e)
{
    if (s - e == 0)
    {
        vector<unsigned int> t;
        t.push_back(A[s]);
        return t;
    }

    int m = (s + e) / 2;

    vector<unsigned int> l;
    vector<unsigned int> r;
    l = merge(A, s, m);
    r = merge(A, m + 1, e);

    return mergeSort(l, r);
}



int main()
{
    unsigned int ya;
    vector<unsigned int> instance;
    fstream inFile;
    inFile.open("MergeSort.inputFile.txt", ios_base::out | ios_base::in); // Open for OUTPUT and input!

    if (!inFile) {
        cout << "The file can't be opened" << endl;
        return -1; // Error - no point continuing!
    }

    std::mt19937_64 generator;
    generator.seed(std::time(0));
    uniform_int_distribution<unsigned int>randomNumber(0, 4294967295); //4294967295
   /* cout << "How many instances?" << endl;
    int n;
    cin >> n;*/

    for (int i = 0; i < 100000; i++) {
        unsigned int number = randomNumber(generator); // Save the number so same is displayed and stored!
        inFile << number << "\n";
    }

    // We shouldn't need this check, because of the earlier " if (!inFile) " check.

    if (inFile.is_open()) {
       
        inFile.seekg(0); // REWIND the file before reading its contents!
       
        inFile.close();
    }

    else {
        cout << "file is not open";
    }

    inFile.open("MergeSort.inputFile.txt");
    while (inFile >> ya) {
        instance.push_back(ya);
    }
    inFile.close();


    int d = instance.size() - 1;
    auto start = std::chrono::high_resolution_clock::now();
    instance = merge(instance, 0, d);
    printv(instance);
    cout << endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9); 
    cout << endl;

    return 0;
}



