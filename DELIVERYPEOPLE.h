#ifndef DELIVERYPEOPLE_H
#define DELIVERYPEOPLE_H

#include <iostream>

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
int DeliveryPeople:: IDnumber=0;

#endif