#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cfloat>

using namespace std;

struct airline
{
string IATA, name;
};

void createAirlines(map<string,string> &airlines);


#endif // AIRLINE_H
