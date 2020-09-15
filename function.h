#ifndef FUNCTION_H
#define FUNCTION_H
/*
Author: Jesus Minjares
Assignment 1:  
    Create a program that simulates ordering from a restaurant menu.
    The program should handle single character commands and print out
    the choices made and order total. The user must be able to order as
    many items as desired.
*/
#include <iostream> //cout
#include <fstream> //ofstream 
#include <iomanip> //fixed and setprecision 
using namespace std; //std:: namespace 
//protoype functions 
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
#endif