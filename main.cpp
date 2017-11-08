/*******************************************************************************
* Filename: map.cpp                                                            *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     10 June 2017                                                       *
*                                                                              *
* Description: Provides definition of main which runs the game loop. The game  *
*    ends when either the clock reaches midnight or the player duct tapes the  *
*    car ans fills it with gas.                                                *
*                                                                              *
*******************************************************************************/

#include "Location.hpp" // Location
#include "map.hpp"      // createMap(), destroyMap()
#include "ioutil.hpp"   // ValidatedInput, terminalClear()
#include "Player.hpp"   // Player
#include <iostream>     // cout, endl
#include <iomanip>      // setfill, setw 

using std::cout;
using std::setfill;
using std::setw;
using std::endl;


int main(void)
{
   Location* startLocation = createMap();
   Player player(startLocation);
   ValidatedInput input;
   terminalClear();
   cout << "You and your girlfriend rented a cabin for a nice romantic getaway"
        << ", however, things don't seem so romantic. A few miles back, you "
        << "stopped for gas and the attendant told your girlfriend something."
        << "You only caught that he said something about midnight.\n\n"
        << "Whatever is going to happen, you don't want to be there to find "
        << "out.";

   cout << "\n\nCan you escape the cabin before midnight?";
   input.fromKeyboard();

   int hour = 6;
   int min  = 0;
   bool playerWon = false;

   /* Display the time and advance the clock by ten minutes each time the user
      takes an action. The loop terminates when the car has been duct-taped and
      filled with gas or the clock reaches midnight. 
   */
   do
   {
      terminalClear();
      cout << "Time - " << setfill('0') << setw(2) << hour << ":" 
           <<  setw(2) << min << " PM" << endl << endl;
         
      player.printLocationDescription();
      playerWon = player.chooseAction();

      min += 10;
      if (min == 60)
      {
         hour++;
         min = 0;
      }

   } while(hour != 12 && !playerWon);

      // If the clock reaches midnight
   if (hour == 12)
   {
      terminalClear();
      cout << "A dark patch of clouds swallows the moon. Suddenly you've "
           << "forgotten where you are. A heavy warm breath dampens the back of "
           << "your neck. What you once were no longer matters. You disappear...";
      destroyMap(startLocation);

      cout << "\n\nPress ENTER to cease to be...";
      input.fromKeyboard();
      terminalClear();
      cout << "you lose\n\n";
   }
      // The player "won" the game
   else
   {
      terminalClear();
      cout << "You rev the engine, it sounds flooded. You rev it again. It's "
           << "dead. You suddenly hear what sounds to be like hooves from all "
           << "sides of your car. Your girlfriend turns to look at you and her "
           << "eyes turn a bright shade of crimson.\n\n"
           << "\"Your meal is ready, master,\" she whispers.";

      cout << "\n\nPress ENTER to be devoured...";
      input.fromKeyboard();
      terminalClear();
      cout << "you won?\n\n";
      destroyMap(startLocation);
   }

   return 0;
}
