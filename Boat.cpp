/*******************************************************************************
* Filename: Boat.cpp                                                           *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     10 June 2017                                                       *
*                                                                              *
* Description: Provides the implementation of a Location derived class named   * 
*    Boat. The boat is the location that contains the gasoline needed to escape*
*    the woods.                                                                *
*                                                                              *
*******************************************************************************/

#include "Location.hpp"


/*******************************************************************************
*    Function: Boat::Boat                                                      *
*                                                                              *
* Description: Initializes the Boat to contain a proper description.           *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Boat::Boat()
{
   description  = "It's an old one motor fishing boat. Why is it here in the ";
   description += "middle of the lake? The wood smells like it's rotten, but ";
   description += "the engine looks in decent shape.";

   item = Item::GAS;
   locationType = LocationType::BOAT;
}
