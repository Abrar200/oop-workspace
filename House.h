#ifndef HOUSE_H
#define HOUSE_H

#include "Appliance.h"
#include <vector>

class House {
private:
    std::vector<Appliance*> appliances;
    int numAppliances;

public:
    House();
    House(int numAppliances);
    ~House();

    bool addAppliance(Appliance* appliance);
    double getTotalPowerConsumption() const;
};

#endif