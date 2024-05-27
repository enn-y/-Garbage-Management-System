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

#ifndef TSPROUTE_H //Header file guard
#define TSPROUTE_H //Header file guard

#define INF INT_MAX //Set INF to the maximum integer value
#define V 8 //Set V to 8 which is the number of vertices, because there are 8 locations then define the number of vertices as well for the algorithm to work

using namespace std; //Use standard namespace

class TSPRoute { //Class for the TSPRoute

public: //Public specifier
    void createGraph(int garbageLocationGraph[][V], const vector<string>& currentLocations, const GarbageLocations& garbageLocations) { //Create the graph for the TSP algorithm
        for (int index = 0; index < V; index++) { //Iterate over the number of vertices which is the number of locations
            for (int index2 = 0; index2 < V; index2++) {
                garbageLocationGraph[index][index2] = garbageLocations.distanceMatrix.at(currentLocations[index]).at(currentLocations[index2]);
            }
        }
    }

    int minimumDistance(float distance[], bool shortestPathTree[]) {//Find the minimum distance
        float minimumValue = INF; //Set the minimum value to the INF which indicates the maximum integer value
        int minimumIndex; //Declare the minimum index

        for (int v = 0; v < V; v++) //Iterate over the number of vertices
            if (shortestPathTree[v] == false && distance[v] <= minimumValue){ //If the shortest path tree is false and the distance is less than or equal to the minimum value
                minimumValue = distance[v]; //Then assign the minimum value to the distance
                minimumIndex = v; //And the minimum index to the vertex
            }
        return minimumIndex;
    }

    void tspPath(int parentLocation[], int index, const vector<string>& currentLocations, ofstream& outFileTSP) { //Find the path for the TSP algorithm
        if (parentLocation[index] == -1) { //If the parent location is -1 it means that the location is the waste station
            outFileTSP << "Waste Station";
            cout << "Waste Station";
            return;
        }

        tspPath(parentLocation, parentLocation[index], currentLocations, outFileTSP); //Recursively call the function to find the path, this is so that the path is printed in the correct order

        if (currentLocations[parentLocation[index]] != currentLocations[index]) { //If the parent location is not equal to the current location
            outFileTSP << " -> " << currentLocations[index];
            cout << " -> " << currentLocations[index];
        }
    }

    void tspSolution(float distance[], int vertex, int parent[], const vector<string>& currentLocations, const GarbageLocations& garbageLocations, ofstream& outFileTSP) { //Find the solution for the TSP algorithm, this is the logic for the algorithm
        outFileTSP << "Shortest Path from Waste Station to each location:" << endl;
        cout << "Shortest Path from Waste Station to each location:" << endl;

        float totalDistance = 0; 
        float totalCost, totalTime, totalFuelConsumption, driverWage = 0;
        int totalWasteCollected = 0;
        int wasteInKG = 0;
        vector<string> locationsWithin8Hours; 
        
        for (int index = 1; index < V; index++) { //Iterate over the number of vertices which is the number of locations
            if (garbageLocations.wasteLevels.at(currentLocations[index]) >= 60) { //If the waste level is greater than or equal to 60
                if (distance[index] <= 12) { //If the distance is less than or equal to 12
                    totalDistance += distance[index]; 
                    totalWasteCollected += garbageLocations.wasteLevels.at(currentLocations[index]);
                    outFileTSP << "Waste Station to " << currentLocations[index] << ": " << distance[index] << " km\t";
                    cout << "Waste Station to " << currentLocations[index] << ": " << distance[index] << " km\t";
                    outFileTSP << "Path: ";
                    cout << "Path: ";

                    tspPath(parent, index, currentLocations, outFileTSP); //Call the tspPath method to find the path

                    outFileTSP << endl;
                    cout << endl;
                    totalTime = totalDistance * 0.2;  
                    if (totalTime <= 8) { //If the total time is less than or equal to 8 hours
                        locationsWithin8Hours.push_back(currentLocations[index]); 
                    } else { //If the total time exceeds 8 hours
                        outFileTSP << "**Total time exceeds 8 hours, refer to the locations below that can be visited within 8 hours**" << endl;
                        cout << "**Total time exceeds 8 hours, refer to the locations below that can be visited within 8 hours**" << endl;
                        break;
                    }
                } else { //If the distance exceeds 12 km
                    outFileTSP << "Waste Station to " << currentLocations[index] << ": Distance exceeds 12 km" << endl;
                    cout << "Waste Station to " << currentLocations[index] << ": Distance exceeds 12 km" << endl;
                }
            }
        }

        totalCost = totalDistance * 2.5; 
        totalFuelConsumption = 2 * totalDistance;  
        wasteInKG = (totalWasteCollected * 500)/100;

        if (totalTime > 8) { //If the total time exceeds 8 hours
            outFileTSP << "\nTotal time exceeds 8 hours" << endl;
            cout << "\nLocations that can be visited within 8 hours:" << endl;
            for (int i = 0; i < locationsWithin8Hours.size(); i++) {
                outFileTSP << locationsWithin8Hours[i] << endl;
                cout << locationsWithin8Hours[i] << endl;
            }
        }

        if(totalTime > 8) { //If the total time exceeds 8 hours
            driverWage = 20 * 8; 
            outFileTSP << "\nDriver Wage for this trip: " << driverWage << " MYR" << endl;
            cout << "\nDriver Wage for this trip: " << driverWage << " MYR" << endl;
        } else { //If the total time less than or equal to 8 hours
            driverWage = 20 * totalTime;  
            outFileTSP << "\nDriver Wage for this trip: " << driverWage << " MYR" << endl;
            cout << "\nDriver Wage for this trip: " << driverWage << " MYR" << endl;
        }

        //Display the total distance, cost, time, fuel consumption and waste collected - all related information
        outFileTSP << "\nTotal Distance for Visited Locations: " << totalDistance << " km" << endl;  
        cout << "\nTotal Distance for Visited Locations: " << totalDistance << " km" << endl;  
        outFileTSP << "Total Cost: " << totalCost << " MYR" << endl;
        cout << "Total Cost: " << totalCost << " MYR" << endl;
        outFileTSP << "Total Time: " << totalTime << " hours" << endl;
        cout << "Total Time: " << totalTime << " hours" << endl;
        outFileTSP << "Total Fuel Consumption: " << totalFuelConsumption << " Liters" << endl;
        cout << "Total Fuel Consumption: " << totalFuelConsumption << " Liters" << endl;
        outFileTSP << "Cumulative total percentage of waste collected from all valid locations: " << totalWasteCollected << "%" << endl;
        cout << "Cumulative total percentage of waste collected from all valid locations: " << totalWasteCollected << "%" << endl;
        outFileTSP << "Total Waste Collected: " << wasteInKG << "kg" << endl;
        cout << "Total Waste Collected: " << wasteInKG << "kg" << endl;
    }

    void travellingSalesmanProblem(int garbageLocationGraph[][V], const vector<string>& currentLocations, const GarbageLocations& garbageLocations, ofstream& outFileTSP) { //Implement the travelling salesman problem algorithm
        float dist[V]; //Create an array to store the distance, the size is the number of locations
        bool shortestPathTree[V]; //Create an array to store the shortest path tree, the size is the number of locations
        int parent[V]; //Create an array to store the parent, the size is the number of locations

        for (int index = 0; index < V; index++) { //Iterate over all locations 
            parent[0] = -1; //Set the source vertex to -1
            dist[index] = INF; //Then set the distance to INF
            shortestPathTree[index] = false; //Set the shortest path tree to false
        }

        dist[0] = 0; //Set source vertex distance to 0

        for (int index2 = 0; index2 < V - 1; index2++) { //Iterate over the number of vertices - 1 which is the number of locations - 1
            int closestVertex = minimumDistance(dist, shortestPathTree);
            shortestPathTree[closestVertex] = true;

            for (int index3 = 0; index3 < V; index3++) //Iterate over the number of vertices which is the number of locations
                if (garbageLocationGraph[closestVertex][index3] && dist[closestVertex] + garbageLocationGraph[closestVertex][index3] < dist[index3] && !shortestPathTree[index3]) {
                    parent[index3] = closestVertex;
                    dist[index3] = dist[closestVertex] + garbageLocationGraph[closestVertex][index3];
                }
        }

        tspSolution(dist, V, parent, currentLocations, garbageLocations, outFileTSP); //Call the tspSolution function
    }
};

#endif