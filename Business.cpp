 #include "BUSINESS.h"

 using namespace std;


//Constructor 
        Business::Business (string ArrMenu[][2], int rows, int columns, int deliveryNum,float deliveryfee, string resName){

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

//Function to print the Menu

//Function to determine availability of Drivers
        //Function Overloading
        vector <int> Business::DriverAvailable (int a){
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

//Function to determine whether there is any driver available
        bool Business::DriverAvailable (bool a){
            bool available=false;
            for (int i=0; i<numberDrivers; i++){
            if(DeliveryWorkers[i].getavailability()==true){
                available = true;
            }
            }
        return available;
        }

//Function to determine whether order is accepted or not. CAN LATER USE FUNCTION OVERRIDING
        bool Business::OrderConfirmation (){
            bool variableresult=false;
            if (DriverAvailable(true)==true){
                variableresult=true;
            }
        return variableresult;
        }
        
//Function to access the position of the customer (object that is automatically created when an object of business is created)        

//Information about the driver assigned to the customer: OBJECT
        //You may need to do function overloading to also obtain a function that gv=ives you the specific distance between a delivery person and a customer to later be able to calculate
        //the time that it will take the driver to arrive to the customer's location 
        //Assign Driver Function
        // template <typename U>
        DeliveryPeople Business::AssignedDriverInfo (){
            //DEFINE A TRY AND CATCH SO THAT IF THE FUNCTION IS CALLED WHEN THERE ARE NO DRIVERS AVAILABLE THE CODE DOES NOT STOP
            float xdriver;
            float ydriver;
            float xcustomer;
            float ycustomer;
            float intermediate;
            float distance;
            float minDistance=10000000000000;
            // careful with possible compilation problems due to -1 as initial index of the assignedDindex
            
            xcustomer=getCustomerPositionX();
            ycustomer=getCustomerPositionY();

            if (DriverAvailable(true)==true){
                int sizevector= DriverAvailable(1).size();
        //FIND THE DISTANCE BETWEEN THE DELIVERY WORKERS AND THE RESTAURANT
            
            for (int i=0; i<sizevector; i++){
                xdriver=DeliveryWorkers[DriverAvailable(1)[i]].getxpos();
                ydriver=DeliveryWorkers[DriverAvailable(1)[i]]. getypos();

                intermediate= pow(xdriver-0,2)+pow(ydriver-0,2);
                distance=sqrt(intermediate);

                if (distance<minDistance){
                    AssignedDIndex=DriverAvailable(1)[i];}
            }
            }

            return DeliveryWorkers[AssignedDIndex];

        }

//Information about the driver assigned to the customer: DISTANCE
        float Business::AssignedDriverInfo (int index){
            //DEFINE A TRY AND CATCH SO THAT IF THE FUNCTION IS CALLED WHEN THERE ARE NO DRIVERS AVAILABLE THE CODE DOES NOT STOP
            float xdriver;
            float ydriver;
            float xcustomer;
            float ycustomer;
            float intermediate1;
            float intermediate2;
            float distance1;
            float distance2;
            //careful comilation problems with a wrong index being passed
            
            xcustomer=getCustomerPositionX();
            ycustomer=getCustomerPositionY();
            xdriver=DeliveryWorkers[index].getxpos();
            ydriver=DeliveryWorkers[index]. getypos();

            //calculate the distance of the delivery person from the resturant
            intermediate1=pow(0-xdriver,2)+pow(0-ydriver,2);
            distance1=sqrt(intermediate1);
                //calculate distance of the customer from the restaurant 
                intermediate2= pow(0-xcustomer,2)+pow(0-ycustomer,2);
                distance2=sqrt(intermediate2);
            return distance1+distance2;
        }

        void Business:: AssignDriverToCustomer () {
            AssignedDriverInfo().setavailability(false);
            cout<<" A driver has been assigned your order!" << endl;
            cout<< "Their Unique ID is " << DeliveryWorkers[AssignedDIndex].getID()<< endl;
            cout<< "The distance of the driver from you is of " << AssignedDriverInfo(AssignedDIndex) << " meters. Hence, the delivery time will take around " << AssignedDriverInfo(AssignedDIndex)/250 << " minutes (Assuming a velocity of 15km per hour)"<< endl; 
        }

        float Business:: getdriverslocation (){
            return DeliveryWorkers[AssignedDIndex].getxpos();
        }
