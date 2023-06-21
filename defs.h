#include <stdio.h>
#include <string.h>

typedef struct 
{
    char* brandName;
    char* brandModel;
    char* color;
    char* trimLevel;
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

typedef struct Node
{
    Car* data
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct 
{
    Node* head;
    Node* tail;    
} CarInventory;

/*
    Initializing Function ProtoTypes
*/

GeneralInfo* createGeneralInfo ();
MechanicalInfo* createMechanicalInfo ();
CarStatus* createCarStatus ();
Car* createCar ();
