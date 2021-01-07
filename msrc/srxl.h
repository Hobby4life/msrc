#ifndef SRXL_H
#define SRXL_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "escHW3.h"
#include "escHW4.h"
#include "escPWM.h"
#include "escCastle.h"
#include "voltage.h"
#include "ntc.h"
#include "pressure.h"
#include "bmp280.h"
#include "bn220.h"
#include "config.h"
#include "xbus.h"

#if SRXL_VARIANT == SRXL_V1
#define SRXL_FRAMELEN 27
#endif
#if SRXL_VARIANT == SRXL_V2
#define SRXL_FRAMELEN 35
#endif

// not sure if 18 or 19: 1 byte header + 16 bytes payload + 2 bytes crc = 19...?¿
#if SRXL_VARIANT == SRXL_V5
#define SRXL_FRAMELEN 18
#endif

class Srxl : public Xbus
{
private:
    uint8_t list[7] = {0};
    SoftwareSerial srxlSerial = SoftwareSerial(PIN_SMARTPORT_RX, PIN_SMARTPORT_TX);
    uint16_t getCrc(uint8_t *buffer, uint8_t lenght);
    uint16_t byteCrc(uint16_t crc, uint8_t new_byte);

public:
    Srxl();
    void begin();
    void checkSerial();
    void send();
};

#endif