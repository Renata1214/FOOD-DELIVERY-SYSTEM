#include "CUSTOMER.h"
#include "BUSINESS.h"

using namespace std;

//Constructor
    Customer::Customer (){
        confirm=false;
        quantity=0;}

//Order Food
    void Customer::OrderFood (){
        int errorselection=-1;
        int ExtraproductDecision=-1;
    do{
        errorselection=-1;
    do{
        cout << "From the options shown in the Menu above, which one would you like to order?"<<
        "Please write exactly as shown or write the number shown on the left column corresponding to the item you would like to order" << endl;
        cin >> item;
        cout << "How many would you like to order"<< endl;
        cin>> quantity;
        if (quantity<=0){
            do{
            cout<<"That is an invalid order, please try ordering again. Select 1 to return to item selection, and 0 to end the program"<< endl;
            cin>>errorselection;
                    if(errorselection==0){
                        exit(0);
                    }
                    }while(errorselection!=1);  
        }
        else if(errorselection!=1){
            order.push_back(item);
            quantityVec.push_back(quantity);
            cout << "Would you like to order something else? (1 (for yes), 0 (for no))"<< endl;
            cin>> ExtraproductDecision;}
            }while (ExtraproductDecision!=0&&errorselection!=1);

        if(errorselection!=1){
        cout<< "Your Order has been recorded!!!" << endl;}

    }while (errorselection==1);
    }

//Print Order
    void Customer::printOrder (Business *b1){

        cout << "\033[32m"; // Set text color to green (32)
        cout << "The recorded order is shown below: " << endl;

        for (int j = 0; j < order.size(); j++) {
            for (int i = 0; i < b1->getMenuOptions().size(); i++) {
                if (order[j] == b1->getMenuOptions()[i]) {
                    cout << "Quantity: " << quantityVec[j] << " " << b1->getMenuOptions()[i] << endl;
                    indexOrderedItems.push_back(i);
                    break;
                }
            }
        }
        cout << "\033[0m"; // Reset to default color
    }

//Confirm Order- OVERRRIDING FUNCTIONS FROM BUSINESS CLASS. virtual
     bool Customer::customerConfirm (Business *b1){
        printOrder(b1);
        cout<< endl;
        cout << "If the order is correct, please select 1, otherwise select 0"<< endl;
        cin >> confirm;
        return confirm;}

//Get the details of the customer
    void Customer::PrintIDdata () {
        cout << "\033[31m"; // Set text color to red (31)
        cout << "Customer's ID details recorded to process the order can be found below: " << endl;
        cout << "\033[0m";
        IdData::PrintIDdata(); 
        cout << "Note that your personal information will remain confidential " << endl;
    }




