#include "Led.h"

#include <fstream>

using std::ifstream;
using std::ofstream;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::advance;
using std::size_t;




/**************************************************
 
 Description:
 Led class ctor. Set filename to parameter,
 currentLine to 1, saved to false
 
 Parameters:
 filename: the file that to be loaded, could be
        empty string
 
 **************************************************/
Led::Led(string filename) : filename(filename), currentLine(1), saved(false) {}




/**************************************************
 
 Description:
 Led class dtor
 
 **************************************************/
Led::~Led() {}




/**************************************************
 
 Description:
 Initialize the Led object. If filename is given,
 load the file to buffer. Then entering command
 mode
 
 **************************************************/
void Led::run() {
    if (!filename.empty()) {
        loadFile();
    } else {
        cout << "\"?\" [New File]" << endl;
    }
    cout << "Entering command mode." << endl;
    while(determineCommand());
}




/**************************************************
 
 Description:
 Load the entire file contents to buffer. Output
 the number of lines that have been read to the
 buffer
 
 **************************************************/
void Led::loadFile() {
    ifstream inFile(filename.c_str());
    string line;
    while (getline(inFile, line)) {
        buffer.push_back(line);
    }
    currentLine = buffer.size();
    cout << "\"" << filename << "\" " << currentLine;
    if (1 < currentLine) {
        cout << " lines" << endl;
    } else {
        cout << " line" << endl;
    }
}




/**************************************************
 
 Description:
 Handle command issued by user, create Command
 object to trim, parse determnine the command case,
 then call the corresponding function to execute
 the command
 
 Returns:
 Return false if command issued by user is quit
 command, true otherwise
 
 **************************************************/
bool Led::determineCommand() {
    bool notQuit = true;
    string userCommand;
    cout << "? ";
    getline(cin, userCommand);
    Command c(userCommand);
    c.parse(currentLine, buffer.size());
    Cmd cmd = c.getCommand();
    int x = c.getX();
    int y = c.getY();
    switch (cmd) {
        case APPEND_AFTER:
            saved = false;
            appendAfter(x);
            break;
        case INSERT_BEFORE:
            saved = false;
            insertBefore(x);
            break;
        case PASTE_BELOW:
            saved = false;
            pasteBelow(x);
            break;
        case PASTE_ABOVE:
            saved = false;
            pasteAbove(x);
            break;
        case DELETE:
            saved = false;
            deletes(x, y);
            break;
        case CUT:
            saved = false;
            cut(x, y);
            break;
        case REPLACE:
            saved = false;
            replace(x, y);
            break;
        case JOIN:
            saved = false;
            join(x, y);
            break;
        case PRINT:
            print(x, y);
            break;
        case CHANGE:
            saved = false;
            change(x, y);
            break;
        case MOVE_UP:
            moveUp(x);
            break;
        case MOVE_DOWN:
            moveDown(x);
            break;
        case GO:
            currentLine = x;
            print(x, x);
            break;
        case WRITE:
            saved = true;
            write();
            break;
        case QUIT:
            quit(notQuit);
            break;
        case INVALID_RANGE:
            cout << "Invalid range" << endl;
            break;
        case INVALID_COMMAND:
            cout << "INVALID_COMMAND" << endl;
            break;
        case EMPTY_BUFFER:
            cout << "empty buffer" << endl;
            break;
    }
    return notQuit;
}




/**************************************************
 
 Description:
 Append text into the buffer after line x, the
 current address is set to the last line entered
 
 Parameters:
 x: line address 1
 
 **************************************************/
void Led::appendAfter(int x) {
    list<string>::iterator it = buffer.begin();
    advance(it, x);
    currentLine = (0 == buffer.size()) ? x-1 : x;
    string line;
    while (getline(cin, line)) {
        buffer.insert(it, line);
        ++currentLine;
    }
    cin.clear();
    clearerr(stdin); // for mac only???
}




/**************************************************
 
 Description:
 Insert text into the before after line x, the
 current address is set to the last line entered
 
 Parameters:
 x: line address 1
 
 **************************************************/
void Led::insertBefore(int x) {
    list<string>::iterator it = buffer.begin();
    advance(it, x-1);
    currentLine = x-1;
    string line;
    while (getline(cin, line)) {
        buffer.insert(it, line);
        ++currentLine;
    }
    cin.clear();
    clearerr(stdin); // for mac only???
}




/**************************************************
 
 Description:
 Paste text from the clipboard into the buffer
 below line x. The current address is set to the
 last line entered
 
 Parameters:
 x: line address 1
 
 **************************************************/
void Led::pasteBelow(int x) {
    if (0 == clipboard.size()) return;
    list<string>::iterator it_b = buffer.begin();
    advance(it_b, x);
    currentLine = (0 == buffer.size()) ? x-1 : x;
    string line;
    for (vector<string>::iterator it_v = clipboard.begin(); it_v != clipboard.end(); ++it_v){
        line = *it_v;
        buffer.insert(it_b, line);
        ++currentLine;
    }
}




/**************************************************
 
 Description:
 Paste text from the clipboard into the buffer
 above line x. The current address is set to the
 last line entered
 
 Parameters:
 x: line address 1
 
 **************************************************/
void Led::pasteAbove(int x) {
    if (0 == clipboard.size()) return;
    list<string>::iterator it_b = buffer.begin();
    advance(it_b, x-1);
    currentLine = x-1;
    string line;
    for (vector<string>::iterator it_v = clipboard.begin(); it_v != clipboard.end(); ++it_v){
        line = *it_v;
        buffer.insert(it_b, line);
        ++currentLine;
    }
}




/**************************************************
 
 Description:
 Delete the line range x through y from the buffer.
 If there is a line after the delete line range,
 then the current address is set to that line.
 Otherwise, the current address is set to the line
 before the deleted line range.
 
 Parameters:
 x: line address 1
 y: line address 2
 
 **************************************************/
void Led::deletes(int x, int y) {
    currentLine = (y < buffer.size()) ? x : x-1;
    if (0 == currentLine) ++currentLine;
    list<string>::iterator it = buffer.begin();
    advance(it, x-1);
    for (int i = x; i <= y; ++i) {
        buffer.erase(it--);
        ++it;
    }
}




/**************************************************
 
 Description:
 Cut the line range x through y from the buffer
 into the clipboard. If there is a line after the
 cut line range, then the current address is set to
 that line. Otherwise the current address is set to
 the line beore the cut line range
 
 Parameters:
 x: line address 1
 y: line address 2
 
 **************************************************/
void Led::cut(int x, int y) {
    clipboard.clear();
    list<string>::iterator it = buffer.begin();
    advance(it, x-1);
    for (int i = x; i <= y; ++i) {
        clipboard.push_back(*(it++));
    }
    deletes(x, y);
}




/**************************************************
 
 Description:
 Replace the line range x through y with input text.
 Equivalent to command line x,yd followed by the
 command xi
 
 Parameters:
 x: line address 1
 y: line address 2
 
 **************************************************/
void Led::replace(int x, int y) {
    deletes(x, y);
    insertBefore(x);
}




/**************************************************
 
 Description:
 Join the line range x through y together on one
 line at address x, sugh that each line in turn is
 appended to line x, separated by a single space.
 Line x becomes the current line
 
 Parameters:
 x: line address 1
 y: line address 2
 
 **************************************************/
void Led::join(int x, int y) {
    currentLine = x;
    list<string>::iterator it = buffer.begin();
    advance(it, x-1);
    for (int i = x; i < y; ++i) {
        string temp = *(++it);
        *it =  *(--it) + " " + temp;
        buffer.erase(++it);
    }
}




/**************************************************
 
 Description:
 Print the line range x through y without affecting
 the current line address
 
 Parameters:
 x: line address 1
 y: line address 2
 
 **************************************************/
void Led::print(int x, int y) {
    list<string>::iterator it = buffer.begin();
    advance(it, x-1);
    for (int i = x; i <= y; ++i) {
        if (i == currentLine) {
            cout << i << "> " << *it << endl;
        } else {
            cout << i << ": " << *it << endl;
        }
        ++it;
    }
}




/**************************************************
 
 Description:
 Prompts for and reads the text to be changed, and
 then promps for and reads the replacement text.
 Searches each line in the line range for an
 occurence of the specified string and changes all
 matched strings to the replacement text.
 
 Parameters:
 x: line address 1
 y: line address 2
 
 **************************************************/
void Led::change(int x, int y) {
    string changeFrom, changeTo;
    int occurence = 0;
    size_t found;
    cout << "Change what? ";
    getline(cin, changeFrom);
    cout << "    To what? ";
    getline(cin, changeTo);
    list<string>::iterator it = buffer.begin();
    advance(it, x-1);
    for (int i = x; i <= y; ++i) {
        found = 0;
        while (true) {
            found = (*it).find(changeFrom, found);
            if (string::npos == found) break;
            (*it).replace(found, changeFrom.length(), changeTo);
            found += changeTo.length();
            ++occurence;
        }
        ++it;
    }
    cout << "Changed " << occurence << " occurence(s)" << endl;
}




/**************************************************
 
 Description:
 Move the current line up by x lines provided that
 there are x lines above the current line; otherwise,
 prints the message top of file reached and sets the
 current line to last line in the buffer. If omitter,
 x = 1.
 
 Parameters:
 x: line address 1
 
 **************************************************/
void Led::moveUp(int x) {
    for (int i = 0; i < x; ++i) {
        --currentLine;
        if (currentLine < 1) {
            cout << "top of file reached" << endl;
            currentLine = 1;
            break;
        }
    }
}




/**************************************************
 
 Description:
 Move the current line down by x lines provided that
 there are x lines above the current line; otherwise,
 prints the message end of file reached and sets the
 current line to last line in the buffer. If omitter,
 x = 1.
 
 Parameters:
 x: line address 1
 
 **************************************************/
void Led::moveDown(int x) {
    for (int i = 0; i < x; ++i) {
        ++currentLine;
        if (currentLine > buffer.size()) {
            cout << "end of file reached" << endl;
            currentLine = buffer.size();
            break;
        }
    }
}




/**************************************************
 
 Description:
 Write out entire buffer to its associated file. If
 the buffer is not associated with a user named file,
 it prompts for and reads the name of the associate
 file.
 
 **************************************************/
void Led::write() {
    if (filename.empty()) {
        cout << "Enter a file name: ";
        cin >> filename;
        cin.ignore();
    }
    ofstream outFile;
    outFile.open(filename.c_str());
    for (list<string>::iterator it = buffer.begin(); it != buffer.end(); ++it) {
        outFile << *it << endl;
    }
    outFile.close();
    string unit = (buffer.size() > 1) ? " lines" : " line";
    cout << buffer.size() << unit + " written to file: \"" << filename << "\"" << endl;
}




/**************************************************
 
 Description:
 Quit led. Before quitting, however, it gives the
 user a last change to save the buffer. If the user
 takes the change, it simulates the w command. Set
 notQUit to false
 
 Parameters:
 notQuit: determine if quit command is received or
          not.
 
 **************************************************/
void Led::quit(bool &notQuit) {
    notQuit = false;
    if (true == saved) {
        cout << "No changes after the last 'w' command issued" << endl;
        cout << "Bye" << endl;
    } else {
        cout << "Save changes to a file (y/n)? ";
        string answer;
        while (cin >> answer) {
            if ("y" == answer) {
                write();
                cout << "Bye" << endl;
                break;
            } else if ("n" == answer) {
                cin.ignore();
                break;
            } else {
                cout << "Bad answer: " << answer << endl;
                cout << "Enter y for yes and n for no" << endl;
                cout << "Save changes to a file (y/n)? ";
            }
        }
    }
}













