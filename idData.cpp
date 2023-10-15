
//Constructor
        IdData::IdData ( ) {
            xCusPos= 0;
            yCusPos = 0;
            nameCustomer= "-";
            personalID=UniqueNumber;
        UniqueNumber++;
        }

        IdData::IdData (float coordinatex, float coordinatey, string name){
            xCusPos= coordinatex;
            yCusPos = coordinatey;
            nameCustomer= name;
            personalID=UniqueNumber;
            UniqueNumber++;
        }

        //Getter Functions
        float IdData::getCusPosX (){return xCusPos;}
        float IdData::getCusPosY (){return yCusPos;}
        string IdData::getName () {return nameCustomer;}
        int IdData::getIDCus () {return personalID;}

        //Setter Functions
        void IdData::setCusPosX (float x){ xCusPos=x;}
        void IdData::setCusPosY (float y){ yCusPos=y;}
        void IdData::setName (string name) {nameCustomer=name;}

        //print all data
        void IdData::PrintIDdata (){
            cout << "Name of the Customer: " << nameCustomer << endl;
            cout << "Unique ID of the customer: " << personalID << endl;
            cout << "Location of the customer: (" << xCusPos << ", " << yCusPos << ")" << endl;
        }
       
//Definition of Static Variable
        int IdData:: UniqueNumber=0;