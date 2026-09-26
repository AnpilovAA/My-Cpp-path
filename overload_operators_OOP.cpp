#include <iostream>
#include <string>


class Point{
    public:
        int x;
        int y;
        Point(int x, int y)
            :x(x), y(y)
            {
            }
        Point operator+(const Point& other){
            return Point(x + other.x, y + other.y);
        }
};


class Player{
    private:
        std::string name;
        int hp;
    public:
        Player(std::string name, int hp)
            : name(name), hp(hp)
            {
            }

            bool operator==(const Player& otherPlayer){
                if(name==otherPlayer.name && hp==otherPlayer.hp){
                    return true;
                }
                else{
                    return false;
                }
            };
};


int main(){
    Point a(2, 3);
    Point b(5,7);
    Point c {a + b};
    std::cout<< c.x << " " << c.y << std::endl;

    Player d("Doom Guy", 100);
    Player f("Doom Guy", 100);
    Player g("Doom Guy", 50);

    std::cout << (d == f) << std::endl;
    std::cout << (d == g) << std::endl;
}