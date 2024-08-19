#ifndef MUSICIAN_H
#define MUSICIAN_H

#include <string>

class Musician {
public:
    Musician();
    Musician(std::string instrument, int experience);
    std::string get_instrument();
    int get_experience();

private:
    std::string instrument;
    int years_of_experience;
};

#endif