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


void populateInventoryFromData(const char* filename, CarInventory* inventory) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char* line = NULL;
    size_t lineBufferSize = 0;

    getline(&line, &lineBufferSize, file); // Read and discard the first line

    while (getline(&line, &lineBufferSize, file) != -1) {
        line[strcspn(line, "\n")] = '\0'; // Remove trailing newline character

        char* tokens[14];
        char* token = strtok(line, ",");
        int tokenIndex = 0;
        while (token != NULL && tokenIndex < 14) {
            tokens[tokenIndex] = token;
            token = strtok(NULL, ",");
            tokenIndex++;
        }

        GeneralInfo* generalInfo = createGeneralInfoFromTokens(tokens);
        MechanicalInfo* mechanicalInfo = createMechanicalInfoFromTokens(tokens);
        CarStatus* carStatus = createCarStatusFromTokens(tokens);
        Car* car = createCar(generalInfo, mechanicalInfo, carStatus);

        addCarToInventory(inventory, car); // Add the car to the inventory
    }

    free(line);
    fclose(file);
}

