#ifndef INVOICE_TEST_H
#define INVOICE_TEST_H

#include <iostream>
#include <cassert>
#include <stdexcept>
#include "Invoice.h"

class InvoiceTest
{
public:
    void runTests()
    {
        testConstructor();
        testAddServiceCost();
        testGetDollarsOwed();
        testGetInvoiceId();
        testNegativeServiceCost();
        std::cout << "All Invoice tests passed!" << std::endl;
    }

private:
    void testConstructor()
    {
        Invoice invoice("ABCD");
        assert(invoice.getDollarsOwed() == 0.0);
        assert(invoice.getInvoiceId() == "ABCD");
    }

    void testAddServiceCost()
    {
        Invoice invoice("ABCD");
        invoice.addServiceCost(10.5);
        assert(invoice.getDollarsOwed() == 10.5);
        invoice.addServiceCost(5.75);
        assert(invoice.getDollarsOwed() == 16.25);
    }

    void testGetDollarsOwed()
    {
        Invoice invoice("EFGH");
        assert(invoice.getDollarsOwed() == 0.0);
        invoice.addServiceCost(100.0);
        assert(invoice.getDollarsOwed() == 100.0);
    }

    void testGetInvoiceId()
    {
        Invoice invoice1("IJKL");
        assert(invoice1.getInvoiceId() == "IJKL");
        Invoice invoice2("1234");
        assert(invoice2.getInvoiceId() == "1234");
    }

    void testNegativeServiceCost()
    {
        Invoice invoice("MNOP");
        try
        {
            invoice.addServiceCost(-10.0);
            assert(false);
        }
        catch (const std::invalid_argument &e)
        {
        }
    }
};

#endif