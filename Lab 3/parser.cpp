#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"

// This is the shape array, to be dynamically allocated
Shape** shapesArray;

// The number of shapes in the database, to be incremented 
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes = 0;

int main() {

    string line; //Input line
    string command; //String containing the wanted command
    string name; //String containing the name of the shape
    string type; //String containing the type of name
    string allShapes; //String that indicates delete all or draw all
    int maxShape; //Integer containing the number of shapes
    int xlocation; //Integer containing the x location of the shape
    int ylocation; //Integer containing the y location of the shape
    int xsize; //Integer containing the x size of the shape
    int ysize; //Integer containing the y size of the shape
    int angle; //Integer containing the rotation angle of the shape
    bool commandValidity = false;
    
    
    cout << "> ";         // Prompt for input
    getline(cin, line);   // Get a line from standard input
    while (!cin.eof()) {
        
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so the flags are cleared
        stringstream lineStream (line);
        
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;
        
        for(int i = 1; i < 7; i++)
        {
            if (command == keyWordsList[i]) //If the entered command is equivalent to one of the possible commands
            {
                commandValidity = false; //It is a correct input
                
                if (i == 1) //This is the command maxShapes
                {
                    if (lineStream.eof()) //If it is empty, since this command only requires one argument
                    {
                        cout << "Error: too few arguments" << endl;
                        break;
                    }
                    
                    lineStream >> maxShape; //If we do not enter first if statement, we continue and read into maxShape
                    
                    if (lineStream.fail()) //Only fails if the input is not of expected input
                    {
                        cout << "Error: invalid argument" << endl;
                        break;
                    }
                    
                    if (maxShape < 1) //When the user input enters invalid input, for this case below 1
                    {
                        cout << "Error: invalid value" << endl;
                        break;
                    }
                    
                    lineStream >> skipws; //Skipping white space
                    if (!lineStream.eof()) //If it is not end of file, it means there are more arguments, but there should only be one
                    {
                        cout << "Error: too many arguments" << endl;
                        break;
                    }
                    
                    cout << "New database: max shapes is " << maxShape << endl;
                    
                    commandValidity = true;
                    
                    /*{
                            max_shapes = maxShape;
                            shapesArray = new Shape *[max_shapes]; //Dynamically allocating
                            for (int j = 0; j < maxShape; j++)
                            {
                                shapesArray[j] = NULL; //Allocating a completely empty array
                            }
                    }*/
                    
                    break;
                }

                else if (i == 2) //This is command create
                {
                    bool argumentChecker = false; //Boolean as a double checker
                    
                    if (lineStream.eof()) //Checking if line is empty, which leads to too few arguments
                    {
                        cout << "Error: too few arguments" << endl;
                        break;
                    }
                    
                    lineStream >> name; //We are reading into name, since there is at least one argument
                    
                    if (lineStream.eof()) //Since this command has more than one argument, if there is an EOF, then error
                    {
                        cout << "Error: too few arguments" << endl;
                        break;
                    }
                    
                    for (int j = 1; j < 7; j++)
                    {
                        if(name == keyWordsList[j]) //Helps carry out the rule of not having shape names the same as command names
                        {
                            cout << "Error: invalid shape name" << endl;
                            argumentChecker = true; //True due to invalidity
                            break;
                        }
                    }
                    
                    for (int j = 0; j < 4; j++)
                    {
                        if (name == shapeTypesList[j]) //Helps carry out the rule of not having shape names the same as shape types
                        {
                            cout << "Error: invalid shape name" << endl;
                            argumentChecker = true; //True due to invalidity
                            break;
                        }
                    }
                   
                    for (int j = 0; j < maxShape; j++) //This is a loop through our array
                    {
                        if (shapesArray[j] != NULL && name == shapesArray[j] -> getName()) //Only occurs when we find the input name
                        {
                            cout << "Error: shape " << shapesArray[j] -> getName() << " exists" << endl; //Already exists, cannot create new shape
                            argumentChecker = true; //True due to invalidity
                            break;
                        }
                    }
                    
                    if (argumentChecker == true) //True due to invalidity
                    {
                        break; //Breaks the loop for this command so we can ask the user again
                    }
     
                    lineStream >> type; //Reading in the type of shape into string type
                    
                    argumentChecker = false; //Boolean is only false when the name of this argument is acceptable
                    
                    if (lineStream.eof()) //Should not be EOF, because there are still four more needed arguments
                    {
                        cout << "Error: too few arguments" << endl;
                        break;
                    }
                    
                    for (int j = 0; j < 4; j++)
                    {
                        if (type == shapeTypesList [j]) //Ensuring entered string type is an actual shape type
                        {
                            argumentChecker = true; //We are setting true if it is a valid shape type
                        }
                    }
                    
                    if (argumentChecker == false)//If not true, print error message
                    {
                        cout << "Error: invalid shape type" << endl;
                        break;
                    }
                   
                    lineStream >> xlocation; //Reading in the x location
                    
                    if (lineStream.fail()) //There could be two reasons for failure
                    {
                        if (lineStream.eof()) //If it is EOF, as there are three more necessary arguments
                        {
                            cout << "Error: too few arguments" << endl;
                            break;
                        }
                        cout << "Error: invalid argument" << endl; //If the entered input is not of integer type
                        break;
                    }
                    
                    if (xlocation < 0) //Ensuring x location is a positive number
                    {
                        cout << "Error: invalid value" << endl;
                        break;
                    }  
                    
                    lineStream >> ylocation; //Reading in the y location
                    
                    if (lineStream.fail()) //There could be two reasons for failure
                    {
                        if (lineStream.eof()) //If it is EOF, as there are two more necessary arguments
                        {
                            cout << "Error: too few arguments" << endl;
                            break;
                        }
                        cout << "Error: invalid argument" << endl; //If the entered input is not of integer type
                        break;
                    }
                    
                    if (ylocation < 0) //Ensuring y location is a positive number
                    {
                        cout << "Error: invalid value" << endl;
                        break;
                    }
                    
                    lineStream >> xsize; //Reading in the x size
                    
                    if (lineStream.fail()) //There could be two reasons for failure
                    {
                        if (lineStream.eof()) //If it is EOF, as there is still one more necessary argument
                        {
                            cout << "Error: too few arguments" << endl;
                            break;
                        }
                        cout << "Error: invalid argument" << endl; //If the entered input is not of integer type
                        break;
                    }                    
                    
                    if (xsize < 1) //Ensuring there is a positive x size
                    {
                        cout << "Error: invalid value" << endl;
                        break;
                    }
                    
                    lineStream >> ysize; //Reading in the y size
                    
                    if (lineStream.fail()) //Only one reason for failure
                    {
                        cout << "Error: invalid argument" << endl; //If the entered input is not of integer type
                        break;
                    }
                    
                    if (ysize < 1) //Ensuring there is a positive y size
                    {
                        cout << "Error: invalid value" << endl;
                        break;
                    }
                    
                    lineStream >> skipws; //Skipping white space
                    
                    if (!lineStream.eof()) //It should be the end of file, as we have checked for all six arguments
                    {
                        cout << "Error: too many arguments" << endl;
                        break;
                    }

                    if (type == shapeTypesList[0]) //This makes sure that the circle is even, aka has the same x and y sizes
                    {
                        if (xsize != ysize)
                        {
                            cout << "Error: invalid value" << endl;
                         break;
                        }
                    }
 
                    commandValidity = true; 
                    /*
                    bool full = false;
                        for(int j = 0; j < max_shapes; j++) //Looping through array
                        {
                            if (shapesArray[j] == NULL) //If there is an empty space in the array
                            {
                                shapesArray[j] = new Shape(name, type, xlocation, ylocation, xsize, ysize); //Setting shape using method function
                                shapeCount++;
                                cout << "Created " << name << ": " << type << " " << xlocation << " " << ylocation<< " " << xsize << " " << ysize << endl;
                                break;
                            }
                            else if (shapesArray[j] != NULL && j == max_shapes -1) //If there is no space in the array
                            {
                                cout << "Error: shape array is full" << endl;
                                full = true;
                                break;
                            }
                        }
                        if (full)
                        {
                            break;
                        } */
                    
                    break;
                }
                
                else if (i == 3) //This is command move
                {
                    bool argumentChecker = false;
                   
                    if (lineStream.eof()) //Checking if the line is empty
                    {
                        cout << "Error: too few arguments" << endl;
                        break;
                    }
                    
                    lineStream >> name; //Reading in the name of the shape that we want to move
                    
                    for (int j = 0; j < maxShape; j++)//Looping through the array
                    {
                        if (shapesArray[j] != NULL && name == shapesArray[j] -> getName()) //We find an element with the given name
                            {
                                argumentChecker = true; //We set to true since we found matching input
                                break;
                            }
                    }
                   
                    if (argumentChecker == false) //Only false if we do not find matching input, so shape is not found
                    {
                        cout << "Error: shape " << name << " not found" << endl;
                        break;
                    }
                    
                    if (lineStream.eof()) //Checking if EOF, since we still have two more necessary inputs 
                    {
                        cout << "Error: too few arguments" << endl;
                        break;
                    }
                    
                    lineStream >> xlocation; //Reading in the x location
                    
                    if (lineStream.fail()) //Two possible reasons for failure
                    {
                        if (lineStream.eof()) //EOF, since we still have one more necessary input
                        {
                            cout << "Error: too few arguments" << endl;
                            break;
                        }
                        cout << "Error: invalid argument" << endl; //input is not of integer type
                        break;
                    }
                    
                    if (xlocation < 0) //Ensuring x location is a positive integer
                    {
                        cout << "Error: invalid value" << endl;
                        break;
                    }
                    
                    lineStream >> ylocation; //Reading in the y location
                    
                    if (lineStream.fail()) //Only one possible reason for failure
                    {
                        cout << "Error: invalid argument" << endl; //input is not of integer type
                        break;
                    }
                    
                    if (ylocation < 0) //Ensuring y location is a positive integer
                    {
                        cout << "Error: invalid value" << endl;
                        break;
                    }
                    
                    lineStream >> skipws; //skipping white space
                    
                    if (!lineStream.eof()) //If it is not EOF, there are extra arguments we do not need as we already checked for all other arguments
                    {
                        cout << "Error: too many arguments" << endl;
                        break;
                    }
                    commandValidity = true;
                    /*
                    for(int j = 0; j < max_shapes; j++) //Looping through the array
                        {
                            if (name == shapesArray[j] -> getName()) //Getting the shape at the array element where the name exists
                            {
                                shapesArray[j]->setXlocation(xlocation); //Using the method function to move x location
                                shapesArray[j]->setYlocation(ylocation); //Using the method function to move y location
                                cout << "Moved " << shapesArray[j]->getName() << " to " << xlocation << ' ' << ylocation << endl;
                                break;
                            }
                        }*/
                    
                    break;
                }
                
                else if (i == 4) //This is command rotate
                {
                    bool argumentChecker = false; 
                    
                    if (lineStream.eof()) //checking if the line is empty
                    {
                        cout << "Error: too few arguments" << endl;
                        break;
                    }
                    
                    lineStream >> name; //If not empty, we are reading in the shape name
                    
                    for (int j = 0; j < maxShape; j++) //Looping through the array
                    {
                        if (shapesArray[j] != NULL && name == shapesArray[j] -> getName()) //we find an array element with input name
                            {
                                argumentChecker = true; //we set to true since we found a valid array element
                                break;
                            }
                    }
                    
                    if (argumentChecker == false) //only false if we do not enter the if statement of the for loop
                    {
                        cout << "Error: shape " << name << " not found" << endl;
                        break;
                    }
                   
                    if (lineStream.eof()) //should not be EOF as there is still one more argument to be read
                    {
                        cout << "Error: too few arguments" << endl;
                        break;
                    }
                    
                    lineStream >> angle; //Now we read in the angle if EOF is not true
                    if (lineStream.fail()) //Only one reason for failure
                    {
                        cout << "Error: invalid argument" <<  endl; //angle input is not of integer type
                        break;
                    }
                    
                    if (angle < 0 || angle > 360) //Ensuring that the angle has a valid degree value
                    {
                        cout << "Error: invalid value" << endl;
                        break;
                    }
                   
                    lineStream >> skipws; //Skipping white space
                    
                    if (!lineStream.eof()) //should be EOF as we have read our two needed inputs already, this means we have more
                    {
                        cout << "Error: too many arguments" <<  endl;
                        break;
                    }
                    
                    commandValidity = true;
                    
                    /*for(int j = 0; j < max_shapes; j++) //Looping through the array
                        {
                            if (name == shapesArray[j] -> getName()) //Getting the shape at the array element where the name exists
                            {
                                shapesArray[j]->setRotate(angle); //Using the method function to rotate the shape
                                cout << "Rotated " << shapesArray[j]->getName() << "by " << angle << " degrees" << endl;
                                break;
                            }
                        }*/
                    
                    break;
                }
                
                else if (i == 5) //This is command draw
                {
                    bool argumentChecker = false;
                    bool argumentChecker2 = false;
                    
                    if (lineStream.eof()) //Checking if the line is empty
                    {
                        cout << "Error: too few arguments" << endl;
                        break;
                    }
                    
                    lineStream >> allShapes; //Checking if the user wants to draw all shapes
                    
                    if (allShapes == keyWordsList[0]) //Command all
                    {
                        lineStream >> skipws;
                        if (!lineStream.eof()) //It should be EOF after reading in, as this command only requires one argument
                        {
                            cout << "Error: too many arguments" << endl;
                            break;
                        }
                        commandValidity = true;
                        
                        /*if (commandValidity == true && allShapes == keyWordsList[0]) //Command all (draw all shapes)
                        {
                            cout << "Drew all shapes" << endl; 
                            for(int j = 0; j < max_shapes; j++) //Looping through the array
                            {
                                if(shapesArray[j] != NULL) //Ensuring we only print full array elements
                                {
                                    // cout << shapesArray[j]->getName() << ": " << shapesArray[j]->getType() << ' ' << shapesArray[j]->getXlocation() << ' ' << shapesArray[j]->getYlocation() << ' ' << shapesArray[j]->getXsize() << ' ' << shapesArray[j]->getYsize() << endl;
                                    shapesArray[j]->draw();
                                }
                            }
                        }*/
                        
                        break;
                    }
                   
                    for (int j = 0; j < maxShape; j++) //Looping through array
                    { // for some reason, cant find previous shapes
                        if (shapesArray[j] != NULL && allShapes == shapesArray[j] -> getName()) //to draw a specific array element
                            {
                                lineStream >> skipws;
                                if (!lineStream.eof()) //It should be EOF as this command only needs one argument
                                {
                                    cout << "Error: too many arguments" << endl;
                                    argumentChecker2 = true;
                                    break;
                                }
                                argumentChecker = true;
                                break;
                            }
                    }
                    
                    if (argumentChecker2 == true)
                    {
                        break;
                    }
                    
                    if (argumentChecker == false) 
                    {
                        cout << "Error: shape " << allShapes << " not found" << endl;
                        break;
                    }
                    
                    commandValidity = true;
                    
                    
                   /* if (commandValidity == true && allShapes != keyWordsList[0])
                        {
                            for(int j = 0; j < max_shapes; j++) //Drawing a specific shape
                            {
                                if (allShapes == shapesArray[j] -> getName())
                                {
                                    //cout << "Drew " << shapesArray[j]->getName() << ": " << shapesArray[j]->getType() << ' ' << shapesArray[j]->getXlocation() << ' ' << shapesArray[j]->getYlocation() << ' ' << shapesArray[j]->getXsize() << ' ' << shapesArray[j]->getYsize() << endl;
                                    cout << "Drew ";
                                    shapesArray[j]->draw();
                                    break;
                                }
                            }
                        }
                        break; */
                        
                    break;
                }
                
                else if (i == 6) //This is command delete
                {
                    bool argumentChecker = false;
                    bool argumentChecker2 = false;
                    
                    if (lineStream.eof()) //This means the line is completely empty
                    {
                        cout << "Error: too few arguments" << endl;
                        break;
                    }
                    
                    lineStream >> allShapes; //This is our input from user
                    
                    if (allShapes == keyWordsList[0]) //Checking if the user wants to delete all shapes
                    {
                    lineStream >> skipws; //Skipping white space
                        if (!lineStream.eof()) //There should only be one input, so if not EOF, there are more than needed
                        {
                            cout << "Error: too many arguments" << endl;
                            break;
                        }
                        commandValidity = true;
                        
                        /*if (commandValidity == true && allShapes == keyWordsList[0]) //Command all (delete all shapes)
                        {
                            cout << "Deleted: all shapes" << endl; 
                            for(int j = 0; j < max_shapes; j++) //Looping through the array
                            {
                                delete shapesArray[j];
                                shapesArray[j] = NULL;
                                shapeCount = 0;
                            }
                        }*/
                        
                        break;
                    }
                    
                    for (int j = 0; j < maxShape; j++) //looping through our array
                    {
                        if (shapesArray[j] != NULL && allShapes == shapesArray[j] -> getName())
                            {
                                lineStream >> skipws; //skipping white space
                                if (!lineStream.eof()) //Should be EOF, since this command only takes one argument
                                {
                                    cout << "Error: too many arguments" << endl;
                                    argumentChecker2 = true;
                                    break;
                                }
                                argumentChecker = true; //Set to true only if the input is valid and the shapeName was found
                                break;
                            }
                    }
                    
                    if (argumentChecker2 == true) //Due to invalidity
                    {
                        break;
                    }
                    
                    if (argumentChecker == false) //It is false because the input was not valid and shape was not found
                    {
                        cout << "Error: shape " << allShapes << " not found" << endl;
                        break;
                    }
                    
                    commandValidity = true;
                    
                    
                    /*if(commandValidity == true && allShapes != keyWordsList[0])
                        {
                            for(int j = 0; j < max_shapes; j++) //deleting a specific shape
                            {
                                if (allShapes == shapesArray[j] -> getName())
                                {
                                    cout << "Deleted shape " << shapesArray[j]->getName() << endl;
                                    delete shapesArray[j];
                                    shapesArray[j] = NULL;
                                    shapeCount--;
                                    break;
                                }
                            }
                        }
                        break;*/
                        
                    break;
                }
            }
            
            if (i == 6) //This is invalid command
            {
                cout << "Error: invalid command" << endl;
            }
           
        }
        
        if (commandValidity)
        {
            for(int i = 0; i < 7; i++)
            {
                if (command == keyWordsList[i])
                {
                    if (i == 1)
                    {
                        max_shapes = maxShape;
                            shapesArray = new Shape *[max_shapes]; //Dynamically allocating
                            for (int j = 0; j < maxShape; j++)
                            {
                                shapesArray[j] = NULL; //Allocating a completely empty array
                            }

                    }
                    
                    if (i == 2)
                    {
                        bool full = false;
                        for(int j = 0; j < max_shapes; j++) //Looping through array
                        {
                            if (shapesArray[j] == NULL) //If there is an empty space in the array
                            {
                                shapesArray[j] = new Shape(name, type, xlocation, ylocation, xsize, ysize); //Setting shape using method function
                                shapeCount++;
                                cout << "Created " << name << ": " << type << " " << xlocation << " " << ylocation<< " " << xsize << " " << ysize << endl;
                                break;
                            }
                            else if (shapesArray[j] != NULL && j == max_shapes -1) //If there is no space in the array
                            {
                                cout << "Error: shape array is full" << endl;
                                full = true;
                                break;
                            }
                        }
                        if (full)
                        {
                            break;
                        }
                    }
                    
                    if(i == 3)
                    {
                        for(int j = 0; j < max_shapes; j++) //Looping through the array
                        {
                            if (name == shapesArray[j] -> getName()) //Getting the shape at the array element where the name exists
                            {
                                shapesArray[j]->setXlocation(xlocation); //Using the method function to move x location
                                shapesArray[j]->setYlocation(ylocation); //Using the method function to move y location
                                cout << "Moved " << shapesArray[j]->getName() << " to " << xlocation << ' ' << ylocation << endl;
                                break;
                            }
                        }
                    }
                    
                    if (i == 4)
                    {
                        for(int j = 0; j < max_shapes; j++) //Looping through the array
                        {
                            if (name == shapesArray[j] -> getName()) //Getting the shape at the array element where the name exists
                            {
                                shapesArray[j]->setRotate(angle); //Using the method function to rotate the shape
                                cout << "Rotated " << shapesArray[j]->getName() << "by " << angle << " degrees" << endl;
                                break;
                            }
                        }
                    }
                    
                    if (i == 5)
                    {
                        if (allShapes == keyWordsList[0]) //Command all (draw all shapes)
                        {
                            cout << "Drew all shapes" << endl; 
                            for(int j = 0; j < max_shapes; j++) //Looping through the array
                            {
                                if(shapesArray[j] != NULL) //Ensuring we only print full array elements
                                {
                                    // cout << shapesArray[j]->getName() << ": " << shapesArray[j]->getType() << ' ' << shapesArray[j]->getXlocation() << ' ' << shapesArray[j]->getYlocation() << ' ' << shapesArray[j]->getXsize() << ' ' << shapesArray[j]->getYsize() << endl;
                                    shapesArray[j]->draw();
                                }
                            }
                        }
                        
                        else
                        {
                            for(int j = 0; j < max_shapes; j++) //Drawing a specific shape
                            {
                                if (allShapes == shapesArray[j] -> getName())
                                {
                                    //cout << "Drew " << shapesArray[j]->getName() << ": " << shapesArray[j]->getType() << ' ' << shapesArray[j]->getXlocation() << ' ' << shapesArray[j]->getYlocation() << ' ' << shapesArray[j]->getXsize() << ' ' << shapesArray[j]->getYsize() << endl;
                                    cout << "Drew ";
                                    shapesArray[j]->draw();
                                    break;
                                }
                            }
                        }
                        break; 
                    }
                    
                    if (i == 6)
                    {
                        if (allShapes == keyWordsList[0]) //Command all (delete all shapes)
                        {
                            cout << "Deleted: all shapes" << endl; 
                            for(int j = 0; j < max_shapes; j++) //Looping through the array
                            {
                                delete shapesArray[j];
                                shapesArray[j] = NULL;
                                shapeCount = 0;
                            }
                        }
                        
                        else
                        {
                            for(int j = 0; j < max_shapes; j++) //deleting a specific shape
                            {
                                if (allShapes == shapesArray[j] -> getName())
                                {
                                    cout << "Deleted shape " << shapesArray[j]->getName() << endl;
                                    delete shapesArray[j];
                                    shapesArray[j] = NULL;
                                    shapeCount--;
                                    break;
                                }
                            }
                        }
                        break;
                        
                       
                    }
                }
            }
        }
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);   // Get the command line
        
    }  // End input loop until EOF.
    
    for(int j = 0; j < max_shapes; j++) //Emptying out the array
    {
        delete shapesArray[j];
        shapesArray[j] = NULL;
    }
    
    delete [] shapesArray;
    *shapesArray = NULL;
    return 0;
}