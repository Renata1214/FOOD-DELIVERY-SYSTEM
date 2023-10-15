#include "RECEIPT.h"

using namespace std;

//Constructor
    Receipt::Receipt (){ };

//Setter and Getter Functions
        
//Print the receipt
    void Receipt::calculateCost (Business *b2) const{ 
        float totalPrice=0;

        cout<< "Your receipt is shown below " << endl;
        cout<< "Customer's ID details: " << endl;
        b2->IdCustomerDetails();
        cout<< "Customer's Order: "<< endl;
            for(int i=0;i<b2->indexOrderedItems.size();i++){
               cout<< b2->quantityVec[i] <<"   "<<b2->MenuOptions[b2->indexOrderedItems[i]]<< "  " <<  b2->quantityVec[i]*b2->PricesMenu[b2->indexOrderedItems[i]];
               totalPrice+=b2->quantityVec[i]*b2->PricesMenu[b2->indexOrderedItems[i]];
            }
            cout<< endl;
            cout<<"Your total would be of $" << totalPrice << endl;
            cout<<endl;
    }
    
