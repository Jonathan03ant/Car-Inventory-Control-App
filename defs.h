#include <stdio.h>
#include <string.h>

typedef struct 
{
    char* brandName;
    char* brandModel;
    char* trimLevel;
    char* color;
    int makeYear;
}GeneralInfo;

typedef struct 
{
    char* carSize;
    char* carType; 
    char* engineSize;
    char* engineType;
    int HP;
}MechanicalInfo;

typedef struct 
{
    char* status;
    int odo;
    int condition;
    char** rentalCustomers; 
}CarStatus;

typedef struct {
    GeneralInfo* generalInfo;
    MechanicalInfo* mechanicalInfo;
    CarStatus* carStatus;
} Car;

typedef struct CarNode
{
    Car* data;
    struct CarNode* prev;
    struct CarNode* next;
} CarNode;

typedef struct 
{
    char* inventoryName;
    CarNode* head;
    CarNode* tail;    
} CarInventory;

typedef struct Storage
{
    /*
        Each element in the storage is a pointer to a separate Inventory.
    */
    CarInventory** inventory; 
    int count;
    int cap;
}Storage;

/*
    Initializing Function ProtoTypes
*/

GeneralInfo* createGeneralInfo ();
void freeGeneralInfo(GeneralInfo*);

MechanicalInfo* createMechanicalInfo ();
void freeMechanicalInfo (MechanicalInfo*);

CarStatus* createCarStatus ();
void freeCarStatus(CarStatus*);

Car* createCar(GeneralInfo*, MechanicalInfo*, CarStatus*); 
void freeCar (Car*);

CarNode* createCarNode (Car*);
void freeCarNode(CarNode*);

CarInventory* createCarInventory (const char*);
void freeCarInventory(CarInventory*);

Storage* createCarStorage ();
void freeCarStorage (Storage*);

void addCarToInventory (CarInventory*, Car*);
void addInventoryToStorage (Storage**, CarInventory*);

void printCarInventory(CarInventory*);
void printCarStorage (Storage*);
void printInventoryByCriteria (const CarInventory*, const char*, const char*);

GeneralInfo* createGeneralInfoFromTokens(char**);
MechanicalInfo* createMechanicalInfoFromTokens(char** );
CarStatus* createCarStatusFromTokens(char**);
void populateInventoryFromCSV(const char*, CarInventory*);

