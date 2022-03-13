#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

/**
 * Class denoting the items hash table will be made from.
 */
class HashNode
{
public:
    string word;
    long long unsigned int timesAppeared;

    /**
     * Initializes a node with its key (word) and 1 time appeared.
     */
    HashNode(string word);
};

class HashTable
{
public:
    HashNode** table;
    long long unsigned int capacity;
    long long unsigned int wordsAdded;

    /**
     * Initializes a HashTable with given capacity and NULL content.
     *
     * @param capacity the starting capacity of the table.
     */
    HashTable(long long unsigned int capacity);

    /**
     * Adds a new object to the HashTable, using the hash function and handling
     * possible collisions.
     *
     * @param word the word the new HashNode will store.
     */
    void addWord(string word);

    /**
     * Hash function to get the index of the key. It calculates the sum of the string
     * in ASCII code and then sum modulo capacity.
     *
     * @param word the word which index we need to find.
     * @return the index of the word in the HashTable.
     */
    int hashWord(string word);

    /**
     * Finds a certain word in the HashTable using hash function.
     *
     * @param word the word to be found.
     * @return the index of the word in the HashTable should the word exist
     * or capacity otherwise.
     */
    long long unsigned int findWord(string word);

    /**
     * Finds a certain word in the HashTable and prints
     * how many times it is appeared.
     *
     * @param word the word to print info about.
     */
    void printInfo(string word);
};

#endif // HASHTABLE_H
