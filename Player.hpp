/*******************************************************************************
* Filename: Player.hpp                                                         *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     10 June 2017                                                       *
*                                                                              *
* Description: Provides the interface to the player class which is able to     *
*    control the player and its movements/interactions in the game.            *
*                                                                              *
*******************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Location.hpp" // Location
#include "Item.hpp"     // enum Item
#include <vector>       // std::vector
#include <string>       // std::string


enum PlayerActions {MOVE_NORTH, MOVE_SOUTH, MOVE_EAST, MOVE_WEST,
                    TAKE_KAYAK, TAKE_HOSE,  TAKE_CAN,  TAKE_GAS,  TAKE_TAPE,
                    USE_KAYAK,  USE_HOSE,   USE_CAN,   USE_GAS,   USE_TAPE,
                    SHOW_INVENTORY, DO_NOTHING, TAKE_ITEM, ESCAPE};

class Player
{
   private:
      Location* currentLocation;
      std::vector<Item> inventory;

   public:
      Player(Location* startingLocation = nullptr);
      ~Player();

         // Display a list of available actions
      bool chooseAction();
      void printLocationDescription() const;

   private:
      bool doAction(PlayerActions doThis);
      void printInventory() const;
      bool hasCan() const;
      bool hasHose() const;
      bool hasTape() const;
      bool hasKayak() const;
      bool hasGas() const;
      void removeItem(Item removeMe);
};


#endif // PLAYER_HPP
