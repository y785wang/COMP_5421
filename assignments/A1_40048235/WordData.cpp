#include "WordData.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;




/**************************************************
 
 WordData():
 Constructor
 
 **************************************************/
WordData::WordData(char *newWord, int lineNumber) : frequence(0) {
    word = new char[strlen(newWord) + 1];
    char *dest = word;
    char *source = newWord;
    while ((*dest++ = tolower(*source++)));
    lineNumbers.append(lineNumber);
    ++frequence;
}




/**************************************************
 
 ~WordData():
 Destructor
 
 **************************************************/
WordData::~WordData() {
    delete [] word;
}




/**************************************************
 
 WordData():
 Copy contructor
 
 **************************************************/
WordData::WordData(const WordData &wd) {
    frequence = wd.frequence;
    lineNumbers = wd.lineNumbers;
    char *dest = word;
    char *source = wd.word;
    while ((*dest++ = *source++));
}




/**************************************************
 
 operator=:
 Copy assignment operator
 
 **************************************************/
void WordData::operator=(const WordData &wd) {
    if (this == &wd) return;
    delete [] word;
    frequence = wd.frequence;
    lineNumbers = wd.lineNumbers;
    char *dest = word;
    char *source = wd.word;
    while ((*dest++ = *source++));
}




/**************************************************
 
 checkLineNumbeerExist:
 Determine whether a line number is in the line
 number list
 
 **************************************************/
bool WordData::checkLineNumberExist(int lineNumber) const {
    return lineNumbers.checkExist(lineNumber);
}




/**************************************************
 
 append:
 Append a given number to the list of line numbers,
 only if it is not already there
 
 **************************************************/
void WordData::append(int lineNumber) {
    if (!checkLineNumberExist(lineNumber)) {
        lineNumbers.append(lineNumber);
    }
    ++frequence;
}




/**************************************************
 
 getFrequence:
 Get the frequence count
 
 **************************************************/
int WordData::getFrequence() const {
    return frequence;
}




/**************************************************
 
 getWord:
 Get a read-only pointer to the stored word
 
 **************************************************/
const char* WordData::getWord() const {
    return word;
}




/**************************************************
 
 getLineNumbers:
 Get a read-only reference to the NumList object
 
 **************************************************/
const NumList& WordData::getLineNumbers() const {
    return lineNumbers;
}




/**************************************************
 
 compare:
 Determine whether the stored word (case
 insensitive) compares equal to, or comes before
 or after a given word
 
 **************************************************/
int WordData::compare(char *anotherWord) const {
    char lowerCaseWord[strlen(anotherWord) + 1];
    char *dest = lowerCaseWord;
    char *source = anotherWord;
    while ((*dest++ = tolower(*source++)));
    return strcmp(word, lowerCaseWord);
}




/**************************************************
 
 print:
 Print the word, with its frequency count, and list
 of line numbers. The word category (beginning
 character) is also indicated.
 
 **************************************************/
void WordData::print(char &category) const {
    if (category != word[0]) {
        while (word[0] - category) {
            ++category;
            if (word[0] - category > 0) { // no word for this category
                cout << "<" << (char)toupper(category) << ">" << endl;
            }
        }
        cout << "<" << (char)toupper(category) << ">" << endl;
    }
    cout << setw(15) << word;
    cout << " (" << frequence << ")";
    for (int i = 0; i < lineNumbers.getSize(); ++i) {
        cout << " " << lineNumbers.getElementAt(i);
    }
    cout << endl;
}
