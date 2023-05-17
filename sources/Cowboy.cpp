/**
 * @package "cowboy_vs_ninja_a"
 * @file sources/Cowboy.cpp- implementations of cowboy class
 * @class Cowboy
 * @extends Character
 * cowboy class represent "cowboy" character type unit, in the "cowboy_vs_ninja" game.
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
#include "Cowboy.hpp"
#define DEBUG
using namespace std;

namespace ariel{

    Cowboy::Cowboy(){
        this->setName("Bill Carson");
        this->setLocation(Point(2.5,2.5));
        this->setHits(110);
        this->reload();
    }

    Cowboy::Cowboy(string name, Point location){
        this->setName(name);
        this->setLocation(location);
        setHits(110);
        this->reload();
    }

    Cowboy::~Cowboy(){}

    void Cowboy::shoot(Character* enemy){
        if(!(this->isAlive())||!(enemy->isAlive())||(enemy==this)){
            throw std::runtime_error("zombie or attacking dead or hurting himself\n");
        }
        if(this->hasboolets()){
            enemy->hit(10);
            this->_bullets--;
        }
    }

    bool Cowboy::hasboolets(){return this->_bullets>0;}

    int Cowboy::getBullets() const{return this->_bullets;}
    
    void Cowboy::reload(){

        if(!(this->isAlive())){
            throw std::runtime_error("dead cowboy cannot reload\n");
        }
        this->_bullets=6;}

    string Cowboy::print(){
        string answer="C: ";
        if(this->isAlive()){
            answer += getName() + ": hits=" + to_string(getHits())+", location: "+getLocation().print();
        }else{
            answer +="("+ getName() + "), location: "+getLocation().print();
        }
        
        return answer;
    }

}