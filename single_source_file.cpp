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
double totalAmount( int , int , int , int , int );
//will print the items based on the counter of each item 
void printItemsSelected(int,int,int,int, int);
//update the items by passreferencing the variables 
void updateItems(char , int , int &, int &, int &, int &, int &);
//print the menu
void printMenu(void);
//write to the file
void writeToFile(ofstream& , double , int , int , int , int , int );
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
void printItemsSelected(int burger, int fries, int salad, int hotdog, int drink){
    //if any of the items if >0, then print the corresponding amount 
    if(burger > 0) cout << "b " << burger << endl;
    if(fries > 0)  cout << "f " << fries << endl;
    if(salad > 0)  cout << "s " << salad << endl;
    if(hotdog > 0) cout << "h " << hotdog << endl;
    if(drink > 0)  cout << "d " << drink << endl;
    return;
}
//update the items value by pass referencing the variables 
void updateItems(char letter, int amount, int &burger, int &fries, int &salad, int &hotdog, int &drink){
    //update the count of the item if exist in the 
    switch(letter){
        case 'b': burger += amount; break;
        case 's': salad += amount; break;
        case 'h': hotdog += amount; break;
        case 'd': drink += amount; break;
        default: break;
    }
    return;
}
//return the balance of the user by multipling the items amounts by its corresponding value 
double totalAmount( int burger, int fries, int salad, int hotdog, int drink){
     return double(burger*1.99) + double(fries*0.99) + double(salad*1.50) + double(hotdog*1.45) + (double)drink*.80;
}
//write to the file 
void writeToFile(ofstream& userFile, double amount, int burger, int fries, int salad, int hotdog, int drink){
    //if any of the items if >0, then print the corresponding amount  to the file
    if(burger > 0) userFile << "b " << burger << endl;
    if(fries > 0)  userFile << "f " << fries << endl;
    if(salad > 0)  userFile << "s " << salad << endl;
    if(hotdog > 0) userFile << "h " << hotdog << endl;
    if(drink > 0)  userFile << "d " << drink << endl;
    userFile << "-------------------------" <<endl;
    userFile << "TOTAL: $" << fixed << setprecision(2) << amount << endl; 
    return;
}