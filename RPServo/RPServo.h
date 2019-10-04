/*
	<This is a super simplified servo library for beginners.>
    Copyright (C) <2019>  <Rupesh Pal>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>
*/

#ifndef RPServo_h
#define RPServo_h

#include "Arduino.h"

class RPServo
{
  private:
  int pinNumber,degree0,degree180;  // degree0 and degree180 are the delays in microseconds
  
  public:
  RPServo();
  RPServo::RPServo(int pin, int deg0=500, int deg180=2500);
  
  void initiate(int pin, int deg0=500, int deg180=2500);
  
  void turnMicroseconds(int microsec);
  void RPServo::turnMicroseconds(int microsec, int delayMiliSec);
  
  void turnDegree(int degree);
  void RPServo::turnDegree(int degree, int delayMiliSec);
  
  void turnRadian(int rad);
  void RPServo::turnRadian(int rad, int delayMiliSec);
  
  void RPServo::testServo();
};

#endif
