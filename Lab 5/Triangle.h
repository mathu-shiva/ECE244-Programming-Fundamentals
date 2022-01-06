//
//  Triangle.h
//  Lab5
//
//  Created by Tarek Abdelrahman on 2020-11-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#ifndef Triangle_h
#define Triangle_h

#include <iostream>
#include <string>
using namespace std;

//USED CIRCLE.H AS A TEMPLATE FOR TRIANGLE.H, BUT WITH DIFFERENT DIMENSIONS
#include "Shape.h"

class Triangle : Shape {
private:
    float xCoord1, xCoord2, xCoord3;        //The x-coordinates of the vertices of the triangle
    float yCoord1, yCoord2, yCoord3;        //The y-coordinates of the vertices of the triangle
    
public:
    //Constructor
    Triangle(string n, float xcent, float ycent, float x1, float y1, float x2, float y2, float x3, float y3);

    //Destructor
    virtual ~Triangle();
    
    //Accessor
    float getxCoord1() const;       //Returns the x value of vertice 1
    float getxCoord2() const;       //Returns the x value of vertice 2
    float getxCoord3() const;       //Returns the x value of vertice 3
    float getyCoord1() const;       //Returns the y value of vertice 1
    float getyCoord2() const;       //Returns the y value of vertice 2
    float getyCoord3() const;       //Returns the y value of vertice 3
    
    //Mutator
    void setxCoord1(float x1);      //Sets the x value of vertice 1
    void setxCoord2(float x2);      //Sets the x value of vertice 2
    void setxCoord3(float x3);      //Sets the x value of vertice 3
    void setyCoord1(float y1);      //Sets the y value of vertice 1
    void setyCoord2(float y2);      //Sets the y value of vertice 2
    void setyCoord3(float y3);      //Sets the y value of vertice 3
    
    //Utility methods
    virtual void draw() const;              //Draws the triangle, for the assignment it
                                            //prints the information of the triangle
    virtual float computeArea() const;      //Computes the area of the triangle
    virtual Shape* clone() const;           //Clones he object
};

#endif /* Triangle_h */


