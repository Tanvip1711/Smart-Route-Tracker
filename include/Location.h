#ifndef LOCATION_H
#define LOCATION_H

#include <string>

using namespace std;

class Location {
private:
    int id;
    string name;
    double latitude;
    double longitude;

public:
    Location();
    Location(int id, string name, double latitude, double longitude);

    int getId() const;
    string getName() const;
    double getLatitude() const;
    double getLongitude() const;
};

#endif