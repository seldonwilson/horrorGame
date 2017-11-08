/*******************************************************************************
* Filename: Garden.cpp                                                         *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     10 June 2017                                                       *
*                                                                              *
* Description: Provides the implementation of a Location derived class named   * 
*    Garden. The garden contains different objects, only one of which is useful*
*    for the advancement: the hose.                                            *
*                                                                              *
*******************************************************************************/

#include "Location.hpp"


/*******************************************************************************
*    Function: Garden::Garden                                                  *
*                                                                              *
* Description: Initializes the Cabin to contain a proper description.          *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Garden::Garden()
{
   description  = "The cabin's garden is surrounded by what once was probably ";
   description += "a short white fence. There's nothing but weeds and cobwebs ";
   description += "now. Even the soil look lifeless.";

   item = Item::HOSE;
   locationType = LocationType::GARDEN;
}
