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
    CarNode* head;
    CarNode* tail;    
} CarInventory;

/*
    Initializing Function ProtoTypes
*/

GeneralInfo* createGeneralInfo ();
void freeGeneralInfo(GeneralInfo*);

MechanicalInfo* createMechanicalInfo ();
void freeMechanicalInfo (MechanicalInfo*);

CarStatus* createCarStatus ();
void freeCarStatus(CarStatus*);

Car* createCar(const char*, const char*, const char*, const char*, int);
void freeCar (Car*);

CarNode* createCarNode (Car*);
void freeCarNode(CarNode*);

CarInventory* createCarInventory ();
void freeCarInventory(CarInventory*);

void addCarToInventory (CarInventory*);

void printCarInventory(CarInventory*);
