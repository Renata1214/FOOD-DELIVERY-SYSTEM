#ifndef RECEIPT_H
#define RECEIPT_H

#include <iostream>
#include "CUSTOMER.h"
#include "BUSINESS.h"

class Receipt: public Customer{
    public:
    Receipt (){ };
    //Setter and Getter Functions
    //Print the receipt
    void calculateCost (Customer*cus1, Business *b2) const;
};


#endif