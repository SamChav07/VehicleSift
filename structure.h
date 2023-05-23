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
    char driverName[30];
    char driverLastname[30];
    char id [10];
    char driverStatus[8];
    date assignDate;

}drivers;

typedef struct 
{
    char truckCode[10];
    char truckPlate[30];
    char truckBrand[30];
    int truckYear;
    char vehicleType[30];
    char refr[4];
    drivers driverInfo;

}trucks;

trucks trucksData[MAX];
drivers drivesrsData[MAX];

