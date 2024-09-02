#include "House.h"

House::House() : numAppliances(0) {}

House::House(int numAppliances) : numAppliances(numAppliances) {
    appliances.reserve(numAppliances);
}

House::~House() {
    for (Appliance* appliance : appliances) {
        delete appliance;
    }
}

bool House::addAppliance(Appliance* appliance) {
    if (appliances.size() < numAppliances) {
        appliances.push_back(appliance);
        return true;
    }
    return false;
}

double House::getTotalPowerConsumption() const {
    double totalConsumption = 0.0;
    for (const Appliance* appliance : appliances) {
        totalConsumption += appliance->getPowerConsumption();
    }
    return totalConsumption;
}