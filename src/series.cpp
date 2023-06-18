#include <string>
#include <vector>
#include <iostream>
#include "series.h"

using namespace std;

Series::Series(int id, string name, double duration, string genre, double rating, vector<Episode> episodes)
    : Video(id, name, duration, genre, rating), episodes(episodes)
{
    calculateAverageDurationAndRating();
}

void Series::calculateAverageDurationAndRating()
{
    Episode totalEpisode("totalRating", 1, 1, 1);


    for (const auto &episode : episodes)
    {
        totalEpisode = totalEpisode + episode;
    }

    if (episodes.size() > 0)
    {
        rating = totalEpisode.getRating() / episodes.size();
    }
    else
    {
        rating = 0;
    }

    duration = totalEpisode.getDuration();
}

vector<Episode> Series::getEpisodes() const
{
    return episodes;
}

void Series::setEpisodes(vector<Episode> newEpisodes)
{
    episodes = newEpisodes;
}
