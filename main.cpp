#include "MASTERHEADER.h"
#include <iomanip>

using namespace std;

void OrderingFoodRestaurant ();

int main (){

    int UserSelection;

    cout << setw(10) <<"Welcome to Renata's Ordering Food System!!!"<< endl;
    cout << "Please select 1 if you wish to order Restaurant A, and 2 for Restaurant B" << endl;
    cin>> UserSelection;

    switch(UserSelection){

        case 1:
        //Definition of the parameters of Restaurant A
        //Array of menu and prices
        string MenuRestaurant [4][2]={{Enchiladas, 20},{Chilaquiles, 25}, {Sopitos. 30}, {Quesadillas, 35}};
        //rows in the menu and //columsnin the menu
        //number of drivers
        int restaurantDrivers =3;
        //delivery fee
        float dFee =20;
        //Name of the restaurant
        string NameRes= "Renata's Kitchen"


        break;

        case 2:
        //Definition of the parameters of Restaurant A
        //Array of menu and prices
        //rows in the menu
        //columsnin the menu
        //number of drivers
        //delivery fee
        //Name of the restaurant

        break;

        default:
        cout<< "There was a mistake in your selection. Please try again later."
        exit(0);

    }

    return 0;
}

void OrderingFoodRestaurant (string **ArrMenu, int rows, int columns, int deliveryNum,float deliveryfee, string resName){

//Create object restaurant
    Business business1 (ArrMenu, rows, columns, deliveryNum, deliveryfee, resName);
    //Print menu 
    business1.PrintMenu();
    //Order food function from customer class
    business1.OrderFood();
    //check if the restaurant can accept the orer based on availability of drivers. Function from business class 
    if(business1.OrderConfirmation()==true){
        //If accepted get the customers ID data, by accessing the setter functions from IdData class
        string customername;
        float xcoordinatecustomer;
        float ycoordinatecustomer;
        int loopvar=1;

        cout<< "Please write your full name!" << endl;
        cin>> customername;
        while (loopvar==1){
        cout<< "Plese write the x coordinate of your lcation with respect to the Restaurant!" << endl;
        cin>> xcoordinatecustomer;}
        cout<< "Please write the y coordinate of your location with respect to the Restaurant!" << endl;
        cin>>ycoordinatecustomer;
        business.setCusPosX(xcoordinatecustomer);
        business.setCusPosY(ycoordinatecustomer);
        business.setName(customername);

        // Assign a driver to the customer 
        business.AssignedDriverInfo();
        


    }
    



}