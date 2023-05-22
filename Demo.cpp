/**
 * Demo file for the exercise Cowboy VS Ninja game
 * 
 * in this demo i build 3 teams and put them in two circles one circle from all the cowboys and the other from all the ninjas,
 * each team attack in his turn the team on his left.
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <cmath>
using namespace std;

#include "sources/Team.hpp" //no need for other includes
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
using namespace ariel;


// Function to calculate the position on a circle given the angle and radius. i asked gpt to order my points in two big circles: ninja in the 
Point calculatePosition(double angle, double radius) {
    double x = radius * cos(angle);
    double y = radius * sin(angle);
    return Point(x, y);
}

const double PI = 3.14159265358979323846;

int main() {

   const double COWBOY_RADIUS = 30.0;
   const double NINJA_RADIUS = 20.0;

   /* Team 1 */
   Cowboy* Sheriff = new Cowboy("Deputy", calculatePosition(0, COWBOY_RADIUS));
   Cowboy* Billy = new Cowboy("Billy The kid", calculatePosition(1*PI / 8, COWBOY_RADIUS));
   Cowboy* TheGood = new Cowboy("Blondie", calculatePosition(2 * PI / 8, COWBOY_RADIUS));
   Cowboy* TheBad = new Cowboy("Angel Eyes", calculatePosition(3 * PI / 8, COWBOY_RADIUS));
   Cowboy* TheUgly = new Cowboy("Tuco", calculatePosition(4 * PI / 8, COWBOY_RADIUS));

   OldNinja* Splinter = new OldNinja("Splinter", calculatePosition(0, NINJA_RADIUS));
   OldNinja* Donatello = new OldNinja("Donatello", calculatePosition(PI / 8, NINJA_RADIUS));
   TrainedNinja* Raphael = new TrainedNinja("Raphael", calculatePosition(2 * PI / 8, NINJA_RADIUS));
   YoungNinja* Michelangelo = new YoungNinja("Michelangelo", calculatePosition(3 * PI / 8, NINJA_RADIUS));
   YoungNinja* Leonardo = new YoungNinja("Leonardo", calculatePosition( 4 * PI / 8, NINJA_RADIUS));


   /* Team 2 */
   Cowboy* John = new Cowboy("John Wesley Hardin", calculatePosition(5 * PI / 8, COWBOY_RADIUS ));
   Cowboy* Frank = new Cowboy("Frank James", calculatePosition(6 * PI / 8, COWBOY_RADIUS ));
   Cowboy* Peters = new Cowboy("Peters Ringo", calculatePosition( 7* PI /8 , COWBOY_RADIUS ));
   Cowboy* Miller = new Cowboy("Jim Miller", calculatePosition(0, -COWBOY_RADIUS));
   Cowboy* Sam = new Cowboy("Sam Bass", calculatePosition(1 * PI / 8, -COWBOY_RADIUS));

   OldNinja* Kakashi = new OldNinja("Kakashi Hatake", calculatePosition(5 * PI / 8, NINJA_RADIUS));
   OldNinja* Scorpion = new OldNinja("Scorpion", calculatePosition(6 * PI / 8, NINJA_RADIUS));
   TrainedNinja* Ryu = new TrainedNinja("Ryu Hayabusa", calculatePosition(7 * PI / 8, NINJA_RADIUS ));
   YoungNinja* Tsunade = new YoungNinja("Tsunade", calculatePosition(0, -NINJA_RADIUS));
   YoungNinja* Naruto = new YoungNinja("Naruto Uzumaki", calculatePosition(PI / 8, -NINJA_RADIUS ));


   /* Team 3 */
   Cowboy* Pat = new Cowboy("Pat Garrett", calculatePosition(2 * PI / 8, -COWBOY_RADIUS));
   Cowboy* Butch = new Cowboy("Butch Cassidy", calculatePosition(3 * PI / 8, -COWBOY_RADIUS ));
   Cowboy* WildBill = new Cowboy("Wild Bill Hickok", calculatePosition(4 * PI / 8, -COWBOY_RADIUS ));
   Cowboy* Jesse = new Cowboy("Jesse James", calculatePosition(5 * PI / 8, -COWBOY_RADIUS ));
   Cowboy* Wyatt = new Cowboy("Wyatt Earp", calculatePosition(6 * PI / 8, -COWBOY_RADIUS ));

   OldNinja* Shikamaru = new OldNinja("Shikamaru Nara", calculatePosition(2*PI/8, -NINJA_RADIUS));
   OldNinja* Neji = new OldNinja("Neji Hyuga", calculatePosition(3* PI / 8, -NINJA_RADIUS ));
   TrainedNinja* Choji = new TrainedNinja("Choji Akimichi", calculatePosition(4 * PI / 8, -NINJA_RADIUS ));
   YoungNinja* Ino = new YoungNinja("Ino Yamanaka", calculatePosition(5 * PI / 8, -NINJA_RADIUS ));
   YoungNinja* Hattori = new YoungNinja("Hattori Hanzō", calculatePosition(6 * PI / 8, -NINJA_RADIUS ));

   Team team_A(Sheriff);
   Team2 team_B(John); 
   SmartTeam team_C(Pat);

   team_A.add(Billy);
   team_A.add(TheGood);
   team_A.add(TheBad);
   team_A.add(TheUgly);

   team_A.add(Donatello);
   team_A.add(Raphael);
   team_A.add(Michelangelo);
   team_A.add(Leonardo);

   team_B.add(Frank);
   team_B.add(Peters);
   team_B.add(Miller);
   team_B.add(Sam);

   team_B.add(Scorpion);
   team_B.add(Ryu);
   team_B.add(Tsunade);
   team_B.add(Naruto);
   team_C.add(Butch);
   team_C.add(WildBill);
   team_C.add(Jesse);
   team_C.add(Wyatt);

   team_C.add(Neji);
   team_C.add(Choji);
   team_C.add(Ino);
   team_C.add(Hattori);
   
   int i=1;

   while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0 && team_C.stillAlive() > 0){

      team_A.attack(&team_B);

      cout<<"Team A position after attack:"<<endl;
      cout << Sheriff->getLocation().print()<<endl;
      cout << Billy->getLocation().print()<<endl;
      cout << TheGood->getLocation().print()<<endl;
      cout << TheBad->getLocation().print()<<endl;
      cout << TheUgly->getLocation().print()<<endl;

      cout << Splinter->getLocation().print()<<endl;
      cout << Donatello->getLocation().print()<<endl;
      cout << Raphael->getLocation().print()<<endl;
      cout << Michelangelo->getLocation().print()<<endl;
      cout << Leonardo->getLocation().print()<<endl;
      cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl<<endl;
      if(team_B.stillAlive() > 0){
         team_B.attack(&team_C);
         cout<<"Team B position after attack:"<<endl;
         cout << John->getLocation().print()<<endl;
         cout << Frank->getLocation().print()<<endl;
         cout << Peters->getLocation().print()<<endl;
         cout << Miller->getLocation().print()<<endl;
         cout << Sam->getLocation().print()<<endl;

         cout << Kakashi->getLocation().print()<<endl;
         cout << Scorpion->getLocation().print()<<endl;
         cout << Ryu->getLocation().print()<<endl;
         cout << Tsunade->getLocation().print()<<endl;
         cout << Naruto->getLocation().print()<<endl;
         cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl<<endl;
      }

      if(team_C.stillAlive() > 0){
         team_C.attack(&team_A);
         cout<<"Team C position after attack:"<<endl;
         cout << Pat->getLocation().print()<<endl;
         cout << Butch->getLocation().print()<<endl;
         cout << WildBill->getLocation().print()<<endl;
         cout << Jesse->getLocation().print()<<endl;
         cout << Wyatt->getLocation().print()<<endl;

         cout << Shikamaru->getLocation().print()<<endl;
         cout << Neji->getLocation().print()<<endl;
         cout << Choji->getLocation().print()<<endl;
         cout << Ino->getLocation().print()<<endl;
         cout << Hattori->getLocation().print()<<endl;
         cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl<<endl;
      }
      cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
      cout<<"end of round "<<i<<endl;
      cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl<<endl;
      i++;
   }
   while(team_A.stillAlive() > 0 && team_B.stillAlive()){
         team_A.attack(&team_B);
         cout<<"Team A position after attack:"<<endl;
         cout << Sheriff->getLocation().print()<<endl;
         cout << Billy->getLocation().print()<<endl;
         cout << TheGood->getLocation().print()<<endl;
         cout << TheBad->getLocation().print()<<endl;
         cout << TheUgly->getLocation().print()<<endl;

         cout << Splinter->getLocation().print()<<endl;
         cout << Donatello->getLocation().print()<<endl;
         cout << Raphael->getLocation().print()<<endl;
         cout << Michelangelo->getLocation().print()<<endl;
         cout << Leonardo->getLocation().print()<<endl;
         cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl<<endl;

         if(team_B.stillAlive() > 0){
            team_B.attack(&team_A);
            cout<<"Team B position after attack:"<<endl;
            cout << John->getLocation().print()<<endl;
            cout << Frank->getLocation().print()<<endl;
            cout << Peters->getLocation().print()<<endl;
            cout << Miller->getLocation().print()<<endl;
            cout << Sam->getLocation().print()<<endl;

            cout << Kakashi->getLocation().print()<<endl;
            cout << Scorpion->getLocation().print()<<endl;
            cout << Ryu->getLocation().print()<<endl;
            cout << Tsunade->getLocation().print()<<endl;
            cout << Naruto->getLocation().print()<<endl;
            cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl<<endl;
         }
      cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
      cout<<"end of round "<<i<<endl;
      cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl<<endl;
      i++;
   }
   while(team_A.stillAlive() > 0 && team_C.stillAlive()){
         team_A.attack(&team_C);
         cout<<"Team A position after attack:"<<endl;
         cout << Sheriff->getLocation().print()<<endl;
         cout << Billy->getLocation().print()<<endl;
         cout << TheGood->getLocation().print()<<endl;
         cout << TheBad->getLocation().print()<<endl;
         cout << TheUgly->getLocation().print()<<endl;

         cout << Splinter->getLocation().print()<<endl;
         cout << Donatello->getLocation().print()<<endl;
         cout << Raphael->getLocation().print()<<endl;
         cout << Michelangelo->getLocation().print()<<endl;
         cout << Leonardo->getLocation().print()<<endl;
         cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl<<endl;


         if(team_C.stillAlive() > 0){
            team_C.attack(&team_A);
            cout<<"Team C position after attack:"<<endl;
            cout << Pat->getLocation().print()<<endl;
            cout << Butch->getLocation().print()<<endl;
            cout << WildBill->getLocation().print()<<endl;
            cout << Jesse->getLocation().print()<<endl;
            cout << Wyatt->getLocation().print()<<endl;

            cout << Shikamaru->getLocation().print()<<endl;
            cout << Neji->getLocation().print()<<endl;
            cout << Choji->getLocation().print()<<endl;
            cout << Ino->getLocation().print()<<endl;
            cout << Hattori->getLocation().print()<<endl;
            cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl<<endl;
         }
      cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
      cout<<"end of round "<<i<<endl;
      cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl<<endl;
      i++;
   }
   while(team_B.stillAlive() > 0 && team_C.stillAlive()){
         team_B.attack(&team_C);
         cout<<"Team B position after attack:"<<endl;
         cout << John->getLocation().print()<<endl;
         cout << Frank->getLocation().print()<<endl;
         cout << Peters->getLocation().print()<<endl;
         cout << Miller->getLocation().print()<<endl;
         cout << Sam->getLocation().print()<<endl;

         cout << Kakashi->getLocation().print()<<endl;
         cout << Scorpion->getLocation().print()<<endl;
         cout << Ryu->getLocation().print()<<endl;
         cout << Tsunade->getLocation().print()<<endl;
         cout << Naruto->getLocation().print()<<endl;
         cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl<<endl;

         if(team_C.stillAlive() > 0){
            team_C.attack(&team_B);
            cout<<"Team C position after attack:"<<endl;
            cout << Pat->getLocation().print()<<endl;
            cout << Butch->getLocation().print()<<endl;
            cout << WildBill->getLocation().print()<<endl;
            cout << Jesse->getLocation().print()<<endl;
            cout << Wyatt->getLocation().print()<<endl;

            cout << Shikamaru->getLocation().print()<<endl;
            cout << Neji->getLocation().print()<<endl;
            cout << Choji->getLocation().print()<<endl;
            cout << Ino->getLocation().print()<<endl;
            cout << Hattori->getLocation().print()<<endl;
            cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl<<endl;
         }
      cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
      cout<<"end of round "<<i<<endl;
      cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl<<endl;
      i++;
   }
      
   if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
   else if(team_B.stillAlive() >0){
      cout << "winner is team_B" << endl;
   }else{
      cout << "winner is team_C" << endl;
   }

   team_A.print();
   team_B.print();
   team_C.print();
   return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}
