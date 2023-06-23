#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defs.h"


int main()
{
    //Inventory.
   CarInventory* HyundaiInventory = createCarInventory();
   Car* Hyundai001 = createCar("Hyundai", "SONATA", "SPORT", "DarkRed", 2017);
   Car* Hyundai002 = createCar("Hyundai", "SONATA", "SPORT", "White", 2018);
   Car* Hyundai003 = createCar("Hyundai", "SONATA", "SPORT", "White", 2019);
   addCarToInventory(HyundaiInventory, Hyundai001);
   addCarToInventory(HyundaiInventory, Hyundai002);
   addCarToInventory(HyundaiInventory, Hyundai003);


   printCarInventory(HyundaiInventory);
   

}
