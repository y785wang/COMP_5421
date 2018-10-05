#ifndef WORDLIST_H
#define WORDLIST_H

#include "WordData.h"
#include "string.h"
#include <string>
#include <iostream>

using std::string;
using std::ostream;

class WordList {
  private:
    struct WordNode {
      public:
        WordData wd;
        WordNode *next;
        inline WordNode(char *word, int lineNumber) : next(nullptr), wd(word, lineNumber) {}
        inline WordNode(char *word, int lineNumber, WordNode *wd) : next(wd), wd(word, lineNumber) {}
    };
  
    WordNode *firstNode;
    WordNode *lastNode;
    int size;
    
    void loadList(string);
    WordNode* getMatchedWordNode(char *) const;
    void addNewWord(char *, int);

  public:
    WordList(const string);
    ~WordList();
    WordList(const WordList &);
    void operator=(const WordList &);
    
    int getSize() const;
    void printList(ostream &) const;
};

#endif
