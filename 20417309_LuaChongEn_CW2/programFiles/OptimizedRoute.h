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

#ifndef OPTIMIZEDROUTE_H //Header file guard
#define OPTIMIZEDROUTE_H //Header file guard

#define INF INT_MAX //Set INF as the maximum integer value
#define V 8 //Set V to 8 which is the number of vertices, because there are 8 locations then define the number of vertices as well for the algorithm to work

using namespace std; //Use standard namespace

class OptimizedRoute { //Class for the optimized route

public: //Public specifier
    void createGraph(const GarbageLocations& garbageLocations, int garbageLocationGraph[][V], const vector<string>& currentLocations) { //Create the graph for the garbage locations
        for (int index = 0; index < V; index++) { //Iterate over the vertices which is the number of locations, similar to greedy algorithm
            for (int index2 = 0; index2 < V; index2++) { //Iterate again over the number of locations
                garbageLocationGraph[index][index2] = garbageLocations.distanceMatrix.at(currentLocations[index]).at(currentLocations[index2]); //Then set the distances between the locations
            }
        }
    }

    void fwSolution(const GarbageLocations& garbageLocations, int shortestDistanceMatrix[][V], int predecessorMatrix[][V], const vector<string>& currentLocations, ofstream& outFileOR) { //Floyd-Warshall algorithm to find the shortest path
        outFileOR << "Shortest Path from Waste Station to each location:" << endl;
        cout << "Shortest Path from Waste Station to each location:" << endl;
        int totalWasteCollected = 0;
        int wasteInKG = 0;
        int source = 0;
        float totalShortestDistanceMatrix = 0; 
        float totalCost, totalTime, totalFuelConsumption, driverWage = 0;
        vector<string> locationsWithin8Hours; 
        for (int index = 1; index < V; index++) { //Iterate over the number of locations/ vertices
            if (garbageLocations.wasteLevels.at(currentLocations[index]) >= 50) { //Then check if the waste levels are greater than or equal to 50
                if (shortestDistanceMatrix[source][index] <= 11) { //Then check if the shortest distance is less than or equal to 11 km
                    totalWasteCollected += garbageLocations.wasteLevels.at(currentLocations[index]);
                    totalShortestDistanceMatrix += shortestDistanceMatrix[0][index];  
                    outFileOR << "Waste Station to " << currentLocations[index] << ": " << shortestDistanceMatrix[source][index] << " km\tPath: ";
                    cout << "Waste Station to " << currentLocations[index] << ": " << shortestDistanceMatrix[source][index] << " km\tPath: ";

                    int index2 = index;
                    vector<string> shortestPathLocations;
                    shortestPathLocations.push_back(currentLocations[index2]);
                    while (predecessorMatrix[source][index2] != -1) {
                        shortestPathLocations.push_back(currentLocations[predecessorMatrix[source][index2]]);
                        index2 = predecessorMatrix[source][index2];
                    }

                    for (int p = shortestPathLocations.size() - 1; p >= 0; p--) {
                        outFileOR << shortestPathLocations[p];
                        cout << shortestPathLocations[p];
                        if (p != 0) {
                            outFileOR << " -> ";
                            cout << " -> ";
                        }
                    }

                    totalTime = totalShortestDistanceMatrix * 0.2;
                    wasteInKG = (totalWasteCollected * 500)/100;

                    if (totalTime <= 8) { //Check if the locations visited is less than or equal to 8 hours which is the time restriction
                        locationsWithin8Hours.push_back(currentLocations[index]);
                    } else {
                        outFileOR << "\n**Total time exceeds 8 hours, refer to the locations below that can be visited within 8 hours**" << endl;
                        cout << "\n**Total time exceeds 8 hours, refer to the locations below that can be visited within 8 hours**" << endl;
                        break;
                    }

                    outFileOR << endl;
                    cout << endl;
                } else { //If the distance exceeds 11 km
                    outFileOR << "Waste Station to " << currentLocations[index] << ": Distance exceeds 11 km" << endl;
                    cout << "Waste Station to " << currentLocations[index] << ": Distance exceeds 11 km" << endl;
                }
            }
        }

        if (totalTime > 8) { //If the total time exceeds 8 hours
            outFileOR << "\nLocations that can be visited within 8 hours:" << endl;
            cout << "\nLocations that can be visited within 8 hours:" << endl;
            for (int i = 0; i < locationsWithin8Hours.size(); i++) {
                outFileOR << locationsWithin8Hours[i] << endl;
                cout << locationsWithin8Hours[i] << endl;
            }
        }

        if(totalTime > 8) { //If the total time exceeds 8 hours then calculate the driver wage
            driverWage = 20 * 8;
            outFileOR << "\nDriver Wage for this trip: " << driverWage << " MYR" << endl; //Print the wage
            cout << "\nDriver Wage for this trip: " << driverWage << " MYR" << endl;
        } else {
            driverWage = 20 * totalTime;
            outFileOR << "\nDriver Wage for this trip: " << driverWage << " MYR" << endl; //Print the wage
            cout << "\nDriver Wage for this trip: " << driverWage << " MYR" << endl;
        }

        totalCost = totalShortestDistanceMatrix * 2.5; 
        totalFuelConsumption = 2 * totalShortestDistanceMatrix;  

        //Display the total distance, cost, time, fuel consumption and waste collected - all related information
        outFileOR << "\nTotal Distance for Visited Locations: " << totalShortestDistanceMatrix << " km" << endl; 
        cout << "\nTotal Distance for Visited Locations: " << totalShortestDistanceMatrix << " km" << endl; 
        outFileOR << "Total Cost: " << totalCost << " MYR" << endl;  
        cout << "Total Cost: " << totalCost << " MYR" << endl;
        outFileOR << "Total Time: " << totalTime << " hours" << endl; 
        cout << "Total Time: " << totalTime << " hours" << endl;
        outFileOR << "Total Fuel Consumption: " << totalFuelConsumption << " Liters" << endl; 
        cout << "Total Fuel Consumption: " << totalFuelConsumption << " Liters" << endl;
        cout << "Cumulative total percentage of waste collected from all valid locations: " << totalWasteCollected << "%" << endl;
        outFileOR << "Cumulative total percentage of waste collected from all valid locations: " << totalWasteCollected << "%" << endl;
        outFileOR << "Total Waste Collected: " << wasteInKG << "kg" << endl;
        cout << "Total Waste Collected: " << wasteInKG << "kg" << endl;
    }

    void floydWarshall(const vector<string>& currentLocations, const GarbageLocations& garbageLocations, ofstream& outFileOR) { //Floyd Warshall Algorithm, this contains the logic for the floyd warshall algorithm
        int garbageLocationGraph[V][V];
        createGraph(garbageLocations, garbageLocationGraph, currentLocations);

        int shortestDistanceMatrix[V][V]; //Shortest distance matrix, this is used to store the distances between locations that are visited
        int predecessorMatrix[V][V]; //Predecessor matrix, this is used to store the predecessor of each location which is used by this algorithm

        for (int index = 0; index < V; index++) { //Iterate over the locations and store the distances and predecessors
            for (int index2 = 0; index2 < V; index2++) { //Iterate over the locationsand store the distances and predecessors
                shortestDistanceMatrix[index][index2] = garbageLocationGraph[index][index2];
                if (index != index2 && garbageLocationGraph[index][index2] != INF) {
                    predecessorMatrix[index][index2] = index;
                } else {
                    predecessorMatrix[index][index2] = -1;
                }
            }
        }

        for (int index = 0; index < V; index++) { //Iterate over the locations
            for (int index2 = 0; index2 < V; index2++) { //Iterate over the locations again
                for (int index3 = 0; index3 < V; index3++) {
                    if (shortestDistanceMatrix[index][index3] != INF && shortestDistanceMatrix[index2][index] + shortestDistanceMatrix[index][index3] < shortestDistanceMatrix[index2][index3] && shortestDistanceMatrix[index2][index] != INF) {
                        predecessorMatrix[index2][index3] = predecessorMatrix[index][index3];
                        shortestDistanceMatrix[index2][index3] = shortestDistanceMatrix[index2][index] + shortestDistanceMatrix[index][index3];
                    }
                }
            }
        }

        fwSolution(garbageLocations, shortestDistanceMatrix, predecessorMatrix, currentLocations, outFileOR); //Call the method to print the solution 
    }
};

#endif