#include <string>
#include <vector>
#include <iostream>
#include "episode.h"

using namespace std;

Episode::Episode(string name, int season, double rating, double duration) : name(name), season(season), rating(rating), duration(duration) {}

string Episode::getTitle() const
{
    return name;
}

int Episode::getSeason() const
{
    return season;
}

double Episode::getDuration() const
{
    return duration;
}

double Episode::getRating() const
{
    return rating;
}

Episode Episode::operator+(Episode const& obj)
{
    int sumDuration = obj.duration;
    sumDuration += duration;

    int sumRating = obj.rating;
    sumRating += rating;

    Episode sum("sumEpisode", 1, sumRating, sumDuration);
    return sum;
}
