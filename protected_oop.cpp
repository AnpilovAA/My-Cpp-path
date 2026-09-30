#include <iostream>
#include <string>


class Character{
    protected:
        int hp;
        std::string name;
    public:
        Character(std::string name, int hp)
            :hp(hp), name(name)
            {
            }
        void takeDamage(int damage){
            hp -= damage;
        }
};

class Player : public Character{
    public:
        Player(std::string name, int hp)
            : Character(name, hp)
            {
            }
        void heal(int amount){
            hp += amount;
        };
};


class Enemy : public Character{
    public:
        Enemy(std::string name, int hp)
            :Character(name, hp)
            {
            }
        void enrage(){
            hp += 50;
        };
};


int main(){
    Player hero("Doom Guy", 10);
    Enemy enemy("Ksenos", 15);
    hero.takeDamage(5);
    hero.heal(10);
    enemy.takeDamage(10);
    enemy.enrage();
};