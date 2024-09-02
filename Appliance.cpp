#include "Appliance.h"

Appliance::Appliance() : powerRating(0), isOn(false) {}

Appliance::Appliance(int powerRating) : powerRating(powerRating), isOn(false) {}

void Appliance::turnOn() {
    isOn = true;
}

void Appliance::turnOff() {
    isOn = false;
}

double Appliance::getPowerConsumption() const {
    return 0.0;
}

int Appliance::get_powerRating() const {
    return powerRating;
}

void Appliance::set_powerRating(int rating) {
    powerRating = rating;
}

bool Appliance::get_isOn() const {
    return isOn;
}

void Appliance::set_isOn(bool on) {
    isOn = on;
}