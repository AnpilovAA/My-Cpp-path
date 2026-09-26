#include <iostream>
#include <string>


class Weapon{
    private:
        std::string name;
        int damage;
    public:
        Weapon(std::string name, int damage)
            : name(name), damage(damage)
            {
            }
        std::string getName(){
            return name;
        }
        int getDamage(){
            return damage;
        }
};


class Player{
    private:
        std::string name;
        Weapon weapon;
    public:
        Player(std::string name, std::string weaponName, int weaponDamage)
            : name(name), weapon(weaponName, weaponDamage)
            {
            }
        std::string getName(){
            return name;
        }
        Weapon getWeapon(){
            return weapon;
        }
        void attack(){
            std::cout<< getName() << " " << "attacks with " << weapon.getName() << " for " << weapon.getDamage() << " damage" << std::endl;
        }
};

class Invetory{
    private:
        Weapon weapon1;
        Weapon weapon2;
    public:
        Invetory(std::string weaponName1, int weaponDamage1, std::string weaponName2, int weaponDamage2)
            : weapon1(weaponName1, weaponDamage1), weapon2(weaponName2, weaponDamage2)
            {
            }
        Weapon getWeapon1(){
            return weapon1;
        }
        Weapon getWeapon2(){
            return weapon2;
        }
};

class Player2{
    private:
        std::string name;
        Invetory invetory;
    public:
        Player2(std::string name, std::string weaponName1, int weaponDamage1, std::string weaponName2, int weaponDamage2)
            : name(name), invetory(weaponName1, weaponDamage1, weaponName2, weaponDamage2)
            {
            }
        std::string getName(){
            return name;
        }
        Invetory getInventory(){
            return invetory;
        }
};



int main(){
    Player player("Doom guy", "Shotgun", 50);
    std::cout<< player.getName() <<std::endl;
    std::cout<< player.getWeapon().getName() <<std::endl;
    std::cout<< player.getWeapon().getDamage() <<std::endl;
    player.attack();
    Player2 player2("CJ", "Minigun", 65, "Glock", 12);
    Invetory invetory = player2.getInventory();
    Weapon wepon1 = invetory.getWeapon1();
    Weapon weapon2 = invetory.getWeapon2();
    std::cout<< wepon1.getName() << " " << wepon1.getDamage() << std::endl;
    std::cout<< weapon2.getName() << " " << weapon2.getDamage() << std::endl;
}