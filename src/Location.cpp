#include "../include/Location.h"

Location::Location() {
    id = -1;
    name = "";
    latitude = 0;
    longitude = 0;
}

Location::Location(int id, string name, double latitude, double longitude) {
    this->id = id;
    this->name = name;
    this->latitude = latitude;
    this->longitude = longitude;
}

int Location::getId() const {
    return id;
}

string Location::getName() const {
    return name;
}

double Location::getLatitude() const {
    return latitude;
}

double Location::getLongitude() const {
    return longitude;
}