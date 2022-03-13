#ifndef UNSORTED_H
#define UNSORTED_H

#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

/**
 * Class denoting an unsorted matrix with words.
 */
class Unsorted
{
private:
    long long unsigned int wordsAdded;
    string* words;

public:
    /**
     * Initializes an unsorted matrix with zero words.
     *
     * @param numOfWords the amount of words in the text.
     */
    Unsorted(long long unsigned int numOfWords);

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
};

#endif // UNSORTED_H
