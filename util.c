#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defs.h"

/*
Function util-1
    Adds Car Nodes (Created from Car*) to an inventory (linked List_)
*/
void addCarToInventory(CarInventory* inventory, Car* car)
{
    CarNode* newNode = createCarNode(car);
    if (newNode == NULL)
    {
        printf("Failed to create newNode\n");
        return;
    }  
     //Add the Car to the Inventory.
     if (inventory->head == NULL)
     {
        inventory->head = newNode;
        inventory->tail = newNode;
     }
     else
     {
        inventory->tail->next = newNode;
        newNode->prev = inventory->tail;
        inventory->tail = newNode;
     }    
}

/*
Functiion util-2
    Adds Car Inventories to our Storage (dynamic Array).
    We have a single Storage to work with.
*/
void addInventoryToStorage(Storage** storage, CarInventory* inventory) {
    // Increment the count
    (*storage)->count++;

    // Reallocate the storage to accommodate the additional inventories
    CarInventory** resizedInventory = 
    realloc((*storage)->inventory, sizeof(CarInventory*) * (*storage)->count);

    if (resizedInventory == NULL) {
        printf("ALLOCATION FAILED\n");
        return;
    }

    // Update the storage with the new resized storage
    (*storage)->inventory = resizedInventory;

    // Add the inventory to the storage
    (*storage)->inventory[(*storage)->count - 1] = inventory;
}


void printCarInventory(CarInventory* inventory)
{
    printf("%-15s%-15s%-15s%-15s%-10s\n",
        "BRAND NAME",
        "BRAND MODEL",
        "BRAND TRIM",
        "BRAND COLOR",
        "MKYR"
    );

    CarNode* currNode = inventory->head;
    while (currNode != NULL)
    {
        Car* car = currNode->data;
        GeneralInfo* generalInfo = car->generalInfo;

        printf("%-15s%-15s%-15s%-15s%d\n",
            generalInfo->brandName,
            generalInfo->brandModel,
            generalInfo->trimLevel,
            generalInfo->color,
            generalInfo->makeYear
        );

        currNode = currNode->next;
    }
    printf("\n");
}

void printCarStorage (Storage* storage)
{
    printf("Car Storage:\n\n");
    for (int i = 0; i <storage->count; i++)
    {
        printf("Inventory %d: %s\n", i + 1, storage->inventory[i]->inventoryName);
    }
printf("Note, to print a specific inventory, use The appropriate function.\n ");
}





