#include "RECEIPT.h"

using namespace std;

//Constructor
    Receipt::Receipt (){ };

//Setter and Getter Functions
        
//Print the receipt
    void Receipt::calculateCost (Business *b2) const{ 
         float totalPrice = 0;
        string TextReceipt;

    TextReceipt += "Your receipt is shown below\n";
    TextReceipt += "Customer's Order:\n";

    for (int i = 0; i < b2->indexOrderedItems.size(); i++) {
        TextReceipt += to_string(b2->quantityVec[i]) + " " + b2->MenuOptions[b2->indexOrderedItems[i]] + " " + to_string(b2->quantityVec[i] * b2->PricesMenu[b2->indexOrderedItems[i]]) + "\n";
        totalPrice += b2->quantityVec[i] * b2->PricesMenu[b2->indexOrderedItems[i]];
    }
    totalPrice+=b2->deliveryPrice;
    string delivery= "Delivery Fee : $" +to_string(b2->deliveryPrice)+"\n";
    TextReceipt +=delivery;

    TextReceipt += "Total cost: $" + to_string(totalPrice);

    b2->Customer::PrintIDdata();
    cout << "\033[31m" << TextReceipt << "\033[0m" << endl;

        string filename = "File.txt";
        ofstream outfile;
        outfile.open(filename);
        outfile << TextReceipt << endl;
        outfile.close();

    // Now, TextReceipt contains the receipt information
}

    
