#ifndef RECEIPT_H
#define RECEIPT_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "CUSTOMER.h"
#include "BUSINESS.h"

class Receipt{
    public:
    Receipt (){ };
    //Setter and Getter Functions
    //Print the receipt
    void calculateCost (Business *b2) const;
};


#endif