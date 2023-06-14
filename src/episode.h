#include <string>

using namespace std;

class Episode
{
private:
    string name;
    double duration;
    double rating;
    int season;

public:
    Episode(string name, int season, double rating, double duration);
    string getTitle() const;
    int getSeason() const;
    double getDuration() const;
    double getRating() const;
};