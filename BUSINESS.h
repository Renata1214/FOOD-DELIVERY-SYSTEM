#ifndef BUSINESS_H
#define BUSINESS_H

#include "CUSTOMER.h"
#include "DELIVERYPEOPLE.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <typeinfo>



//Class Business
class Business: public Customer{

private:
    std::vector <std::string> MenuOptions;
    std::vector <float> PricesMenu;
    std::vector <int> ItemIndex;
    std::vector <DeliveryPeople> DeliveryWorkers;
    std::string nameRestaurant;
    bool availableDelivery;
    bool confirmationOrd;
    int numberDrivers;
    int AssignedDIndex;
    float deliveryPrice;

//check if it should be friend or derived class
    friend class Receipt;
    friend bool confirmationOrd (Business *b1);

public:
Business (std::string ArrMenu[][2], int rows, int columns, int deliveryNum,float deliveryfee, std::string resName);
//Setter and Getter Functions
std::vector <int> getItemIndex ();
std::vector <std::string> getMenuOptions();
std::vector <float> getPricesMenu ();
std::string getResName ();
//Function to print the Menu
void PrintMenu ();
//Function to determine availability of Drivers
std::vector <int> DriverAvailable (int a);
//Function to determine if any of the drivers are available
bool DriverAvailable (bool a);
//Function to determine whether order is accepted or not. CAN LATER USE FUNCTION OVERRIDING
bool OrderConfirmation ();
//Function to access the position of the customer (object that is automatically created when an object of business is created)
float getCustomerPositionX ();
float getCustomerPositionY ();
//Assign Driver Function
DeliveryPeople AssignedDriverInfo ();
//Function to get the data from the drivers
float AssignedDriverInfo (int index);
//Assign Driver to customer
void AssignDriverToCustomer ();
//Pretend delivery
void PretendDelivery ();

float getdriverslocation ();

};

#endif