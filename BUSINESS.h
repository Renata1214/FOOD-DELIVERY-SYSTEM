#ifndef BUSINESS_H
#define BUSINESS_H

#include "CUSTOMER.h"
#include <iostream>

//Class Business
class Business: public Customer{

private:
    vector <string> MenuOptions;
    vector <float> PricesMenu;
    vector <int> ItemIndex;
    vector <DeliveryPeople> DeliveryWorkers;
    string nameRestaurant;
    bool availableDelivery;
    bool confirmationOrd;
    int numberDrivers;
    int AssignedDIndex;
    float deliveryPrice;

//check if it should be friend or derived class
    friend class Receipt;
    friend bool confirmationOrd (Business *b1);

public:
Business (string **ArrMenu, int rows, int columns, int deliveryNum,float deliveryfee, string resName);
//Setter and Getter Functions
vector <int> getItemIndex ();
vector <string> getMenuOptions();
vector <float> getPricesMenu ();
string getResName ();
//Function to print the Menu
void PrintMenu ();
//Function to determine availability of Drivers
vector <int> DriverAvailable (int a);
//Function to determine if any of the drivers are available
bool DriverAvailable (bool a);
//Function to determine whether order is accepted or not. CAN LATER USE FUNCTION OVERRIDING
bool OrderConfirmation ();
//Assign Driver Function
// template <typename U>
DeliveryPeople AssignedDriverInfo (Customer *Example);
//Function to get the data from the drivers
float AssignedDriverInfo (Customer *Example, int index);
};

#endif