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
#include "wasteLevel.h" //Include the wasteLevel header file

#ifndef NON_OPTIMIZED_ROUTE_H //Header file guard
#define NON_OPTIMIZED_ROUTE_H //Header file guard

using namespace std; //Use standard namespace

class NonOptimizedRoute { //Class for the NonOptimizedRoute

public: //public specifier
    void noSolution(GarbageLocations& garbageLocations, const vector<string>& currentLocations, const vector<string>& shortestPathLocations, ofstream& outFileNOR) { //Non-Optimized solution for the route
        cout << "Shortest Path from Waste Station to each location:" << endl;
        outFileNOR << "Shortest Path from Waste Station to each location:" << endl;

        int totalDistance = 0; //Initiailizing the totalDistance variable to 0
        int totalWasteCollected = 0; //Initiailizing the totalWasteCollected variable to 0
        float totalCost, totalTime, totalFuelConsumption, driverWage = 0; //Initiailizing the float totalCost, totalTime, totalFuelConsumption and driverWage variables to 0
        int wasteInKG = 0; //Initiailizing the wasteInKG variable to 0

        vector<string> locationsWithin12Hours; //Creating a vector of strings called locationsWithin12Hours

        for (int index = 1; index < currentLocations.size(); index++) { //For loop to iterate through the currentLocations vector, this is all the locations in the distance matrix
            if (garbageLocations.wasteLevels[currentLocations[index]] >= 40) { //Check if the waste level is greater than or equal to 40
                int pathDistanceFromWasteStation = 0; //Initiailizing the pathDistanceFromWasteStation variable to 0
                cout << "Waste Station to " << currentLocations[index] << ": ";
                outFileNOR << "Waste Station to " << currentLocations[index] << ": ";
                for (int index2 = 1; index2 < shortestPathLocations.size(); index2++) { //Loop the shortestPathLocations vector
                    if (shortestPathLocations[index2] == currentLocations[index]) {
                        for (int index3 = 1; index3 <= index2; index3++) {
                            int findIndex = index3 - 1;
                            pathDistanceFromWasteStation += garbageLocations.distanceMatrix[shortestPathLocations[findIndex]][shortestPathLocations[index3]];
                        }
                        if (pathDistanceFromWasteStation <= 30) { //Check if the distance from the waste station to target location is less than or equal to 30
                            totalDistance += pathDistanceFromWasteStation;
                            totalWasteCollected += garbageLocations.wasteLevels[currentLocations[index]]; //Find the total waste collected
                            cout << pathDistanceFromWasteStation << " km \tPath : ";
                            outFileNOR << pathDistanceFromWasteStation << " km \tPath: "; 
                            for (int index4 = 0; index4 <= index2; index4++) { //Loop through the second index to display the path
                                cout << shortestPathLocations[index4];
                                outFileNOR << shortestPathLocations[index4];
                                if (index4 != index2) {
                                    cout << " -> ";
                                    outFileNOR << " -> ";
                                }
                            }
                        } else { //If not then display the output below
                            cout << "Distance exceeds 30 km, Location not visited";
                            outFileNOR << "Distance exceeds 30 km, Location not visited";
                        }
                        break;
                    }
                }

                wasteInKG = (totalWasteCollected * 500) / 100; //Convert the waste collected from percentage to KG

                cout << endl;
                outFileNOR << endl;
                totalCost = totalDistance * 2.5;
                totalTime = totalDistance * 0.2;
                totalFuelConsumption = 2 * totalDistance;

                if (totalTime <= 12) {
                    locationsWithin12Hours.push_back(currentLocations[index]);
                } else {
                    cout << "\n**Total time exceeds 12 hours, refer to the locations below that can be visited within 12 hours**" << endl;
                    outFileNOR << "\n**Total time exceeds 12 hours, refer to the locations below that can be visited within 12 hours**" << endl;
                    break;
                }
            }
        }

        if (totalTime > 12) { //There is a time limit of 12 hours, if exceeded then display the output below
            cout << "\nLocations that can be visited within 12 hours:" << endl;
            outFileNOR << "\nLocations that can be visited within 12 hours:" << endl;
            for (int i = 0; i < locationsWithin12Hours.size(); i++) {
                cout << locationsWithin12Hours[i] << endl;
                outFileNOR << locationsWithin12Hours[i] << endl;
            }
        }
        
        if (totalTime > 12) {
            driverWage = 20 * 12;  // Driver wage for visited locations
            cout << "\nDriver Wage for this trip: " << driverWage << " MYR" << endl;
            outFileNOR << "\nDriver Wage for this trip: " << driverWage << " MYR" << endl;
        } else {
            driverWage = 20 * totalTime;  // Driver wage for visited locations
            cout << "\nDriver Wage for this trip: " << driverWage << " MYR" << endl;
            outFileNOR << "\nDriver Wage for this trip: " << driverWage << " MYR" << endl;
        }

        //Display the total distance, cost, time, fuel consumption and waste collected - all related information
        cout << "\nTotal Distance for Visited Locations: " << totalDistance << " km" << endl;
        outFileNOR << "\nTotal Distance for Visited Locations: " << totalDistance << " km" << endl;
        cout << "Total Cost: " << totalCost << " MYR" << endl;
        outFileNOR << "Total Cost: " << totalCost << " MYR" << endl;
        cout << "Total Time: " << totalTime << " hours" << endl;
        outFileNOR << "Total Time: " << totalTime << " hours" << endl;
        cout << "Total Fuel Consumption: " << totalFuelConsumption << " Liters" << endl;
        outFileNOR << "Total Fuel Consumption: " << totalFuelConsumption << " Liters" << endl;
        cout << "Cumulative total percentage of waste collected from all valid locations: " << totalWasteCollected << "%" << endl;
        outFileNOR << "Cumulative total percentage of waste collected from all valid locations: " << totalWasteCollected << "%" << endl;
        cout << "Total Waste Collected: " << wasteInKG << "kg" << endl;
        outFileNOR << "Total Waste Collected: " << wasteInKG << "kg" << endl;
    }

    vector<string> calculateShortestPath(const vector<string>& currentLocations) { //Method that pre-defines the shortest path using the graph and distance matrix
        vector<string> shortestPathLocations; //Create the shortestPathLocations vector
        shortestPathLocations.push_back("Waste Station"); //Push the waste station into the vector
        shortestPathLocations.push_back("Location 1"); //Push the locations 1 into the vector
        shortestPathLocations.push_back("Location 3"); //Push the locations 3 into the vector
        shortestPathLocations.push_back("Location 2"); //Push the locations 2 into the vector
        shortestPathLocations.push_back("Location 4"); //Push the locations 4 into the vector
        shortestPathLocations.push_back("Location 3"); //Push the locations 3 into the vector
        shortestPathLocations.push_back("Location 6"); //Push the locations 6 into the vector
        shortestPathLocations.push_back("Location 5"); //Push the locations 5 into the vector
        shortestPathLocations.push_back("Location 6"); //Push the locations 6 into the vector
        shortestPathLocations.push_back("Location 7"); //Push the locations 7 into the vector

        return shortestPathLocations; //Return the shortestPathLocations vector
    }
};

#endif