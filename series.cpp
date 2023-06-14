#include <string>
#include <vector>
#include <iostream>
#include "movie.cpp"
#include "episode.cpp"

using namespace std;

class Series : public Video
{
private:
    vector<Episode> episodes;

public:
    Series(int id, string name, double duration, string genre, double rating, vector<Episode> episodes)
        : Video(id, name, duration, genre, rating), episodes(episodes)
    {
        calculateAverageDuration();
        calculateAverageRating();
    }

    void calculateAverageDuration()
    {
        double totalDuration = 0;
        for (const auto &episode : episodes)
        {
            totalDuration += episode.getDuration();
        }
        duration = totalDuration;
    }

    void calculateAverageRating()
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

    vector<Episode> getEpisodes() const
    {
        return episodes;
    }

    void setEpisodes(vector<Episode> newEpisodes)
    {
        episodes = newEpisodes;
    }
};