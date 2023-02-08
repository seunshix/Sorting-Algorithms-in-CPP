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

using namespace std;

class BST {

    struct node {
        int data;
        node* left;
        node* right;
    };

    node* root;

    node* minimum(node* bstree)
    {
        if (bstree == NULL)
            return NULL;
        else if (bstree->left == NULL)
            return bstree;
        else
            return minimum(bstree->left);
    }

    node* maximum(node* bstree) {
        if (bstree == NULL)
            return NULL;
        else if (bstree->right == NULL)
            return bstree;
        else
            return maximum(bstree->right);
    }

    node* deleteNode(int x, node* bstree) {
        node* temp;
        if (bstree == NULL)
            return NULL;
        else if (x < bstree->data)
            bstree->left = deleteNode(x, bstree->left);
        else if (x > bstree->data)
            bstree->right = deleteNode(x, bstree->right);
        else if (bstree->left && bstree->right)
        {
            temp = minimum(bstree->right);
            bstree->data = temp->data;
            bstree->right = deleteNode(bstree->data, bstree->right);
        }
        else
        {
            temp = bstree;
            if (bstree->left == NULL)
                bstree = bstree->right;
            else if (bstree->right == NULL)
                bstree = bstree->left;
            delete temp;
        }

        return bstree;
    }

    void inOrderTree(node* bstree) {
        if (bstree == NULL)
            return;
        inOrderTree(bstree->left);
        cout << bstree->data << " ";
        inOrderTree(bstree->right);
    }

    node* makeTreeEmpty(node* bstree) {
        if (bstree == NULL)
            return NULL;
        {
            makeTreeEmpty(bstree->left);
            makeTreeEmpty(bstree->right);
            delete bstree;
        }
        return NULL;
    }


    node* insertNode(int x, node* bstree)
    {
        if (bstree == NULL)
        {
            bstree = new node;
            bstree->data = x;
            bstree->left = bstree->right = NULL;
        }
        else if (x < bstree->data)
            bstree->left = insertNode(x, bstree->left);
        else if (x > bstree->data)
            bstree->right = insertNode(x, bstree->right);
        return bstree;
    }

    node* find(node* bstree, int x) {
        if (bstree == NULL)
            return NULL;
        else if (x < bstree->data)
            return find(bstree->left, x);
        else if (x > bstree->data)
            return find(bstree->right, x);
        else
            return bstree;
    }

    int height(struct node* node)
    {
        if (node == NULL)
            return 0;
        else
        {
            int lDepth = height(node->left);
            int rDepth = height(node->right);

            if (lDepth > rDepth)
                return(lDepth + 1);
            else return(rDepth + 1);
        }

        
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        root = makeTreeEmpty(root);
    }

    void insertNode(int x) {
        root = insertNode(x, root);
    }

    void deleteNode(int x) {
        root = deleteNode(x, root);
    }

    void display() {
        inOrderTree(root);
        cout << endl;
    }

    void search(int x) {
        root = find(root, x);
    }

    void depth() {
        height(root);
        cout << height(root)<<endl;
           
    }
};

int main() {
    int ya;
    vector<int> instance;
    fstream inFile;
    inFile.open("BST.inputFile.txt", ios_base::out | ios_base::in); 

    if (!inFile) {
        cout << "The file can't be opened" << endl;
        return -1; 
    }

    std::mt19937_64 generator;
    generator.seed(std::time(0));
    uniform_int_distribution<int>randomNumber(1, 1000); 
    

    //for (int i = 0; i < 10; i++) {
    //    int number = randomNumber(generator); // Save the number so same is displayed and stored!
    //    inFile << number << "\n";
    //}

   
    if (inFile.is_open()) {
        cout << "File contents:" << endl;
        inFile.seekg(0); 
        cout << inFile.rdbuf();
        inFile.close();
    }

    else {
        cout << "file is not open";
    }

    inFile.open("BST.inputFile.txt");
    while (inFile >> ya) {
        instance.push_back(ya);
    }
    inFile.close();


    cout << endl;

    int d = instance.size();



    BST bstree;
    for (int i = 0; i < instance.size(); i++) {

        bstree.insertNode(instance[i]);
    }

       
    cout << "Binary Search Tree" << endl;
    bstree.display();

    cout << "Tree Height: " << endl;
    bstree.depth();

    int a;

    cout << "What do you want to delete" << endl;
    cin >> a;

    for (int i = 0; i < instance.size(); i++) {
        if (a == instance[i]) {
            bstree.deleteNode(a);

        }
    }
    bstree.display();
  
    return 0;
}