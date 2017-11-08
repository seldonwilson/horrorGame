/*******************************************************************************
* Filename: map.cpp                                                            *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     10 June 2017                                                       *
*                                                                              *
* Description: Provides function definitions that are used in the creation of  *
*    the game map.                                                             *
*                                                                              *
*******************************************************************************/

#include "Location.hpp"


/*******************************************************************************
*    Function: createMap                                                       *
*                                                                              *
* Description: Creates all of the locations for the Escape the Cabin game and  *
*              returns a pointer to the starting location.                     *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: Location* - the starting location (cabin)                       *
*******************************************************************************/
Location* createMap()
{
   Location* cabin     = new Cabin();
   Location* car       = new Car();
   Location* garden    = new Garden();
   Location* junkpile  = new Junkpile();
   Location* forest    = new Forest();
   Location* cliffwall = new Cliffwall();
   Location* shed      = new Shed();
   Location* lakeshore = new Lakeshore();
   Location* boat      = new Boat();

   cabin->setSouth(car);
   cabin->setWest(garden);
   cabin->setEast(junkpile);
   cabin->setNorth(forest);

   car->setNorth(cabin);

   garden->setEast(cabin);

   junkpile->setWest(cabin);

   forest->setSouth(cabin);
   forest->setWest(cliffwall);
   forest->setEast(lakeshore);
   forest->setNorth(shed);

   cliffwall->setEast(forest);

   shed->setSouth(forest);

   lakeshore->setWest(forest);
   lakeshore->setSouth(boat);

   boat->setNorth(lakeshore);

   return cabin;
}



/*******************************************************************************
*    Function: destroyMap                                                      *
*                                                                              *
* Description: Deletes the entire map, but must be passed the cabin location   *
*              to properly work.                                               *
*                                                                              *
*      Inputs: destroyMe - Location* (must be cabin)                           *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void destroyMap(Location* destroyMe)
{
   Location* tempLocation = destroyMe->getNorth();

   delete destroyMe->getWest();
   delete destroyMe->getSouth();
   delete destroyMe->getEast();
   delete destroyMe;

   destroyMe = tempLocation;
   delete destroyMe->getWest();
   delete destroyMe->getNorth();
   tempLocation = destroyMe->getEast();
   delete destroyMe;

   destroyMe = tempLocation;
   delete destroyMe->getSouth();
   delete destroyMe;
}
