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


class Vector2{
    public:
        float x;
        float y;
        Vector2(float x, float y)
            : x(x), y(y)
            {
            }
        Vector2 operator-(const Vector2& otherVector2){
            return Vector2(x-otherVector2.x, y-otherVector2.y);
        }
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

    Vector2 t(10, 8);
    Vector2 y(3, 5);
    Vector2 u = t - y;
    std::cout << u.x << " " << u.y << std::endl;
}
// a + b это сложение двух объектов класса в данном случае мы складывали параметры объектов, и сумму этих параметров объектов использовали для инициализации
// operator+ мы сообщаем компилятору, что наш класс позволяем объектам класса производить слажение его параметров.
// operator+ должен вернуть объект/экземпляр класса Point
// operator== является булевым оператором, он сравнивает параметры класса а вот operator+ является математическим и позволяет складывать параметры 