#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include "ItemToPurchase.h"
#include <string>
#include <vector>
using namespace std;

class ShoppingCart {
private:
   string customerName = "none";
   string currentDate = "January 1, 2016";
   vector < ItemToPurchase > cartItems;

public:
   
   ShoppingCart();
   
   ShoppingCart(string customerName, string currentDate);
   
   string GetCustomerName();
   
   string GetDate();
   
   void AddItem(ItemToPurchase item);
   
   void RemoveItem(ItemToPurchase item);
   
   void ModifyItem(ItemToPurchase item);
   
   int GetNumItemsInCart();
   
   int GetCostOfCart();
   
   void PrintTotal();
   
   void PrintDescriptions();
   
};

#endif
