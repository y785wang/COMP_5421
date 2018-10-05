#include "Oblique.h"




/**************************************************
 
 Description:
 Ctor, pass the object description and the name
 to the parent ctor, store construction value
 
 Parameters:
 _b: construction value, add 1 on it if it's even
 description: object description, default value is
 "Class Oblique"
 name: object name, default value is "Oblique"
 
 Returns:
 None
 
 **************************************************/
Oblique::Oblique(int _b, string description, string name) : Isosceles(description, name) {
    b = (0 == _b % 2) ? _b + 1 : _b;
}




/**************************************************
 
 Description:
 Generate Oblique specific representation
 
 Parameters:
 none
 
 Returns:
 Return a string contains specific representation
 
 **************************************************/
string Oblique::toString() const {
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
 Generate Oblique geometric area
 
 Parameters:
 none
 
 Returns:
 Return the area value
 
 **************************************************/
double Oblique::geoArea() const {
    return getHeight() * b / 2.0;
}




/**************************************************
 
 Description:
 Generate Oblique geometric perimeter
 
 Parameters:
 none
 
 Returns:
 Return the perimeter value
 
 **************************************************/
double Oblique::geoPerimeter() const {
    return b + 2 * sqrt(0.25 * b * b + getHeight() * getHeight());
}




/**************************************************
 
 Description:
 Generate Oblique screen area
 
 Parameters:
 none
 
 Returns:
 Return the area value
 
 **************************************************/
int Oblique::scrArea() const {
    return getHeight() * getHeight();
}




/**************************************************
 
 Description:
 Generate Oblique screen perimeter
 
 Parameters:
 none
 
 Returns:
 Return the perimeter value
 
 **************************************************/
int Oblique::scrPerimeter() const {
    return 4 * (getHeight() - 1);
}




/**************************************************
 
 Description:
 Draw Oblique textual image on a given drawing
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

void Oblique::draw(Canvas &canvas, int row, int col, char fChar, char bChar) const {
    for (int r = 0; r < getHeight(); ++r) {
        for (int c = 0; c < getWidth(); ++c) {
            if (c < getHeight()-1-r || c > getHeight()-1+r) {
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
 Get the Oblique height
 
 Parameters:
 none
 
 Returns:
 Return height value
 
 **************************************************/
int Oblique::getHeight() const {
    return (b + 1) / 2;
}




/**************************************************
 
 Description:
 Get the Oblique width
 
 Parameters:
 none
 
 Returns:
 Return width value
 
 **************************************************/

int Oblique::getWidth() const {
    return b;
}
















