#include <iostream> 
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <typeinfo>


using namespace std;

//Class declarations
class Business;
class DeliveryPeople;
class Customer;
class IdData;
class Receipt;

//Function Declarations
Business::vector <int> getItemIndex ();
Business::vector <string> getMenuOptions();
Business::vector <float> getPricesMenu ();
Business::string getResName ();

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

friend class Business;
public:

DeliveryPeople (){
    xcoordinate= rand_float(0,100);
    ycoordinate= rand_float(0,100);
    availability= rand_int(0,1);
    id=IDnumber;
    IDnumber ++;
}

//setter functions
void setPosition(float x, float y){
    xcoordinate=x;
    ycoordinate=y;}

void setavailability(bool value){ availability=value;}

float getxpos (){return xcoordinate;}

float getypos (){return ycoordinate;}

bool getavailability (){return availability;}

int getID () {return id;}

};
int DeliveryPeople:: IDnumber=0;

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

//Getter Functions
float getCusPosX (){return xCusPos;}
float getCusPosY (){return yCusPos;}
string getName () {return nameCustomer;}
int getIDCus () {return personalID;}

//Setter Functions
void setCusPosX (float x){ xCusPos=x;}
void setCusPosY (float y){ yCusPos=y;}
void setName (string name) {nameCustomer=name;}

//print all data
void PrintIDdata (){
    cout << "Name of the Customer: " << nameCustomer << endl;
    cout << "Unique ID of the customer: " << personalID << endl;
    cout << "Location of the customer: (" << xCusPos << ", " << yCusPos << ")" << endl;
}

};
//Definition of Static Variable
int IdData:: UniqueNumber=0;



class Customer: public IdData{

    //business will be inherited from customer such that business can do all the stuff related to ordering the food and saving it, etc. 

    private:
    vector <string> order;
    string item;
    vector <int> quantityVec; 
    int quantity;
    bool confirm;
    vector <int> indexOrderedItems;
   

    friend class Business;
    friend class Receipt;

    public:

    //Constructor
    Customer (){
        confirm=false;
        quantity=0;
    }


    //Order Food
    void OrderFood (){
        int errorselection=-1;
        int ExtraproductDecision=-1;

    do{
        cout << "From the options shown in the Menu above, which one would you like to order?"<<
        "Please write exactly as shown or write the number shown on the left column corresponding to the item you would like to order" << endl;
        cin >> item;
        cout << "How many would you like to order"<< endl;
        cin>> quantity;
        if (quantity<=0){
            cout<<"That is an invalid order, please try ordering again. Select 1 to return to item selection, and 0 to end the program"<< endl;
            cin>>errorselection;
                    if(errorselection==0){
                        exit(0);
                    }
            while(errorselection!=1||errorselection!=0){
                cout<<"Invalid selection, please try again. Select 1 to return to item selection and 0 to en program"<< endl;
                cin >> errorselection;
                if(errorselection==0){
                        exit(0);
                    }
            }
                
        }
        else if(errorselection!=1){
            order.push_back(item);
            quantityVec.push_back(quantity);
            cout << "Would you like to order something else? (1 (for yes), 0 (for no))"<< endl;
            cin>> ExtraproductDecision;
            do{
                if (ExtraproductDecision!=0){
                    cout <<"Please write exactly as shown or write the number shown on the left column corresponding to the item you would like to order" << endl;
                    cin >> item;
                    cout << "How many would you like to order"<<endl;
                    cin>> quantity;
                        if (quantity<=0){
                            cout<<"That is an invalid order, please try ordering again. Select 1 to return to inital item selection (previous ordered items will need to be re-ordered), and 0 to end the program"<< endl;
                            cin>>errorselection;
                                if(errorselection==0){
                                    exit(0);
                                }
                                while(errorselection!=1||errorselection!=0){
                                    cout<<"Invalid selection, please try again. Select 1 to return to item selection and 0 to en program"<< endl;
                                    cin >> errorselection;
                                        if(errorselection==0){
                                            exit(0);
                                            }
                                }
                        }
                        else if(errorselection!=1){
                            order.push_back(item);
                            quantityVec.push_back(quantity);
                            cout << "Would you like to order something else? (1 (for yes), 0 (for no))"<< endl;
                            cin>> ExtraproductDecision;
                }
                    }
        }while (ExtraproductDecision!=0&&errorselection!=1);

        if(errorselection!=1){
        cout<< "Your Order has been recorded!!!" << endl;}
        
        }

    }while (errorselection==1);
    }

    void printOrder (Business *b1){
        cout << "The recorded order is shown below: " << endl;

        if(typeid(order[0])==typeid(int)){
            for (int j=0; j<order.size();j++){
            for (int i=0; i<b1->ItemIndex.size(); i++){

                if(order[j]==b1->ItemIndex[i]){
                cout << "Quantity: " << quantityVec[j] << " " << b1->MenuOptions[i] << endl;
                indexOrderedItems.push_back(i);
                break;
                }

            }}
        }
        else{
            for (int j=0; j<order.size();j++){
            for (int i=0; i<b1->MenuOptions.size(); i++){
                if(order[j]==b1->MenuOptions[i]){
                cout << "Quantity: " << quantityVec[j] << " " << b1->MenuOptions[i] << endl;
                indexOrderedItems.push_back(i);
                break;
                }

            }}

        }
    }

    //Confirm Order- OVERRRIDING FUNCTIONS FROM BUSINESS CLASS. virtual
     bool customerConfirm (Business *b1){

        printOrder(b1);

        cout << "If the order is correct, please select 1, otherwise select 0"<< endl;
        cin >> confirm;

        return confirm;

    }

    //Get the details of the customer
    void IdCustomer () {
    };

    //Getter functions
    vector <string> getOrder () {return order;}
    vector <int> getQuantity (){return quantityVec;}
    bool getCusConfirmation (){return confirm;}
};


//Class Business
class Business: public Customer{

private:
    vector <string> MenuOptions;
    vector <float> PricesMenu;
    vector <int> ItemIndex;
    vector <DeliveryPeople> DeliveryWorkers;
    string nameRestaurant;
    bool availableDelivery;
    bool confirmationOrd;
    int numberDrivers;
    int AssignedDIndex;
    float deliveryPrice;

//check if it should be friend or derived class
    friend class Receipt;
    friend bool confirmationOrd (Business *b1);

public:
Business (string **ArrMenu, int rows, int columns, int deliveryNum,float deliveryfee, string resName){

    availableDelivery=false;
    confirmationOrd=false;
    nameRestaurant=resName;
    numberDrivers=deliveryNum;
    deliveryPrice=deliveryfee;
    AssignedDIndex=-1;
    for (int i=0; i<rows; i++){
        ItemIndex. push_back(i);
        MenuOptions.push_back(ArrMenu[i][0]);
        float floatValue;
    try {
        floatValue = stof(ArrMenu[i][1]); // Convert the string to a float
    } catch (const invalid_argument& e) {
        cerr << "Invalid argument: " << e.what() << endl;
    } catch (const out_of_range& e) {
        cerr << "Out of range: " << e.what() << endl;
    }
        PricesMenu.push_back(floatValue);
    }

    for (int j=0; j<numberDrivers; j++){
        DeliveryPeople newObject;
        DeliveryWorkers.push_back(newObject);
    }

}

//Setter and Getter Functions

vector <int> getItemIndex (){ return ItemIndex;}
vector <string> getMenuOptions(){return MenuOptions;}
vector <float> getPricesMenu (){return PricesMenu;}
string getResName (){return nameRestaurant;}

//Function to print the Menu
void PrintMenu (){
cout<< "Welcome to " << nameRestaurant << "!!" << endl<< endl << endl;
cout << "Menu." << endl;

for (int i=0; i< MenuOptions.size(); i++){
    cout << ItemIndex[i] << "          " << MenuOptions[i] << "          " <<"$" <<PricesMenu[i] << endl;
}
}

//Function to determine availability of Drivers
//Function Overloading
vector <int> DriverAvailable (int a){
//Stablish a try and catch in case the -1 is passed.
//Create a dynamic array that can save the number of drivers that are available. There will be max n number of drivers available. But they can be less, that is why you will 
//use dynamic memory array. Did not use dynamic because vector would be more efficient as it creates the mmeory automatically
vector <int> indexVecAvailable;
    for (int i=0; i<numberDrivers; i++){
       if(DeliveryWorkers[i].getavailability()==true){
        indexVecAvailable.push_back(i);
       }
    }
return indexVecAvailable;
}

bool DriverAvailable (bool a){
    bool available=false;
    for (int i=0; i<numberDrivers; i++){
       if(DeliveryWorkers[i].getavailability()==true){
        available = true;
       }
    }
return available;
}

//Function to determine whether order is accepted or not. CAN LATER USE FUNCTION OVERRIDING
bool OrderConfirmation (){
    bool variableresult=false;
    if (DriverAvailable(true)==true){
        variableresult=true;
    }
return variableresult;
}


//You may need to do function overloading to also obtain a function that gv=ives you the specific distance between a delivery person and a customer to later be able to calculate
//the time that it will take the driver to arrive to the customer's location 
//Assign Driver Function
template <typename U>
DeliveryPeople AssignedDriverInfo (Customer *Example){
    //DEFINE A TRY AND CATCH SO THAT IF THE FUNCTION IS CALLED WHEN THERE ARE NO DRIVERS AVAILABLE THE CODE DOES NOT STOP
    float xdriver;
    float ydriver;
    float xcustomer;
    float ycustomer;
    float intermediate;
    float distance;
    float minDistance=10000000000000;
     // careful with possible compilation problems due to -1 as initial index of the assignedDindex
    
    xcustomer=Example->getCusPosX();
    ycustomer=Example->getCusPosY();

    if (DriverAvailable(true)==true){
        int sizevector= DriverAvailable(1).size();
//FIND THE DISTANCE BETWEEN THE CUSTOMER AND EACH OF THE ELIVERY WORKERS, AND SAVE THE ONE THAT IS THE SMALLEST ONE. ASSIGN THAT DRIVER TO THE CUSTOMER. 
       
       for (int i=0; i<sizevector; i++){
        xdriver=DeliveryWorkers[DriverAvailable(1)[i]].getxpos();
        ydriver=DeliveryWorkers[DriverAvailable(1)[i]]. getypos();

        intermediate= pow(xdriver-xcustomer,2)+pow(ydriver-ycustomer,2);
        distance=sqrt(intermediate);

        if (distance<minDistance){
            AssignedDIndex=DriverAvailable(1)[i];}
       }
    }

    return DeliveryWorkers[AssignedDIndex];

}

float AssignedDriverInfo (Customer *Example, int index){
    //DEFINE A TRY AND CATCH SO THAT IF THE FUNCTION IS CALLED WHEN THERE ARE NO DRIVERS AVAILABLE THE CODE DOES NOT STOP
    float xdriver;
    float ydriver;
    float xcustomer;
    float ycustomer;
    float intermediate;
    float distance;
    //careful comilation problems with a wrong index being passed
    
    xcustomer=Example->getCusPosX();
    ycustomer=Example->getCusPosY();
    xdriver=DeliveryWorkers[index].getxpos();
    ydriver=DeliveryWorkers[index]. getypos();
        //calculate distance
        intermediate= pow(xdriver-xcustomer,2)+pow(ydriver-ycustomer,2);
        distance=sqrt(intermediate);
    return distance;
}

};

// //Receipt of the order
class Receipt: public Customer{
    
    public:
    Receipt (){ };

    //Setter and Getter Functions
        
    //Print the receipt
    void calculateCost (Customer*cus1, Business *b2) const{ 
        float totalPrice=0;

        cus1->PrintIDdata();
       bool confirmed= cus1->customerConfirm(b2);
        if(confirmed==true){

        cout<< "Your receipt is shown below " << endl;

            for(int i=0;i<cus1->indexOrderedItems.size();i++){
               cout<< cus1->quantityVec[i] <<"   "<<b2->MenuOptions[cus1->indexOrderedItems[i]]<< "  " <<  cus1->quantityVec[i]*b2->PricesMenu[cus1->indexOrderedItems[i]];
               totalPrice+=cus1->quantityVec[i]*b2->PricesMenu[cus1->indexOrderedItems[i]];
            }
            cout<<"Your total would be of $" << totalPrice << endl;
        }
        else {
            cout << "Your order was not confirmed. Please try again later"<< endl;
           exit(0);
        }

    }
    
};

int main (){


    return 0;
}