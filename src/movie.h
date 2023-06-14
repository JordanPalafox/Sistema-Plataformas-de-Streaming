#include "video.cpp"

class Movie : public Video
{
public:
    Movie(int id, std::string name, double duration, std::string genre, double rating);

    void calculateAverageDuration() override;
    void calculateAverageRating() override;
};