#include "Isosceles.h"




/**************************************************
 
 Description:
 Ctor, pass the object description and the name
 to the parent ctor
 
 Parameters:
 description: object description
 name: object name
 
 Returns:
 None
 
 **************************************************/
Isosceles::Isosceles(string description, string name) : Shape(description, name) {}




/**************************************************
 
 Description:
 Get Shape common representation
 
 Parameters:
 none
 
 Returns:
 Return a string contains common representation
 
 **************************************************/
string Isosceles::toString() const {
    ostringstream oss;
    oss << Shape::toString();
    return oss.str();
}
