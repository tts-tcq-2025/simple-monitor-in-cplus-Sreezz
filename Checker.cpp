#include <assert.h>
#include <iostream>
using namespace std;


#define MIN_TEMPERATURE 0.0;
#define MAX_TEMPERATURE 45.0;
#define MIN_SOC 20.0;
#define MAX_SOC 80.0;
#define MAX_CHARGE_RATE 0.8;

bool isTemperatureOk(float temperature) 
{
  if (temperature < MIN_TEMPERATURE || temperature > MAX_TEMPERATURE) 
  {
    cout << "Temperature out of range!\n";
    return false;
  }
  return true;
}


bool isSocOk(float soc) 
{
  if (soc < MIN_SOC || soc > MAX_SOC) 
  {
    cout << "State of Charge out of range!\n";
    return false;
  }
  return true;
}

bool isChargeRateOk(float chargeRate) 
{
  if (chargeRate > MAX_CHARGE_RATE) 
  {
    cout << "Charge Rate out of range!\n";
    return false;
  }
  return true;
}


bool batteryIsOk(float temperature, float soc, float chargeRate) 
{
  return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}


int main() 
{
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
