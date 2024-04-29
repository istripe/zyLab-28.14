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
   for (auto it = cartItems.begin() ; it != cartItems.end(); ++it) {
      if (name == it->GetName() ) {
         cartItems.erase(it);
         break;
      }
   }
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
   string name = item.GetName();
   for (auto it = cartItems.begin() ; it != cartItems.end(); ++it) {
      if (name == it->GetName() ) {
         if (item.GetPrice() != 0) {
            it->SetPrice(item.GetPrice());
         }
         if (item.GetQuantity() != 0) {
            it->SetQuantity(item.GetQuantity());
         }
      }
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
   
   // for loop using iterators
   for (auto it = cartItems.begin() ; it != cartItems.end(); ++it) {
      it->PrintItemCost();
   }
   // in general, if you have a pointer or an iterator, (*obj).member == obj->member
   
   cout << endl << "Total: $" << GetCostOfCart() << endl;
}

void ShoppingCart::PrintDescriptions() {
   for (auto it = cartItems.begin() ; it != cartItems.end(); ++it) {
      it->PrintItemDescription();
   }
}
