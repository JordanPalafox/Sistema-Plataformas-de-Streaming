#include <string>
#include <vector>
#include <iostream>
#include "video.cpp"

using namespace std;

class Movie : public Video
{
public:
    Movie(int id, string name, double duration, string genre, double rating) : Video(id, name, duration, genre, rating) {}

    void calculateAverageDuration()
    {
        duration = duration;
    }
    void calculateAverageRating()
    {
        rating = rating;
    }
};