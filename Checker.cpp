#include <assert.h>
#include <iostream>
using namespace std;


#define MIN_TEMPERATURE 0.0f
#define MAX_TEMPERATURE 45.0f
#define MIN_SOC 20.0f
#define MAX_SOC 80.0f
#define MAX_CHARGE_RATE 0.8f

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
  assert(batteryIsOk(50, 85, 0) == false);   //OOR temp and SOC
  assert(batteryIsOk(0, 20, 0.8) == true); // Low Edge case
  assert(batteryIsOk(45, 80, 0.8) == true); // High Edge case
  assert(batteryIsOk(-1, 70, 0.7) == false); // Low temp
  assert(batteryIsOk(46, 70, 0.7) == false); // High temp
  assert(batteryIsOk(25, 10, 0.7) == false); // Low SOC
  assert(batteryIsOk(25, 90, 0.7) == false); // High SOC
  assert(batteryIsOk(25, 70, 0.9) == false); // High charge rate
  assert(batteryIsOk(-5, 10, 1.0) == false); // All bad
}
