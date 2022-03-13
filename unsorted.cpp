#include "unsorted.h"

Unsorted::Unsorted(long long unsigned int numOfWords){
    words = new string[numOfWords];
    wordsAdded = 0;
}

void Unsorted::addWord(string word){
    words[wordsAdded] = word;
    wordsAdded++;
}

void Unsorted::deleteWord(string word){
    for(long long unsigned int i = 0; i < wordsAdded; i++){
        if(words[i] == word)
            words[i] = "";
    }
}

void Unsorted::printInfo(string word){
    long long unsigned int i;
    long long unsigned int counter = 0;
    for(i = 0; i < wordsAdded; i++){
        if(words[i] == word)
            counter++;
    }
    if(!counter)
        cout << "The word \"" << word << "\" is used 0 times." << endl;
    else
        cout << "The word \"" << word << "\" is used " << counter << ((counter > 1)? " times." : " time.") << endl;
}
