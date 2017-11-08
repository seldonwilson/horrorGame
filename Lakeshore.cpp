/*******************************************************************************
* Filename: Lakeshore.cpp                                                      *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     10 June 2017                                                       *
*                                                                              *
* Description: Provides the implementation of a Location derived class named   * 
*    Cabin. The cabin is the starting location of the Escape the Woods game.   *
*    There are no items here.                                                  *
*                                                                              *
*******************************************************************************/

#include "Location.hpp"


/*******************************************************************************
*    Function: Lakeshore::Lakeshore                                            *
*                                                                              *
* Description: Initializes the Cabin to contain a proper description.          *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Lakeshore::Lakeshore()
{
   description  = "A vast lake takes up your entire field of vision. It's ";
   description += "surrounded on all sides by trees. Strangely, you don't ";
   description += "see any reflected moonlight on its surface. You can't quite";
   description += " make it out, but it looks like something is floating a few";
   description += " hundred yards away.";

   item = NO_ITEM;
   locationType = LocationType::LAKESHORE;
}
