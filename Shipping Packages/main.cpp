#include "Address.h"
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
#include <iostream>
#include <vector>
using namespace std;

const double TDP_BASE_PRICE = 20.99; //two-day package base price
const double ONP_BASE_PRICE = 25.00; //overnight package base price
const double RP_BASE_PRICE = 7.50; // regular package base price

int main(){
    
//create an array containing adresses
    string address_array[] = {
        "Hospital address",
        "Library address",
        "Home address",
        "Office address",
        "Amazon address",
        "eBay address",
        "eMag address"
    };

//Create Address Objects
    vector<Address*> v_adresses;
    for (string a : address_array){
        v_adresses.push_back(new Address(a));
    }

//Create Package Objects
    vector<Package*> v_packages;
    cout << "Number of packages: ";
    int num_packs;
    cin >> num_packs;

    for (int i = 0; i < num_packs; i++){

        cout << "Sender, Receiver IDs, and Package type (Regular[0]; Two-Day[1]; Overnight[2])\n";
        cout << "Adress[ID]: ";
        for (size_t i = 0; i < v_adresses.size(); i++)
        {
            cout << v_adresses.at(i)->getAddress() << "[" << i << "] ; ";
        }
        cout << endl;
        int ap[3]; //2 addresses and package type ids
        cin >> ap[0] >> ap[1] >> ap[2];
        cout << "Package weight(kg): ";
        double current_weight;
        cin >> current_weight;
        
        switch (ap[2])
        {
        case 0:
            v_packages.push_back(new Package(*v_adresses.at(ap[0]),*v_adresses.at(ap[1]),RP_BASE_PRICE , current_weight));
            break;
        case 1:
            v_packages.push_back(new TwoDayPackage(*v_adresses.at(ap[0]),*v_adresses.at(ap[1]),TDP_BASE_PRICE , current_weight));
            break;    
        case 2:
            v_packages.push_back(new OvernightPackage(*v_adresses.at(ap[0]),*v_adresses.at(ap[1]),ONP_BASE_PRICE , current_weight));
            break;
        default: return 0;
            break;
        }
    }

    double totalCost = 0;
    for (Package* p : v_packages){
        cout << "--------Package Info--------\n\n";
        cout << "Sender: ";
        p->printSenderAddress();
        cout << "Receiver: ";
        p->printReceiverAddress();
        cout << "BP: "<< p->getBasePrice() << "; Weight: " << p->getWeight() << "; Cost: "<< p->calculateCost() << endl;
        totalCost += p->calculateCost();
        cout << "\n\n";
    }
    cout << "Total cost: " << totalCost << endl;

// delete objects
    for (Package* p : v_packages){
        delete p;
    }      
    for (Address* v : v_adresses){
        delete v;
    }  
    // Address sender("Sender address");
    // Address receiver("Receiver address");
    // Address home("Home address");
    // Address office("Office address");
    // Address Amazon("Amazon address");
    // Address eBay("eBay address");
    // Address eMag("eMag address");

    // Package pack_1(sender, receiver, RP_BASE_PRICE, 10.00);
    // Package pack_2(office, home, RP_BASE_PRICE, 10.00);
    // TwoDayPackage pack_3(Amazon, home, TDP_BASE_PRICE, 10.00);
    // TwoDayPackage pack_4(eBay, office, TDP_BASE_PRICE, 10.00);
    // Package pack_5(eMag, home);
    // pack_5.setBasePrice(RP_BASE_PRICE);
    // pack_5.setWeight(10.00);
    // OvernightPackage pack_6(Amazon, office, ONP_BASE_PRICE, 10.00);
    // OvernightPackage pack_7(eMag, home);
    // pack_7.setBasePrice(ONP_BASE_PRICE);
    // pack_7.setWeight(10.00);

    // vector<Package*> packages;
    // packages.push_back(&pack_1);
    // packages.push_back(&pack_2);
    // packages.push_back(&pack_3);
    // packages.push_back(&pack_4);
    // packages.push_back(&pack_5);
    // packages.push_back(&pack_6);
    // packages.push_back(&pack_7);

    // double totalCost = 0;
    // for (Package* p : packages){
    //     cout << "--------Package Info--------\n";
    //     cout << "Sender: ";
    //     p->printSenderAddress();
    //     cout << "Receiver: ";
    //     p->printReceiverAddress();
    //     cout << "Cost: "<< p->calculateCost() << endl;
    //     totalCost += p->calculateCost();
    // }
    // cout << "Total cost: " << totalCost << endl;

    return 0;
}