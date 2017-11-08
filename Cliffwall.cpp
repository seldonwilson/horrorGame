/*******************************************************************************
* Filename: Cliffwall.cpp                                                      *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     10 June 2017                                                       *
*                                                                              *
* Description: Provides the implementation of a Location derived class named   * 
*    Cliffwall. The cliffwall a dead end in the game and is the used as a red  *
*    herring to throw the player off a bit.                                    *
*                                                                              *
*******************************************************************************/

#include "Location.hpp"


/*******************************************************************************
*    Function: Cliffwall::Cliffwall                                            *
*                                                                              *
* Description: Initializes the Cabin to contain a proper description.          *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Cliffwall::Cliffwall()
{
   description  = "A giant vertical cliff wall faces you. It must be more ";
   description += "than two-hundred feet high! You think you spot a figure ";
   description += "watching you from above, but it could just be your ";
   description += "imagination.";

   item = NO_ITEM;
   locationType = LocationType::CLIFFWALL;
}
