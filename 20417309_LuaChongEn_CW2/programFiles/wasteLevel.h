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
#include "GarbageLocations.h" //Include the GarbageLocations header file

#ifndef WASTELEVEL_H //Header file guard
#define WASTELEVEL_H //Header file guard

using namespace std; //Use standard namespace

class wasteLevel { //Class for the waste levels

public: //Public specifier
    void wasteLevels(const GarbageLocations& garbageLocations, ofstream &outFile) { //Method to display the waste levels
        outFile << "\nCurrent Waste Levels: \n";
        cout << "\nCurrent Waste Levels: \n";

        int wasteInKG = 0; //Initialize the waste in KG variable as integer
        int maxWaste = 500; //Initialize the maximum waste as 500

        for (map<string, map<string, int> >::const_iterator iterator = garbageLocations.distanceMatrix.begin(); iterator != garbageLocations.distanceMatrix.end(); iterator++) { //Iterate through the distance matrix
            const pair<string, map<string, int> >& currentLocation = *iterator; //Initialize the current location as a key value pair
            if (currentLocation.first != "Waste Station") { //If the current location is NOT the waste station/ source
                outFile << "Waste at " << currentLocation.first << ": " << garbageLocations.wasteLevels.at(currentLocation.first) << "%" << endl;
                cout << "Waste at " << currentLocation.first << ": " << garbageLocations.wasteLevels.at(currentLocation.first) << "%" << endl;
            }
        }

        cout << "\nWaste in kg: \n";
        for (map<string, map<string, int> >::const_iterator iterator = garbageLocations.distanceMatrix.begin(); iterator != garbageLocations.distanceMatrix.end(); iterator++) { //Iterate through the distance matrix
            const pair<string, map<string, int> >& currentLocation = *iterator; //Initialize the current location as a key value pair
            if (currentLocation.first != "Waste Station") { //If the current location is NOT the waste station/ source
                wasteInKG = (maxWaste * garbageLocations.wasteLevels.at(currentLocation.first)) / 100; //Calculate the waste in KG
                outFile << "Waste in KG at " << currentLocation.first << ": " << wasteInKG << "kg" << endl;
                cout << "Waste in KG at " << currentLocation.first << ": " << wasteInKG << "kg" << endl;
            }
        }
        
        outFile << "\n";
        cout << "\n";
    }

    void wasteLevels(const GarbageLocations& garbageLocations) { //Method to display the waste levels
        int wasteInKG = 0;
        int maxWaste = 500;
        
        cout << "\nCurrent Waste Levels: \n";
        for (map<string, map<string, int> >::const_iterator iterator = garbageLocations.distanceMatrix.begin(); iterator != garbageLocations.distanceMatrix.end(); iterator++) { //Iterate through the distance matrix
            const pair<string, map<string, int> >& currentLocation = *iterator;
            if (currentLocation.first != "Waste Station") { //If the current location is NOT the waste station/ source
                cout << "Waste at " << currentLocation.first << ": " << garbageLocations.wasteLevels.at(currentLocation.first) << "%" << endl;
            }
        }
        
        cout << "\nWaste in kg: \n";
        for (map<string, map<string, int> >::const_iterator iterator = garbageLocations.distanceMatrix.begin(); iterator != garbageLocations.distanceMatrix.end(); iterator++) { //Iterate through the distance matrix
            const pair<string, map<string, int> >& currentLocation = *iterator;
            if (currentLocation.first != "Waste Station") { //If the current location is NOT the waste station/ source
                wasteInKG = (maxWaste * garbageLocations.wasteLevels.at(currentLocation.first)) / 100;
                cout << "Waste in KG at " << currentLocation.first << ": " << wasteInKG << "kg" << endl;
            }
        }
        cout << "\n";
    }
};

#endif