#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defs.h"


int main()
{
  
    Storage* storage = createCarStorage();
    CarInventory* inventory = createCarInventory("Main Inventory");

    populateInventoryFromData("cars.csv", inventory); // Populate the cars from the CSV file

    addInventoryToStorage(&storage, inventory); // Add the inventory to the storage

    printCarStorage(storage); 
    printCarInventory(inventory);

    return 0;
}

   
    

