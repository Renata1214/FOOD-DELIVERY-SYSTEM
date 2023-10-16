#ifndef BUSINESS_H
#define BUSINESS_H

#include "CUSTOMER.h"
#include "DELIVERYPEOPLE.h"
#include <iostream>
#include <iomanip>
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
inline std::vector <int> getItemIndex (){ return ItemIndex;}
inline std::vector <std::string> getMenuOptions(){return MenuOptions;}
inline std::vector <float> getPricesMenu (){return PricesMenu;}
inline std::string getResName (){return nameRestaurant;}

//Function to print the Menu
inline void PrintMenu (){
        std::cout << "\033[44m\033[1;37m"; // Set background to blue (44) and text to bold white (1;37)
        std::cout << " Welcome to " << nameRestaurant << "!! " << "\033[0m" << std::endl;
       std::cout << "\033[34m"; // Set text color to blue (34)
        std::cout << "Menu." << std::endl;
        std::cout << "\033[0m"; // Reset to default color

        for (int i = 0; i < MenuOptions.size(); i++) {
            std::cout << "\033[34m"; // Set text color to blue (34)
            std::cout << ItemIndex[i] << std::setw(30) << MenuOptions[i] << std::setw(20) << "$" << PricesMenu[i] << std::endl;
            std::cout << "\033[0m"; // Reset to default color
        }}

//Function to determine availability of Drivers
std::vector <int> DriverAvailable (int a);
//Function to determine if any of the drivers are available
bool DriverAvailable (bool a);
//Function to determine whether order is accepted or not. CAN LATER USE FUNCTION OVERRIDING
bool OrderConfirmation ();
//Function to access the position of the customer (object that is automatically created when an object of business is created)
inline float getCustomerPositionX (){return getCusPosX();}
inline float getCustomerPositionY (){return getCusPosY();}
//Assign Driver Function
DeliveryPeople AssignedDriverInfo ();
//Function to get the data from the drivers
float AssignedDriverInfo (int index);
//Assign Driver to customer
void AssignDriverToCustomer ();
//Pretend delivery
inline void PretendDelivery () {
            DeliveryWorkers[AssignedDIndex].setPosition(getCustomerPositionX(), getCustomerPositionY());
            std::cout<< "Your order has been successfully delivered! Thank you for ordering from " << nameRestaurant << std::endl;
            DeliveryWorkers[AssignedDIndex].setavailability(true);
        }

float getdriverslocation ();

};

#endif