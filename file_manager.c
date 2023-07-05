#include "defs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

GeneralInfo* createGeneralInfoFromTokens(char** tokens)
{
    GeneralInfo* generalInfo = (GeneralInfo*)malloc(sizeof(GeneralInfo));
    generalInfo->brandName = strdup(tokens[0]);
    generalInfo->brandModel = strdup(tokens[1]);
    generalInfo->trimLevel = strdup(tokens[2]);
    generalInfo->color = strdup(tokens[3]);
    generalInfo->makeYear = atoi(tokens[4]);
    return generalInfo;
}

MechanicalInfo* createMechanicalInfoFromTokens(char** tokens)
{
    MechanicalInfo* mechanicalInfo = (MechanicalInfo*)malloc(sizeof(MechanicalInfo));
    mechanicalInfo->carSize = strdup(tokens[5]);
    mechanicalInfo->carType = strdup(tokens[6]);
    mechanicalInfo->engineSize = strdup(tokens[7]);
    mechanicalInfo->engineType = strdup(tokens[8]);
    mechanicalInfo->HP = atoi(tokens[9]);
    return mechanicalInfo;
}

CarStatus* createCarStatusFromTokens(char** tokens)
{
    CarStatus* carStatus = (CarStatus*)malloc(sizeof(CarStatus));
    carStatus->status = strdup(tokens[10]);
    carStatus->odo = atoi(tokens[11]);
    carStatus->condition = atoi(tokens[12]);
    carStatus->rentalCustomers = (char**)malloc(sizeof(char*));
    carStatus->rentalCustomers[0] = strdup(tokens[13]);
    return carStatus;
}


void populateInventoryFromCSV(const char* filename, CarInventory* inventory) 
{
    /*
        Open a file to read in csv
        file name is csvfile
        check error handling 
    */
    FILE* csvfile = fopen(filename, "r");
    if (csvfile == NULL) 
    {
        printf("Error Opening the file %s\n", filename);
        
    }

    /*
        Now we have read the file and is in csvfile,
        we can use a char pointer to read each line.
        we need getline()
    */

    char* lineBuffer = NULL;
    size_t linesize = 0;

    getline(&lineBuffer, &linesize, csvfile);
    while (getline(&lineBuffer, &linesize, csvfile) != -1) 
    {
        /*
            Now we need need to store our fields
            separately using the delimeter. 
        */

        char* field[14];
        /*
            allFields now contains the line buffer
        */
        char* allFields = strtok(lineBuffer, ",");
        int fieldIndex = 0;
        while (allFields != NULL && fieldIndex < 14) {
            field[fieldIndex] = allFields;
            allFields = strtok(NULL, ",");
            fieldIndex++;
        }

        // Create the car and add it to the inventory
        GeneralInfo* generalInfo = createGeneralInfoFromTokens(field);
        MechanicalInfo* mechanicalInfo = createMechanicalInfoFromTokens(field);
        CarStatus* carStatus = createCarStatusFromTokens(field);
        Car* car = createCar(generalInfo, mechanicalInfo, carStatus);

        addCarToInventory(inventory, car); // Add the car to the inventory
    }

    free(lineBuffer);
    fclose(csvfile);
}


        