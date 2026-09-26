#include <iostream>
#include <string>


class Player{
    private:
        std::string name = "";
        int hp;
    public:
        static int count;
        Player(std::string name, int hp)
                : name(name), hp(hp)
                {
                }
        std::string getName() const {
            return name;
        }
        int getHp() const{
            return hp;
        }
        int takeDamage(int amount){
            hp -= amount;
            return hp;
        }
};

int Player::count = 0;

class Player2 {
private:
    int hp;

public:
    Player2(int hp)
        : hp(hp)
    {
    }

    int getHp() const {
        return hp;
    }
};

int main(){
    const Player hero("Doom Guy", 100);
    std::cout<< hero.getName() << std::endl;
    std::cout<< hero.getHp() << std::endl;
    std::cout<< hero.takeDamage(20); // 2. Ошибка потому, что при создании объекта мы используем  const и указываем что объет не будет изменяться при этом takeDamage должен изменять паметр hp. 
    const Player2 hero2(100);
    std::cout<< hero2.getHp() << std::endl;
}