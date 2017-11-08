/*******************************************************************************
* Filename: Forest.cpp                                                         *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     10 June 2017                                                       *
*                                                                              *
* Description: Provides the implementation of a Location derived class named   * 
*    Forest. The forest is the starting location of the Escape the Woods game. *
*    There are no items here.                                                  *
*                                                                              *
*******************************************************************************/

#include "Location.hpp"


/*******************************************************************************
*    Function: Forest::Forest                                                  *
*                                                                              *
* Description: Initializes the Cabin to contain a proper description.          *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Forest::Forest()
{
   description  = "The trees are so thick above you, only dapples of light are";
   description += " able to peer in. Lichen and fungi have made their way ";
   description += "across every perceivable surface. You see some sort of ";
   description += "large cloven tracks heading east/west, but it doesn't ";
   description += "appear to be like anything you've seen before.";

   item = NO_ITEM;
   locationType = LocationType::FOREST;
}
