#define MAX 100

using namespace std;

typedef struct 
{
    int day;
    int month;
    int year;

}date;


typedef struct 
{
    char truckBrand[30];
    int truckYear;
    char refr[2];
    char vehicleType[30];
    int truckCode;
    char truckPlate[30];
    char driver[30];

}trucks;

typedef struct 
{
    
    char driverName[30];
    char driverLastname[30];
    char id [10];
    char driverStatus[8];
    date assignDate;

}drivers;

trucks trucksData[MAX];
drivers drivesrsData[MAX];

