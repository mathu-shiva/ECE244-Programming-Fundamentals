//
//  parser.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"
#include "ShapeNode.h"
#include "GroupNode.h"
#include "ShapeList.h"
#include "GroupList.h"

// This is a pointer to the groups list
// The list itseld must be allocated
GroupList* gList;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here
void commandChecker(string command, stringstream& sstream);
void shapeBuilder(stringstream& sstream);
void groupBuilder(stringstream& sstream);
void draw();
void moveShape(stringstream& sstream);
void deleteShape (stringstream& sstream);
bool validName(string name);
bool validNameName(string name);
bool commandExist(string s);
bool shapeChecker(string s);
bool nameFinder(string name);
int getValue(string s, int& number);
GroupNode* currentGroupNode(string name);
GroupNode* newGroupNode(string name);
ShapeNode* newShapeNode(string name, string type, int locationx, int locationy, int sizex, int sizey);

int main() {
    // Create the groups list
    gList = new GroupList();
    
    // Create the poo group and add it to the group list
    GroupNode* poolGroup = new GroupNode(keyWordsList[NUM_KEYWORDS-1]);
    gList->insert(poolGroup);
    
    string line;
    string command;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get a line from standard input

    while ( !cin.eof () ) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream lineStream (line);
        
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
        commandChecker(command, lineStream);
        
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }  // End input loop until EOF.
    
    return 0;
}

void commandChecker(string command, stringstream& sstream)
{
    if(command == "shape")
    {
        shapeBuilder(sstream);
    }
    else if(command == "group")
    {
        groupBuilder(sstream);
    }
    else if(command == "draw")
    {
        draw();
    }
    else if(command == "move")
    {
        moveShape(sstream);
    }
    else if(command == "delete")
    {
        deleteShape(sstream);
    }
    else
    {
        cout << "error: invalid command" << endl;
    }
    return;
}

//Command Draw
void draw()
{
    cout << "drawing: " << endl;
    gList->print();
}

//Command Delete
void deleteShape (stringstream& sstream)
{
    string name;
    sstream >> name;
    
    if(!validNameName(name))
    {
        return;
    }
    
    GroupNode* deleteNode = currentGroupNode(name);
    if(deleteNode != NULL)
    {
        delete deleteNode->getShapeList()->remove(name);
        cout << name << ": deleted" << endl;
        return;
    }
    
    deleteNode = newGroupNode(name);
    if(deleteNode != NULL)
    {
        ShapeList* shapesList = deleteNode->getShapeList();
        ShapeList* pool = gList->getHead()->getShapeList();
        
        while(shapesList->getHead() != NULL)
        {
            string sentence = shapesList->getHead()->getShape()->getName();
            ShapeNode* currentShape = shapesList->remove(sentence);
            pool->insert(currentShape);
        }
        delete gList->remove(name);
        cout << name << ": deleted" << endl;
        return;
    }
    cout << "error: shape " << name << " not found" << endl;
}

//Command Move Shape
void moveShape(stringstream& sstream)
{
    string shapeName;
    string groupName;
    
    sstream >> shapeName >> groupName;
    
    if(validNameName(shapeName) && validNameName(groupName))
    {
        GroupNode* shape = currentGroupNode(shapeName);
        GroupNode* group = newGroupNode(groupName);
        
        if(shape == NULL)
        {
            cout << "error: shape " << shapeName << " not found" << endl;
            return;
        }
        else if(group == NULL)
        {
            cout << "error: group " << groupName << " not found" << endl;
        }
        ShapeNode* oldShape = shape->getShapeList()->remove(shapeName);
        group->getShapeList()->insert(oldShape);
        cout << "moved " << shapeName << " to " << groupName << endl;
    }
}


//Command Group Create
void groupBuilder(stringstream& sstream)
{
    string name;
    sstream >> name;
    
    if(validName(name))
    {
        GroupNode* temp = new GroupNode(name);
        gList->insert(temp);
        cout << name << ": group" << endl;
    }
}

//Command Shape Create
void shapeBuilder(stringstream& sstream)
{
    int locationx;
    int locationy;
    int sizex;
    int sizey;
    string name;
    string type;
    string loclocx;
    string loclocy;
    string sizesizex;
    string sizesizey;
    
    sstream >> name >> type;
    sstream >> loclocx >> loclocy >> sizesizex >> sizesizey;
    
    getValue(loclocx, locationx);
    getValue(loclocy, locationy);
    getValue(sizesizex, sizex);
    getValue(sizesizey, sizey);
    
    if(validName(name))
    {
        ShapeNode* temp = newShapeNode(name, type, locationx, locationy, sizex, sizey);
        temp->getShape()->draw();
        GroupNode* temporary = gList->getHead();
        temporary->getShapeList()->insert(temp);
    }
}

//Checks using Boolean Functions
bool shapeChecker(string s)
{
    for (int i = 1; i <= sizeof(shapeTypesList)/sizeof(shapeTypesList[0]); i++)
    {
        if(s == shapeTypesList[i])
        {
            return true;
        }
    }
    return false;
}

bool commandExist(string s)
{
    for (int i = 1; i <= sizeof(keyWordsList)/sizeof(keyWordsList[0]); i++)
    {
        if(s == keyWordsList[i])
        {
            return true;
        }
    }
    return false;
}

bool validName(string name)
{
    if(commandExist(name)||shapeChecker(name))
    {
        cout << "error: invalid name" << endl;
        return false;
    }
    else if(nameFinder(name))
    {
        cout << "error: name " << name << " exists" << endl;
        return false;
    }
    return true;
}

bool validNameName(string name)
{
  if(commandExist(name)||shapeChecker(name))
  {
      cout << "error: invalid name" << endl;
        return false;
  }
  return true;
}

bool nameFinder(string name)
{
    streambuf* def_cout = cout.rdbuf();
    stringstream sstream;
    cout.rdbuf(sstream.rdbuf());
    gList->print();
    cout.rdbuf(def_cout);
    while(!sstream.eof())
    {
        string temporary;
        sstream >> temporary;
        if(temporary.find(name) != string::npos)
        {
            return true;
        }
    }  
    return false;
}

int getValue(string s, int& number)
{
    int num;
    string word;
    stringstream sstream(s);
    sstream >> num;
    if(!sstream.fail())
    {
        if(sstream.peek() != ' ' && !sstream.eof())
        {
            cout << "error: invalid argument" << endl;
            return -1;
        }
        else
        {
            number = num;
            return 1;
        }
        
    }
    else if(sstream.eof())
    {
        return 0;
    }
    else
    {
        cout << "error: invalid argument" << endl;
        return -1;
    }
    return 0;
}

GroupNode* currentGroupNode(string name)
{
    GroupNode* ptr = gList->getHead();
    while(ptr != NULL)
    {
        ShapeNode* tempo = ptr->getShapeList()->find(name);
        if(tempo != NULL)
        {
            return ptr;
        }
        ptr = ptr->getNext();
    }
    return NULL;
}

GroupNode* newGroupNode(string name)
{
    GroupNode* ptr = gList->getHead();
    while(ptr != NULL)
    {
        if(ptr->getName() == name)
        {
            return ptr;
        }
        ptr = ptr->getNext();
    }
    return NULL;
}

ShapeNode* newShapeNode(string name, string type, int locationx, int locationy, int sizex, int sizey)
{
    Shape* pointer = new Shape(name, type, locationx, locationy, sizex, sizey);
    ShapeNode* shapeNodePointer = new ShapeNode();
    shapeNodePointer->setShape(pointer);
    return shapeNodePointer;
}