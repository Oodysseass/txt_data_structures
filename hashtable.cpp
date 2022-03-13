#include "hashtable.h"

HashNode::HashNode(string word){
    this->word = word;
    timesAppeared = 1;
}

HashTable::HashTable(long long unsigned int capacity){
    this->capacity = capacity;
    wordsAdded = 0;
    table = new HashNode*[capacity];
    for(long long unsigned int i = 0; i < capacity; i++)
        table[i] = NULL;
}

void HashTable::addWord(string word){
    long long unsigned int index = hashWord(word);
    while(table[index] != NULL){
        if(table[index]->word == word){
            table[index]->timesAppeared++;
            break;
        }
        index++;
        index %= capacity;
    }
    if(table[index] == NULL)
        table[index] = new HashNode(word);
}

int HashTable::hashWord(string word){
    int sum = 0;
    for(int i = 0; i < word.length(); i++)
        sum += (int) word[i];
    return  sum % capacity;
}

long long unsigned int HashTable::findWord(string word){
    long long unsigned int counter = 0;
    long long unsigned int index = hashWord(word);
    while(table[index] != NULL && counter < capacity){
        if(table[index]->word == word)
            return index;
        counter++;
        index++;
        index %= capacity;
    }
    return capacity;
}

void HashTable::printInfo(string word){
    long long unsigned int index = findWord(word);
    if(index == capacity)
        cout << "The word \"" << word << "\" is used 0 times." << endl;
    else
        cout << "The word \"" << word << "\" is used " << table[index]->timesAppeared << (table[index]->timesAppeared > 1  ? " times." : " time.") << endl;
}
