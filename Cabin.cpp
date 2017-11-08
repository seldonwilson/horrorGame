/*******************************************************************************
* Filename: Cabin.cpp                                                          *
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
*    Function: Cabin::Cabin                                                    *
*                                                                              *
* Description: Initializes the Cabin to contain a proper description.          *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Cabin::Cabin()
{
   description  = "A dank and dimly lit cabin. You can smell the faint aroma ";
   description += "of stale beer that seems to get stronger near the coffee ";
   description += "table. Your girlfriend is staring nervously out the window,";
   description += " babbling nonsense to herself. You can't quite make out the";
   description += " words...";

   item = TAPE;
   locationType = LocationType::CABIN;
}