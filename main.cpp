#include "MASTERHEADER.h"

using namespace std;


//Random Function configuration
int rand_int(int a, int b)
{
return rand()%(b-a+1) + a;
}

float rand_float(float a, float b)
{
return ((float)rand()/RAND_MAX)*(b-a) + a;
}


int main (){


    return 0;
}