#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defs.h"

/*
Functiion mctrl1
    Dynamically Allocates Memory for A Car's General Information
    Set the fields to NULL.
*/
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

/*
Functiion mctrl2
    Frees The memory of General Information passed as prm; created by createGeneralInfo())
*/
void freeGeneralInfo(GeneralInfo* info)
{
    if (info ==  NULL)
        return;
    free(info);

}

/*
Functiion mctrl3
    Dynamically Allocates Memory for A Car's Mechanical Information
    Set the fields to NULL.
*/
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
    info->HP = 0;

    return info;
}

/*
Functiion mctrl4
    Frees The memory of Mechanical Information passed as prm; created by createMechanicalInfo()
*/
void freeMechanicalInfo (MechanicalInfo* info)
{
    if (info == NULL)
    {
        return;
        free(info);
    }
}

/*
Functiion mctrl5
    Dynamically Allocates Memory for A Car's Status Information
    Set the fields to NULL.
*/
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

/*
Functiion mctrl6
    Frees The memory of Car Status Information passed as prm; created by createCarStatus()
*/
void freeCarStatus(CarStatus* status)
{
    if (status == NULL)
        return;
    free(status);
}

/*
Functiion mctrl7
    Dynamically Allocates Memory for for the car we are creating.
    it contains fields that point to other DataTypes that are define within the prg.
    N.B. **we also need to allocate memory for those DataTypes
    Set the fields to NULL.
*/
Car* createCar(GeneralInfo* generalInfo, MechanicalInfo* mechanicalInfo, CarStatus* carStatus)
{
    Car* newCar = (Car*)malloc(sizeof(Car));

    if (newCar == NULL)
    {
        printf("ALLOCATION FAILED!!\n");
        return NULL;   
    }

    //Initializing General Info
    newCar->generalInfo = generalInfo;
    newCar->mechanicalInfo = mechanicalInfo;
    newCar->carStatus = carStatus;

    return newCar;
}

/*
Functiion mctrl8
    Frees The memory of Car Data-Type passed as prm; 
    Also free's (Contained by the CAR)
    -GeneralInformation; by freeGeneralInfo ()
    -MechanicalInformation; by freeMechanicalInfo()
    -CarStatus; by freeCarStatus()
*/
void freeCar (Car* car){
    if ( car == NULL)
        return;
    freeGeneralInfo(car->generalInfo);
    freeMechanicalInfo(car->mechanicalInfo);
    freeCarStatus(car->carStatus);
    free(car);
}

/*
Functiion mctrl9
    Dynamically Allocates Memory for individual Car Node.
    points the value of newCarNode to CAR*
    Set the fields to NULL.
*/
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

/*
Functiion mctrl10
    Frees The memory of an Individual CarNode passed as prm; created by createCarStatus()
*/
void freeCarNode(CarNode* node)
{
    if (node == NULL)
        return;
    freeCar(node->data);
    free(node);
    
}

/*
Functiion mctrl11
    Dynamically Allocates Memory for A Car Car Inventory
    N.B. **Put same Brand in one inventory
    Sets the Head and Tail pointers to NULL.
*/
CarInventory* createCarInventory (const char* name)
{
    CarInventory* inventory = (CarInventory*)malloc(sizeof(CarInventory));
    if (inventory == NULL)
    {
        printf("ALLOCATION FAILED!!\n");
        return NULL;   
    }
    
    //Initializing The Inventory
    inventory->inventoryName = strdup(name);
    inventory->head = NULL;
    inventory->tail = NULL;

    return inventory;
}

/*
Functiion mctrl12
    Frees The memory of an Inventory (SameBrandCars) passed as prm; created by createCarStatus()
*/
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
    inventory->head = NULL; // Reset the head pointer to NULL
    inventory->tail = NULL;
    
    
}

/*
Functiion mctrl13
    Dynamically allocates a memory for a Storage which will hold all possible inventories.
    Typically, we will only work with single Storage to manage multiple inventories.
*/
Storage* createCarStorage ()
{
    Storage* newStorage = (Storage*) malloc (sizeof(Storage));
    if (newStorage == NULL)
    {
        printf("ALLOCATION FAILED\n");
        return NULL;
    }
    
    newStorage->inventory = (CarInventory**) malloc (sizeof(CarInventory*));
    if (newStorage->inventory == NULL)
    {
        printf("ALLOCATION FAILED\n");
        free(newStorage);
        return NULL;
    }

    newStorage->count = 0;
    return newStorage;
}

/*
Functiion mctrl13
    Frees The memory of a car Storage which contains Car Inventories
    Car Inventories holds car Instances. 
*/
void freeCarStorage(Storage* storage) {
    if (storage == NULL)
        return;

    for (int i = 0; i < storage->count; i++) 
    {
        freeCarInventory(storage->inventory[i]);
    }

    free(storage->inventory);
    free(storage);
}
