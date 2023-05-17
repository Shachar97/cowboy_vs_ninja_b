/**
 * @package "cowboy_vs_ninja_a"
 * @file sources/Team2.cpp- implement of Team2 class
 * @class Team2
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
#include "Team2.hpp"

using namespace std;
namespace ariel{
    Team2::Team2():Team(){}

    Team2::Team2(Character *leader):Team(leader){}
    
    int Team2::attack(Team* enemyTeam){
        if(!enemyTeam){
            throw std::invalid_argument("nullptr enemy\n");
        }
        if(this->getSize()==0){
            throw std::invalid_argument("ghost army: empty team!\n");
        }
        Character* leader;
        if(!(leader=this->findLeader(this))){
            throw std::invalid_argument("dead army: everyone died!\n");
        }
        if(enemyTeam->stillAlive()==0){
            throw std::runtime_error("dead army: everyone died!\n");
        }
        Character* target;

        for(int i=0;i<this->getSize();i++){
            Cowboy* cowboy = dynamic_cast<Cowboy*>(this->getCharacterAt(i));
            if(cowboy){
                if(cowboy->isAlive()){
                    if((target = this->closestEnemy(leader,enemyTeam))){
                        if(!target){
                            return 1; //enemy dead
                        }
                        if(cowboy->hasboolets()){
                            cowboy->shoot(target);
                        }else{
                            cowboy->reload();
                        }
                    }
                }
            }else{
                Ninja* ninja = dynamic_cast<Ninja*>(this->getCharacterAt(i));
                if(ninja->isAlive()){
                    if((target = this->closestEnemy(leader,enemyTeam))){
                        if(!target){
                            return 1; //enemy dead
                        }
                        if(ninja->distance(target)>1){
                            ninja->move(target);
                        }else{
                            ninja->slash(target);
                        }
                    }
                }
            }
        }
        return 0;
    }

    void Team2::print(){
        for(int i=0;i<getSize();i++){
            cout<<getCharacterAt(i)->print();
            cout<<endl;
        }
    }
}