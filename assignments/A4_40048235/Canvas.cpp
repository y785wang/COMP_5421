#include "Canvas.h"

using std::endl;




/********************************************c*****
 
 Description:
 Ctor, initialize every cell with the fill character
 fillCh, default is blank
 
 Parameters:
 row: the number of rows
 col: the number of columns
 
 Returns:
 None
 
 **************************************************/
Canvas::Canvas(int rows, int cols, char fillCh) : rows(rows), cols(cols) {
    for (int i = 0; i < rows; ++i) {
        vector<char> row;
        for (int j = 0; j < cols; ++j) {
            row.push_back(fillCh);
        }
        cells.push_back(row);
    }
}




/**************************************************
 
 Description:
 Output operator overloading. Write the entire canvas
 cells to a given ostream
 
 Parameters:
 out: receive canvas' drawing cell
 c: Canvas that needs to be drawn
 
 Returns:
 Ostream& out.
 
 **************************************************/
ostream& operator<<(ostream &out, const Canvas c) {
    for (int i = 0; i < c.getHeight(); ++i) {
        for (int j = 0; j < c.getWidth(); ++j) {
            out << c[i][j];
        }
        out << endl;
    }
    return out;
}




/**************************************************
 
 Description:
 Subscripts, const version. Based on the row,
 return a row of cells. Read-only.
 
 Parameters:
 row: determine which row should be return
 
 Returns:
 A row of cells represented by vector
 
 **************************************************/
const vector<char>& Canvas::operator[](int row) const {
    return cells[row];
}




/**************************************************
 
 Description:
 Subscripts, non-const version. Based on the row,
 return a row of cells. Read and write.
 
 Parameters:
 row: determine which row should be return
 
 Returns:
 A row of cells represented by vector
 
 **************************************************/
vector<char>& Canvas::operator[](int row) {
    return cells[row];
}




/**************************************************
 
 Description:
 Write ch in the cell at specific row and column.
 It check against bounds, as they effectively
 reflect the corresponding operators of the underlying
 vectors
 
 Parameters:
 row: determine the row number
 col: determine the column number
 fillCh: determine the character that to be filled
 
 Returns:
 None
 
 **************************************************/
void Canvas::put(int row, int col, char fillCh) {
    if (inBounds(row, col)) cells[row][col] = fillCh;
}




/**************************************************
 
 Description:
 Get the Canvas height(rows)
 
 Parameters:
 None
 
 Returns:
 Return the height value
 
 **************************************************/
int Canvas::getHeight() const {
    return rows;
}




/**************************************************
 
 Description:
 Get the Canvas width(columns)
 
 Parameters:
 None
 
 Returns:
 Return the width value
 
 **************************************************/
int Canvas::getWidth() const {
    return cols;
}




/**************************************************
 
 Description:
 Determine whether the specified row and column
 positions are inside the bounds of this canvas
 
 Parameters:
 row: row to be check
 col: column to be check
 
 Returns:
 Return true if the specified row and column
 position are inside the bounds of this canvas,
 false otherwise
 
 **************************************************/
bool Canvas::inBounds(int row, int col) const {
    return 0 <= row && row < rows && 0 <= col && col < cols;
}




/**************************************************
 
 Description:
 Take an optional fill character and write the cells
 with the character
 
 Parameters:
 fillCh: character to be filled, default is blank
 
 Returns:
 None
 
 **************************************************/
void Canvas::clear(char fillCh) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cells[i][j] = fillCh;
        }
    }
}
