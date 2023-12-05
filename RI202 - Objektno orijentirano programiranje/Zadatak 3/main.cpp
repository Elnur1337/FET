#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <regex>
#include <cctype>

using namespace std;

namespace filmska_analiza {
    struct Film {
        string title;
        unsigned short year;
        vector<string> genre;
        vector<string> director;
        float rating;
    };

    void fillData(vector<Film>&);
    short showMenu();
    void addMovie(vector<Film>&);
    string generateStringFromVector(std::vector<string>::const_iterator, std::vector<string>::const_iterator);
    void allMovies(std::vector<Film>::const_iterator, std::vector<Film>::const_iterator);
    short showSearchMenu();
    void searchMovies(std::vector<Film>::const_iterator, std::vector<Film>::const_iterator, std::back_insert_iterator<std::vector<Film>>, std::function<bool(std::vector<Film>::const_iterator)>);
    short showSortMenu();
    void deleteMovie(std::vector<Film>&, std::vector<Film>::const_iterator, std::vector<Film>::const_iterator, std::vector<Film>::const_iterator, std::vector<Film>::const_iterator);
    void updateMovie(std::vector<Film>::iterator, std::vector<Film>::const_iterator, std::vector<Film>::const_iterator, std::vector<Film>::const_iterator);
    void avgRatingByGenre(std::vector<Film>::const_iterator, std::vector<Film>::const_iterator);
}

using namespace filmska_analiza;

int main()
{
    vector<Film> data;
    fillData(data);
    unsigned short option;

    vector<Film> result;
    unsigned short searchOption;
    string inputText;
    unsigned short inputYear;
    bool isInputValid = false;
    regex yearRegex("^[0-9]{4}$");
    float rating;

    unsigned short sortOption;
    do {
        option = showMenu();
        switch (option) {
            case 1:
                addMovie(data);
                break;
            case 2:
                deleteMovie(data, data.begin(), data.end(), result.begin(), result.end());
                break;
            case 3:
                searchOption = showSearchMenu();
                result.clear();
                switch(searchOption) {
                    case 1:
                        cout << "Unesite naziv filma: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(std::cin, inputText);
                        if (inputText.size() > 0) {
                            searchMovies(data.begin(), data.end(), std::back_inserter(result), [inputText](std::vector<Film>::const_iterator movie) {
                                if ((*movie).title.find(inputText) != -1) {
                                    return true;
                                } else {
                                    return false;
                                }
                            });
                        }
                        break;
                    case 2:
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        do {
                            cout << "Unesite godinu: ";
                            cin >> inputText;
                            if (regex_match(inputText, yearRegex)) {
                                inputYear = stoi(inputText);
                                if (inputYear >= 1888) {
                                    isInputValid = true;
                                }
                            } else {
                                cout << "Niste unijeli validnu godinu!\n";
                            }
                        } while (!isInputValid);
                        searchMovies(data.begin(), data.end(), std::back_inserter(result), [inputYear](std::vector<Film>::const_iterator movie) {
                        if ((*movie).year == inputYear) {
                            return true;
                        } else {
                            return false;
                        }
                        });
                        break;
                    case 3:
                        cout << "Unesite zanr filma: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(std::cin, inputText);
                        if (inputText.size() > 0) {
                            searchMovies(data.begin(), data.end(), std::back_inserter(result), [inputText](std::vector<Film>::const_iterator movie) {
                                if (generateStringFromVector((*movie).genre.begin(), (*movie).genre.end()).find(inputText) != -1) {
                                    return true;
                                } else {
                                    return false;
                                }
                            });
                        }
                        break;
                    case 4:
                        cout << "Unesite rezisera filma: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(std::cin, inputText);
                        if (inputText.size() > 0) {
                            searchMovies(data.begin(), data.end(), std::back_inserter(result), [inputText](std::vector<Film>::const_iterator movie) {
                                if (generateStringFromVector((*movie).director.begin(), (*movie).director.end()).find(inputText) != -1) {
                                    return true;
                                } else {
                                    return false;
                                }
                            });
                        }
                        break;
                    case 5:
                        isInputValid = false;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        do {
                            cout << "Unesite ocjenu: ";
                            cin >> inputText;
                            try {
                                rating = stof(inputText);
                                isInputValid = true;
                            } catch (const std::invalid_argument& err) {
                                cout << "Niste unijeli broj!\n";
                            } catch (const std::out_of_range& err) {
                                cout << "Niste unijeli broj!\n";
                            }
                        } while (!isInputValid);
                        searchMovies(data.begin(), data.end(), std::back_inserter(result), [rating](std::vector<Film>::const_iterator movie) {
                        if ((*movie).rating == rating) {
                            return true;
                        } else {
                            return false;
                        }
                        });
                        break;
                    default:
                        cout << "Unijeli ste nepostojecu opciju, molimo odaberite ponovo!\n";
                        break;
                }
                allMovies(result.begin(), result.end());
                break;
            case 4:
                allMovies(data.begin(), data.end());
                break;
            case 5:
                sortOption = showSortMenu();
                switch(sortOption) {
                    case 1:
                        sort(data.begin(), data.end(), [](const Film& movie1, const Film& movie2){
                            return movie1.title < movie2.title;
                        });
                        break;
                    case 2:
                        sort(data.begin(), data.end(), [](const Film& movie1, const Film& movie2){
                            return movie1.year < movie2.year;
                        });
                        break;
                    case 3:
                        sort(data.begin(), data.end(), [](const Film& movie1, const Film& movie2){
                            return generateStringFromVector(movie1.genre.begin(), movie1.genre.end()) < generateStringFromVector(movie2.genre.begin(), movie2.genre.end());
                        });
                        break;
                    case 4:
                        sort(data.begin(), data.end(), [](const Film& movie1, const Film& movie2){
                            return generateStringFromVector(movie1.director.begin(), movie1.director.end()) < generateStringFromVector(movie2.director.begin(), movie2.director.end());
                        });
                        break;
                    case 5:
                        sort(data.begin(), data.end(), [](const Film& movie1, const Film& movie2){
                            return movie1.rating > movie2.rating;
                        });
                        break;
                    default:
                        cout << "Unijeli ste nepostojecu opciju, molimo odaberite ponovo!\n";
                        break;
                }
                break;
            case 6:
                updateMovie(data.begin(), data.end(), result.begin(), result.end());
                break;
            case 7:
                avgRatingByGenre(result.begin(), result.end());
                break;
            default:
                cout << "Unijeli ste nepostojecu opciju, molimo odaberite ponovo!\n";
                break;
        }
        cout << endl;
    } while (option != 8);
    return 0;
}

void filmska_analiza::fillData(vector<Film>& vec) {
    Film temp;
    ifstream data("movies.csv");
    string row;
    getline(data, row);
    unsigned short cPos;
    while(getline(data, row)) {
        if (row.at(0) == '"') {
            row.erase(0, 1);
            cPos = row.find('"');
            temp.title = row.substr(0, cPos);
            row.erase(0, cPos + 2);
        } else {
            cPos = row.find(',');
            temp.title = row.substr(0, cPos);
            row.erase(0, cPos + 1);
        }

        cPos = row.find(',');
        temp.year = stoi(row.substr(0, cPos));
        row.erase(0, cPos + 1);

        string genre;
        if (row.at(0) == '"') {
            row.erase(0, 1);
            cPos = row.find('"');
            genre = row.substr(0, cPos);
            row.erase(0, cPos + 2);
            short pos = genre.find(',');
            string singleGenre;
            while (pos != -1) {
                singleGenre = genre.substr(0, pos);
                temp.genre.push_back(singleGenre);
                genre.erase(0, pos + 2);
                pos = genre.find(',');
            }
            temp.genre.push_back(genre);
        } else {
            cPos = row.find(',');
            genre = row.substr(0, cPos);
            temp.genre.push_back(genre);
            row.erase(0, cPos + 1);
        }

        string directors;
        if (row.at(0) == '"') {
            row.erase(0, 1);
            cPos = row.find('"');
            directors = row.substr(0, cPos);
            row.erase(0, cPos + 2);
            short pos = directors.find(',');
            string singleDirector;
            while (pos != -1) {
                singleDirector = directors.substr(0, pos);
                temp.director.push_back(singleDirector);
                directors.erase(0, pos + 2);
                pos = genre.find(',');
            }
            temp.director.push_back(directors);
        } else {
            cPos = row.find(',');
            directors = row.substr(0, cPos);
            temp.director.push_back(directors);
            row.erase(0, cPos + 1);
        }

        temp.rating = stof(row);

        vec.push_back(temp);
        temp.genre.clear();
        temp.director.clear();
    }
    data.close();
}

short filmska_analiza::showMenu() {
    short option;
    cout << "Odaberite opciju:\n";
    cout << "1. Dodajte novi film\n";
    cout << "2. Obrisite film/ove (Potrebno je prvo odraditi pretragu, brisu se filmovi koji su dobijeni u pretrazivanju)\n";
    cout << "3. Pretrazivanje\n";
    cout << "4. Ispis svih filmova\n";
    cout << "5. Sortiranje filmova\n";
    cout << "6. Promijeni podatke odredjenog filma (Potrebno je prvo odraditi pretragu, mijanjaju se podaci filmova koji su dobijeni u pretrazivanju!)\n";
    cout << "7. Prosjecna ocjena prema zanru (Potrebno je prvo odraditi pretragu, prosjecna ocjena se racuna nad filmovima koji su dobijeni u pretrazivanju!)\n";
    cout << "8. Izlaz\n";
    cout << "-----------------------------------------\n";
    bool isInputValid = false;
    do {
        string input;
        cout << "Unesite broj opcije: ";
        cin >> input;
        try {
            option = stoi(input);
            isInputValid = true;
        } catch (const std::invalid_argument& err) {
            cout << "Niste unijeli broj!\n";
        } catch (const std::out_of_range& err) {
            cout << "Niste unijeli broj!\n";
        }
    } while (!isInputValid);
    return option;
}

void filmska_analiza::addMovie(vector<Film>& vec) {
    Film temp;
    string inputText;

    cout << "Unesite naziv filma: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, inputText);
    temp.title = inputText;

    regex yearRegex("^[0-9]{4}$");
    bool isInputValid = false;
    do {
        cout << "Unesite godinu: ";
        cin >> inputText;
        if (regex_match(inputText, yearRegex)) {
            const unsigned short inputYear = stoi(inputText);
            if (inputYear >= 1888) {
                temp.year = inputYear;
                isInputValid = true;
            }
        } else {
            cout << "Niste unijeli validnu godinu!\n";
        }
    } while (!isInputValid);
    isInputValid = false;

    cout << "Unesite zanr (Ako ima vise zanrova navedite jedan iza drugog odvojeni zarezom): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, inputText);
    string singleGenre = "", singleGenreM = "";
    short pos = inputText.find(',');
    if (pos != -1) {
        while (pos != -1) {
            singleGenre = inputText.substr(0, pos);
            for(const char c : singleGenre) {
                singleGenreM += tolower(c);
            }
            singleGenreM.at(0) = toupper(singleGenre.at(0));
            temp.genre.push_back(singleGenreM);
            inputText.erase(0, pos + 1);
            pos = inputText.find(',');
        }
        singleGenre = "";
        for(const char c : inputText) {
            singleGenre += tolower(c);
        }
        singleGenre.at(0) = toupper(singleGenre.at(0));
        temp.genre.push_back(singleGenre);
    } else {
        for(const char c : inputText) {
            singleGenre += tolower(c);
        }
        singleGenre.at(0) = toupper(singleGenre.at(0));
        temp.genre.push_back(singleGenre);
    }

    cout << "Unesite rezisera (Ako ima vise rezisera navedite jedan iza drugog odvojeni zarezom): ";
    getline(std::cin, inputText);
    cout << inputText << endl;
    singleGenre = "";
    pos = inputText.find(',');
    if (pos != -1) {
        while (pos != -1) {
            singleGenre = inputText.substr(0, pos);
            temp.director.push_back(singleGenre);
            inputText.erase(0, pos + 2);
            pos = inputText.find(',');
        }
        temp.director.push_back(inputText);
    } else {
        temp.director.push_back(inputText);
    }

    float rating;
    do {
        string input;
        cout << "Unesite ocjenu: ";
        cin >> input;
        try {
            rating = stof(input);
            isInputValid = true;
        } catch (const std::invalid_argument& err) {
            cout << "Niste unijeli broj!\n";
        } catch (const std::out_of_range& err) {
            cout << "Niste unijeli broj!\n";
        }
    } while (!isInputValid);
    temp.rating = rating;

    vec.push_back(temp);
    return;
}

string filmska_analiza::generateStringFromVector(std::vector<string>::const_iterator start, std::vector<string>::const_iterator finish) {
    string result = "";
    while (start != finish) {
        if (start + 1 == finish) {
            result += *start;
        } else {
            result += *start;
            result += ", ";
        }
        ++start;
    }
    return result;
}

void filmska_analiza::allMovies(std::vector<Film>::const_iterator start, std::vector<Film>::const_iterator finish) {
    while (start != finish) {
        cout << (*start).title << endl;
        cout << (*start).year << endl;
        cout << generateStringFromVector((*start).genre.begin(), (*start).genre.end()) << endl;
        cout << generateStringFromVector((*start).director.begin(), (*start).director.end()) << endl;
        cout << (*start).rating << endl;
        cout << endl;
        ++start;
    }
    return;
}

short filmska_analiza::showSearchMenu() {
    short option;
    cout << "Odaberite po cemu zelite da pretrazite filmove:\n";
    cout << "1. Naziv filma\n";
    cout << "2. Godina izdanja\n";
    cout << "3. Zanr\n";
    cout << "4. Reziser\n";
    cout << "5. Ocjena\n";
    cout << "-------------------------------------------------\n";
    bool isInputValid = false;
    do {
        string input;
        cout << "Unesite broj opcije: ";
        cin >> input;
        try {
            option = stoi(input);
            isInputValid = true;
        } catch (const std::invalid_argument& err) {
            cout << "Niste unijeli broj!\n";
        } catch (const std::out_of_range& err) {
            cout << "Niste unijeli broj!\n";
        }
    } while (!isInputValid);
    return option;
}

void filmska_analiza::searchMovies(std::vector<Film>::const_iterator start, std::vector<Film>::const_iterator finish, std::back_insert_iterator<std::vector<Film>> backInserter, std::function<bool(std::vector<Film>::const_iterator)> searchFilter) {
    while (start != finish) {
        if (searchFilter(start)) {
            *backInserter = *start;
        }
        ++start;
    }
    return;
}

short filmska_analiza::showSortMenu() {
    short option;
    cout << "Odaberite po cemu zelite da sortirate filmove:\n";
    cout << "1. Naziv filma\n";
    cout << "2. Godina izdanja\n";
    cout << "3. Zanr\n";
    cout << "4. Reziser\n";
    cout << "5. Ocjena\n";
    cout << "-------------------------------------------------\n";
    bool isInputValid = false;
    do {
        string input;
        cout << "Unesite broj opcije: ";
        cin >> input;
        try {
            option = stoi(input);
            isInputValid = true;
        } catch (const std::invalid_argument& err) {
            cout << "Niste unijeli broj!\n";
        } catch (const std::out_of_range& err) {
            cout << "Niste unijeli broj!\n";
        }
    } while (!isInputValid);
    return option;
}

void filmska_analiza::deleteMovie(std::vector<Film>& vec1, std::vector<Film>::const_iterator vec1Start, std::vector<Film>::const_iterator vec1Finish, std::vector<Film>::const_iterator vec2Start, std::vector<Film>::const_iterator vec2Finish) {
    while (vec1Start != vec1Finish) {
        std::vector<Film>::const_iterator vec2StartLoop = vec2Start;
        while (vec2StartLoop != vec2Finish) {
            if ((*vec2StartLoop).title == (*vec1Start).title && (*vec2StartLoop).year == (*vec1Start).year && (*vec2StartLoop).genre == (*vec1Start).genre && (*vec2StartLoop).director == (*vec1Start).director && (*vec2StartLoop).rating == (*vec1Start).rating) {
                vec1.erase(vec1Start);
                continue;
            }
            ++vec2StartLoop;
        }
        ++vec1Start;
    }
    return;
}

void filmska_analiza::updateMovie(std::vector<Film>::iterator vec1Start, std::vector<Film>::const_iterator vec1Finish, std::vector<Film>::const_iterator vec2Start, std::vector<Film>::const_iterator vec2Finish) {
    vector<Film> temp;
    addMovie(temp);
    while (vec1Start != vec1Finish) {
        std::vector<Film>::const_iterator vec2StartLoop = vec2Start;
        while (vec2StartLoop != vec2Finish) {
            if ((*vec2StartLoop).title == (*vec1Start).title && (*vec2StartLoop).year == (*vec1Start).year && (*vec2StartLoop).genre == (*vec1Start).genre && (*vec2StartLoop).director == (*vec1Start).director && (*vec2StartLoop).rating == (*vec1Start).rating) {
                (*vec1Start).title = temp.at(0).title;
                (*vec1Start).year = temp.at(0).year;
                (*vec1Start).genre = temp.at(0).genre;
                (*vec1Start).director = temp.at(0).director;
                (*vec1Start).rating = temp.at(0).rating;
                continue;
            }
            ++vec2StartLoop;
        }
        ++vec1Start;
    }
    return;
}

void filmska_analiza::avgRatingByGenre(std::vector<Film>::const_iterator start, std::vector<Film>::const_iterator finish) {
    float sum = 0;
    short numberOfMovies = 0;
    while (start != finish) {
        sum += (*start).rating;
        ++numberOfMovies;
        ++start;
    }
    cout << "Prosjecna ocjena po odabranom zanru iznosi: " << sum/numberOfMovies << endl;
}
