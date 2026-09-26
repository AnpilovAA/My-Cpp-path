#include <iostream>
#include <string>


class Player{
    private:
        int hp;
    public:
        static int count;
        Player(int hp)
            :hp(hp)
            {
                count++;
            }
        static int getCount(){
            return count;
        };
};

int Player::count = 0;


class Enemy{
    private:
        int hp;
    public:
        static int count;
        Enemy(int hp)
            : hp(hp)
        {
            count++;
        }
        static int getCount(){
            return count;
        }
        static void showHp(){
            std::cout << count << std::endl;
        }

};


int Enemy::count = 0;


int main(){
    Player hero(1);
    Player enemy(2);
    Player x(3);
    Enemy enemy1(1);
    Enemy enemy2(1);
    Enemy enemy3(1);
    Enemy enemy4(1);
    std::cout << enemy.count << std::endl;
    std::cout << Enemy::getCount() << std::endl;
}
// 1.Static-поле отличается тем, что оно инициализируется отдельно от обычных полей, так же оно можно сказать изолировано от других полей, что позволяет к примеру считать количество созданных экземпляров класса, может быть это можно как то ещё использовать.
// 2.Count инициализируется в родительском классе по этому он существует в единственном экземпляре для всех Player
// 3.Player::getCount() необходимо писать, поскольку у hero нет доступа к родительскому get.Count ведь это статическое поле, к нему имеет доступ только родитель Player