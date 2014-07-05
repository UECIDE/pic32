/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 * 
 */

//* Edit History
//*  Aug  3,  2011 <Lowell Scott Hanson> ported toh chipKIT boards
//*  Sept 13, 2011	<Gene Apperson> change SPI clock divider from DIV8 to DIV32

#include <stdio.h>
#include <string.h>

//#include <avr/interrupt.h>
#include "w5100.h"
#include "WProgram.h"
// W5100 controller instance
W5100Class W5100;

#define TX_RX_MAX_BUF_SIZE 2048
#define TX_BUF 0x1100
#define RX_BUF (TX_BUF + TX_RX_MAX_BUF_SIZE)

#define TXBUF_BASE 0x4000
#define RXBUF_BASE 0x6000

void W5100Class::init(void)
{
  delay(300);
  

  SPI.begin();
  //Set the SPI clock speed to 2.5Mhz. Setting it to 5Mhz (DIV16) may
  //work for some hardware configurations.
  SPI.setClockDivider(SPI_CLOCK_DIV32);
  //The W5100 chip operates in SPI mode 0. Early versions of the chipKIT
  //SPI library (prior to 20110907) set the modes incorrectly. To work
  //with those early versions use SPI_MODE1.
  SPI.setDataMode(SPI_MODE0);

  initSS();
  writeMR(1<<RST);
  writeTMSR(0x55);
  writeRMSR(0x55);

  for (int i=0; i<MAX_SOCK_NUM; i++) {
    SBASE[i] = TXBUF_BASE + SSIZE * i;
    RBASE[i] = RXBUF_BASE + RSIZE * i;
  }
}

uint16_t W5100Class::getTXFreeSize(SOCKET s)
{
  uint16_t val=0, val1=0;
  do {
    val1 = readSnTX_FSR(s);
    if (val1 != 0)
      val = readSnTX_FSR(s);
  } 
  while (val != val1);
  return val;
}

uint16_t W5100Class::getRXReceivedSize(SOCKET s)
{
  uint16_t val=0,val1=0;
  do {
    val1 = readSnRX_RSR(s);
    if (val1 != 0)
      val = readSnRX_RSR(s);
  } 
  while (val != val1);
  return val;
}


void W5100Class::send_data_processing(SOCKET s, uint8_t *data, uint16_t len)
{
  uint16_t ptr = readSnTX_WR(s);
  uint16_t offset = ptr & SMASK;
  uint16_t dstAddr = offset + SBASE[s];

digitalWrite(13,HIGH);

  if (offset + len > SSIZE) 
  {
    // Wrap around circular buffer
    uint16_t size = SSIZE - offset;
    write(dstAddr, data, size);
    write(SBASE[s], data + size, len - size);
  } 
  else {
    write(dstAddr, data, len);
  }

  ptr += len;
  writeSnTX_WR(s, ptr);
}


void W5100Class::recv_data_processing(SOCKET s, uint8_t *data, uint16_t len, uint8_t peek)
{
  uint16_t ptr;
  ptr = readSnRX_RD(s);
  digitalWrite(13,LOW);
/* removed unint8_t pointer cast in read_data due to pic32 pointer values are 32 bit and compiler errors out due to data loss from cast to 16-bit int -LSH */
read_data(s, ptr, data, len);
  if (!peek)
  {
    ptr += len;
    writeSnRX_RD(s, ptr);
  }
}

/* removed unint8_t pointer cast in read_data due to pic32 pointer values are 32 bit and compiler errors out due to data loss from cast to 16-bit int -LSH */
void W5100Class::read_data(SOCKET s,  uint16_t src, volatile uint8_t *dst, uint16_t len)
{
  uint16_t size;
  uint16_t src_mask;
  uint16_t src_ptr;

  src_mask = src & RMASK;  
  src_ptr = RBASE[s] + src_mask;

  if( (src_mask + len) > RSIZE ) 
  {
    size = RSIZE - src_mask;
    read(src_ptr, (uint8_t *)dst, size);
    dst += size;
    read(RBASE[s], (uint8_t *) dst, len - size);
  } 
  else
    read(src_ptr, (uint8_t *) dst, len);
}


uint8_t W5100Class::write(uint16_t _addr, uint8_t _data)
{

  setSS();  
  SPI.transfer(0xF0);
  SPI.transfer(_addr >> 8);
  SPI.transfer(_addr & 0xFF);
  SPI.transfer(_data);
    
  resetSS();
  return 1;
}

uint16_t W5100Class::write(uint16_t _addr, uint8_t *_buf, uint16_t _len)
{
  for (uint16_t i=0; i<_len; i++)
  {
    setSS();    
    SPI.transfer(0xF0);
    SPI.transfer(_addr >> 8);
    SPI.transfer(_addr & 0xFF);
    _addr++;
    SPI.transfer(_buf[i]);
   
	resetSS();
  }
  return _len;
}

uint8_t W5100Class::read(uint16_t _addr)
{
  setSS();  
  SPI.transfer(0x0F);
  SPI.transfer(_addr >> 8);
  SPI.transfer(_addr & 0xFF);
  uint8_t _data = SPI.transfer(0);
  resetSS();
  return _data;
}

uint16_t W5100Class::read(uint16_t _addr, uint8_t *_buf, uint16_t _len)
{
  for (uint16_t i=0; i<_len; i++)
  {
    setSS();
    SPI.transfer(0x0F);
    SPI.transfer(_addr >> 8);
    SPI.transfer(_addr & 0xFF);
    _addr++;
    _buf[i] = SPI.transfer(0);
    resetSS();
  }
  return _len;
}

void W5100Class::execCmdSn(SOCKET s, SockCMD _cmd) {
  // Send command to socket
  writeSnCR(s, _cmd);
  // Wait for command to complete
  while (readSnCR(s))
    ;
}
