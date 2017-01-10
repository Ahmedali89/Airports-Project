#include "airport.h"

void createAirports (map<string, airport> &airports)
{
    ifstream ifs("airports.dat");
    string line;
    while (getline(ifs, line))
    {
        size_t pos;
        airport ap;
        stringstream ss;
        string num;
        while ((pos = line.find('"'))< string::npos)
            line.erase(pos,1);
        
        pos = line.find(',');
        ap.airportCity = line.substr(pos + 1, line.find(',', pos + 1) - (pos + 1));
        for (size_t i = 0; i < 2; ++i)
            pos = line.find(',', pos + 1);
        ap.countryName = line.substr(pos + 1,line.find(',',pos + 1) -(pos + 1));
        pos = line.find(',', pos + 1);
        ap.IATA = line.substr(pos + 1, line.find(',', pos + 1) - (pos + 1));
        for (size_t i = 0; i < 2; ++i)
            pos = line.find(',', pos + 1);
        num = line.substr(pos + 1, line.find(',', pos + 1) - (pos + 1));
        ss << num;
        ss >> ap.latitude;
        pos = line.find(',', pos + 1);
        num = line.substr(pos + 1, line.find(',', pos + 1) - (pos + 1));
        ss.clear();
        ss << num;
        ss >> ap.longitude;
        airports.insert(pair<string, airport> (ap.IATA, ap));
    }
    
    ifs.close();
}

void createConnections (map<string, airport> &airports)
{
    ifstream ifs("routes.dat");
    string line;
    
    while (getline(ifs, line))
    {
        route root;
        size_t pos = line.find(',');
        root.airline.push_back(line.substr(0, pos));
        pos = line.find(',', pos + 1);
        root.origin = line.substr(pos+1, line.find(',', pos + 1) - (pos + 1));
        pos = line.find(',', pos + 1);
        pos = line.find(',', pos + 1);
        root.destination = line.substr(pos+1, line.find(',', pos + 1) - (pos + 1));
        if (airports.find(root.origin) != airports.end() && airports.find(root.destination) != airports.end())
        {
            root.distance = greatCircle( airports.find(root.origin)->second, airports.find(root.destination)->second );
            airport org = airports.find(root.origin)->second;
            set<route> rts = org.connections;
            if (rts.find(root) != rts.end())
            {
                root += *rts.find(root);
                airports.find(root.origin)->second.connections.erase(root);
            }
            airports.find(root.origin)->second.connections.insert(root);
        }
    }
    
    map<string, airport>::iterator it = airports.begin();
    while (it != airports.end())
        if (it->second.connections.empty())
            airports.erase(it++);
        else
            ++it;
    
    ifs.close();
    
}

double greatCircle (airport ap1, airport ap2)
{
    double lat1 = ap1.latitude, long1 = ap1.longitude, lat2 = ap2.latitude, long2 = ap2.longitude;
    return RADIUS * acos( sin (lat1 * PI/180) * sin (lat2 * PI/180) + cos (lat1 * PI/180) * cos (lat2 * PI/180) * cos ( abs(long2 - long1)  * PI/180 ));
}
