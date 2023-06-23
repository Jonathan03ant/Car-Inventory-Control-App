#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defs.h"

//Functiion 1))
GeneralInfo* createGeneralInfo()
{
    GeneralInfo* info = (GeneralInfo*)malloc(sizeof(GeneralInfo));

    if (info == NULL)
    {
        printf("ALLOCATION FAILED!!\n");
        
        return NULL;
    }

    //Initializing The Fields
    info->brandName = NULL;
    info->brandModel = NULL;
    info->color = NULL;
    info->trimLevel = NULL;
    info->makeYear = 0;

    return info;
    
}

//Function 2))
void freeGeneralInfo(GeneralInfo* info)
{
    if (info ==  NULL)
        return;
    free(info);

}

//Function 3))
MechanicalInfo* createMechanicalInfo()
{
    MechanicalInfo* info = (MechanicalInfo*)malloc(sizeof(MechanicalInfo));

    if (info == NULL)
    {
        printf("ALLOCATION FAILED!!\n");
    }

    //Initializing The Fields
    info->carSize = NULL;
    info->carType = NULL;
    info->engineSize = NULL;
    info->engineType = NULL;

    return info;
}

//Function 4))
void freeMechanicalInfo (MechanicalInfo* info)
{
    if (info == NULL)
        return;
    free(info);
}

//Function 5))
CarStatus* createCarStatus()
{
    CarStatus* status = (CarStatus*)malloc(sizeof(CarStatus));

    if (status == NULL)
    {
        printf("ALLOCATION FAILED!!\n");
        return NULL;   
    }

    //Initializing The fields
    status->status = NULL;
    status->odo = 0;
    status->condition = 0;
    status->rentalCustomers = NULL;

    return status;
}

//Function 6))
void freeCarStatus(CarStatus* status)
{
    if (status != NULL)
        return;
    free(status);
}

//Function 7))
Car* createCar(const char* brndnm, const char* brndmdl, 
const char* trmlvl, const char* clr, int mkyr)
{
    Car* newCar = (Car*)malloc(sizeof(Car));

    if (newCar == NULL)
    {
        printf("ALLOCATION FAILED!!\n");
        return NULL;   
    }

    //Initializing General Info
    newCar->generalInfo = createGeneralInfo();
    newCar->generalInfo->brandName = strdup(brndnm);
    newCar->generalInfo->brandModel = strdup(brndmdl);
    newCar->generalInfo->trimLevel = strdup(trmlvl);
    newCar->generalInfo->color = strdup(clr);
    newCar->generalInfo->makeYear = mkyr;


    newCar->mechanicalInfo = createMechanicalInfo();
    newCar->carStatus = createCarStatus();

    return newCar;
}

//Function 8))
void freeCar (Car* car){
    if ( car == NULL)
        return;
    freeGeneralInfo(car->generalInfo);
    freeMechanicalInfo(car->mechanicalInfo);
    freeCarStatus(car->carStatus);
    free(car);
}

//Function 9))
CarNode* createCarNode (Car* car)
{
    CarNode* newCarNode = (CarNode*)malloc(sizeof(CarNode));
    if (newCarNode == NULL)
    {
        printf("ALLOCATION FAILED!!\n");
        return NULL;   
    }

    //Initializing New Car Node
    newCarNode->data = car;
    newCarNode->prev = NULL;
    newCarNode->next = NULL;

    return newCarNode;
}

//Function 10))
void freeCarNode(CarNode* node)
{
    if (node == NULL)
        return;
    freeCar(node->data);
    free(node);
    
}

//Function 11))
CarInventory* createCarInventory ()
{
    CarInventory* inventory = (CarInventory*)malloc(sizeof(CarInventory));
    if (inventory == NULL)
    {
        printf("ALLOCATION FAILED!!\n");
        return NULL;   
    }
    
    //Initializing The Inventory
    inventory->head = NULL;
    inventory->tail = NULL;

    return inventory;

}

//Function 12)).
void freeCarInventory(CarInventory* inventory)
{
    if (inventory == NULL)
        return;
    CarNode* currNode = inventory->head;
    while (currNode != NULL)
    {
        CarNode* nextNode = currNode->next;
        freeCarNode(currNode);
        currNode = nextNode;
    }
    free(inventory);
}