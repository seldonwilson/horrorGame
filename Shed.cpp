/*******************************************************************************
* Filename: Shed.cpp                                                           *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     10 June 2017                                                       *
*                                                                              *
* Description: Provides the implementation of a Location derived class named   * 
*    Shed. The shed is a location that exists as an item hub.                  *
*                                                                              *
*******************************************************************************/

#include "Location.hpp"


/*******************************************************************************
*    Function: Shed::Shed                                                      *
*                                                                              *
* Description: Initializes the Shed to contain a proper description.           *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Shed::Shed()
{
   description  = "A drafty old shed stands in the middle of an opening in ";
   description += "the woods. It's shorter than you're used to and you have ";
   description += "to duck to enter. Hooks hang from the ceiling with bones ";
   description += "picked clean of all flesh hanging from them. A few toy ";
   description += "soilders are scattered on the floor and a tattered baseball";
   description += " glove is peeking out of what looks to be a treasure chest.";

   item = Item::CAN;
   locationType = LocationType::SHED;
}
