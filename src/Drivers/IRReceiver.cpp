#include "Drivers/IRReceiver.hpp"

bool IRReceiver::begin()
{
    receiver.enableIRIn();

    Serial.println("IR Receiver Ready");

    return true;
}

void IRReceiver::update()
{
    if (!receiver.decode(&results))
        return;

    Serial.println(resultToHumanReadableBasic(&results));

    Serial.println(resultToSourceCode(&results));

    Serial.println("----------------");

    receiver.resume();
}