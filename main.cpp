#include "UnitTest.h"
#include "EquivalenceTests.h"
#include "InvoiceTest.h"

int main()
{
    std::cout << "Running Unit Tests:" << std::endl;
    UnitTest unitTest;
    unitTest.runTests();

    std::cout << "\nRunning Equivalence Tests:" << std::endl;
    EquivalenceTests equivalenceTests;
    equivalenceTests.runTests();

    std::cout << "\nRunning Invoice Tests:" << std::endl;
    InvoiceTest invoiceTest;
    invoiceTest.runTests();

    return 0;
}