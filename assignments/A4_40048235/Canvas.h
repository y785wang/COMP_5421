#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::ostream;

class Canvas {
  private:
    int rows;
    int cols;
    vector<vector<char>> cells;
  public:
    Canvas(int , int, char = ' ');
    Canvas(const Canvas &) = default;
    Canvas& operator=(const Canvas &) = default;
    ~Canvas() = default;
    
    friend ostream& operator<<(ostream &, const Canvas);

    const vector<char>& operator[](int) const; // no bounds check
    vector<char>& operator[](int);             // no bounds check
    void put(int, int c, char = '*');       // check bounds
    int getHeight() const;
    int getWidth() const;
    bool inBounds(int, int) const;
    void clear(char = ' ');
    
};

#endif
