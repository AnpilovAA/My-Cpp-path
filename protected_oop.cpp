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


class TestPrivate{
    private:
        int value;
    public:
        TestPrivate(int value)
            :value(value)
            {
            }
};


class TestProtected{
    protected:
        int value;
    public:
        TestProtected(int value)
            :value(value)
        {
        }
};


class TestPublic{
    public:
        int value;
        TestPublic(int value)
            :value(value)
            {
            }
};



class ChildPrivate: public TestPrivate{
    public:
        ChildPrivate(int value)
            :TestPrivate(value)
            {
            }
        void changeValuePrivate(){
            value += 1;
        }
};

class ChildProtected: public TestProtected{
    public:
        ChildProtected(int value)
            :TestProtected(value)
            {
            }
        void changeValumeProtected(){
            value += 2;
        }
};


class ChildPublic: public TestPublic{
    public:
        ChildPublic(int value)
            : TestPublic(value)
            {
            }
        void changeValuePublic(){
            value += 3;
        }
};


int main(){
    Player hero("Doom Guy", 10);
    Enemy enemy("Ksenos", 15);
    hero.takeDamage(5);
    hero.heal(10);
    enemy.takeDamage(10);
    enemy.enrage();
    ChildPrivate chilPrivate(1);
    ChildProtected chilProtected(1);
    ChildPublic chilPublic(1);
    chilPrivate.changeValuePrivate();
    chilProtected.changeValumeProtected();
    chilPublic.changeValuePublic();
    chilPrivate.value = 2;
    chilProtected.value = 3;
    chilPublic.value = 4;

};
/*
1. Базовый класс TestPrivate int value не доступен кроме инициализации. TestProtected по мимо инициализации позволяет потомкам изменять внутри своего класса value. TestPublic позволяет получить доступ с любой области как в потомках так и снаружи в main
2. Произвольные класс ChildPublic и ChildProtected позволяет изменять value ChildPrivate не позволяет изменять параметр value
3. В main только ChildPublic позволяет на прямую изменять параметр value. Все остальные не позволяют изменять на прямую параметр value
*/