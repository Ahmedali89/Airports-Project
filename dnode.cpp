#include "dnode.h"

bool operator<(const dnode &x, const dnode &y)
{
    return x.distance < y.distance;
}

vector<route> djikstra (string origin, string destination, map<string,string> &airlines, map<string, airport> &airports)
{
    map<string, dnode> q;

    for (map<string, airport>::iterator it = airports.begin(); it != airports.end(); ++it)
    {
        dnode d;
        d.IATA = it->second.IATA;
        if (d.IATA == origin )
        {
            d.distance = 0;
        }
        else
            d.distance = DBL_MAX;

        q.insert( pair<string, dnode> (d.IATA, d) );
    }

    while (!q.empty())
    {

        map<string, dnode>::iterator minNode = q.begin();
        for (map<string, dnode>::iterator it = q.begin(); it != q.end(); ++it)
            if (it->second < minNode->second)
                minNode = it;
        dnode current = minNode->second;

        if (current.IATA == destination)
            return current.root;
        q.erase(minNode);
        map<string, airport>::iterator apIt = airports.find(current.IATA);
        airport ap = apIt->second;
        for (set<route>::iterator rtIt = ap.connections.begin(); rtIt != ap.connections.end(); ++rtIt)
        {
            route rt = *rtIt;
            map<string, dnode>::iterator destNode = q.find(rt.destination);
            if (destNode != q.end())
            {

                if ((current.distance + rt.distance) < destNode->second.distance)
                {
                    destNode->second.distance = (current.distance + rt.distance);
                    destNode->second.root = current.root;
                    destNode->second.root.push_back(rt);
                    
                }
            }
        }
    }

}
