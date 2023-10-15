#include "RECEIPT.h"

using namespace std;

//Constructor
    Receipt::Receipt (){ };

//Setter and Getter Functions
        
//Print the receipt
    void Receipt::calculateCost (Customer*cus1, Business *b2) const{ 
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
    
