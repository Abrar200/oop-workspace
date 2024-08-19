#include "Musician.h"

Musician::Musician() : instrument("null"), years_of_experience(0) {}

Musician::Musician(std::string instrument, int experience) 
    : instrument(instrument), years_of_experience(experience) {}

std::string Musician::get_instrument() {
    return instrument;
}

int Musician::get_experience() {
    return years_of_experience;
}