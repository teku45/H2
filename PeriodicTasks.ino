#include <Ethernet.h>
#include <EthernetUdp.h>


void PeriodicInit(){
    WirelessInit();
}

void PeriodicTasks(){
    Wireless();

}
