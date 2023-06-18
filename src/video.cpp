#include <string>
#include <vector>
#include <iostream>
#include "video.h"

using namespace std;

Video::Video(int id, string name, double duration, string genre, double rating) : id(id), name(name), duration(duration), genre(genre), rating(rating) {}

void Video::calculateAverageDurationAndRating() {}
void Video::setEpisodes(vector<Episode> newEpisodes) {}
void Video::setRating(double newRating)

{
    rating = newRating;
}

int Video::getId() const
{
    return id;
}

string Video::getName() const
{
    return name;
}

double Video::getDuration() const
{
    return duration;
}

string Video::getGenre() const
{
    return genre;
}

double Video::getRating() const
{
    return rating;
}
