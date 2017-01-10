#ifndef DNODE
#define DNODE

#include <string>
#include "route.h"
#include "airport.h"

using namespace std;

struct dnode
{
    string IATA;
    vector<route> root;
    double distance;
};

bool operator<(const dnode &x, const dnode &y);

vector<route> djikstra(string origin, string destination, map<string,string> &airlines, map<string, airport> &airports);

#endif // DNODE

