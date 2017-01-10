#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cfloat>

using namespace std;
struct route
{
    string origin, destination;
    vector<string> airline;
    double distance;
    
    route& operator+=(const route &other);
};

bool operator<(const route &x, const route &y);

#endif // ROUTE_H
