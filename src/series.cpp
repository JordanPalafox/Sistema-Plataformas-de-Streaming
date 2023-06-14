#include <string>
#include <vector>
#include <iostream>
#include "series.h"

using namespace std;

Series::Series(int id, string name, double duration, string genre, double rating, vector<Episode> episodes)
    : Video(id, name, duration, genre, rating), episodes(episodes)
{
    calculateAverageDuration();
    calculateAverageRating();
}

void Series::calculateAverageDuration()
{
    double totalDuration = 0;
    for (const auto &episode : episodes)
    {
        totalDuration += episode.getDuration();
    }
    duration = totalDuration;
}

void Series::calculateAverageRating()
{
    double totalRating = 0;
    for (const auto &episode : episodes)
    {
        totalRating += episode.getRating();
    }
    if (episodes.size() > 0)
    {
        rating = totalRating / episodes.size();
    }
    else
    {
        rating = 0;
    }
}

vector<Episode> Series::getEpisodes() const
{
    return episodes;
}

void Series::setEpisodes(vector<Episode> newEpisodes)
{
    episodes = newEpisodes;
}