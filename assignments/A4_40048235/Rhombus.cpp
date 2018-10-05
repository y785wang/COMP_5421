#include "Rhombus.h"




/**************************************************
 
 Description:
 Ctor, pass the object description and the name
 to the parent ctor, store construction value,
 
 Parameters:
 _d: construction value, if it's even, add 1 on 1
 description: object description, default value is
 "Class Rhombus"
 name: object name, default value is "Rhombus"
 
 Returns:
 None
 
 **************************************************/
Rhombus::Rhombus(int _d, string description, string name) : Shape(description, name) {
    d = (0 == _d % 2) ? _d + 1 : _d;
}




/**************************************************
 
 Description:
 Generate Rhombus specific representation
 
 Parameters:
 none
 
 Returns:
 Return a string contains specific representation
 
 **************************************************/
string Rhombus::toString() const {
    ostringstream oss;
    oss << std::setprecision(2) << fixed;
    oss << Shape::toString();
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
 Generate Rhombus geometric area
 
 Parameters:
 none
 
 Returns:
 Return the area value
 
 **************************************************/
double Rhombus::geoArea() const {
    return d * d / 2.0;
}




/**************************************************
 
 Description:
 Generate Rhombus geometric perimeter
 
 Parameters:
 none
 
 Returns:
 Return the perimeter value
 
 **************************************************/
double Rhombus::geoPerimeter() const {
    return 2.0 * sqrt(2) * d;
}




/**************************************************
 
 Description:
 Generate Rhombus screen area
 
 Parameters:
 none
 
 Returns:
 Return the area value
 
 **************************************************/
int Rhombus::scrArea() const {
    int n = d / 2;
    return 2 * n * (n + 1) + 1;
}




/**************************************************
 
 Description:
 Generate Rhombus screen perimeter
 
 Parameters:
 none
 
 Returns:
 Return the perimeter value
 
 **************************************************/
int Rhombus::scrPerimeter() const {
    return 2 * (d - 1);
}




/**************************************************
 
 Description:
 Draw Rhombus textual image on a given drawing
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
void Rhombus::draw(Canvas &canvas, int row, int col, char fChar, char bChar) const {
    for (int r = 0; r < getHeight(); ++r) {
        for (int c = 0; c < getWidth(); ++c) {
            int temp =r <= d/2 ? r : d-r-1;
            if (c < d/2-temp || c > d/2+temp) {
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
 Get the Rhombus height
 
 Parameters:
 none
 
 Returns:
 Return height value
 
 **************************************************/
int Rhombus::getHeight() const {
    return d;
}




/**************************************************
 
 Description:
 Get the Rhombus width
 
 Parameters:
 none
 
 Returns:
 Return width value
 
 **************************************************/
int Rhombus::getWidth() const {
    return d;
}

