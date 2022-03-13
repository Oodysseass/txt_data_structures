#include <iostream>
#include <fstream>
#include <string>
#include "unsorted.h"
#include "sorted.h"
#include "bst.h"
#include "avl.h"
#include "hashtable.h"

using namespace std;

string fixWord(string word){                                    //function for removing punctuation, numbers, fixing capital letters etc
    while(!((word[0] > 64 && word[0] < 91) || (word[0] > 96 && word[0] < 123)) && word.length() > 0){
        for(int i = 0; i < word.length() - 1; i++)
            word[i] = word[i + 1];
        word.resize(word.length() - 1);
    }
    while(!((word[word.length() - 1] > 64 && word[word.length() - 1] < 91) || (word[word.length() - 1] > 96 && word[word.length() - 1] < 123)) && word.length() > 0){
        word.pop_back();
    }
    for(int i = 0; i < word.length(); i++){
        if(word[i] > 64 && word[i] < 91)
            word[i] += 32;
    }
    return word;
}

int main(){
    srand(time(NULL));
    fstream readFile("gutenberg.txt");
    long long unsigned int numOfWords = 0;                      //variable for the total number of words
    string word;
    while(readFile >> word){                                    //getting total number of words for size purposes
            word = fixWord(word);
            if(word.length() > 0)                               //precautionary measure
                numOfWords++;
    }
    Unsorted unsortedWords(numOfWords);
    Sorted sortedWords(numOfWords);
    BST btree, *bst = NULL;
    AVL avltree, *avl = NULL;
    HashTable hashTable(numOfWords);
    bool flag = true;                                           //flag for first word, used for the BST and AVL trees
    readFile.clear();                                           //setting file pointer to start
    readFile.seekg(0);
    auto start = high_resolution_clock::now();
    while(readFile >> word){
        word = fixWord(word);
        if(word.length() > 0)
            unsortedWords.addWord(word);
    }
    auto ending = high_resolution_clock::now();
    auto timeNeeded = duration_cast<microseconds>(ending - start);
    cout << "Time needed to create unsorted matrix: " << timeNeeded.count() / 1000000 << "sec." << endl;
    readFile.clear();
    readFile.seekg(0);
    start = high_resolution_clock::now();
    while(readFile >> word){
        word = fixWord(word);
        if(word.length() > 0)
            sortedWords.addWord(word);
    }
    sortedWords.makeTimesTable();
    ending = high_resolution_clock::now();
    timeNeeded = duration_cast<microseconds>(ending - start);
    cout << "Time needed to create sorted matrix: " << timeNeeded.count() / 1000000 << "sec." << endl;
    readFile.clear();
    readFile.seekg(0);
    start = high_resolution_clock::now();
    while(readFile >> word){
        word = fixWord(word);
        if(word.length() > 0){
            if(!flag)
                btree.addWord(bst, word);
            else{
                bst = btree.addWord(bst, word);
                flag = false;
            }
        }
    }
    ending = high_resolution_clock::now();
    timeNeeded = duration_cast<microseconds>(ending - start);
    cout << "Time needed to create BST: " << timeNeeded.count() / 1000000 << "sec." << endl;
    readFile.clear();
    readFile.seekg(0);
    start = high_resolution_clock::now();
    while(readFile >> word){
        word = fixWord(word);
        if(word.length() > 0)
            avl = avltree.addWord(avl, word);
    }
    ending = high_resolution_clock::now();
    timeNeeded = duration_cast<microseconds>(ending - start);
    cout << "Time needed to create AVL tree: " << timeNeeded.count() / 1000000 << "sec." << endl;
    readFile.clear();
    readFile.seekg(0);
    start = high_resolution_clock::now();
    while(readFile >> word){
        word = fixWord(word);
        if(word.length() > 0)
            hashTable.addWord(word);
    }
    ending = high_resolution_clock::now();
    timeNeeded = duration_cast<microseconds>(ending - start);
    cout << "Time needed to create hash map: " << timeNeeded.count() / 1000000 << "sec." << endl << endl;
    readFile.clear();
    readFile.seekg(0);
    int random = rand() % 100;
    string* randomWords = new string[random];
    int i = 0;
    while(i < random){
        readFile >> word;
        if((rand() % 10000000) == 0){
            word = fixWord(word);
            if(word.length() > 0){
                randomWords[i] = word;
                i++;
            }
        }
        if(!(readFile >> word)){
            readFile.clear();
            readFile.seekg(0);
        }
    }
    cout << "We are going to print info about " << random << " random words from the given text." << endl << endl << endl;
    cout << "-----------------Unsorted Matrix-----------------" << endl << endl;
    start = high_resolution_clock::now();
    for(int i = 0; i < random; i++){
        unsortedWords.printInfo(randomWords[i]);
    }
    ending = high_resolution_clock::now();
    timeNeeded = duration_cast<microseconds>(ending - start);
    cout << "Time needed to find the words in unsorted matrix: " << timeNeeded.count() / 1000000 << "sec." << endl << endl << endl;
    cout << "-----------------Sorted Matrix-----------------" << endl << endl;
    start = high_resolution_clock::now();
    for(int i = 0; i < random; i++){
        sortedWords.printInfo(randomWords[i]);
    }
    ending = high_resolution_clock::now();
    timeNeeded = duration_cast<microseconds>(ending - start);
    cout << "Time needed to find the words in sorted matrix: 0.00" << timeNeeded.count() / 1000 << "sec." << endl << endl << endl;
    cout << "-----------------BST-----------------" << endl << endl;
    start = high_resolution_clock::now();
    for(int i = 0; i < random; i++){
        btree.printInfo(bst, randomWords[i]);
    }
    ending = high_resolution_clock::now();
    timeNeeded = duration_cast<microseconds>(ending - start);
    cout << "Time needed to find the words in BST: 0.00" << timeNeeded.count() / 1000 << "sec." << endl << endl << endl;
    cout << "-----------------AVL Tree-----------------" << endl << endl;
    start = high_resolution_clock::now();
    for(int i = 0; i < random; i++){
        avltree.printInfo(avl, randomWords[i]);
    }
    ending = high_resolution_clock::now();
    timeNeeded = duration_cast<microseconds>(ending - start);
    cout << "Time needed to find the words in AVL tree: 0.00" << timeNeeded.count() / 1000 << "sec." << endl << endl << endl;
    cout << "-----------------Open Address Hash Map-----------------" << endl << endl;
    start = high_resolution_clock::now();
    for(int i = 0; i < random; i++){
        hashTable.printInfo(randomWords[i]);
    }
    ending = high_resolution_clock::now();
    timeNeeded = duration_cast<microseconds>(ending - start);
    cout << "Time needed to find the words in hash map: 0.00" << timeNeeded.count() / 1000 << "sec." << endl << endl << endl;
    return 0;
}
