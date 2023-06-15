#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "globalFunctions.cpp"

using namespace std;

// el comando que se usa para limpiar la pantalla
// depende de el sistema operativo, con esta variable
// podemos hacer que cambie de valor dependiendo de esto
#ifdef _WIN32
    const char* clearScreen = "cls";
    const char* pauseScreen = "pause>nul";
#else
    const char* clearScreen = "clear";
    const char* pauseScreen = "read -n 1 -s";
#endif


int main()
{
    vector<Video *> videos;
    importData(videos);
    int option;
    bool exit = false;
    while (!exit)
    {
        system(clearScreen);
        cout << "MENU:" << endl;
        cout << "1. Mostrar videos en general" << endl;
        cout << "2. Mostrar episodios de una serie" << endl;
        cout << "3. Mostrar peliculas" << endl;
        cout << "4. Calificar un video" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            system(clearScreen);
            for (const auto &video : videos)
            {
                cout << "Nombre: " << video->getName() << endl;
                cout << "Duracion: " << video->getDuration() << endl;
                cout << "Genero: " << video->getGenre() << endl;
                cout << "Calificacion: " << video->getRating() << endl;
                Series *series = dynamic_cast<Series *>(video);
                if (series)
                {
                    cout << "Episodios: " << series->getEpisodes().size() << endl;
                }
                cout << "-------------------------" << endl;
            }
            cout << "Presiona cualquier tecla para continuar..." << endl;
            system(pauseScreen);
            break;
        }
        case 2:
        {
            system(clearScreen);
            string seriesName;
            cout << "Ingrese el nombre de la serie: ";
            cin.ignore();
            getline(cin, seriesName);

            for (const auto &video : videos)
            {
                Series *series = dynamic_cast<Series *>(video);
                if (series && series->getName() == seriesName)
                {
                    for (const auto &episode : series->getEpisodes())
                    {
                        cout << "Episodio: " << episode.getTitle() << endl;
                        cout << "Temporada: " << episode.getSeason() << endl;
                        cout << "Duracion: " << episode.getDuration() << endl;
                        cout << "Calificacion: " << episode.getRating() << endl;
                        cout << "-------------------------" << endl;
                    }
                    break;
                }
            }
            cout << "Presiona cualquier tecla para continuar..." << endl;
            system(pauseScreen);
            break;
        }
        case 3:
        {
            system(clearScreen);
            for (const auto &video : videos)
            {
                Movie *movie = dynamic_cast<Movie *>(video);
                if (movie)
                {
                    cout << "Nombre: " << movie->getName() << endl;
                    cout << "Duracion: " << movie->getDuration() << endl;
                    cout << "Genero: " << movie->getGenre() << endl;
                    cout << "Calificacion: " << movie->getRating() << endl;
                    cout << "-------------------------" << endl;
                }
            }
            cout << "Presiona cualquier tecla para continuar..." << endl;
            system(pauseScreen);
            break;
        }
        case 4:
        {
            system(clearScreen);
            string videoTitle;
            double ratingValue;
            cout << "Ingrese el titulo del video a calificar: ";
            cin.ignore();
            getline(cin, videoTitle);
            cout << "Ingrese el valor de calificacion: ";
            cin >> ratingValue;

            for (const auto &video : videos)
            {
                if (video->getName() == videoTitle)
                {
                    video->setRating(ratingValue);
                    cout << "Calificacion actualizada correctamente." << endl;
                    break;
                }
            }
            cout << "Presiona cualquier tecla para continuar..." << endl;
            system(pauseScreen);
            break;
        }
        case 0:
            exit = true;
            break;
        default:
            cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
            break;
        }

        cout << endl;
    }
    return 0;
}
