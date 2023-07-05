#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defs.h"


int main()
{
    Storage* storage = createCarStorage();
    CarInventory* inventory = createCarInventory("Main Inventory");

    populateInventoryFromCSV("cars.csv", inventory); // Populate the cars from the CSV file

    addInventoryToStorage(&storage, inventory); // Add the inventory to the storage

    printCarStorage(storage); 
    //
    
    printInventoryByCriteria(inventory, "color", "Blue");
    printInventoryByCriteria(inventory, "type", "ECO");
    printInventoryByCriteria(inventory, "makeYear", "2021");

    freeCarStorage(storage);
    freeCarInventory(inventory);
    return 0;
}

   
    

