#include<iostream>
#include<string>
#include<vector>

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

class player {
    private:
     int health;
     string name;
     weapon* wpn;  // Pointer to weapon class

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
};

class enemy {
    protected:
    string name;
    int health;
     public:

     string getName() {
        return name;
     }
};

class goblin : public enemy {
    public:
    goblin() {
        name = "goblin";
        health = 100;
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
     spear() : weapon("axe", 23) {}

    int attack() override {
        return getdamage();  // Return weapon's damage
    }
};
int main() {
    sword swordObj;  // Create a sword object
    player p("Hero", &swordObj);  // Create a player and assign the sword

    cout << "Player health: " << p.gethealth() << endl;
    cout << "Player attacks and deals: " << p.attack() << " damage!" << endl;

    return 0;
}
