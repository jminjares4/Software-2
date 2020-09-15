/*
Author: Jesus Minjares
Assignment 1:  
    Create a program that simulates ordering from a restaurant menu.
    The program should handle single character commands and print out
    the choices made and order total. The user must be able to order as
    many items as desired.
*/
#include <iostream> //for cin and cout 
#include <iomanip> //fixed and setprecision 
#include <fstream> //ofstream files  
#include <string.h> //string datatype 
#include "function.h" //userdefine functions 
using namespace std; //std:: namespace

int main(int argc, char* argv[]){
    if(argc < 2){ //check if the user enter the file name 
        cout << "./main fileName" <<endl; //prompt excepted input 
        return 0; //exit program 
    }
    //get char argv[1] and store it into a string to catenate with .txt 
    string result = string(argv[1]);
    ofstream userFile (result + ".txt", ios::trunc ); //open a output file 

    //intialize counter of the each item 
    int amount, burger, fries, salad, hotdog, drink;
    //set the value at 0 
    amount = burger = fries = salad = hotdog = drink = 0;
    //char variable to get and store user decision 
    char userInput;
    double userTotalAmount;  //userTotalAmount will store user current balance 
    printMenu(); //print the menu
    cout << "Please enter letter and amount: "; 
    cin >> userInput; //get user input
    //if the user enter x or e it will exit as they have not order anything
    if(userInput == 'x' || userInput == 'e') cout << "Thank you!" << endl;    
    else{
        cin >> amount; //get the amount of the item 
        while(userInput != 'e'){ //as long as the user do not end the order 
            cout << "You entered: " << userInput << endl;
            //update the items by passreference the variables 
            updateItems(userInput, amount, burger, fries, salad,hotdog, drink);
            //print the current selection of the user 
            printItemsSelected(burger,fries, salad, hotdog, drink);
            //get the user balance 
            userTotalAmount = totalAmount(burger,fries,salad,hotdog, drink);
            //print the user balance with 2 decimal places 
            cout << "TOTAL: $" << fixed << setprecision(2) << userTotalAmount << endl; 
            //print the menu
            printMenu();
            cout << "Please enter letter and amount: ";
            cin >> userInput; //get user input 
            if(userInput == 'x'){ //if the user enter x, then proceed 
                //if the user enter x, they will delete an item 
                cout << "Enter item and how many to remove: ";
                cin >> userInput; //get char 
                cin >> amount; //get amount 
                amount = amount > 0 ? -amount : amount;
            }
            else if(userInput == 'e') break; //end order 
            else cin >> amount; //else get amount of the item 
         }
    }
    //print the balance of the user 
    cout << "TOTAL: $" << fixed << setprecision(2) << userTotalAmount << endl; 
    //write to the file by passing it pass reference 
    writeToFile( userFile, userTotalAmount,  burger, fries, salad, hotdog, drink);
    userFile.close(); //close the file 
   
}