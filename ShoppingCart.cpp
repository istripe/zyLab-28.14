#include <iostream>
using namespace std;

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() { }

ShoppingCart::ShoppingCart(string name, string date) {
   customerName = name;
   currentDate = date;
}
      

string ShoppingCart::GetCustomerName() {
   return customerName;
}

string ShoppingCart::GetDate() {
   return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
   cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(ItemToPurchase item) {
   string name = item.GetName();
   bool exists = false;
   if (cartItems.size() == 0) {
      cout << "Item not found in cart. Nothing removed.";
   }
   else{
      for (auto it = cartItems.begin() ; it != cartItems.end(); ++it) {
         if (name == it->GetName() ) {
            cartItems.erase(it);
            exists = true;
            break;
         }
      }
      if (exists == false) {
         cout << "Item not found in cart. Nothing removed." << endl;
      }
   }
}

void ShoppingCart::ModifyItem(ItemToPurchase item, int num) {
   string name = item.GetName();
   bool exists = false;
   for (auto it = cartItems.begin() ; it != cartItems.end(); ++it) {
      if (name == it->GetName() ) {
         /*if (item.GetPrice() == 0) {
            it->SetPrice(num);
         }*/
         if (item.GetQuantity() == 0) {
            it->SetQuantity(num);
            exists = true;
            cout << "Item quantity changed." << endl;
            break;
         }
      }
   }
   if (exists == false) {
      cout <<"Item not found in cart. Nothing modified." << endl;
   }
}

int ShoppingCart::GetNumItemsInCart() {
   int sum = 0;
   for (auto it = cartItems.begin(); it != cartItems.end(); it++) {
      sum += it->GetQuantity();
   }
   return sum;
}

int ShoppingCart::GetCostOfCart() {
   int sum = 0;
   for (auto it = cartItems.begin(); it != cartItems.end(); it++) {
      sum += it->GetTotal();
   }
   return sum;
}

void ShoppingCart::PrintTotal() {      
   cout << customerName << "'s Shopping Cart - " << currentDate << endl
      << "Number of Items: " << GetNumItemsInCart() << endl << endl;
   
   if (cartItems.empty())
      cout << "SHOPPING CART IS EMPTY" << endl;
   else {
      // for loop using iterators
      for (auto it = cartItems.begin() ; it != cartItems.end(); ++it) {
         it->PrintItemCost();
      }
      // in general, if you have a pointer or an iterator, (*obj).member == obj->member
   }
   
   cout << endl << "Total: $" << GetCostOfCart() << endl;
}

void ShoppingCart::PrintDescriptions() {
   cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
   cout << "Item Descriptions" << endl;
   if (cartItems.empty()) {
      cout << "SHOPPING CART IS EMPTY" << endl;
   }
   else {
      for (auto it = cartItems.begin() ; it != cartItems.end(); ++it) {
         it->PrintItemDescription();
      }  
   }
}
