#include <iostream>
#include <string>

class Character{
    public:
        std::string name;
        int hp;
        Character(std::string name, int hp)
            : name(name), hp(hp)
            {
            }
        void takeDamage(int damage){
            hp -= damage;
        }
        void showInfo() const{
            std::cout << name << "\n" << hp << std::endl;
        };
};


class Player : public Character{
    public:
        Player(std::string name, int hp)
            : Character(name, hp)
            {
            }
        void heal(int amount){
            hp += amount;
        }
};


class Enemy: public Character{
    public:
        Enemy(std::string name, int hp)
            : Character(name, hp)
            {
            }
        void attack(){
            std::cout << name << " attacked" << std::endl;
        };
};


int main(){
    Player hero("Doom Guy", 100);
    Enemy enemy("Ksenos", 150);
    hero.showInfo();
    enemy.showInfo();
    
};