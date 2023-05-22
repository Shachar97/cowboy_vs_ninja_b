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
        private:
        bool _round_attack[10];
        public:

        /**
         * constructor.
        */
        SmartTeam();
        
        /**
         * constructor- with leader.
        */
        SmartTeam(Character* leader);

        /**
         * change status in _round_attack array on index to true
         * @param index
         * @exception out_of_range
        */
        void set_character_attack(int index);

        /**
         * help function in start of smart_team battle, represent all the character in the team that can fight in this round:
         * set all live character to false, and all dead character to true;
        */
        void set_round();

        /**
         * return character status in _round_attack array
         * @param index
         * @exception out_of_range
        */
        bool get_character_attack(int index);

        /**
         * @return true if all character in the smarteam had fights.
        */
        bool finish_round();
        /**
         * @param target the enemy character pointer
         * @return pointer to character in the team that can hurt the most to the target
         * # if there is more then one, it return the character with the smaller index in the array,
         * # if all the character cant do damage, the function will return closest and fastest ninja
         * # if there is no ninja left in the round, it will return the firs cowboy in the array that didn't fight yet.
         * @exception invalid_argument- # character is nullptr 
         * @exception runtime_error- # end of round
        */
        Character* most_damage(Character* target);

        /**
         * attack() receives a pointer to an enemy group. Attacking the enemy group will be done in the following way:
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
         * attack orders: first Cowboys member, then Ninjas members
         * @param enemyTeam pointer
         * @return 1 if the enemy died in the mid of the attack else return 0.
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