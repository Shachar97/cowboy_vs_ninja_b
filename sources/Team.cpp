/**
 * @package "cowboy_vs_ninja_a"
 * @file sources/Team.cpp- implementation of Team class
 * @class Team
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
#include <limits>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"
#include "Team.hpp"

#define DEBUG

using namespace std;

namespace ariel{
    Team::Team():_size(0),_leader(nullptr){ }

    Team::Team(Character *leader):_size(0),_leader(leader){

        this->add(leader);
    }

    Team::~Team(){
        for(int i=0;i < this->getSize(); i++){
            delete _myTeam[i];
        }
    }

    int Team::getSize() const {return this->_size;}

    Character* Team::getLeader() const{return this->_leader;}

    void Team::setLeader(Character* newLeader){this->_leader=newLeader;}

    Character* Team::getCharacterAt(int index){
        if(getSize()<=index){
            return nullptr;
        }
        return _myTeam[index];
    }

    void Team::incSize(){_size++;}

    void Team::add(Character* soldier){
        if(!soldier){
            throw std::runtime_error("nullptr soldier");
        }
        if(!(soldier->isLonely())){
            throw std::runtime_error("soldier already in a team");
        }
        if(this->getSize()<10){

            if((this->getSize()==0)){
                setLeader(soldier);
            }
            soldier->add_To_Team();

            _myTeam[_size++]=soldier;
            return;
        }
        throw std::runtime_error("Team is full\n");
        
    }

    int Team::attack(Team* enemyTeam){
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
            Cowboy* cowboy = dynamic_cast<Cowboy*>(_myTeam[i]);
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
            }
        }
        for(int i=0;i<this->getSize();i++){
            Ninja* ninja = dynamic_cast<Ninja*>(this->getCharacterAt(i));
            if(ninja){
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

    Character* Team::findLeader(Team* team) const{
        
        /*nullptr*/
        if(!team){
            throw std::runtime_error("Team is nullptr\n");
        }
        /*no members in the team*/
        if(team->getSize()==0){
            throw std::runtime_error("Team is empty\n");
        }

        /*leader is alive*/
        if(team->getLeader()->isAlive()){
            return team->getLeader();
        }

        /*find new leader*/

        double closest = std::numeric_limits<int>::max();
        Character* newLeader=nullptr;

        for(int i=0; i< team->getSize(); i++ ){

            /*skip leader body*/
            if(team->getCharacterAt(i)==team->getLeader()){
                continue;
            }

            /*check if character is alive*/
            else if(team->getCharacterAt(i)->isAlive()){

                Character* temp = team->getCharacterAt(i);
                double dist= temp->distance(team->getLeader());

                /*check if character is the closest one to the body*/
                if(closest>dist){
                    closest=dist;
                    newLeader=temp;
                }
            }
        }

        if(newLeader){
            team->setLeader(newLeader);
        }
        return newLeader;
    }

    Character* Team::closestEnemy(Character* myLeader, Team* enemyTeam) const{
        if(!myLeader){
            throw std::runtime_error("character is nullptr\n");
        }
        if(!enemyTeam){
            throw std::runtime_error("Team is nullptr\n");
        }
        if(enemyTeam->getSize()==0){
            throw std::runtime_error("Team is empty\n");
        }

        double closest = std::numeric_limits<int>::max();
        Character* newTarget=nullptr;


        for(int i=0; i<enemyTeam->getSize(); i++){
            Character* temp=enemyTeam->getCharacterAt(i);
            if(temp->isAlive()){
                double dist = myLeader->distance(temp);
                if(dist<closest){
                    closest=dist;
                    newTarget=temp;
                }
            }
        }
        return newTarget;
    }

    int Team::stillAlive(){
        int count=0;
        for(int i=0;i<this->getSize();i++){
            if(_myTeam[i]->isAlive()){
                count++;
            }
        }
        return count;
    }

    void Team::print(){
        for(int i=0;i<this->getSize();i++){
            Cowboy* cowboy = dynamic_cast<Cowboy*>(_myTeam[i]);
            if(cowboy){
                cout<<cowboy->print();
                cout<<endl;
            }
            
        }
        for(int i=0;i<this->getSize();i++){
            Cowboy* cowboy = dynamic_cast<Cowboy*>(_myTeam[i]);
            if(!cowboy){
                cout<<_myTeam[i]->print();
                cout<<endl;
            }
        }
    }
}