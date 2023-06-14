#include <string>
#include <vector>

using namespace std;

class Episode;

class Video
{
protected:
    int id;
    std::string name;
    double duration;
    std::string genre;
    double rating;

public:
    Video(int id, string name, double duration, string genre, double rating);

    virtual void calculateAverageDuration();
    virtual void calculateAverageRating();
    virtual void setEpisodes(vector<Episode> newEpisodes);

    virtual void setRating(double newRating);

    int getId() const;
    string getName() const;
    double getDuration() const;
    string getGenre() const;
    double getRating() const;
};
