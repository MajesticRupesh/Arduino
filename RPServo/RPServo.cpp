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

#include "Arduino.h"
#include "RPServo.h"

RPServo::RPServo()
  {
	degree0=500;
	degree180=2500;
  }

RPServo::RPServo(int pin, int deg0=500, int deg180=2500)
  {
  	pinNumber=pin;
  	degree0=deg0;
	degree180=deg180;
	pinMode(pinNumber,OUTPUT);
  }

void RPServo::initiate(int pin, int deg0=500, int deg180=2500)
  {
    pinNumber=pin;
    degree0=deg0;
    degree180=deg180;
    pinMode(pinNumber,OUTPUT);
  }
  
void RPServo::turnMicroseconds(int microsec)
  {
    digitalWrite(pinNumber,HIGH);
    delayMicroseconds(microsec);
    digitalWrite(pinNumber,LOW);
  }
  
void RPServo::turnMicroseconds(int microsec, int delayMiliSec)
  {
    digitalWrite(pinNumber,HIGH);
    delayMicroseconds(microsec);
    digitalWrite(pinNumber,LOW);
    delay(delayMiliSec);
  }
  
void RPServo::turnDegree(int degree)
  {
    int microsec=map(degree,0,180,500,2500);
    turnMicroseconds(microsec);
  }
    
void RPServo::turnDegree(int degree, int delayMiliSec)
  {
    int microsec=map(degree,0,180,500,2500);
    turnMicroseconds(microsec);
    delay(delayMiliSec);
  }
  
void RPServo::turnRadian(int rad)
  {
    int degree=(int)(rad*180/3.14159);
    turnDegree(degree);
  }
  
void RPServo::turnRadian(int rad, int delayMiliSec)
  {
  	int degree=(int)(rad*180/3.14159);
    turnDegree(degree,delayMiliSec);
  }
  
void RPServo::testServo()
  {
  	int i;
  	for(i=0;i<180;i++)
  		turnDegree(i,20);
  	for(i=180;i>0;i--)
  		turnDegree(i,20);
  }
