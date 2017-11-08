/*******************************************************************************
* Filename: Junkpile.cpp                                                       *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     10 June 2017                                                       *
*                                                                              *
* Description: Provides the implementation of a Location derived class named   * 
*    Junkpile. The Junkpile is where the player will find the kayak.           *
*                                                                              *
*******************************************************************************/

#include "Location.hpp"


/*******************************************************************************
*    Function: Junkpile::Junkpile                                              *
*                                                                              *
* Description: Initializes the Junkpile to contain a proper description.       *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Junkpile::Junkpile()
{
   description  = "A lifetime's worth of junk sits in a pile by the cabin. ";
   description += "You wonder if any of this stuff could be useful, it looks ";
   description += "as if it's been untouched for a long time.";

   item = Item::KAYAK;
   locationType = LocationType::JUNKPILE;
}
