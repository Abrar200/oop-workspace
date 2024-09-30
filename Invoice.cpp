#include "Invoice.h"
#include <stdexcept>

Invoice::Invoice(const std::string &id) : invoiceId(id), dollarsOwed(0.0) {}

void Invoice::addServiceCost(double costDollars)
{
    if (costDollars <= 0)
    {
        throw std::invalid_argument("Cost must be positive");
    }
    dollarsOwed += costDollars;
}

double Invoice::getDollarsOwed() const
{
    return dollarsOwed;
}

std::string Invoice::getInvoiceId() const
{
    return invoiceId;
}