#include <iostream>

#include "include/Graph.h"

using namespace std;

int main() {

    cout << "=================================\n";
    cout << "       SMART ROUTE TRACKER       \n";
    cout << "=================================\n";

    Graph city(5);

    // Locations
    city.addLocation(
        Location(0, "Ravet", 18.6507, 73.7597)
    );

    city.addLocation(
        Location(1, "Akurdi", 18.6500, 73.7769)
    );

    city.addLocation(
        Location(2, "Nigdi", 18.6516, 73.7798)
    );

    city.addLocation(
        Location(3, "Pimpri", 18.6298, 73.7997)
    );

    city.addLocation(
        Location(4, "Chinchwad", 18.6298, 73.7810)
    );

    // Roads
    city.addRoad(0, 1, 4);
    city.addRoad(0, 2, 6);
    city.addRoad(1, 2, 2);
    city.addRoad(1, 3, 7);
    city.addRoad(2, 3, 4);
    city.addRoad(2, 4, 5);
    city.addRoad(3, 4, 3);

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

    return 0;
}

    city.findShortestRoute(
        source,
        destination
    );

    return 0;
}