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

    Business business1 (ArrMenu, rows, columns, deliveryNum, deliveryfee, resName);
    business1.PrintMenu();
    business1.OrderFood();
    if(business1.DriverAvailable(true)){
        
    }
    



}