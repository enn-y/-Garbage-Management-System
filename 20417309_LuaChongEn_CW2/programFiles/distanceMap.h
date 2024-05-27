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

using namespace std; //Use standard namespace

#ifndef MAP_H //Header file guard
#define MAP_H //Header file guard

class distanceMap { //Class for the distance map
 
public: //Public specifier
    void printMap(ofstream &outFile) { //Print map to console and to output file

        outFile << "                        3                              \n";
        outFile << "   +---> WasteStation <----> Location1                 \n";
        outFile << "   |                             ^                       \n";
        outFile << "   |                             |                     \n";
        outFile << "   |                             | 6                   \n";
        outFile << "   |                             |                     \n";
        outFile << "   |                             |                     \n";
        outFile << "   |                     5       v                      \n";
        outFile << "  4|        Location2 <----> Location3                 \n";
        outFile << "   |            ^            ^   ^                      \n";
        outFile << "   |            |            |   |                     \n";
        outFile << "   |          4 |    +-------+   | 2                   \n";
        outFile << "   |            |    |    2      |                     \n";
        outFile << "   |            |    |           |                     \n";
        outFile << "   |            v    v           v                       \n";
        outFile << "   |        Location4        Location6 <----> Location5\n";
        outFile << "   |                             ^         7            \n";
        outFile << "   v                             |                     \n";
        outFile << "Location7 <----------------------+                     \n";
        outFile << "                    3                                  \n";

        cout << "                        3                              \n";
        cout << "   +---> WasteStation <----> Location1                 \n";
        cout << "   |                             ^                       \n";
        cout << "   |                             |                     \n";
        cout << "   |                             | 6                   \n";
        cout << "   |                             |                     \n";
        cout << "   |                             |                     \n";
        cout << "   |                     5       v                      \n";
        cout << "  4|        Location2 <----> Location3                 \n";
        cout << "   |            ^            ^   ^                      \n";
        cout << "   |            |            |   |                     \n";
        cout << "   |          4 |    +-------+   | 2                   \n";
        cout << "   |            |    |    2      |                     \n";
        cout << "   |            |    |           |                     \n";
        cout << "   |            v    v           v                       \n";
        cout << "   |        Location4        Location6 <----> Location5\n";
        cout << "   |                             ^         7            \n";
        cout << "   v                             |                     \n";
        cout << "Location7 <----------------------+                     \n";
        cout << "                    3                                  \n";
    }

    void printMapInformation(ofstream &outFile) { //Print map information to console and to output file

        vector<string> locations; //Vector to store the locations
        locations.push_back("Waste Station");
        locations.push_back("Location 1");
        locations.push_back("Location 2");
        locations.push_back("Location 3");
        locations.push_back("Location 4");
        locations.push_back("Location 5");
        locations.push_back("Location 6");
        locations.push_back("Location 7");

        vector<vector<int> > distanceMatrix(8, vector<int>(8)); //Vector to store the distance matrix

        //Now set the distance matrix values for every location
        distanceMatrix[0][0] = 0; 
        distanceMatrix[0][1] = 3;
        distanceMatrix[0][2] = INF;
        distanceMatrix[0][3] = INF;
        distanceMatrix[0][4] = INF;
        distanceMatrix[0][5] = INF;
        distanceMatrix[0][6] = INF;
        distanceMatrix[0][7] = 4;

        distanceMatrix[1][0] = 3;
        distanceMatrix[1][1] = 0;
        distanceMatrix[1][2] = INF;
        distanceMatrix[1][3] = 6;
        distanceMatrix[1][4] = INF;
        distanceMatrix[1][5] = INF;
        distanceMatrix[1][6] = INF;
        distanceMatrix[1][7] = INF;

        distanceMatrix[2][0] = INF;
        distanceMatrix[2][1] = INF;
        distanceMatrix[2][2] = 0;
        distanceMatrix[2][3] = 5;
        distanceMatrix[2][4] = 4;
        distanceMatrix[2][5] = INF;
        distanceMatrix[2][6] = INF;
        distanceMatrix[2][7] = INF;

        distanceMatrix[3][0] = INF;
        distanceMatrix[3][1] = 6;
        distanceMatrix[3][2] = 5;
        distanceMatrix[3][3] = 0;
        distanceMatrix[3][4] = 2;
        distanceMatrix[3][5] = INF;
        distanceMatrix[3][6] = 2;
        distanceMatrix[3][7] = INF;

        distanceMatrix[4][0] = INF;
        distanceMatrix[4][1] = INF;
        distanceMatrix[4][2] = 4;
        distanceMatrix[4][3] = 2;
        distanceMatrix[4][4] = 0;
        distanceMatrix[4][5] = INF;
        distanceMatrix[4][6] = INF;
        distanceMatrix[4][7] = INF;

        distanceMatrix[5][0] = INF;
        distanceMatrix[5][1] = INF;
        distanceMatrix[5][2] = INF;
        distanceMatrix[5][3] = INF;
        distanceMatrix[5][4] = INF;
        distanceMatrix[5][5] = 0;
        distanceMatrix[5][6] = 7;
        distanceMatrix[5][7] = INF;

        distanceMatrix[6][0] = INF;
        distanceMatrix[6][1] = INF;
        distanceMatrix[6][2] = INF;
        distanceMatrix[6][3] = 2;
        distanceMatrix[6][4] = INF;
        distanceMatrix[6][5] = 7;
        distanceMatrix[6][6] = 0;
        distanceMatrix[6][7] = 3;

        distanceMatrix[7][0] = 4;
        distanceMatrix[7][1] = INF;
        distanceMatrix[7][2] = INF;
        distanceMatrix[7][3] = INF;
        distanceMatrix[7][4] = INF;
        distanceMatrix[7][5] = INF;
        distanceMatrix[7][6] = 3;
        distanceMatrix[7][7] = 0;

        outFile << "Distance Matrix: \n\n";
        cout << "Distance Matrix: \n\n";

        outFile << setw(15) << " "; //Print the distance matrix and include formatting using setw
        cout << setw(15) << " "; //Print the distance matrix and include formatting using setw
        for (vector<string>::const_iterator iterator = locations.begin(); iterator != locations.end(); iterator++) { //Print the distance matrix and include formatting using setw
            outFile << setw(15) << *iterator;
            cout << setw(15) << *iterator;
        }
        outFile << endl;
        cout << endl;

        for (int index=0; index < locations.size(); index++) { //Print the distance matrix and include formatting using setw
            outFile << setw(15) << locations[index];
            cout << setw(15) << locations[index];
            for (int index2 = 0; index2 < locations.size(); index2++) {  //iterate over the locations
                if (distanceMatrix[index][index2] != INF) { //If there is a direct path because it is != INF then print the distance and display
                    outFile << setw(15) << distanceMatrix[index][index2];
                    cout << setw(15) << distanceMatrix[index][index2];
                } else { //If there is no direct path because it is == INF then print INF and display
                    outFile << setw(15) << "INF"; //Print INF values to indicate no direct path
                    cout << setw(15) << "INF"; //Print INF values to indicate no direct path
                }
            }
            outFile << endl;
            cout << endl;
        }
    }
};

#endif 