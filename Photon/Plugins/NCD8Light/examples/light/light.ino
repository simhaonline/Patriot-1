/*******************************************************
NCD 8 Light board Example

This example supports the 1st channel on an NCD 8 PWM board.

http://www.github.com/rlisle/Patriot

Written by Ron Lisle

BSD license, check LICENSE for more information.
All text above must be included in any redistribution.

Changelog:
2020-02-11: Initial creation from modified NCD8Relay
********************************************************/

#include <IoT.h>
#include <PatriotNCD8Light.h>

IoT *iot;

void setup() {
    iot = IoT::getInstance();
    iot->begin();

    byte address = 0x20;
    byte numLights = 8;
    NCDLight *light1 = new NCDLight(address, numLights, 0, "light1");
    iot->addDevice(light1);

    iot->addBehavior(light1, new Behavior("my gadget", '>', 0, 100));    // Turn on
    iot->addBehavior(light1, new Behavior("my gadget", '=', 0, 0));      // Turn off
}

void loop() {
    iot->loop();
}
