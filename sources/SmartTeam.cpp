/**
 * @package "cowboy_vs_ninja_a"
 * @file sources/SmartTeam.cpp- implement of SmartTeam class
 * @class SmartTeam
 * @extends Team class
 * class represent Team type unit, in the "cowboy_vs_ninja" game
 * Team unit is array that can contain at most of 10 characters pointers units
 * 
 * @author Shachar Ketz
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"
#include "Team.hpp"
#include "SmartTeam.hpp"

using namespace std;

namespace ariel{

    SmartTeam::SmartTeam():Team(){ }

    SmartTeam::SmartTeam(Character *leader):Team(leader){ }
    
    void SmartTeam::set_round(){
        int len = this->getSize();
        for(int i=0;i<len;i++){
            if(this->getCharacterAt(i)->isAlive()){
                _round_attack[i]=false;
            }else{
                _round_attack[i]=true;
            }
        }
    }

    void SmartTeam::set_character_attack(int index){
        if(index >= this->getSize()){
            throw std::out_of_range("out of range\n");
        }
        _round_attack[index]=true;
    }

    bool SmartTeam::get_character_attack(int index){
        if(index >= this->getSize()){
            throw std::out_of_range("out of range\n");
        }
        return _round_attack[index];
    }

    bool SmartTeam::finish_round(){
        int len = this->getSize();
        for(int i=0;i<len; i++){
            if(!_round_attack[i]){
                return false;
            }
        }
        return true;
    }
    Character* SmartTeam::most_damage(Character* target){
        if(!target){
            throw std::invalid_argument("nullptr target\n");
        }
        if(this->finish_round()){
            throw std::runtime_error("end of round\n");
        }

        int len = this->getSize();
        int damage=-1, character_index=-1;
        for(int i=0; i<len; i++){

            /*character can fight this round:*/
            if(!this->get_character_attack(i)){
                Cowboy* cowboy = dynamic_cast<Cowboy*>(this->getCharacterAt(i));
                if(cowboy){
                    if(cowboy->hasboolets()){
                        if(damage<10){
                            damage=10;
                            character_index=i;
                        }
                    }
                }else{
                    Ninja* ninja = dynamic_cast<Ninja*>(this->getCharacterAt(i));
                    if(ninja->distance(target)<=1){
                        if(damage<40){
                            damage=40;
                            character_index=i;
                        }
                    }
                }
            }
        }

        /*no damage can be done in this round:
        # find ninja
        # if there is no ninja find cowboy
        */
        if(damage==-1){
            int speed=-1;
            for(int i=0; i<len; i++){
                /*character can fight this round:*/
                if(!this->get_character_attack(i)){
                    Ninja* ninja = dynamic_cast<Ninja*>(this->getCharacterAt(i));
                    if(ninja){
                        if(speed < ninja->getSpeed()){
                            speed = ninja->getSpeed();
                            character_index=i;
                        }
                    }
                }
            }

            /*no ninja in this round*/
            if(speed==-1){
                for(int i=0; i<len; i++){

                    /*character can fight this round:*/
                    if(!this->get_character_attack(i)){
                        Cowboy* cowboy = dynamic_cast<Cowboy*>(this->getCharacterAt(i));
                        if(cowboy){
                            this->set_character_attack(i);
                            return this->getCharacterAt(i);
                        }
                    }
                }
            }
        }
        /*if here: damage != -1 or speed != -1*/
        this->set_character_attack(character_index);
        return this->getCharacterAt(character_index);
    }

    int SmartTeam::attack(Team* enemyTeam){
        /*throws*/
        if(!enemyTeam){
            throw std::invalid_argument("nullptr enemy\n");
        }
        if(this->getSize()==0){
            throw std::invalid_argument("ghost army: empty team!\n");
        }
        Character* leader;
        if(!(leader=this->findLeader(this))){
            throw std::invalid_argument("in find leader: dead army: everyone died!\n");
        }
        if(enemyTeam->stillAlive()==0){
            throw std::runtime_error("dead army: everyone died!\n");
        }
        this->set_round();

        /*closest enemy to leader*/
        Character* target = this->closestEnemy(leader,enemyTeam);
        Character* attacker;

        /*run over all smart_team character that can fight this round
            # exit if all smart_team had fights of if the enemy team eliminate.
        */
        while(!(this->finish_round()) && target){

            /*if there is enemy left- target will be the closest one to leader*/
            if((target = this->closestEnemy(leader,enemyTeam))){

                attacker=this->most_damage(target);

                Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker);
                if(cowboy){
                    
                    if(cowboy->hasboolets()){
                        cowboy->shoot(target);
                    }else{
                        cowboy->reload();
                    }

                }else{
                    Ninja* ninja = dynamic_cast<Ninja*>(attacker);
                    
                    if((target = this->closestEnemy(leader,enemyTeam))){
                        if(ninja->distance(target)>1){
                            ninja->move(target);
                        }else{
                            ninja->slash(target);
                        }
                    }
                    
                }
            }
        }

        if(enemyTeam->stillAlive()==0){
            return 1;
        }
        return 0;
    }

    void SmartTeam::print(){
        for(int i=0;i<getSize();i++){
            cout<<getCharacterAt(i)->print();
            cout<<endl;
        }
    }
}