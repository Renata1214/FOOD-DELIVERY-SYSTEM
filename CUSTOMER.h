#ifndef CUSTOMER_H
#define CUSTOMER_H

//#include "BUSINESS.h"
#include "IdData.h"
//#include "RECEIPT.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <typeinfo>

class Business;
class Receipt;

class Customer: public IdData{

    private:
    std::vector <std::string> order;
    std::string item;
    std::vector <int> quantityVec; 
    int quantity;
    bool confirm;
    std::vector <int> indexOrderedItems;
    //FRIEND CLASSES
    friend class Business;
    friend class Receipt;

    public:
    //Constructor
    Customer ();
    //Getter functions
    //Getter functions
    inline std::vector <std::string> getOrder () {return order;}
   inline std::vector <int> getQuantity (){return quantityVec;}
    inline bool getCusConfirmation (){return confirm;}

    //Order Food
    void OrderFood ();
    //Print Order
    void printOrder (Business *b1);
    //Confirm Order- OVERRRIDING FUNCTIONS FROM BUSINESS CLASS. virtual
     bool customerConfirm (Business *b1);
    //Get the details of the customer
    void PrintIDdata ();
};

#endif