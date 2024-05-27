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

using namespace std; //Using standard namespace

#define INF INT_MAX //Set INF to a max int value

#ifndef GARBAGE_LOCATIONS_H //Header file guard
#define GARBAGE_LOCATIONS_H //Header file guard

class GarbageLocations {  //GarbageLocations class

public: //Public specifier
    map<string, int> wasteLevels; //Defining a map key value pair for the wastelevels
    map<string, map<string, int> > distanceMatrix; //Defining a map key value pair for the distance matrix

    GarbageLocations() { //Constructor
        vector<string> locations; //Defining the vector locations
        locations.push_back("Waste Station"); //Push the locations into the vector
        locations.push_back("Location 1"); //Push the locations into the vector
        locations.push_back("Location 2"); //Push the locations into the vector
        locations.push_back("Location 3"); //Push the locations into the vector
        locations.push_back("Location 4"); //Push the locations into the vector
        locations.push_back("Location 5"); //Push the locations into the vector
        locations.push_back("Location 6"); //Push the locations into the vector
        locations.push_back("Location 7"); //Push the locations into the vector

        distanceMatrix["Waste Station"]["Waste Station"] = 0; //Location pointing to itself is 0
        distanceMatrix["Waste Station"]["Location 1"] = 3; //The distance between the waste station and location 1 is 3
        distanceMatrix["Waste Station"]["Location 2"] = INF; //There is no direct path between the waste station and location 2
        distanceMatrix["Waste Station"]["Location 3"] = INF; //There is no direct path between the waste station and location 3
        distanceMatrix["Waste Station"]["Location 4"] = INF; //There is no direct path between the waste station and location 4
        distanceMatrix["Waste Station"]["Location 5"] = INF; //There is no direct path between the waste station and location 5
        distanceMatrix["Waste Station"]["Location 6"] = INF; //There is no direct path between the waste station and location 6
        distanceMatrix["Waste Station"]["Location 7"] = 4; //The distance between the waste station and location 7 is 4

        distanceMatrix["Location 1"]["Waste Station"] = 3; //The distance between location 1 and the waste station is 3
        distanceMatrix["Location 1"]["Location 1"] = 0; //Location pointing to itself is 0
        distanceMatrix["Location 1"]["Location 2"] = INF; //There is no direct path between location 1 and location 2
        distanceMatrix["Location 1"]["Location 3"] = 6; //The distance between location 1 and location 3 is 6
        distanceMatrix["Location 1"]["Location 4"] = INF; //There is no direct path between location 1 and location 4
        distanceMatrix["Location 1"]["Location 5"] = INF, //There is no direct path between location 1 and location 5
        distanceMatrix["Location 1"]["Location 6"] = INF; //There is no direct path between location 1 and location 6
        distanceMatrix["Location 1"]["Location 7"] = INF; //There is no direct path between location 1 and location 7

        distanceMatrix["Location 2"]["Waste Station"] = INF; //There is no direct path between location 2 and the waste station
        distanceMatrix["Location 2"]["Location 1"] = INF; //There is no direct path between location 2 and location 1
        distanceMatrix["Location 2"]["Location 2"] = 0; //Location pointing to itself is 0
        distanceMatrix["Location 2"]["Location 3"] = 5; //The distance between location 2 and location 3 is 5
        distanceMatrix["Location 2"]["Location 4"] = 4; //The distance between location 2 and location 4 is 4
        distanceMatrix["Location 2"]["Location 5"] = INF; //There is no direct path between location 2 and location 5
        distanceMatrix["Location 2"]["Location 6"] = INF; //There is no direct path between location 2 and location 6
        distanceMatrix["Location 2"]["Location 7"] = INF; //There is no direct path between location 2 and location 7

        distanceMatrix["Location 3"]["Waste Station"] = INF; //There is no direct path between location 3 and the waste station
        distanceMatrix["Location 3"]["Location 1"] = 6; //The distance between location 3 and location 1 is 6
        distanceMatrix["Location 3"]["Location 2"] = 5; //The distance between location 3 and location 2 is 5
        distanceMatrix["Location 3"]["Location 3"] = 0; //Location pointing to itself is 0
        distanceMatrix["Location 3"]["Location 4"] = 2; //The distance between location 3 and location 4 is 2
        distanceMatrix["Location 3"]["Location 5"] = INF; //There is no direct path between location 3 and location 5
        distanceMatrix["Location 3"]["Location 6"] = 2; //The distance between location 3 and location 6 is 2
        distanceMatrix["Location 3"]["Location 7"] = INF; //There is no direct path between location 3 and location 7

        distanceMatrix["Location 4"]["Waste Station"] = INF; //There is no direct path between location 4 and the waste station
        distanceMatrix["Location 4"]["Location 1"] = INF; //There is no direct path between location 4 and location 1
        distanceMatrix["Location 4"]["Location 2"] = 4; //The distance between location 4 and location 2 is 4
        distanceMatrix["Location 4"]["Location 3"] = 2; //The distance between location 4 and location 3 is 2
        distanceMatrix["Location 4"]["Location 4"] = 0; //Location pointing to itself is 0
        distanceMatrix["Location 4"]["Location 5"] = INF; //There is no direct path between location 4 and location 5
        distanceMatrix["Location 4"]["Location 6"] = INF; //There is no direct path between location 4 and location 6
        distanceMatrix["Location 4"]["Location 7"] = INF; //There is no direct path between location 4 and location 7

        distanceMatrix["Location 5"]["Waste Station"] = INF; //There is no direct path between location 5 and the waste station
        distanceMatrix["Location 5"]["Location 1"] = INF; //There is no direct path between location 5 and location 1
        distanceMatrix["Location 5"]["Location 2"] = INF; //There is no direct path between location 5 and location 2
        distanceMatrix["Location 5"]["Location 3"] = INF; //There is no direct path between location 5 and location 3
        distanceMatrix["Location 5"]["Location 4"] = INF; //There is no direct path between location 5 and location 4
        distanceMatrix["Location 5"]["Location 5"] = 0; //Location pointing to itself is 0
        distanceMatrix["Location 5"]["Location 6"] = 7; //The distance between location 5 and location 6 is 7
        distanceMatrix["Location 5"]["Location 7"] = INF; //There is no direct path between location 5 and location 7

        distanceMatrix["Location 6"]["Waste Station"] = INF; //There is no direct path between location 6 and the waste station
        distanceMatrix["Location 6"]["Location 1"] = INF; //There is no direct path between location 6 and location 1
        distanceMatrix["Location 6"]["Location 2"] = INF; //There is no direct path between location 6 and location 2
        distanceMatrix["Location 6"]["Location 3"] = 2; //The distance between location 6 and location 3 is 2
        distanceMatrix["Location 6"]["Location 4"] = INF; //There is no direct path between location 6 and location 4
        distanceMatrix["Location 6"]["Location 5"] = 7; //The distance between location 6 and location 5 is 7
        distanceMatrix["Location 6"]["Location 6"] = 0; //Location pointing to itself is 0
        distanceMatrix["Location 6"]["Location 7"] = 3; //The distance between location 6 and location 7 is 3

        distanceMatrix["Location 7"]["Waste Station"] = 4; //The distance between location 7 and the waste station is 4
        distanceMatrix["Location 7"]["Location 1"] = INF; //There is no direct path between location 7 and location 1
        distanceMatrix["Location 7"]["Location 2"] = INF; //There is no direct path between location 7 and location 2
        distanceMatrix["Location 7"]["Location 3"] = INF; //There is no direct path between location 7 and location 3
        distanceMatrix["Location 7"]["Location 4"] = INF; //There is no direct path between location 7 and location 4
        distanceMatrix["Location 7"]["Location 5"] = INF; //There is no direct path between location 7 and location 5
        distanceMatrix["Location 7"]["Location 6"] = 3; //The distance between location 7 and location 6 is 3
        distanceMatrix["Location 7"]["Location 7"] = 0; //Location pointing to itself is 0

        srand(time(0)); //seeding the random number generator

        wasteLevels[locations[0]] = 0; //Waste at source is 0
        for (int index = 1; index < locations.size(); index++) { 
            int wasteLevel = rand() % 101; //Assigining a random value to every location except the source
            wasteLevels[locations[index]] = wasteLevel; //Assigning the random value to the location
        }
    }

    void regenerateWasteLevels() { //Regenerating waste levels
        srand(time(0)); 
 
        wasteLevels.clear(); //Clearing the waste levels
        vector<string> locations; //Creating a vector for locations
        locations.push_back("Waste Station"); //Pushing the waste station into the vector
        locations.push_back("Location 1"); //Pushing location 1 into the vector
        locations.push_back("Location 2"); //Pushing location 2 into the vector
        locations.push_back("Location 3"); //Pushing location 3 into the vector
        locations.push_back("Location 4"); //Pushing location 4 into the vector
        locations.push_back("Location 5"); //Pushing location 5 into the vector
        locations.push_back("Location 6"); //Pushing location 6 into the vector
        locations.push_back("Location 7"); //Pushing location 7 into the vector

        wasteLevels["Waste Station"] = 0; //Waste at source is 0
        for (int index = 1; index < locations.size(); index++) { 
            int wasteLevel = rand() % 101; //Assigining a random value to every location except the source
            wasteLevels[locations[index]] = wasteLevel; //Assigning the random value to the location
        }
    }
};

#endif 