#include "sorted.h"

Sorted::Sorted(long long unsigned int numOfWords){
    words = new string[numOfWords];
    timesAppeared = new long long unsigned int[numOfWords];
    wordsAdded = 0;
}

void Sorted::addWord(string word){
    words[wordsAdded] = word;
    wordsAdded++;
}

void Sorted::deleteWord(string word){
    for(long long unsigned int i = 0; i < wordsAdded; i += timesAppeared[i]){
        if(words[i] == word){
            long long unsigned int counter = timesAppeared[i];
            for(long long unsigned int j = i; j < wordsAdded - counter; j++){
                words[j] = words[j + counter];
                timesAppeared[j] = timesAppeared[j + counter];
            }
            wordsAdded -= counter;
            break;
        }
    }
}

void Sorted::printInfo(string word){
    long long unsigned int index = binarySearch(word);
    if(index == -1)
        cout << "The word \"" << word << "\" is used 0 times." << endl;
    else
        cout << "The word \"" << word << "\" is used " << timesAppeared[index] << (timesAppeared[index] > 1  ? " times." : " time.") << endl;
}

int Sorted::binarySearch(string wordToFind){
    long long unsigned int lower = 0;
    long long unsigned int upper = wordsAdded - 1;
    long long unsigned int mid;
    while(lower <= upper){
        mid = (lower + upper) / 2;
        if(wordToFind == words[mid])
            return mid;
        else if(wordToFind > words[mid])
            lower = mid + 1;
        else
            upper = mid - 1;
    }
    return -1;
}

void Sorted::sortWords(){
    sort(words, words + wordsAdded);
}

void Sorted::makeTimesTable(){
    sortWords();
    int counter;
    long long unsigned int i, j, k;
    i = 0;
    while(i < wordsAdded){
        counter = 0;
        for(j = i; j < wordsAdded; j++){
            if(words[j] == words[i])
                counter++;
            else{
                for(k = i; k < j; k++)
                    timesAppeared[k] = counter;
                break;
            }
        }
        i = j;
    }
}
