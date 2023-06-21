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
        printf("ALLOCATION FAILED!!\n");`   jk49i]
        
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
MechanicalInfo createMechanicalInfo()
{
    MechanicalInfo* info = (MechanicalInfo*)malloc(sizeof(MechanicalInfo));

    if (info == NULL)
    {
        printf("ALLOCATION FAILED!!\n");
        return NULL;   
    }

    //Initializing The Fields
    info->carSize = NULL;
    info->carType = NULL;
    info->engineSize = NULL;
    info->engineType = NULL;

    return info;
}

//Function 3))
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

//Function 4))
Car* createCar()
{
    Car* newCar = (Car*)malloc(sizeof(Car));

    if (newCar == NULL)
    {
        printf("ALLOCATION FAILED!!\n");
        return NULL;   
    }

    //Initializing The fields
    newCar->generalInfo = createGeneralInfo();
    newCar->mechanicalInfo = createMechanicalInfo();
    newCar->carStatus = createCarStatus();

    return newCar;
}



