#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <utility>
#include <string>
#include "Location.h"

using namespace std;

class Graph {
private:
    int vertices;
    vector<Location> locations;
    vector<vector<pair<int, int>>> roads;

public:
    Graph(int vertices);

    void addLocation(Location location);

    void addRoad(int source, int destination, int distance);

    void displayLocations() const;

    int findLocation(string name) const;

    void findShortestRoute(int source, int destination);
};

#endif