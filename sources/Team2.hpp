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


#ifndef TEAM2_HPP
#define TEAM2_HPP

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

    class Team2: public Team{
        public:

        /**
         * constructor.
        */
        Team2();

        /**
         * constructor- with leader.
        */
        Team2(Character* leader);

        /**
         * receives a pointer to an enemy group. Attacking the enemy group will be done in the following way:
         * * First check if the leader of the attacking group is alive.
         * * Otherwise, a new leader must be chosen, who is the living character closest (in terms of location) to the dead leader.
         * * Then the group will choose a victim from among the enemy group.
         * * The victim is the member of the living enemy group who is closest to the leader of the attacking group.
         * * All living members of the attacking group will attack the chosen victim.
         * * Cowboys who have bullets in their guns will shoot the victim, and cowboys who don't have bullets will load their weapons.
         * * Ninjas within 1 meter of the victim will kill the victim, and ninjas further away will advance towards the victim.
         * * At each stage, if the victim If dead, a new victim will be chosen (which will be, again, the living enemy character closest to the leader of the attacking group).
         * * If there are no living members in the attacking group or the enemy group the attack will end.
         * 
         *  attack orders: by order of joining the Team
         * 
         * @param enemyTeam pointer
         * @exception invalid_argument- # nullptr enemy
         * @exception runtime_error- # ghost army: empty team! # dead army: everyone died!
        */
        int attack(Team* enemyTeam) override;

        /**
         * print to the screen all the characters members in the group.
         * by order of joining the Team
        */
        void print() override;
    };

}
#endif