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

#ifndef GREEDY_ROUTE_H //Header file guard
#define GREEDY_ROUTE_H //Header file guard

#define INF INT_MAX //Set INF to the maximum integer value
#define V 8 //Set V to 8 which is the number of vertices, because there are 8 locations then define the number of vertices as well for the algorithm to work

using namespace std; //Use standard namespace

class GreedyRoute { //Class for the Greedy Route algorithm

public: //Public specifier
    void createGraph(const GarbageLocations& garbageLocations, int garbageLocationGraph[][V], const vector<string>& currentLocations) { //Create the graph for the Greedy Route algorithm
        for (int index = 0; index < V; index++) { //Iterate over the number of vertices/ locations
            for (int index2 = 0; index2 < V; index2++) { //Then iterate over the number of vertices/ locations again, this is to set the distance between the locations
                garbageLocationGraph[index][index2] = garbageLocations.distanceMatrix.at(currentLocations[index]).at(currentLocations[index2]); //Distance between the locations is initialised here
            }
        }
    }

    void createPath(int parentLocation[], int index, vector<string> currentLocations, ofstream& outFileGR) { //Create the path for the algorithm, initialise the path using the locations
        if (parentLocation[index] == -1) { //If the parent location is equal to -1, then it is the source/ waste station
            outFileGR << "Waste Station";
            cout << "Waste Station";
        }

        if (parentLocation[index] != 0) { //If the parent location is not equal to 0, then it is not the source/ waste station, opposite to the first condition
            createPath(parentLocation, parentLocation[index], currentLocations, outFileGR);
        }

        if (currentLocations[parentLocation[index]] == "Waste Station") { //So if the parent lcoation is source/ waste station, then start by printing the path from "Waste Station -> "
            outFileGR << "Waste Station -> " << currentLocations[index];
            cout << "Waste Station -> " << currentLocations[index];
        } else if (parentLocation[index] != 0) { //If parent location is NOT the source/ waste station, then print the path from " -> ", this way it prints the path consistently
            outFileGR << " -> " << currentLocations[index];
            cout << " -> " << currentLocations[index];
        } else { //
            outFileGR << currentLocations[index]; //Print the current location
            cout << currentLocations[index]; //Print the current location
        }
    }

    void daSolution(float distance[], int vertex, int parentLocation[], vector<string> currentLocations, const GarbageLocations& garbageLocations, ofstream& outFileGR) { //Dijkstra Algorithm solution method
        float totalCost, totalTime, totalFuelConsumption, driverWage, totalDistance = 0; //Initialise the float variables for the total cost, total time, total fuel consumption, driver wage and total distance to 0
        int totalWasteCollected = 0; //Initialise the integer total waste collected to 0
        int wasteInKG = 0; //Initialise the integer waste in KG to 0

        outFileGR << "Shortest Path from Waste Station to each location:" << endl;
        cout << "Shortest Path from Waste Station to each location:" << endl;

        vector<string> locationsWithin8Hours;  //Create the vector to store locations that can be visited under 8 hours

        for (int index = 1; index < V; index++) { //Iterate over the number of vertices/ locations
            if (distance[index] < INF && garbageLocations.wasteLevels.at(currentLocations[index]) >= 30) { //If the distance is less than the defined INf and the waste level is greater than or equal to 30 then perform the following operations

                totalWasteCollected += garbageLocations.wasteLevels.at(currentLocations[index]);
                totalDistance += distance[index];  

                outFileGR << "Waste Station to " << currentLocations[index] << ": " << distance[index] << " km\t";
                cout << "Waste Station to " << currentLocations[index] << ": " << distance[index] << " km\t";
                outFileGR << "Path: ";
                cout << "Path: ";
                
                createPath(parentLocation, index, currentLocations, outFileGR);

                outFileGR << endl;
                cout << endl;
                
                totalTime = totalDistance * 0.2;  
                if (totalTime <= 8) { //Check if the total time is less than or equal to 8 hours
                    locationsWithin8Hours.push_back(currentLocations[index]);
                } else {
                    outFileGR << "\n**Total time exceeds 8 hours, refer to the locations below that can be visited within 8 hours**" << endl;
                    cout << "\n**Total time exceeds 8 hours, refer to the locations below that can be visited within 8 hours**" << endl;
                    break;
                }

                wasteInKG = (totalWasteCollected * 500)/100;
            }
        }

        if (totalTime > 8) { //If the total time is greater than 8 hours, then perform the following operations
            outFileGR << "\nLocations that can be visited within 8 hours:" << endl;
            cout << "\nLocations that can be visited within 8 hours:" << endl;

            for (int i = 0; i < locationsWithin8Hours.size(); i++) { //Loop within the locations that can be visited within 8 hours
                outFileGR << locationsWithin8Hours[i] << endl;
                cout << locationsWithin8Hours[i] << endl;
            }
        }

        if(totalTime > 8) { //If the total time is exceeds 8 hours
            driverWage = 20 * 8; 
            outFileGR << "\nDriver Wage for this trip: " << driverWage << " MYR" << endl;
            cout << "\nDriver Wage for this trip: " << driverWage << " MYR" << endl;
        } else { //If the total time is less than or equal to 8 hours
            driverWage = 20 * totalTime; 
            outFileGR << "\nDriver Wage for this trip: " << driverWage << " MYR" << endl;
            cout << "\nDriver Wage for this trip: " << driverWage << " MYR" << endl;
        }

        totalCost = totalDistance * 2.5;  
        totalFuelConsumption = 2 * totalDistance;  

        //Display the total distance, cost, time, fuel consumption and waste collected - all related information
        outFileGR << "\nTotal Distance for Visited Locations: " << totalDistance << " km" << endl;  
        cout << "\nTotal Distance for Visited Locations: " << totalDistance << " km" << endl;  
        outFileGR << "Total Cost: " << totalCost << " MYR" << endl;  
        cout << "Total Cost: " << totalCost << " MYR" << endl;
        outFileGR << "Total Time: " << totalTime << " hours" << endl;  
        cout << "Total Time: " << totalTime << " hours" << endl;
        outFileGR << "Total Fuel Consumption: " << totalFuelConsumption << " Liters" << endl;  
        cout << "Total Fuel Consumption: " << totalFuelConsumption << " Liters" << endl;
        cout << "Cumulative total percentage of waste collected from all valid locations: " << totalWasteCollected << "%" << endl;
        outFileGR << "Cumulative total percentage of waste collected from all valid locations: " << totalWasteCollected << "%" << endl;
        outFileGR << "Total Waste Collected: " << wasteInKG << "kg" << endl;
        cout << "Total Waste Collected: " << wasteInKG << "kg" << endl;
    }

    int minimumDistance(float distance[], bool shortestPathTree[]) { //Method to find the minimum distance, this method is used to find the minimum distance from the source to the destination so that the shortest path can be found through the Dijkstra Algorithm
        float minimumValue = INF; //First assign the minimumValue to the defined INF
        int minimumIndex; //Initialise the minimumIndex to 0

        for (int vertex = 0; vertex < V; vertex++) { //Iterate over the number of vertices which is the number of locations present
            if (distance[vertex] <= minimumValue && shortestPathTree[vertex] == false){ //If the distance at the location is less than INF and the shortest path tree at the location is false then perform the following operations
                minimumValue = distance[vertex];
                minimumIndex = vertex;
            }
        }

        return minimumIndex;
    }

    void dijkstraAlgorithm(int garbageLocationGraph[V][V], int source, const vector<string>& currentLocations, const GarbageLocations& garbageLocations, ofstream& outFileGR) { //This is the Dijkstra Algorithm method which contains the algorithm logic
        float distance[V]; //First initialise the distance array with the number of locations
        bool shortestPathTree[V]; //Then initialise the shortestPathTree array with the number of locations
        int parentLocation[V]; //Then initialise the parentLocation array with the number of locations this is to store the parent location of the current location

        for (int index = 0; index < V; index++) { //Iterate over the number of locations
            parentLocation[source] = -1;
            distance[index] = INF;
            shortestPathTree[index] = false;
        }

        distance[source] = 0; //Assign the source distance as 0

        for (int count = 0; count < V - 1; count++) { //Iterate over the number of locations - 1
            int closestVertex = minimumDistance(distance, shortestPathTree);
            shortestPathTree[closestVertex] = true;

            for (int vertex = 0; vertex < V; vertex++) { //Iterate over the number of locations
                int temporaryVertex = distance[closestVertex] + garbageLocationGraph[closestVertex][vertex];
                if (garbageLocationGraph[closestVertex][vertex] && temporaryVertex < distance[vertex] && !shortestPathTree[vertex]) {
                    parentLocation[vertex] = closestVertex;
                    distance[vertex] = distance[closestVertex] + garbageLocationGraph[closestVertex][vertex];
                }
            }
        }

        daSolution(distance, V, parentLocation, currentLocations, garbageLocations, outFileGR); //Call the daSolution method to find the solution
    }
};

#endif