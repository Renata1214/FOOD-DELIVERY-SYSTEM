#include "MASTERHEADER.h"
#include <iomanip>

using namespace std;

void OrderingFoodRestaurant (string ArrMenu[][2], int rows, int columns, int deliveryNum,float deliveryfee, string resName);

int main (){

    int UserSelection;

    cout << "\033[41m\033[1;37m";  // Set background to red (41) and text to white (1;37)
    cout << setw(40) << " Welcome to Renata's Ordering Food System!!! " << "\033[0m" << endl;
    cout << "Please select 1 if you wish to order Restaurant A, and 2 for Restaurant B" << endl;
    cin>> UserSelection;

    switch(UserSelection){

        case 1:
        {
        //Definition of the parameters of Restaurant A
        //Array of menu and prices
        string MenuRestaurant [4][2]={{"Enchiladas", "20"},{"Chilaquiles", "25"}, {"Sopitos", "30"}, {"Quesadillas", "35"}};
        //rows in the menu and //columsnin the menu
        //number of drivers
        int restaurantDrivers =3;
        //delivery fee
        float dFee =20;
        //Name of the restaurant
        string NameRes= "Renata's Kitchen";

        OrderingFoodRestaurant(MenuRestaurant, 4,2,restaurantDrivers,dFee,NameRes);

        break;}

        case 2:
        {
        //Definition of the parameters of Restaurant A
        //Array of menu and prices
        //rows in the menu
        //columsnin the menu
        //number of drivers
        //delivery fee
        //Name of the restaurant

        break;
        }
        default:
        {
        cout<< "There was a mistake in your selection. Please try again later." << endl;
        }

    }

    return 0;
}

void OrderingFoodRestaurant (string ArrMenu[][2], int rows, int columns, int deliveryNum,float deliveryfee, string resName){

//Create object restaurant
    Business business1 (ArrMenu, rows, columns, deliveryNum, deliveryfee, resName);
    //Print menu 
    business1.PrintMenu();
    //Order food function from customer class
    business1.OrderFood();
    //check if the restaurant can accept the orer based on availability of drivers. Function from business class 
if(business1.OrderConfirmation()==true){
        //If accepted get the customers ID data, by accessing the setter functions from IdData class
        std::string customername;
        float xcoordinatecustomer;
        float ycoordinatecustomer;

        cout<< "Please write your full name!" << endl;
        cin.ignore(); // Clear any previous input left in the buffer
        getline(cin, customername); // Use getline to capture the full name
        //cin>> customername;
        //Loop to enter the position of the customer and check if it is within the bounds that the drivers can reach
       
        cout<< "Plese write the x coordinate of your location with respect to the Restaurant!" <<endl;
        cin >>xcoordinatecustomer;
        
       cout<< "Please write the y coordinate of your location with respect to the Restaurant!" << endl;
        cin>>ycoordinatecustomer;
        cout<< endl<< endl;
        
        business1.setCusPosX(xcoordinatecustomer);
        business1.setCusPosY(ycoordinatecustomer);
        business1.setName(customername);

//here tou should change to do override of function from business to class customer
        bool customerConfirmation= business1.customerConfirm (&business1);

        if(customerConfirmation==true){
            const Receipt receipt1;
            cout<< endl;
            receipt1.calculateCost (&business1);
            cout<< endl<< endl;
            business1.AssignDriverToCustomer();
            cout<< endl;
            cout<<"Your order will be delivered soon!!!" << endl;
            cout<< endl;
            business1. PretendDelivery();
        }

        else{
            cout<< "You have not confirmed your order, we are sorry to hear that. If you want to order later, we will happily take your order!" << endl;
            exit(0);
        }
    }
else{
    cout <<"At the moment we are unable to place your order as all our drivers are occupied, please try ordering later. We apologize for the inconvenience." << endl;
    exit(0);
    }
}