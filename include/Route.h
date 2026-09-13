#ifndef ROUTE_H
#define ROUTE_H

#include <string>

using namespace std;

class Route {
private:
    string routeName;
    int distance;
    int trafficLevel;

public:
    Route();

    Route(
        string routeName,
        int distance,
        int trafficLevel
    );

    string getRouteName() const;
    int getDistance() const;
    int getTrafficLevel() const;
};

#endif