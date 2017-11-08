/*******************************************************************************
* Filename: Car.cpp                                                            *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     10 June 2017                                                       *
*                                                                              *
* Description: Provides the implementation of a Location derived class named   * 
*    Car. The car is used as the escape location for the game,                 *
*                                                                              *
*******************************************************************************/

#include "Location.hpp"


/*******************************************************************************
*    Function: Car::Car                                                        *
*                                                                              *
* Description: Initializes the Car to contain a proper description.            *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Car::Car()
{
   description  = "What a junker. This thing probably won't start, even if ";
   description += "your life depends on it. You see some slash marks by the ";
   description += "gas tank––it's empty.";

   item = NO_ITEM;
   locationType = LocationType::CAR;
}
