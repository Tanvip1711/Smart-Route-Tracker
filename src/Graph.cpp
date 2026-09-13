#include "../include/Graph.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

Graph::Graph(int vertices) {
    this->vertices = vertices;
    roads.resize(vertices);
}

void Graph::addLocation(Location location) {
    locations.push_back(location);
}

void Graph::addRoad(int source, int destination, int distance) {

    roads[source].push_back({destination, distance});
    roads[destination].push_back({source, distance});
}

void Graph::displayLocations() const {

    cout << "\nAvailable Locations:\n";

    for (const auto& location : locations) {

        cout << location.getId()
             << " - "
             << location.getName()
             << endl;
    }
}
int Graph::findLocation(string name) const {

    for (const auto& location : locations) {

        if (location.getName() == name) {
            return location.getId();
        }
    }

    return -1;
}
void Graph::findShortestRoute(int source, int destination) {

    vector<int> distance(
        vertices,
        numeric_limits<int>::max()
    );

    vector<int> parent(vertices, -1);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    distance[source] = 0;

    pq.push({0, source});

    while (!pq.empty()) {

        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;

        pq.pop();

        if (currentDistance > distance[currentNode])
            continue;

        for (auto road : roads[currentNode]) {

            int nextNode = road.first;
            int roadDistance = road.second;

            if (distance[currentNode] + roadDistance
                < distance[nextNode]) {

                distance[nextNode] =
                    distance[currentNode] + roadDistance;

                parent[nextNode] = currentNode;

                pq.push({
                    distance[nextNode],
                    nextNode
                });
            }
        }
    }

    if (distance[destination] ==
        numeric_limits<int>::max()) {

        cout << "\nNo route available.\n";
        return;
    }

    vector<int> path;

    int current = destination;

    while (current != -1) {

        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    cout << "\nShortest Route:\n";

    for (int i = 0; i < path.size(); i++) {

        cout << locations[path[i]].getName();

        if (i < path.size() - 1)
            cout << " -> ";
    }

    cout << "\nTotal Distance: "
         << distance[destination]
         << " km\n";

         
}
bool Graph::loadData(
    const string& locationFile,
    const string& roadFile
) {

    ifstream locationInput(locationFile);

    if (!locationInput.is_open()) {
        cout << "Error: Could not open location file.\n";
        return false;
    }

    string line;

    while (getline(locationInput, line)) {

        stringstream ss(line);

        string idText;
        string name;
        string latitudeText;
        string longitudeText;

        getline(ss, idText, ',');
        getline(ss, name, ',');
        getline(ss, latitudeText, ',');
        getline(ss, longitudeText, ',');

        int id = stoi(idText);
        double latitude = stod(latitudeText);
        double longitude = stod(longitudeText);

        addLocation(
            Location(
                id,
                name,
                latitude,
                longitude
            )
        );
    }

    locationInput.close();

    ifstream roadInput(roadFile);

    if (!roadInput.is_open()) {
        cout << "Error: Could not open road file.\n";
        return false;
    }

    while (getline(roadInput, line)) {

        stringstream ss(line);

        string sourceText;
        string destinationText;
        string distanceText;

        getline(ss, sourceText, ',');
        getline(ss, destinationText, ',');
        getline(ss, distanceText, ',');

        int source = stoi(sourceText);
        int destination = stoi(destinationText);
        int distance = stoi(distanceText);

        addRoad(
            source,
            destination,
            distance
        );
    }

    roadInput.close();

    return true;
}