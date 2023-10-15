#ifndef IdData_H
#define IdData_H

#include "CUSTOMER.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>


class IdData {

private:
float xCusPos;
float yCusPos;
string nameCustomer;
int personalID;
static int UniqueNumber;

friend class receipt;

public:
//Constructor
IdData ( );
IdData (float coordinatex, float coordinatey, string name);

//Getter Functions
float getCusPosX ();
float getCusPosY ();
string getName () ;
int getIDCus ();

//Setter Functions
void setCusPosX (float x);
void setCusPosY (float y);
void setName (string name);

//print all data
void PrintIDdata ();
};


#endif