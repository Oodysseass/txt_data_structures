#ifndef SORTED_H
#define SORTED_H

#include <iostream>
#include <string>
#include <chrono>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

/**
 * Class denoting a sorted matrix with words.
 */
class Sorted
{
private:
    long long unsigned int wordsAdded;
    string* words;
    long long unsigned int* timesAppeared;

public:
    /**
     * Initializes an sorted matrix with zero words.
     *
     * @param numOfWords the amount of words in the text.
     */
    Sorted(long long unsigned int numOfWords);

    /**
     * Adds a word to the array and increases times appeared.
     *
     * @param word the word to be added.
     */
    void addWord(string word);

    /**
     * Deletes a word from the matrix.
     *
     * @param word the word to be deleted.
     */
    void deleteWord(string word);

    /**
     * Finds a word in the array and prints how many times it is appeared.
     *
     * @param word the word to be searched.
     */
    void printInfo(string word);

    /**
     * Searches a word in the sorted array using binary search.
     *
     * @param wordToFind the word we are looking for.
     * @return the index of the word's position or -1 if the word is not in the array.
     */
    int binarySearch(string wordToFind);

    /**
     * Sorts the string array with the words in ascending order.
     */
    void sortWords();

    /**
     * Creates an int array with the times each word apperas
     */
    void makeTimesTable();
};

#endif // SORTED_H
