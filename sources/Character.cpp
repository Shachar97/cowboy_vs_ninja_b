/**
 * @package "cowboy_vs_ninja_a"
 * @file sources/Character.cpp- implementation of character class
 * @class Character
 * @extends Point
 * abstract class represent character unit in the "cowboy_vs_ninja" game
 * 
 * @author Shachar Ketz
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Point.hpp"
#include "Character.hpp"
#include <string.h>

using namespace std;

namespace ariel{


    Character::Character(string name,Point location):_name(name),_location(location),_hits(100),_lonely_wolf(true){}

    Character::~Character(){}


    bool Character::isAlive(){ return _hits>0;}


    string Character::getName() const {return _name;}


    int Character::getHits() const {return _hits;}

    void Character::setHits(int lives){ _hits=lives;}


    double Character::distance( Character* other) const{
        return this->getLocation().distance(other->getLocation());
    }

    void Character::setName(string name){this->_name=name;}

    bool Character::isLonely() const{return _lonely_wolf;}

    void Character::add_To_Team(){_lonely_wolf=false;}

    void Character::hit(int damage){
        if(damage<0){
            throw std::invalid_argument("no negative damage\n");
        }
        if(this->getHits()-damage < 0){
            this->setHits(0);
        }else{
            this->setHits(this->getHits()-damage);
        }
    }

    Point Character::getLocation() const {return this->_location;}


    void Character::setLocation(Point location){this->_location=location;}

}