/**
 * @package "cowboy_vs_ninja_a"
 * @file sources/Character.hpp- declarations of character class
 * @class Character
 * @extends Point
 * abstract class represent character unit in the "cowboy_vs_ninja" game
 * 
 * @author Shachar Ketz
*/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Point.hpp"

using namespace std;

namespace ariel{

    /**
     * @class Character
     * @extends Point
     * abstract class represent character unit in the "cowboy_vs_ninja" game
    */
    class Character: public Point
    {
    private:
        int _hits;
        string _name;
        Point _location;
        bool _lonely_wolf;
    public:

        /**
         * Constructor
         * @param name string name of character
         * @param location point
         * @details hit-lives, location-point represent location on the board, lonely_wolf-true if not in a team
        */
        Character(string name="NPC", Point location=Point(0,0));

        /**
         * destructor
        */
        virtual ~Character();

        /**
         * @return how much hits(lives) the character remain with
        */
        int getHits() const;

        /**
         * set the hits of character
         * @param hits(lives) -hole number to reset
        */
        void setHits(int lives);

        /**
         * allow to change names of character's and access to name field from inheritance classes
         * @param name string.
        */
        void setName(string name);

        /**
         * @return bool indication if the character have hits(live) left (<0)
        */
        bool isAlive();

        /**
         * @return bool indicate if character is in a team.
        */
        bool isLonely() const;

        /**
         * change bool _lonely_wolf to be false. 
        */
        void add_To_Team();

        /**
         * return the distance between the character to given character
         * @param other character
         * @return the distance.
        */    
        double distance(Character* other) const;

        /**
         * reduce hits(lives) to the character
         * @param damage how much to reduce
         * @exception invalid_argument- # no negative damage
        */
        void hit(int damage);

        /**
         * @return name of character
        */
        string getName() const;
        
        /**
         * @return location point of character
        */
        Point getLocation() const;

        /**
         * allow to change location of character's and access to location field from inheritance classes
         * @param location point
        */
        void setLocation(Point location);

        /**
         * pure virtual: string that represent the character (name, hits, location)
        */
        virtual string print()=0;
    
    };
}
#endif