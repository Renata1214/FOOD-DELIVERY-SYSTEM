#ifndef DELIVERYPEOPLE_H
#define DELIVERYPEOPLE_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

//Random Function configuration
int rand_int(int a, int b);
float rand_float(float a, float b);

class DeliveryPeople{

private:
float xcoordinate;
float ycoordinate;
int id;
bool availability;
static int IDnumber;

friend class Business;

public:
DeliveryPeople ();

//setter functions
void setPosition(float x, float y);
void setavailability(bool value);
float getxpos ();
float getypos ();
bool getavailability ();
int getID ();

};


#endif