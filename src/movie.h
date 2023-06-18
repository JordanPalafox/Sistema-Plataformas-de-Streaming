#include "video.cpp"

class Movie : public Video
{
public:
    Movie(int id, string name, double duration, string genre, double rating);

    void calculateAverageDurationAndRating() override;
};
