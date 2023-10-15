#ifndef IdData_H
#define IdData_H

//#include "CUSTOMER.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <string>


class IdData {

private:
float xCusPos;
float yCusPos;
std::string nameCustomer;
int personalID;
static int UniqueNumber;

friend class receipt;

public:
//Constructor
IdData ( );
IdData (float coordinatex, float coordinatey, std::string name);

//Getter Functions
float getCusPosX ();
float getCusPosY ();
std::string getName () ;
int getIDCus ();

//Setter Functions
void setCusPosX (float x);
void setCusPosY (float y);
void setName (std::string name);

//print all data
void PrintIDdata ();
};


#endif