#include "RightTriangle.h"




/**************************************************
 
 Description:
 Ctor, pass the object description and the name
 to the parent ctor, store construction value
 
 Parameters:
 b: construction value
 description: object description, default value is
    "Class RightTriangle"
 name: object name, default value is "RightTriangle"
 
 Returns:
 None
 
 **************************************************/
RightTriangle::RightTriangle(int b, string description, string name) : Isosceles(description, name), b(b) {
}




/**************************************************
 
 Description:
 Generate RightTriangle specific representation
 
 Parameters:
 none
 
 Returns:
 Return a string contains specific representation
 
 **************************************************/
string RightTriangle::toString() const {
    ostringstream oss;
    oss << std::setprecision(2) << fixed;
    oss << Isosceles::toString();
    oss << "b. box width:  " << getWidth() << endl;
    oss << "b. box height: " << getHeight() << endl;
    oss << "Scr area:      " << scrArea() << endl;
    oss << "Geo area:      " << geoArea() << endl;
    oss << "Scr perimeter: " << scrPerimeter() << endl;
    oss << "Geo perimeter: " << geoPerimeter() << endl << endl << endl;
    return oss.str();
}




/**************************************************
 
 Description:
 Generate RightTriangle geometric area
 
 Parameters:
 none
 
 Returns:
 Return the area value
 
 **************************************************/
double RightTriangle::geoArea() const {
    return b * b / 2.0;
}




/**************************************************
 
 Description:
 Generate RightTriangle geometric perimeter
 
 Parameters:
 none
 
 Returns:
 Return the perimeter value
 
 **************************************************/
double RightTriangle::geoPerimeter() const {
    return (2 + sqrt(2)) * b * 1.0;
}




/**************************************************
 
 Description:
 Generate RightTriangle screen area
 
 Parameters:
 none
 
 Returns:
 Return the area value
 
 **************************************************/
int RightTriangle::scrArea() const {
    return b * (b + 1) / 2;
}




/**************************************************
 
 Description:
 Generate RightTriangle screen perimeter
 
 Parameters:
 none
 
 Returns:
 Return the perimeter value
 
 **************************************************/
int RightTriangle::scrPerimeter() const {
    return 3 * (b - 1);
}




/**************************************************
 
 Description:
 Draw RightTriangle textual image on a given drawing
 surface named Canvas
 
 Parameters:
 canvas: drawing surface
 row: the y coordinate of the bounding box to be drawn
 col: the x coordinate of the bounding box to be drawn
 foreChar: foreground char, default is '*'
 backChar: background char, default is ' '
 
 Returns:
 none
 
 **************************************************/
void RightTriangle::draw(Canvas &canvas, int row, int col, char fChar, char bChar) const {
    for (int r = 0; r < getHeight(); ++r) {
        for (int c = 0; c < getWidth(); ++c) {
            if (c > r) {
//                canvas[row + r][col + c] = bChar;
                canvas.put(row + r, col + c, bChar);
            } else {
//                canvas[row + r][col + c] = fChar;
                canvas.put(row + r, col + c, fChar);
            }
        }
    }
}




/**************************************************
 
 Description:
 Get the RightTriangle height
 
 Parameters:
 none
 
 Returns:
 Return height value
 
 **************************************************/
int RightTriangle::getHeight() const {
    return b;
}




/**************************************************
 
 Description:
 Get the RightTriangle width
 
 Parameters:
 none
 
 Returns:
 Return width value
 
 **************************************************/
int RightTriangle::getWidth() const {
    return b;
}

















