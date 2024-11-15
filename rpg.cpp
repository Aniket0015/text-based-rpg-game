#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;



class weapon {  // Define weapon class before player
    protected:
          string name;
          int damage;
    public:
        weapon(string name, int damage): name(name), damage(damage) {}

        virtual string getname() {
            return name;
        }

        virtual int getdamage() {
            return damage;
        }

        virtual int attack() {
            return getdamage(); // Default attack behavior, returns damage
        }
};
class heal{};
class inventory{
    vector<weapon*> player_weapon;
    vector<heal*> player_healing;
};

class player {
    private:
     int health;
     string name;
     weapon* wpn;  // Pointer to weapon class
     int level = 1 ,exp=0, speed=13,based;

     public:
     // Constructor
     player(string name, weapon* w) : name(name), wpn(w) {
        health = 100;
     }

     int gethealth() {
          return health;
     }

     void takedamage(int hit) {
       health -= hit;
     }

     int attack() {
        return wpn->attack();  // Call the attack() function of the weapon object
     } 
     
     int sendspeed(){
        return speed;
     }
     void collect_exp_from_kill(int exp_from){
        exp+=exp_from;

       if(level<12)  {
             while (exp >= level * 100) { // Need level * 100 XP for level up
            level++;
            exp -= 100 * level; // Subtract the XP spent for leveling up
            health += 10;  // Increase health by 10 per level-up
            speed += 2;    // Increase speed per level-up
            cout << "Level Up! You are now level " << level << endl;
          }
        }
     }

     
};

class enemy {
    protected:
    string name;
    int health;
    int a_damage;
    int exp, speed;
     public:
       int gethealth(){
        return health;
       }
     string getName() {
        return name;
     }
     int attack_e(){
        return a_damage;
     }
     int return_exp(){
        return exp;
     }
     bool is_dead(){
        return health<=0;
     }
     int sendspeed(){
        return speed;
     }
     void takedamage( int damage){
        health-=damage;
     }
}; //Note  add speed thing in future and distance for bow 

class goblin : public enemy {
    public:
    goblin() {
        name = "goblin";
        health = 46;
        a_damage=12;
        exp=15;
    }
};
class toll : public enemy {
    public:
      toll() {
        name = "toll";
        health = 86;
        a_damage=21;
        exp=27;
    }
};
class orc : public enemy {
    public:
      orc() {
        name = "orc";
        health = 78;
        a_damage=19;
         exp=21;
    }
};

class sword : public weapon {
    public:
    
    sword() : weapon("sword", 21) {}

    int attack() override {
        return getdamage();  // Return weapon's damage
    }
};

class axe: public weapon {
    public:
    axe() : weapon("axe", 26) {}

    int attack() override {
        return getdamage();  // Return weapon's damage
    }
};
class spear: public weapon {
    public:
     spear() : weapon("spear", 23) {}

    int attack() override {
        return getdamage();  // Return weapon's damage
    }
};


  void combat( player &main , enemy &boss){
        
         if(main.sendspeed()>boss.sendspeed())
         {
          // player will attack first , So use loop for this , while is great for ths
           while(1) // 1 is to run infinity till break activate, it not best but it will work
           { 
               cout << "Player attacks!" << endl;
               boss.takedamage(main.attack());
               cout << "Enemy health: " << boss.gethealth() << endl;
               if(boss.is_dead()){
                   cout << "The " << boss.getName() << " is defeated!" << endl;
                   main.collect_exp_from_kill(boss.return_exp());
                   break;
               }

                 cout << "Enemy attacks!" << endl;
                 main.takedamage(boss.attack_e());
                 cout << "Player health: " << main.gethealth() << endl;

                  if(main.gethealth()<=0){
                    cout << "You have been defeated!" << endl;
                         break;
                  }
           }
        }else{
            while(1){
                 cout << "Enemy attacks!" << endl;
                 main.takedamage(boss.attack_e());
                 cout << "Player health: " << main.gethealth() << endl;

                  if(main.gethealth()<=0){
                    cout << "You have been defeated!" << endl;
                         break;
                  }
                    
                      cout << "Player attacks!" << endl;
               boss.takedamage(main.attack());
               cout << "Enemy health: " << boss.gethealth() << endl;
               if(boss.is_dead()){
                   cout << "The " << boss.getName() << " is defeated!" << endl;
                   main.collect_exp_from_kill(boss.return_exp());
                   break;
               }

            }
        }
       
  }
int main() {
    
    sword swordObj;  // Create a sword object
    player p("Hero", &swordObj);  // Create a player and assign the sword

    cout << "Player health: " << p.gethealth() << endl;
    cout << "Player attacks and deals: " << p.attack() << " damage!" << endl;
  
    return 0;
}
