/* 
Purdue - UPV Hyperloop 2 Flight Code
Author: Sidd Subramanyam
Periodic Tasks Process -> Wireless
Description:
Handles wireless communication between Pod and the GUI through SpaceX's NAP wireless tube network
*/

#include <Ethernet.h>
#include <EthernetUdp.h>

//Wireless Networking global Variables
extern int wirelessCommand;
extern bool connection;
extern byte teensyMac[];
extern unsigned int teensyPort;
extern IPAddress teensyIP(192, 168, 0, 9);
extern unsigned int computerPort;
extern const char *computerIP;

void WirelessInit(){

    EthernetUDP Udp;
    char packetBuffer[1];
    Ethernet.begin(teensyMAC, teensyIP);
    Udp.begin(teensyPort);
    Serial.println("Wireless Initialized");

}

void Wireless(){

    int packetSize = Udp.parsePacket();

    //Check for UDP message 
    if (packetSize) { 
        Serial.print("Packet Received: ");
        connection = true;
        lastCommunicationTime = millis();
        Udp.read(packetBuffer, 1);

        //Switch through message to send a particular command
        switch (packetBuffer[0]){
            case 0:
                //Set Pod State variables or commands to true here
                Serial.println("Brake Command"); //Always include a print to indicate which command was logged
                break;
            case 1:
                break;
            case 2:
                break;
            default:
                //Don't set anything in the default case
        }

    }
    //Check for connection based on our time threshhold
    else if (millis() - lastCommunicationTime >= timeOutThreshold) {
        connection = false;
    }

}
