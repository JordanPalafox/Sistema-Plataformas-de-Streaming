#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "series.cpp"

using namespace std;

void importData(vector<Video *> &videos)
{
    ifstream file("../data/database.csv");


    if (!file.is_open())
    {
        cout << "Error: El archivo no se pudo abrir" << endl;
        return;
    }

    string line;
    getline(file, line); // Leer la primera línea (encabezados)
    vector<Episode> episodes;

    while (getline(file, line))
    {
        stringstream ss(line);
        string id;
        string name;
        string duration;
        string genre;
        string rating;
        string season;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, duration, ',');
        getline(ss, genre, ',');
        getline(ss, rating, ',');
        getline(ss, season, ',');

        if (id[0] != '3')
        {
            if (episodes.size() > 0)
            {
                static_cast<Series *>(videos.back())->setEpisodes(episodes);
                videos.back()->calculateAverageDurationAndRating();
                episodes.clear();
            }
        }
        if (id[0] == '1')
        {
            videos.push_back(new Movie(stoi(id), name, stod(duration), genre, stod(rating)));
        }
        else if (id[0] == '2')
        {
            videos.push_back(new Series(stoi(id), name, stod(duration), genre, stod(rating), {}));
        }
        else if (id[0] == '3')
        {
            episodes.push_back(Episode(name, stoi(season), stod(rating), stod(duration)));
        }
    }

    file.close();
}
