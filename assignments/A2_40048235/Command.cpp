#include "Command.h"

#include "ctype.h"
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::istringstream;
using std::ostringstream;
using std::stringstream;




/**************************************************
 
 Description:
 Command class ctor. Set command variable as user
 issued, set cmd to INVALID_COMMAND, set both line
 address variable x and y to -1
 
 Parameters:
 command: command issued by user
 
 **************************************************/
Command::Command(string command) : command(command), cmd(INVALID_COMMAND), x(-1), y(-1) {}




/**************************************************
 
 Description:
 Command class dtor
 
 **************************************************/
Command::~Command() {}




/**************************************************
 
 Description:
 Parse the trimmed command into four parts, int,
 char, int, char. Then check the constraint of two
 line addresses' range, determine the command type.
 If all valid, set twp line address variables and
 cmd type variable
 
 Parameters:
 currentLine: # of current line
 bufferSize: # of buffer size (# of last line)
 
 **************************************************/
void Command::parse(int currentLine, int bufferSize) {
    // translate two int parameters to corresponding string
    ostringstream oss_cl, oss_bs;
    oss_cl << currentLine;
    oss_bs << bufferSize;
    string originalCommand = command;
    
    // trin the command
    trim(oss_cl.str(), oss_bs.str());
    // cout << "TRIMED: " << command << endl;
    
    // parse the command into four parts
    istringstream iss(command);
    char c_1 = '\0', c_2 = '\0';
    iss >> x;
    iss.clear();
    iss >> c_1; // may be punctuation or command
    iss.clear();
    iss >> y;
    iss.clear();
    iss >> c_2; // may be command
    iss.clear();
    // cout << "PARSED: " << x << "|" << c_1 << "|" << y << "|" << c_2 << endl;
    
    // check empty buffer, check range, determind command type
    if (0 == bufferSize && 1 == originalCommand.length()) { // empty buffer case
        if ("a" == originalCommand) {
            cmd = APPEND_AFTER;
        } else if ("i" == originalCommand) {
            cmd = INSERT_BEFORE;
        } else if ("v" == originalCommand) {
            cmd = PASTE_BELOW;
        } else if ("u" == originalCommand) {
            cmd = PASTE_ABOVE;
        } else if ("w" == originalCommand) {
            cmd = WRITE;
        } else if ("q" == originalCommand) {
            cmd = QUIT;
        } else if ("," == originalCommand) {
            cmd = INVALID_RANGE;
        } else {
            cmd = EMPTY_BUFFER;
        }
    } else if ('a' == c_1 || 'a' == c_2) { // append after
            cmd = (x < 1 || x > bufferSize) ? INVALID_RANGE : APPEND_AFTER;
    } else if ('i' == c_1 || 'i' == c_2) { // insert before
            cmd = (x < 1 || x > bufferSize) ? INVALID_RANGE : INSERT_BEFORE;
    } else if ('v' == c_1 || 'v' == c_2) { // paste below
        cmd = (x < 1 || x > bufferSize) ? INVALID_RANGE : PASTE_BELOW;
    } else if ('u' == c_1 || 'u' == c_2) { // paste above
        cmd = (x < 1 || x > bufferSize) ? INVALID_RANGE : PASTE_ABOVE;
    } else if ('d' == c_1 || 'd' == c_2) { // delete
        if ('d' == c_1) y = x;
        cmd = (x < 1 || x > y || y > bufferSize) ? INVALID_RANGE : DELETE;
    } else if ('x' == c_1 || 'x' == c_2) { // cut
        if ('x' == c_1) y = x;
        cmd = (x < 1 || x > y || y > bufferSize) ? INVALID_RANGE : CUT;
    } else if ('r' == c_1 || 'r' == c_2) { // replace
        if ('r' == c_1) y = x;
        cmd = (x < 1 || x > y || y > bufferSize) ? INVALID_RANGE : REPLACE;
    } else if ('j' == c_1 || 'j' == c_2) { // join
        if ('j' == c_1) y = x;
        cmd = (x < 1 || x > y || y > bufferSize) ? INVALID_RANGE : JOIN;
    } else if ('p' == c_1 || 'p' == c_2) { // print
        if ('p' == c_1) y = x;
        cmd = (x < 1 || x > y || y > bufferSize) ? INVALID_RANGE : PRINT;
    } else if ('c' == c_1 || 'c' == c_2) { // change
        if ('c' == c_1) y = x;
        cmd = (x < 1 || x > y || y > bufferSize) ? INVALID_RANGE : CHANGE;
    } else if ('+' == c_1 || '+' == c_2) { // move down
        cmd = MOVE_DOWN;
    } else if ('-' == c_1 || '-' == c_2) { // move up
        cmd = MOVE_UP;
    } else if ('g' == c_1 || 'g' == c_2) { // move up
        cmd = (x < 1 || x > bufferSize) ? INVALID_RANGE : GO;
    } else if ('w' == c_1 || 'w' == c_2) { // write
        cmd = WRITE;
    } else if ('q' == c_1 || 'q' == c_2) { // quit
        cmd = QUIT;
    }
}




/**************************************************
 
 Description:
 Interpret user issued command. Change '$' and '.'
 to line number, fill up the missing line address
 and command.
 
 Parameters:
 currentLine: # of current line
 bufferSize: # of buffer size (# of last line)
 
 **************************************************/
void Command::trim(string currentLine, string bufferSize) {
    // remove white spaces
    for (string::iterator it = command.begin(); it != command.end(); ++it) {
        if (isspace(*it)) {
            command.erase(it--);
        }
    }
    
    // interpret command issued by user
    if (command.empty()) { // empty command case
        command = "1+";
    } else if (checkInt(command)) { // single integer case
        command = command + "," + command + "g";
    } else if ("+" == command || "-" == command) { // '+' and '-' case
        command = "1" + command;
    } else if ("," == command) { // ',' case
        command = currentLine + "," + currentLine + "p";
    } else if ("*" == command) { // '*' case
        command = "1," + bufferSize + "p";
    } else if ("." == command || "$" == command) { // translate '.' and '$'
        string lineNumber = ("." == command) ? currentLine : bufferSize;
        command = lineNumber + "," + lineNumber + "g";
    } else if ("a" == command || "i" == command || "v" == command ||
               "u" == command || "d" == command || "x" == command ||
               "r" == command || "j" == command || "p" == command ||
               "c" == command || "g" == command) { // single command variable case
        command = currentLine + "," + currentLine + command;
    } else {
        int count = 0; // the iterator position
        string::iterator it = command.begin();
        for ( ; it != command.end(); ++it) {
            if ('.' == *it) { // translate '.' to currentLine number
                command.replace(count, 1, currentLine);
                it += currentLine.length()-1;
                count += currentLine.length()-1;
            } else if ('$' == *it) { // translate '$' to lastLine number
                command.replace(count, 1, bufferSize);
                it += bufferSize.length()-1;
                count += bufferSize.length()-1;
            } else if (',' == *it) {
                if (0 == count) { // translate ',' if it's at position 0
                    command.replace(0, 1, currentLine+",");
                    it += currentLine.length();
                    count += currentLine.length();
                } else { // translate ',' if it's not at position 0
                    ++it;
                    if (!isdigit(*it) && '.' != *it && '$' != *it) {
                        command.replace(count, 1, ","+bufferSize);
                        it += bufferSize.length()-1;
                        count += bufferSize.length()-1;
                    }
                    --it;
                }
            }
            ++count;
        }
        if (isdigit(*(--it))) command += "p"; // print case without issuing "p"
    }
}




/**************************************************
 
 Description:
 Interpret user issued command. Change '$' and '.'
 to line number, fill up the missing line address
 and command
 
 Parameters:
 s: string that to be checked, whether it is an
    integer or not
 
 Returns:
 Return true if s is an integer, false otherwise
 
 **************************************************/
bool Command::checkInt(string s) const {
    stringstream ss;
    ss << s;
    int x = 0;
    ss >> x;
    if (1 == ss.good()) { // check case like "12p"
        return false;
    } else if (0 == x && '0' != s[0]) { // check case like ,12
        return false;
    }
    return true;
}




/**************************************************
 
 Description:
 Simple getter function, get the cmd type
 
 Returns:
 Return cmd variable.
 
 **************************************************/
Cmd Command::getCommand() const {
    return cmd;
}




/**************************************************
 
 Description:
 Simple getter function, get the first line address
 
 Returns:
 Return the first line address
 
 **************************************************/
int Command::getX() const {
    return x;
}




/**************************************************
 
 Description:
 Simple getter function, get the second line address
 
 Returns:
 Return the second line address
 
 **************************************************/
int Command::getY() const {
    return y;
}











