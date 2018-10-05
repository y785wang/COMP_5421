#include "Shape.h"




// for generate the unique object id
int Shape::count = 0;




/**************************************************
 
 Description:
 Ctor, store the object description and the name
 based on the parameters, give object an identical
 id
 
 Parameters:
 fescription: object description
 fame: object name
 
 Returns:
 None
 
 **************************************************/
Shape::Shape(string description, string name) : description(description), name(name) {
    ++count;
    ID = count;
}




/**************************************************
 
 Description:
 Output operator overloading. Generates a string
 representation for the shape object
 
 Parameters:
 out: receive object's string representation
 s: Shape that needs to be represented
 
 Returns:
 Ostream& out.
 
 **************************************************/
ostream& operator<<(ostream &out, const Shape &s) {
    out << s.toString();
    return out;
}




/**************************************************
 
 Description:
 Get the object id
 
 Parameters:
 None
 
 Returns:
 Object id
 
 **************************************************/
int Shape::getID() const {
    return ID;
}




/**************************************************
 
 Description:
 Get the object name
 
 Parameters:
 None
 
 Returns:
 Object name
 
 **************************************************/
string Shape::getName() const {
    return name;
}




/**************************************************
 
 Description:
 Get the object description
 
 Parameters:
 None
 
 Returns:
 Object description
 
 **************************************************/
string Shape::getDescription() const {
    return description;
}




/**************************************************
 
 Description:
 Set the object name as the parameter
 
 Parameters:
 name: object new name
 
 Returns:
 None
 
 **************************************************/
void Shape::setName(string name) {
    name = name;
}




/**************************************************
 
 Description:
 Set the object description as the parameter
 
 Parameters:
 description: object new description
 
 Returns:
 None
 
 **************************************************/
void Shape::setDescription(string description) {
    description = description;
}




/**************************************************
 
 Description:
 Generate Shape common representation
 
 Parameters:
 none
 
 Returns:
 Return a string contains common representation
 
 **************************************************/
string Shape::toString() const {
    ostringstream oss;
    oss << "Shape Information" << endl;
    oss << "-----------------" << endl;
    oss << "Static type:   " << typeid(this).name() << endl;
    oss << "Dynamic type:  " << typeid(*this).name() << endl;
    oss << "Shape name:    " << getName() << endl;
    oss << "Description:   " << getDescription() << endl;
    oss << "id:            " << getID() << endl;
    return oss.str();
}





