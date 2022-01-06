//
//  Triangle.cpp
//  Lab5
//
//  Created by Tarek Abdelrahman on 2020-11-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student: Write the implementation of the class Rectangle here

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//USED CIRCLE.CPP AS A TEMPLATE FOR TRIANGLE.CPP, BUT WITH DIFFERENT METHODS

#include "Shape.h"
#include "Triangle.h"

//Build a Triangle object
Triangle::Triangle(string n, float xcent, float ycent, float x1, float y1, float x2, float y2, float x3, float y3):Shape(n, xcent, ycent){
    xCoord1 = x1;
    xCoord2 = x2;
    xCoord3 = x3;
    yCoord1 = y1;
    yCoord2 = y2;
    yCoord3 = y3;
}

Triangle::~Triangle(){
    //Nothing to do
}

//Accessor
float Triangle::getxCoord1() const {
    return xCoord1;
}

float Triangle::getxCoord2() const {
    return xCoord2;
}

float Triangle::getxCoord3() const {
    return xCoord3;
}

float Triangle::getyCoord1() const {
    return yCoord1;
}

float Triangle::getyCoord2() const {
    return yCoord2;
}

float Triangle::getyCoord3() const {
    return yCoord3;
}

//Mutator
void Triangle::setxCoord1(float x1) {
    xCoord1 = x1;
}

void Triangle::setxCoord2(float x2) {
    xCoord2 = x2;
}

void Triangle::setxCoord3(float x3) {
    xCoord3 = x3;
}

void Triangle::setyCoord1(float y1) {
    yCoord1 = y1;
}

void Triangle::setyCoord2(float y2) {
    yCoord2 = y2;
}

void Triangle::setyCoord3 (float y3) {
    yCoord3 = y3;
}

void Triangle::draw() const {
    //Set floating point printing to fixed point with 2 decimals
    cout << std::fixed;
    cout << std::setprecision(2);
    
    //Print the information
    cout << "triangle: " << name << " "
    << x_centre << " " << y_centre << " "
    << xCoord1 << " " << yCoord1 << " "
    << xCoord2 << " " << yCoord2 << " "
    << xCoord3 << " " << yCoord3 << " "
    << computeArea() << endl;
}

float Triangle::computeArea() const {
    float area = (xCoord1*(yCoord2 - yCoord3) + xCoord2*(yCoord3 - yCoord1) + 
    xCoord3*(yCoord1 - yCoord2))/2;
    return (area >= 0) ? area : -area;
}

Shape* Triangle::clone() const {
    return (new Triangle(*this));
}