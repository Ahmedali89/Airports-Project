#ifndef AIRPORT_H
#define AIRPORT_H

#include "route.h"

#define PI 3.14159265
#define RADIUS 3959

struct airport
{
    string airportCity , IATA , countryName;
    double latitude, longitude;
    std::set<route> connections;
};

void createAirports (map<string, airport> &airports);
void createConnections (map<string, airport> &airports);
double greatCircle (airport ap1, airport ap2);

#endif // AIRPORT_H
