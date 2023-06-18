#include "movie.cpp"
#include "episode.cpp"
#include <vector>
#include <string>

using namespace std;

class Series : public Video
{
private:
    vector<Episode> episodes;

public:
    Series(int id, string name, double duration, string genre, double rating, vector<Episode> episodes);

    void calculateAverageDurationAndRating();
    vector<Episode> getEpisodes() const;
    void setEpisodes(vector<Episode> newEpisodes);
};
