#include <string>
#include <vector>
#include <iostream>
#include "movie.h"

using namespace std;

Movie::Movie(int id, string name, double duration, string genre, double rating) : Video(id, name, duration, genre, rating) {}

void Movie::calculateAverageDuration()
{
    duration = duration;
}
void Movie::calculateAverageRating()
{
    rating = rating;
}
