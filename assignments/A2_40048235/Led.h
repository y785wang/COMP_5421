#ifndef LED_H
#define LED_H

#include "Command.h"

#include <list>
#include <vector>
#include <string>
#include <iostream>

using std::list;
using std::vector;
using std::string;

class Led {
  private:
    string filename;
    int currentLine;
    bool saved; // determine if the buffer is saved or not
    list<string> buffer;
    vector<string> clipboard;
  public:
    Led(string);
    ~Led();
    void run();
    void loadFile();
    bool determineCommand();
    
    void appendAfter(int);
    void insertBefore(int);
    void pasteBelow(int);
    void pasteAbove(int);
    void deletes(int, int);
    void cut(int, int);
    void replace(int, int);
    void join(int, int);
    void print(int, int);
    void change(int, int);
    void moveUp(int);
    void moveDown(int);
    void write();
    void quit(bool &);
};

#endif
