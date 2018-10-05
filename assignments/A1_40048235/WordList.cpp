#include "WordList.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "ctype.h"
#include "string.h"
#include "assert.h"

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
using std::ostream;




/**************************************************
 
 WordList():
 Constructor
 
 **************************************************/
WordList::WordList(const string filename):firstNode(nullptr), lastNode(nullptr), size(0) {
    loadList(filename);
}




/**************************************************
 
 ~WordList():
 Destructor
 
 **************************************************/
WordList::~WordList() {
    WordNode *currentNode = firstNode;
    WordNode *nextNode;
    for (int i = 0; i < size; ++i) {
        nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
}




/**************************************************

 WordList():
 Copy contructor

 **************************************************/
WordList::WordList(const WordList &wl) {
    firstNode = wl.firstNode;
    lastNode = wl.lastNode;
    size = wl.size;
}




/**************************************************

 operator=:
 Copy assignment operator

 **************************************************/
void WordList::operator=(const WordList &wl) {
    if (this == &wl) return;
    WordNode *currentNode = firstNode;
    WordNode *nextNode;
    for (int i = 0; i < size; ++i) {
        nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    firstNode = wl.firstNode;
    lastNode = wl.lastNode;
    size = wl.size;
}




/**************************************************
 
 loadList:
 Read test.txt, one token by one token (within
 one line, tokens are separated by white space),
 trim the token to a human readable word, then
 try to add them int WordList.
 
 **************************************************/
void WordList::loadList(const string filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "ERRER: Could not open input file: " << filename << endl;
        exit(1);
    }
    int lineNumber = 0;
    string line;
    getline(fin, line);
    while (fin) {
        ++lineNumber;
        istringstream iss(line);
        string word;
        while (iss >> word) {
            // trim word(token), remove punctuation character and decimal digit
            int begin = 0;
            int end = word.length() - 1;
            while (begin < word.length() && (ispunct(word.at(begin)) || isdigit(word.at(begin)))) { ++begin; }
            while (end >= 0 && (ispunct(word.at(end)) || isdigit(word.at(end)))) { --end; }
            if (end - begin >= 0) {
                word = word.substr(begin, end - begin + 1);
                char *charArrayWord = new char[word.length() + 1];
                std::strcpy(charArrayWord, word.c_str());
                addNewWord(charArrayWord, lineNumber);
                delete[] charArrayWord;
            }
        }
        getline(fin, line);
    }
    fin.close();
}




/**************************************************
 
 getMatchedWordNode:
 Return a WordNode if its WordData member has the
 same word field as the given word, nullptr otherwise.
 
 **************************************************/
WordList::WordNode* WordList::getMatchedWordNode(char *word) const {
    assert(size > 0);
    char *ctemp = word;
    while ((*ctemp = tolower(*ctemp))) ++ctemp;
    WordNode *matchedNode = firstNode;
    do {
        if (0 == strcmp(word, matchedNode->wd.getWord())) {
            break;
        }
        matchedNode = matchedNode->next;
    } while (matchedNode);
    return matchedNode;
}




/**************************************************
 
 addNewWord:
 Add a new WordNode if the word member for it does
 not exist, append to a existing WordNode otherwise.
 
 **************************************************/
void WordList::addNewWord(char *word, int lineNumber) {
    if (0 == size) {
        WordNode *wn = new WordNode(word, lineNumber);
        firstNode = wn;
        lastNode = wn;
        ++size;
    } else {
        WordNode *matchedNode = getMatchedWordNode(word);
        if (nullptr == matchedNode) {
            WordNode *wn = new WordNode(word, lineNumber);
            if (firstNode->wd.compare(word) > 0) { // insert beginning case
                wn->next = firstNode;
                firstNode = wn;
            } else {
                if (1 == size) { // size == 1 case
                    firstNode->next = wn;
                    lastNode = wn;
                } else { // size > 1 case
                    WordNode *checkNode = firstNode;
                    while (true) {
                        if (checkNode->next->wd.compare(word) > 0) { // insert middle case
                            wn->next = checkNode->next;
                            checkNode->next = wn;
                            break;
                        }
                        checkNode = checkNode->next;
                        if (checkNode->next == nullptr) break;
                    }
                    if (nullptr == wn->next) { // insert ending case
                        checkNode->next = wn;
                        lastNode = wn;
                    }
                }
                
            }
            ++size;
        } else {
            matchedNode->wd.append(lineNumber);
        }
    }
}




/**************************************************
 
 getSize:
 Return the size of WordList.
 
 **************************************************/
int WordList::getSize() const {
    return size;
}




/**************************************************
 
 printList:
 Print the entire WordList in sorting order.
 
 **************************************************/
void WordList::printList(ostream & out) const {
    char category = '`'; // '`' is a character before 'a' in ASCII table
    WordNode *wn = firstNode;
    while (wn) {
        wn->wd.print(category);
        wn = wn->next;
    }
    while (++category <= 'z') {
        out << "<" << (char)toupper(category) << ">" << endl;
    }
}
