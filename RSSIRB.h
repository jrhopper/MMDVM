/*
Serial fifo control - Copyright (C) KI6ZUM 2015
Copyright (C) 2015,2016 by Jonathan Naylor G4KLX

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public
License along with this library; if not, write to the
Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
Boston, MA  02110-1301, USA.
*/

#if !defined(RSSIRB_H)
#define  RSSIRB_H

#if defined(STM32F4XX) || defined(STM32F4)
#include "stm32f4xx.h"
#include <cstddef>
#else
#include <Arduino.h>
#endif

class CRSSIRB {
public:
  CRSSIRB(uint16_t length);
  
  uint16_t getSpace() const;
  
  uint16_t getData() const;

  bool put(uint16_t rssi);

  bool get(uint16_t& rssi);

  bool hasOverflowed();

private:
  uint16_t           m_length;
  volatile uint16_t* m_rssi;
  volatile uint16_t  m_head;
  volatile uint16_t  m_tail;
  volatile bool      m_full;
  bool               m_overflow;
};

#endif

