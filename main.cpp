#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

void PrintMenu() {
   cout << "MENU" << endl
      << "a - Add item to cart" << endl
      << "d - Remove item from cart" << endl
      << "c - Change item quantity" << endl
      << "i - Output items' descriptions" << endl
      << "o - Output shopping cart" << endl
      << "q - Quit" << endl << endl;
}

bool ExecuteMenu(char option, ShoppingCart& theCart) {
   switch (option) {
      case 'a': {
         //Add item to cart
         cout << "ADD ITEM TO CART" << endl;
         cout << "Enter the item name:" << endl;
         string name;
         getline(cin, name);
         
         cout << "Enter the item description:" << endl;
         string description;
         getline(cin, description);
         
         cout << "Enter the item price:" << endl;
         int price;
         cin >> price;
         
         cout << "Enter the item quantity:" << endl;
         int quantity;
         cin >> quantity;
         
         // Creating a new item and adding it to cart
         ItemToPurchase newItem(name, description, price, quantity);
         theCart.AddItem(newItem);
         break;
      }
      
      case 'd': {
         //Remove item from cart
         cout << "REMOVE ITEM FROM CART" << endl;
         cout << "Enter name of item to remove:" << endl;
         string itemName;
         getline(cin, itemName);
         theCart.RemoveItem(itemName);
         break;
      }
      
      case 'c': {
         //Change item quantity
         cout << "CHANGE ITEM QUANTITY" << endl;
         cout << "Enter the item name:" << endl;
         string itemName;
         getline(cin, itemName);
         cout << "Enter the new quantity:" << endl;
         int newQuantity;
         cin >> newQuantity;
         theCart.ModifyItem(itemName, newQuantity);
         break;
      }
      
      case 'i': {
         //Output items' descriptions
         cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;

         theCart.PrintDescriptions();
         break;
      }

      case 'o': {
         //Output shopping cart
         cout << "OUTPUT SHOPPING CART" << endl;
         theCart.PrintTotal();
         break;
      }
      
      case 'q': {
         //Quit
         exit(0);
      default:
         return false;
      }
   }
   return true;
}

int main() {
   string mainname;
   string maindate;
   cout << "Enter customer's name:" << endl;
   getline(cin,mainname);
   cout << "Enter today's date:" << endl;
   getline(cin,maindate);
   
   ShoppingCart maincart(mainname,maindate);
   
   cout << endl << "Customer name: " << maincart.GetCustomerName() << endl;
   cout << "Today's date: " << maincart.GetDate() << endl << endl;
   
   PrintMenu();
   while (true) {
      cout << "Choose an option:" << endl;
      char mainoption;
      cin >> mainoption;
      cin.ignore();
      if (ExecuteMenu(mainoption, maincart)) {// if command is executed successfully
         cout << endl;
         PrintMenu(); // print the next menu
      }
   }
   
   return 0;
}