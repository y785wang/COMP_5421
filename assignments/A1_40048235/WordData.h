#ifndef WORDDATA_H
#define WORDDATA_H

#include "NumList.h"
#include "string.h"
#include "ctype.h"

class WordData {
  private:
    char *word;
    int frequence;
    NumList lineNumbers;

  public:
    WordData(char *, int);
    ~WordData();
    explicit WordData(const WordData &);
    void operator=(const WordData &);
    
    bool checkLineNumberExist(int) const;
    void append(int);
    int getFrequence() const;
    const char* getWord() const;
    const NumList& getLineNumbers() const;
    int compare(char *) const;
    void print(char &) const;
};

#endif
