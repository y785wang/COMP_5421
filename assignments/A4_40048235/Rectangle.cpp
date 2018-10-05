#include "Rectangle.h"




/**************************************************
 
 Description:
 Ctor, pass the object description and the name
 to the parent ctor, store width and height
 
 Parameters:
 width: width of the object
 height: height of the object
 description: object description, default value is
 "Class Rectangle"
 name: object name, default value is "Rectangle"
 
 Returns:
 None
 
 **************************************************/
Rectangle::Rectangle(int width, int height, string description, string name) : Shape(description, name), width(width), height(height) {}




/**************************************************
 
 Description:
 Generate Rectangle specific representation
 
 Parameters:
 none
 
 Returns:
 Return a string contains specific representation
 
 **************************************************/
string Rectangle::toString() const {
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
 Generate Rectangle geometric area
 
 Parameters:
 none
 
 Returns:
 Return the area value
 
 **************************************************/
double Rectangle::geoArea() const {
    return height * width * 1.0;
}




/**************************************************
 
 Description:
 Generate Rectangle geometric perimeter
 
 Parameters:
 none
 
 Returns:
 Return the perimeter value
 
 **************************************************/
double Rectangle::geoPerimeter() const {
    return 2.0 * (height + width);
}




/**************************************************
 
 Description:
 Generate Rectangle screen area
 
 Parameters:
 none
 
 Returns:
 Return the area value
 
 **************************************************/
int Rectangle::scrArea() const {
    return height * width;
}




/**************************************************
 
 Description:
 Generate Rectangle screen perimeter
 
 Parameters:
 none
 
 Returns:
 Return the perimeter value
 
 **************************************************/
int Rectangle::scrPerimeter() const {
    return 2 * (height + width) - 4;
}




/**************************************************
 
 Description:
 Draw Rectangle textual image on a given drawing
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
void Rectangle::draw(Canvas &canvas, int row, int col, char fChar, char bChar) const {
    for (int r = 0; r < getHeight(); ++r) {
        for (int c = 0; c < getWidth(); ++c) {
//            canvas[row + r][col + c] = fChar;
            canvas.put(row + r, col + c, fChar);
        }
    }
}




/**************************************************
 
 Description:
 Get the Rectangle height
 
 Parameters:
 none
 
 Returns:
 Return height value
 
 **************************************************/
int Rectangle::getHeight() const {
    return height;
}




/**************************************************
 
 Description:
 Get the Rectangle width
 
 Parameters:
 none
 
 Returns:
 Return width value
 
 **************************************************/
int Rectangle::getWidth() const {
    return width;
}
