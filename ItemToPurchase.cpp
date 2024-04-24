#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

/* Type your code here */
   
   ItemToPurchase::ItemToPurchase() {
   }

   ItemToPurchase::ItemToPurchase(string itemName) {
      name = itemName;
      // description is uninitialized??
      price = 0;
      quantity = 0;
   }
   
   //new, extended constructor implementation
   ItemToPurchase::ItemToPurchase(string itemName, string itemDescription, int itemPrice = 0, int itemQuantity = 0) {
      name = itemName;
      description = itemDescription;
      price = itemPrice;
      quantity = itemQuantity;
   }
   
   void ItemToPurchase::SetName(string itemName) {
      name = itemName;
   }
   
   string ItemToPurchase::GetName() {
      return name;
   }

   void ItemToPurchase::SetDescription(string itemDescription) {
      description = itemDescription;
   }
   
   string ItemToPurchase::GetDescription() {
      return description;
   }
   
   
   void ItemToPurchase::SetPrice(int itemPrice) {
      price = itemPrice;
   }
   
   int ItemToPurchase::GetPrice() {
      return price;
   }
   
   void ItemToPurchase::SetQuantity(int itemQuantity) {
      quantity = itemQuantity;
   }
   
   int ItemToPurchase::GetQuantity() {
      return quantity;
   }
   
   void ItemToPurchase::SetTotal(int itemTotal) {
      total = itemTotal;
   }
   
   int ItemToPurchase::GetTotal() {
      return total;
   }
   
   void ItemToPurchase::PrintItemCost() {
      SetTotal(price*quantity);
      cout << name << " " << quantity <<  " @ $" << price << " = $" << total << endl;
   }
   
   void ItemToPurchase::PrintItemDescription() {
      cout << name << ": " << description << endl;
   }
