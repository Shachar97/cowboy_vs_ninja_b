/**
 * @package "cowboy_vs_ninja_a"
 * @file sources/Team2.hpp- declaration of Team2 class
 * @class Team2
 * @extends Team class
 * class represent Team type unit, in the "cowboy_vs_ninja" game
 * Team unit is array that can contain at most of 10 characters pointers units
 * 
 * @author Shachar Ketz
*/


#ifndef SMART_TEAM_HPP
#define SMART_TEAM_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"
#include "Team.hpp"

namespace ariel{
    
    class SmartTeam: public Team{
        public:

        /**
         * constructor.
        */
        SmartTeam();
        
        /**
         * constructor- with leader.
        */
        SmartTeam(Character* leader);

        /*attackthe other groop To-DO*/
        int attack(Team* enemyTeam) override;

        /**
         * print to the screen all the characters members in the group.
         * by order of joining the Team
        */
        void print() override;
    };

}
#endif