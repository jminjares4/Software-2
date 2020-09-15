/*
Author: Jesus Minjares
Assignment 1:  
    Create a program that simulates ordering from a restaurant menu.
    The program should handle single character commands and print out
    the choices made and order total. The user must be able to order as
    many items as desired.
*/
#include "function.h" //userdefine header file 
#include <iomanip> //fixed and setprecision 
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
//return the balance of the user by multipling the items amounts by its
//corresponding value 
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
