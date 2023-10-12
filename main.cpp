#include <iostream> 
#include <cmath>
#include <string>
#include <vector>
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
int rand_int(int a, int b)
{
return rand()%(b-a+1) + a;
}

float rand_float(float a, float b)
{
return ((float)rand()/RAND_MAX)*(b-a) + a;
}

//Class Definitions

//Delivery details
class DeliveryPeople{

private:
float xcoordinate;
float ycoordinate;
int id;
bool availability;
static int IDnumber;


public:

DeliveryPeople (){
    xcoordinate= rand_float(0,100);
    ycoordinate= rand_float(0,100);
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
    return xcoordinate;
}

float getypos (){
    return ycoordinate;
}

bool getavailability (){
    return availability;
}

};
int DeliveryPeople:: IDnumber=0;

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
    for (int i=0; i<rows; i++){
        MenuOptions.push_back(ArrMenuPrices[i][0]);
        PricesMenu. push_back(ArrMenuPrices[i][1]);
    }

    for (int j=0; j<deliveryNum; j++){
        DeliveryPeople newObject;
        DeliveryWorkers.push_back(newObject);
    }

}

//Setter and Getter Functions

//Function to determine availability of Drivers
bool DriverAvailability (){


return true;
}


//Function to determine whether order is accepted or not


};

class Customer{

    private:

    
    friend class Receipt;

    public:



    //Setter and Getter functions



};

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
IdData ( ) {
    xCusPos= 0;
    yCusPos = 0;
    nameCustomer= "-";
    personalID=UniqueNumber;
   UniqueNumber++;
}

IdData (float coordinatex, float coordinatey, string name){
    xCusPos= coordinatex;
    yCusPos = coordinatey;
    nameCustomer= name;
    personalID=UniqueNumber;
    UniqueNumber++;
}

//Getter and Setter Functions


};
//Definition of Static Variable
int IdData:: UniqueNumber=0;


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

int main (){

    return 0;
}