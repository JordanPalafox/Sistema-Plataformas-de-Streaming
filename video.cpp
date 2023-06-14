#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Episode;

class Video
{
protected:
    int id;
    string name;
    double duration;
    string genre;
    double rating;

public:
    Video(int id, string name, double duration, string genre, double rating) : id(id), name(name), duration(duration), genre(genre), rating(rating) {}

    virtual void calculateAverageDuration() {}
    virtual void calculateAverageRating() {}
    virtual void setEpisodes(vector<Episode> newEpisodes) {}

    virtual void setRating(double newRating)
    {
        rating = newRating;
    }

    int getId() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }

    double getDuration() const
    {
        return duration;
    }

    string getGenre() const
    {
        return genre;
    }

    double getRating() const
    {
        return rating;
    }
};