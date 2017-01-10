#include "airline.h"

void createAirlines(map<string,string> &airlines)
{
    ifstream ifs("airlines.dat");
    string line;

    while (getline(ifs, line))
    {
        size_t size;
        while ((size = line.find('"'))<string::npos)
            line.erase(size, 1);
        size = line.find(',');
        string name = line.substr(size + 1,  line.find(',', size + 1) - (size+1) );
        size = line.find(',', size + 1);
        size = line.find(',', size + 1);
        string IATA = line.substr(size + 1,  line.find(',', size + 1) - (size+1) );
        if (IATA == "")
        {
            size = line.find(',', size + 1);
            string IATA = line.substr(size + 1,  line.find(',', size + 1) - (size+1) );
        }
        if (IATA != "")
            airlines.insert(pair<string,string> (IATA, name));

    }
    ifs.close();
}
