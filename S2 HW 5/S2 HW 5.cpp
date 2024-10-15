#include <iostream>
#include <string>
using namespace std;

struct VideoStore
{
    string NameFilm;
    string FilmDirector;
    string Genre;
    int Score;
    int Cost;
};

void Out(VideoStore name[], int index)
{
    cout << "Name film: " << name[index].NameFilm << endl;
    cout << "Name of the movie director: " << name[index].FilmDirector << endl;
    cout << "Film genre: " << name[index].Genre << endl;
    cout << "Film score: " << name[index].Score << endl;
    cout << "Film cost: " << name[index].Cost << endl;
    cout << "<<---------------------------------------------------------------------->>" << endl;
}
void Viewing(VideoStore name[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << "<<---------------------------------------------------------------------->>" << endl;
        cout << "Name film: " << name[i].NameFilm << endl;
        cout << "Name of the movie director: " << name[i].FilmDirector << endl;
        cout << "Film genre: " << name[i].Genre << endl;
        cout << "Film score: " << name[i].Score << endl;
        cout << "Film cost: " << name[i].Cost << endl;
        cout << "<<---------------------------------------------------------------------->>" << endl;
    }
}
void InputData(VideoStore* name, int size)
{
    for (int i = 0; i < size; i++)
    {
        cin.ignore();
        cout << "Enter name film:";                   getline(cin, name[i].NameFilm);
        cout << "Enter name of the movie director:";  getline(cin, name[i].FilmDirector);
        cout << "Enter genre:";                       getline(cin, name[i].Genre);
        cout << "Enter score:";                       cin >> name[i].Score;
        cout << "Enter cost:";                        cin >> name[i].Cost;
        cin.ignore();
    }
}
void SearchName(VideoStore name[], int size, string namefilm)
{
    bool find = false;
    for (int i = 0; i < size; i++)
    {
        if (name[i].NameFilm == namefilm)
        {
            Out(name, i);
            find = true;
        }
    }
    if (find != true)
    {
        cout << "Cant find film or you write incorect name!";
    }
}
void SearchGenre(VideoStore name[], int size, string namegenre)
{
    bool find = false;
    for (int i = 0; i < size; i++)
    {
        if (name[i].Genre == namegenre)
        {
            Out(name, i);
            find = true;
        }
    }
    if (find != true)
    {
        cout << "Cant find genre or you write incorect genre!";
    }
}
void SearchNameDirector(VideoStore name[], int size, string namefilmDirector)
{
    bool find = false;
    for (int i = 0; i < size; i++)
    {
        if (name[i].FilmDirector == namefilmDirector)
        {
            Out(name, i);
            find = true;
        }
    }
    if (find != true)
    {
        cout << "Cant find director or you write incorect name!";
    }
}
void TheMostFilm(VideoStore name[], int size, string namegenre)
{
    int pos = -1; int scoring = 0;
    for (int i = 0; i < size; i++)
    {
        if (name[i].Genre == namegenre)
        {
            if (name[i].Score > scoring)
            {
                pos = i;
            }
            else
            {
                continue;
            }
        }
    }
    if (pos != -1)
    {
        Out(name, pos);
    }
    else
    {
        cout << "No films found for the specified genre!" << endl;
    }
}
void Show_com()
{
    cout << "1.Enter records" << endl;
    cout << "2.Show all records" << endl;
    cout << "3.Search for a movie by title" << endl;
    cout << "4.Search for a movie by genre" << endl;
    cout << "5.Search for a movie by director" << endl;
    cout << "6.The most popular movie by genre" << endl;
    cout << "0.Exit" << endl;
}

void Avtor() 
{
    cout << "About avtor" << endl;
    cout << "I'm 16 " << endl;
    cout << "I study at IT Step" << endl;
    cout << "I live in Ukraine" << endl;
}





int main()
{
    int size;
    cout << "Enter the number of movies: ";
    cin >> size;

    VideoStore* arr = new VideoStore[size];

    int count;
    string searchInput;

    do {
        Show_com();
        cout << "Enter your choice: ";
        cin >> count;

        switch (count)
        {
        case 1:
            InputData(arr, size);
            break;

        case 2:
            Viewing(arr, size);
            break;

        case 3:
            cout << "Enter the name of the movie: ";
            cin.ignore();
            getline(cin, searchInput);
            SearchName(arr, size, searchInput);
            break;

        case 4:
            cout << "Enter the genre of the movie: ";
            cin.ignore();
            getline(cin, searchInput);
            SearchGenre(arr, size, searchInput);
            break;

        case 5:
            cout << "Enter the director's name: ";
            cin.ignore();
            getline(cin, searchInput);
            SearchNameDirector(arr, size, searchInput);
            break;

        case 6:
            cout << "Enter the genre to find the most popular movie: ";
            cin.ignore();
            getline(cin, searchInput);
            TheMostFilm(arr, size, searchInput);
            break;

        case 0:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid option! Please try again." << endl;
            break;
        }

    } while (count != 0);
    cout << "<<---------------------------->>"<<endl;
    Avtor();
    delete[] arr;
    return 0;
}

