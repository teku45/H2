#include <Ethernet.h>
#include <EthernetUdp.h>

bool testMode = false;
bool connection = false;
int wirelessCommand = 0;

void setup() {
  PeriodicInit();

}

void loop() {
  PeriodicTasks();

}
