#include <iostream> //Input and Output operations
#include <string> //String operations
#include <vector> //Dynamic array structure operations
#include <stdio.h> //Standard Input/Output operations
#include <stdlib.h> //Standard Library operations
#include <ctime> //To get date and time
#include <cmath> //Math related functions
#include <map> //Store map opearations for key value pairs
#include <limits> //Uses constants that represent the limits of data types
#include <algorithm> //Provides a collection of functions for working with containers 
#include <tuple> //Allows the use of fixed-size collection of elements 
#include <climits> //So INF and INT MAX can be used

#ifndef LOCATIONS_H //Header file guard
#define LOCATIONS_H //Header file guard

using namespace std; //Use standard namespace

class Locations{ //Class for the locations

public: //Public specifier
    void initializeLocations(vector<string>& currentLocations) { //Initialize the locations and push all the locations to the vector
        currentLocations.push_back("Waste Station"); //Push the source to the vector
        currentLocations.push_back("Location 1"); //Push the location 1 to the vector
        currentLocations.push_back("Location 2"); //Push the location 2 to the vector
        currentLocations.push_back("Location 3"); //Push the location 3 to the vector
        currentLocations.push_back("Location 4"); //Push the location 4 to the vector
        currentLocations.push_back("Location 5"); //Push the location 5 to the vector
        currentLocations.push_back("Location 6"); //Push the location 6 to the vector
        currentLocations.push_back("Location 7"); //Push the location 7 to the vector
    }
};

#endif