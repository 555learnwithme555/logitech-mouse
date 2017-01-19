/*
 Copyright (C) 2017 Ronan Gaillard <ronan.gaillard@live.fr>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
*/

#ifndef LOGITECH_MOUSE
#define LOGITECH_MOUSE

#include "nRF24L01.h"
#include "RF24.h"

#define DEFAULT_CE_PIN 8
#define DEFAULT_CS_PIN 7
#define CHANNEL 5
#define PAYLOAD_SIZE 22
#define PAIRING_MAC_ADDRESS 0xBB0ADCA575LL

class logiMouse
{
  private : 

  RF24 radio;

  void setChecksum(uint8_t *payload, uint8_t len);

  /* Pre-defined pairing packets */
  byte pairing_packet_1[22] = {0x15, 0x5F, 0x01, 0x84, 0x5E, 0x3A, 0xA2, 0x57, 0x08, 0x10, 0x25, 0x04, 0x00, 0x01, 0x47, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xEC};
  byte pairing_packet_1_bis[5] = {0x15, 0x40, 0x01, 0x84, 0x26};
  byte pairing_packet_2[22] = {0x00, 0x5F, 0x02, 0x00, 0x00, 0x00, 0x00, 0x58, 0x8A, 0x51, 0xEA, 0x01, 0x07, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};
  byte pairing_packet_2_bis[5] = {0x00, 0x40, 0x02, 0x01, 0xbd};
  byte pairing_packet_3[22] = {0x00, 0x5F, 0x03, 0x01, 0x00, 0x04, 0x4D, 0x35, 0x31, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB6};
  byte pairing_packet_3_bis[5] = {0x00, 0x5F, 0x03, 0x01, 0x0f};
  byte pairing_packet_4[10] = {0x00, 0x0F, 0x06, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEA};
  /* Enf of pre-defined pairing packets */

  public :

  logiMouse(uint8_t _cepin, uint8_t _cspin);
  logiMouse();

  bool begin();

  void pair();

  void move(uint16_t x_move, uint16_t y_move);
};

#endif