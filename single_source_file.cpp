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

//protoype functions
//-----------------------------------------------------------------
//return the total balance of the user 
double totalAmount(int item[5] );
//will print the items based on the counter of each item 
void printItemsSelected(int item[5] );
//update the items by passreferencing the variables 
void updateItems(char , int ,int item[5] );
//print the menu
void printMenu(void);
//write to the file
void writeToFile(ofstream& , double ,int item[5]  );
//-------------------------------------------------------------------
int main(int argc, char* argv[]){
    if(argc < 2){ //check if the user enter the file name 
        cout << "./main fileName" <<endl; //prompt excepted input 
        return 0; //exit program 
    }
    //get char argv[1] and store it into a string to catenate with .txt 
    string result = string(argv[1]);
    ofstream userFile (result + ".txt", ios::trunc ); //open a output file 

    //intialize counter of the each item 
    int item[5] = {0}, amount = 0;
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
            updateItems(userInput, amount,item);
            //print the current selection of the user 
            printItemsSelected(item);
            //get the user balance 
            userTotalAmount = totalAmount(item);
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
    writeToFile( userFile, userTotalAmount,item);
    userFile.close(); //close the file 
   
}
void printMenu(){
    //print the menu and how to order 
    cout <<  " ---------------\n"
             "|Burger - $1.99 |\n"
             "|Fries - $0.99  |\n"
             "|Salad - $1.50  |\n"
             "|Hot Dog- $1.45 |\n"
             "|Drink - $0.80  |\n"
             " --------------" << endl;
    cout <<  "----------------\n" 
         << "|b for burger    |\n"
         << "|f for fries     |\n" 
         << "|s for salad     |\n"
         << "|h for hotdog    |\n"
         << "|d for drink     |\n"
         << "|e to end order  |\n"
         << "|x to remove item|\n"
         <<  "----------------" << endl; 
}
//print the items if the items are greater than 0
void printItemsSelected(int item[5]){
    //if any of the items if >0, then print the corresponding amount 
    if(item[0] > 0) cout << "b " << item[0] << endl;
    if(item[1] > 0)  cout << "f " << item[1] << endl;
    if(item[2] > 0)  cout << "s " << item[2] << endl;
    if(item[3] > 0) cout << "h " << item[3] << endl;
    if(item[4] > 0)  cout << "d " << item[4] << endl;
    return;
}
//update the items value by pass referencing the variables 
void updateItems(char letter, int amount, int item[5]){
    //update the count of the item if exist in the 
    switch(letter){
        case 'b': item[0] += amount; break;
        case 'f': item[1] += amount; break;
        case 's': item[2] += amount; break;
        case 'h': item[3] += amount; break;
        case 'd': item[4] += amount; break;
        default: break;
    }
    return;
}
//return the balance of the user by multipling the items amounts by its corresponding value 
double totalAmount(int item[5]){
     return double(item[0]*1.99) + double(item[1]*0.99) + double(item[2]*1.50) + double(item[3]*1.45) + (double)item[4]*.80;
}
//write to the file 
void writeToFile(ofstream& userFile, double amount, int item[5]){
    //if any of the items if >0, then print the corresponding amount  to the file
    if(item[0] > 0) userFile << "b " << item[0] << endl;
    if(item[1] > 0)  userFile << "f " << item[1] << endl;
    if(item[2]> 0)  userFile << "s " << item[2] << endl;
    if(item[3] > 0) userFile << "h " << item[3] << endl;
    if(item[4] > 0)  userFile << "d " << item[4] << endl;
    userFile << "-------------------------" <<endl;
    userFile << "TOTAL: $" << fixed << setprecision(2) << amount << endl; 
    return;
}
