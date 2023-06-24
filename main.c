#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defs.h"


int main()
{
    //Inventory.
   CarInventory* HyundaiInventory = createCarInventory("HyundaiInventory");
   Car* Hyundai001 = createCar("Hyundai", "SONATA", "SPORT", "DarkRed", 2017);
   Car* Hyundai002 = createCar("Hyundai", "SONATA", "SPORT", "White", 2018);
   Car* Hyundai003 = createCar("Hyundai", "SONATA", "SPORT", "White", 2019);
   addCarToInventory(HyundaiInventory, Hyundai001);
   addCarToInventory(HyundaiInventory, Hyundai002);
   addCarToInventory(HyundaiInventory, Hyundai003);

   //inventory 2
   CarInventory* HondaInventory = createCarInventory("HondaInventory");
   Car* Honda001 = createCar("Honda", "CIVIC", "SPORT", "DarkRed", 2017);
   Car* Honda002 = createCar("Honda", "CIVIC", "TOURING", "White", 2017);
   Car* Honda003 = createCar("Honda", "ACCORD", "SPORT", "BLUE", 2017);
   addCarToInventory(HondaInventory, Honda001);
   addCarToInventory(HondaInventory, Honda002);
   addCarToInventory(HondaInventory, Honda003);

   

   Storage* storage = createCarStorage();
   addInventoryToStorage(&storage, HyundaiInventory);
   addInventoryToStorage(&storage, HondaInventory);
   printCarInventory(HyundaiInventory);
   printCarInventory(HondaInventory);
   printCarStorage (storage);

   

   freeCarInventory(HyundaiInventory);
   freeCarStorage(storage);

   
    
}
