#include <iostream> 
#include <cmath>
#include <string>
#include <vectors>
#include <cstdlib>
#include <ctime>


using namespace std;

//Class declarations
class Business;
class DeliveryPeople;
class Customer;
class IdData;
class Receipt;

//Random Function configuration
srand(time(NULL));
int rand_int(int a, int b)
{
return rand()%(b-a+1) + a;
}

#Class Definitions

class Business {

private:
    vector <string> MenuOptions;
    vector <string> PricesMenu;
    vector <DeliveryPeople> DeliveryWorkers;
    bool availableDelivery;
    bool confirmationOrd;
    int numberDrivers;

    friend class Receipt;

public:
Business (string **ArrMenuPrices, int rows, int columns, int deliveryNum){

    availableDelivery=false;
    confirmationOrd=false;
    numberDrivers=deliveryNum;
    for (int i=0, i<rows; i++){
        MenuOptions[i]= ArrMenuPrices[i][0];
        PricesMenu[i]=ArrMenuPrices[i][1];
    }

    for (int j=0; j<deliveryNum; j++){
        DeliveryPeople newObject();
        DeliveryWorkers[j]= newObject;
    }

}

//Setter and Getter Functions

//Function to determine availability of Drivers
bool DriverAvailability (){



}


//Function to determine whether order is accepted or not


};

class Customer: public idData {

    private:

    
    friend class Receipt;

    public:



    //Setter and Getter functions



};


//Delivery details
class DeliveryPeople : public Business{

private:
float xcoordinate;
float ycoordinate;
int id;
bool availability;
static int IDnumber;


public:

DeliveryPeople (){
    xcoordinate= rand ();
    ycoordinate= rand ();
    availability= rand_int(0,1);
    id=IDnumber;
    IDnumber ++;
}

//setter and getter functions
void setPosition(float x, float y){
    xcoordinate=x;
    ycoordinate=y;}

void setavailability(bool value){
    availability=value;
}

float getxpos (){
    return xpos;
}

float getypos (){
    return ypos;
}

bool getavailability (){
    return availability;
}

};
int DeliveryPeople:: IDnumber=0;

//ID information of the customer
class IdData {

private:
float xCusPos;
float yCusPos;
string nameCustomer;
int personalID;
static int UniqueNumber;

public:
//Constructor
idData(){
    xCusPos= 0;
    yCusPos = 0;
    nameCustomer= 0;
    personalID=UniqueNumber;
    UniqueNumber++;
}

idData (float coordinatex, float coordinatey, string name){
    xCusPos= coordinatex;
    yCusPos = coordinatey;
    nameCustomer= name;
    personalID=UniqueNumber;
    UniqueNumber++;
}

//Getter and Setter Functions


};
//Definition of Static Variable
int IDdata:: UniqueNumber=0;


//Receipt of the order
class Receipt {
    private:
    float totalCost;
    float deliveryFee;
    

    public:
    Receipt (){

        totalCost=0;
        deliveryFee=0;
    }

    //Setter and Getter Functions





};