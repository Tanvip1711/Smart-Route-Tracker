#include <iostream>
#include <string>

#include "include/Graph.h"

using namespace std;

int main() {

    cout << "=================================\n";
    cout << "       SMART ROUTE TRACKER       \n";
    cout << "=================================\n";

    Graph city(5);

    // Load locations and roads from files
    if (!city.loadData(
        "data/locations.txt",
        "data/roads.txt"
    )) {

        cout << "Failed to load route data.\n";
        return 1;
    }

    city.displayLocations();

    string sourceName;
    string destinationName;

    cout << "\nEnter source location: ";
    cin >> sourceName;

    cout << "Enter destination location: ";
    cin >> destinationName;

    int source = city.findLocation(sourceName);
    int destination = city.findLocation(destinationName);

    if (source == -1 || destination == -1) {

        cout << "\nLocation not found.\n";
        return 1;
    }

    city.findShortestRoute(
        source,
        destination
    );

    return 0;
}