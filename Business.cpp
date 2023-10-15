 #include "BUSINESS.h"

 using namespace std;


//Constructor 
        Business::Business (string **ArrMenu, int rows, int columns, int deliveryNum,float deliveryfee, string resName){

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
        vector <int> Business::getItemIndex (){ return ItemIndex;}
        vector <string> Business::getMenuOptions(){return MenuOptions;}
        vector <float> Business::getPricesMenu (){return PricesMenu;}
        string Business::getResName (){return nameRestaurant;}

//Function to print the Menu
        void Business::PrintMenu (){
        cout<< "Welcome to " << nameRestaurant << "!!" << endl<< endl << endl;
        cout << "Menu." << endl;
        for (int i=0; i< MenuOptions.size(); i++){
            cout << ItemIndex[i] << "          " << MenuOptions[i] << "          " <<"$" <<PricesMenu[i] << endl;
        }
        }

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


//Information about the driver assigned to the customer: OBJECT
        //You may need to do function overloading to also obtain a function that gv=ives you the specific distance between a delivery person and a customer to later be able to calculate
        //the time that it will take the driver to arrive to the customer's location 
        //Assign Driver Function
        // template <typename U>
        DeliveryPeople Business::AssignedDriverInfo (Customer *Example){
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

//Information about the driver assigned to the customer: DISTANCE
        float Business::AssignedDriverInfo (Customer *Example, int index){
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
