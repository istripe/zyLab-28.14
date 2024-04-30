#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

/* Type your code here */
class ItemToPurchase {
private:
   string name;
   string description;
   int price;
   int quantity;
   
public:
   ItemToPurchase();
   
   ItemToPurchase(string name);
   
   // new, extended constructor
   ItemToPurchase(string name, string description, int price, int quantity);
   
   void SetName(string name);
   
   string GetName();
   
   void SetDescription(string description);
   
   string GetDescription();
   
   void SetPrice(int price);
   
   int GetPrice();
   
   void SetQuantity(int quantity);
   
   int GetQuantity();
   
   int GetTotal();
   
   void PrintItemCost();
   
   void PrintItemDescription();

};

#endif
