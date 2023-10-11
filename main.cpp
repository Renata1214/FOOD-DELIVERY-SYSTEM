#include <iostream> 
#include <cmath>
#include <string>
#include <vectors>
#include <cstdlib>
#include <ctime>


using namespace std;

srand(time(NULL));

#Class Definitions

class Business {

private:
    vector <string> MenuOptions;
    vector <string> PricesMenu;
    bool availableDriver;
    bool confirmationOrd;
    int numberDrivers;




public:


};

class Customer: public  {

    private:

    

    public:



};

class DeliveryPeople  {

private:
float xcoordinate;
float ycoordinate;
int id;
static int IDnumber;
bool availability;

public:

DeliveryPeople (){
    xcoordinate= rand ();
    ycoordinate= rand ();
    id=IDnumber;
    IDnumber ++;
}




};
int DeliveryPeople:: IDnumber=0;

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