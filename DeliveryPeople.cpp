#include "DELIVERYPEOPLE.h"

using namespace std;

//Defintiion of functions to get random numbers

        int rand_int(int a, int b)
        {
        return rand()%(b-a+1) + a;
        }

        float rand_float(float a, float b)
        {
        return ((float)rand()/RAND_MAX)*(b-a) + a;
        }

//Constructor
        DeliveryPeople::DeliveryPeople (){
            xcoordinate= rand_float(0,100);
            ycoordinate= rand_float(0,100);
            availability= rand_int(0,1);
            id=IDnumber;
            IDnumber ++;
        }

//Setter functions
        void DeliveryPeople::setPosition(float x, float y){
            xcoordinate=x;
            ycoordinate=y;}

        void DeliveryPeople::setavailability(bool value){ availability=value;}
//Getter Functions
        float DeliveryPeople::getxpos (){return xcoordinate;}

        float DeliveryPeople::getypos (){return ycoordinate;}

        bool DeliveryPeople::getavailability (){return availability;}

        int DeliveryPeople::getID () {return id;}

//static variable definition
        int DeliveryPeople:: IDnumber=0;