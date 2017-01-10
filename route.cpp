#include "route.h"

bool operator<(const route &x, const route &y)
{
    return x.destination < y.destination;
}

route& route::operator+=(const route &other)
{
    airline.insert(airline.end(), other.airline.begin(), other.airline.end());
    return *this;
}