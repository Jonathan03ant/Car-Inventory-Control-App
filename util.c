#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defs.h"


void addCarToInventory(CarInventory* inventory, Car* car)
{
    CarNode* newNode = createCarNode(car);
    if (newNode == NULL)
    {
        printf("Failed to create newNode\n");
        return;
    }
    
     //Add the Car to the Inventory
     if (inventory->head == NULL)
     {
        inventory->head = newNode;
        inventory->tail = newNode;
     }
     else
     {
        newNode->prev = inventory->tail;
        inventory->tail->next = newNode;
        inventory->tail = newNode;
     }
    
    
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


}




