#ifndef APPLIANCE_H
#define APPLIANCE_H

class Appliance {
private:
    int powerRating;
    bool isOn;

public:
    Appliance();
    Appliance(int powerRating);
    
    void turnOn();
    void turnOff();
    virtual double getPowerConsumption() const;

    int get_powerRating() const;
    void set_powerRating(int rating);
    bool get_isOn() const;
    void set_isOn(bool on);
};

#endif