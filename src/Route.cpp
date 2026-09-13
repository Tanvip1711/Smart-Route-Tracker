#include "../include/Route.h"

Route::Route() {

    routeName = "";
    distance = 0;
    trafficLevel = 0;
}

Route::Route(
    string routeName,
    int distance,
    int trafficLevel
) {

    this->routeName = routeName;
    this->distance = distance;
    this->trafficLevel = trafficLevel;
}

string Route::getRouteName() const {
    return routeName;
}

int Route::getDistance() const {
    return distance;
}

int Route::getTrafficLevel() const {
    return trafficLevel;
}