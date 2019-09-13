/*
 *        File: invoice.cc
 *      Author: Easton Scowden
 *        Date: 09/11/2019
 * Description: This program creates an invoice for someone buying hard drives from a store.
 *              
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[]) {
    /// creating variables for program 
    char hardDriveType ; 
    string ohioResident ; 
    int quantity ; 
    int totalPrice ;
    double seagatePrice = 95 ;
    double digitalPrice = 90 ;
    double discount ; 
    double subtotal ; 
    double taxes ; 

    cout << "Enter a hard drive type (w, s) followed by a quantity: " ; 
    cin >> hardDriveType >> quantity ;

    ///declaring variable totalPrice 
    if (hardDriveType == 'w') {
        totalPrice = quantity * digitalPrice ; 
    } else {
        totalPrice = quantity * seagatePrice ; 
    }

    cout << "Are you a resident of Ohio (yes or no): " ;
    cin >> ohioResident ; 
    cout << endl ; 
    
    /// 5% discount if quantity>=5,  7% tax to price if ohioResident="yes"
    
    ///setting deciaml to two places for every number printed 
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    /// This returns first part of invoice 
    if (hardDriveType == 'w'){
        cout << "Hard Drives Invoice" << endl; 
        cout << "------------------------------ " << endl; 
        cout << "Drive Brand: Western Digital" << endl; 
        cout << setw(17) << "Quantity: " << quantity << endl; 
        cout << setw(17) << "Price: $" << digitalPrice << endl;
        cout << setw(17) << "Ohio Resident: " << ohioResident << endl; 
        cout << setw(17) << "Total Price: $" << totalPrice << endl;
        cout << "------------------------------ " << endl;
     } else { 
        cout << "Hard Drives Invoice" << endl; 
        cout << "------------------------------ " << endl;
        cout << "Drive Brand: Seagate" << endl; 
        cout << setw(17) << "Quantity: " << quantity << endl; 
        cout << setw(17) << "Price: $" << seagatePrice << endl;
        cout << setw(17) << "Ohio Resident: " << ohioResident << endl; 
        cout << setw(17) << "Total Price: $" << totalPrice << endl; 
        cout << "------------------------------ " << endl;
     }
    
    /// applies 5% discount if the quantity bought is equal to or greater than five and prints subtotal
    if (quantity >= 5){
        discount = totalPrice * .05 ; 
        cout << setw(17) << "Discount: $" << discount << endl;
        subtotal = totalPrice - discount ;
        cout << setw(17) << "Subtotal: $" << subtotal << endl; 
        
    } else {
        cout << setw(17) << "Discount: $0.00" << endl; 
        subtotal = totalPrice ; 
        cout << setw(17) << "Subtotal: $" << subtotal << endl; 
    }

    /// determines if subtotal should be taxed or not and then prints the line taxes and prints final total line by adding the subtotal and taxes together 
    if (ohioResident == "yes") {
        taxes = subtotal * .07 ; 
        cout << setw(17) << "Taxes: $" << taxes << endl;
        cout << "===============================" << endl;
        cout << setw(17) << "Total: $" << subtotal + taxes << endl; 
        cout << "===============================" << endl;
    } else {
        taxes = 0.0 ; 
        cout << setw(17) << "Taxes: $" << taxes << endl; 
        cout << "===============================" << endl;
        cout << setw(17) << "Total: $" << subtotal + taxes << endl; 
        cout << "===============================" << endl;
    }
    return 0;
}