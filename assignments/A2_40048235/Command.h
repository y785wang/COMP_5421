#ifndef COMMAND_H
#define COMMAND_H

#include <string>

using std::string;

// enum for command type
enum Cmd { APPEND_AFTER, INSERT_BEFORE, PASTE_BELOW, PASTE_ABOVE, DELETE, CUT, REPLACE, JOIN, PRINT, CHANGE, MOVE_UP, MOVE_DOWN, GO, WRITE, QUIT, INVALID_RANGE, INVALID_COMMAND, EMPTY_BUFFER };

class Command {
  private:
    string command; // command issued by user
    Cmd cmd; // command type
    int x, y; // two line addresses
  public:
    Command(string);
    ~Command();
    void parse(int, int);
    void trim(string, string);
    bool checkInt(string) const;
    Cmd getCommand() const;
    int getX() const;
    int getY() const;
};

#endif
