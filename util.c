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
        printf("Inventory %d: %s Inventory\n", i + 1, storage->inventory[i]->inventoryName);
    }
    printf("\n");
}



/*
*/

void printInventoryByCriteria (const CarInventory* inventory, const char* field, const char* value)
{
    printf("Printing Car Inventor- Filtered by\nField: %s\nValue: %s\n\n", field, value);
    printf("%-15s%-15s%-15s%-15s%-10s\n",
        "BRAND NAME",
        "BRAND MODEL",
        "BRAND TRIM",
        "BRAND COLOR",
        "MKYR"
    );

    CarNode* current = inventory->head;
    while (current !=NULL)
    {
        Car* car = current->data;
        
        /*
        Field Matching
        */
        int fieldMatch = 0;

        /*
        General Information
        */

        if ((strcmp (field, "brandName") == 0) && (strcmp(value, car->generalInfo->brandName) == 0))
            fieldMatch = 1;
        else if ((strcmp(field, "brandModel") == 0) && (strcmp(value, car->generalInfo->brandModel) == 0))
            fieldMatch = 1;
        else if ((strcmp(field, "trimLevel") == 0) && (strcmp(value, car->generalInfo->trimLevel) == 0))
            fieldMatch = 1;
        else if ((strcmp(field, "color") == 0) && (strcmp(value, car->generalInfo->color) == 0))
            fieldMatch = 1;
        else if ((strcmp(field, "makeYear") == 0) && (atoi(value) == car->generalInfo->makeYear))
            fieldMatch = 1;
        
        /*
        Mechanical Information, continued
        */
        else if ((strcmp (field, "size") == 0) && (strcmp(value, car->mechanicalInfo->carSize) == 0))
            fieldMatch = 1;
        else if ((strcmp (field, "type") == 0) && (strcmp(value, car->mechanicalInfo->carType) == 0))
            fieldMatch = 1;
        else if ((strcmp (field, "engineSize") == 0) && (strcmp(value, car->mechanicalInfo->engineSize) == 0))
            fieldMatch = 1;
        else if ((strcmp (field, "engineType") == 0) && (strcmp(value, car->mechanicalInfo->engineType) == 0))
            fieldMatch = 1;
        else if ((strcmp(field, "HP") == 0) && (atoi(value) == car->mechanicalInfo->HP)== 0)
            fieldMatch = 1;
        
        /*
        Mechanical Information, continued
        */
        else if ((strcmp(field, "status") == 0) && (strcmp(car->carStatus->status, value) == 0)) 
            fieldMatch = 1;
        else if ((strcmp(field, "odo") == 0) && (atoi(value) == car->carStatus->odo))
            fieldMatch = 1;
        else if ((strcmp(field, "condition") == 0) && (atoi(value) == car->carStatus->condition)) 
            fieldMatch = 1;

        /*
        Printing Based On field Match
        */

        if (fieldMatch) 
        {
            printf("%-15s%-15s%-15s%-15s%d\n",
            car->generalInfo->brandName,
            car->generalInfo->brandModel,
            car->generalInfo->trimLevel,
            car->generalInfo->color,
            car->generalInfo->makeYear);
        }
        current = current->next;
    }
}

