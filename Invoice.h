#ifndef INVOICE_H
#define INVOICE_H

#include <string>

class Invoice
{
private:
    std::string invoiceId;
    double dollarsOwed;

public:
    Invoice(const std::string &id);
    void addServiceCost(double costDollars);
    double getDollarsOwed() const;
    std::string getInvoiceId() const;
};

#endif