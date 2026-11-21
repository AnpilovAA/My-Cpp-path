#include <memory>
#include <iostream>
#include <string>


class Item{
    private:
        size_t item_size_;
    public:
        Item() = default;
        explicit Item(size_t item_size)
            :item_size_(item_size)
            {
            }
        size_t getSize() const{
            return item_size_;
        };
};

class WeaponBag{
    private:
        size_t count_ = 0;
        size_t capacity_ = 0;
        std::unique_ptr<Item[]> items_;
    public:
        /*
        explicit
        Запрещает компилятору молча превращать число в объект. Без него WeaponBag b = 3; скомпилировалось бы (тройка стала бы сумкой). С explicit — только явный вызов WeaponBag b(3)
        */
        explicit WeaponBag(size_t capacity)
            :capacity_(capacity), items_(std::make_unique<Item[]>(capacity_))
            {
            }
        void add(std::unique_ptr<Item> item){
            if (count_ < capacity_){
                items_[count_] = *item;
                ++count_;
            }
            else{
                std::cout << "Bag is full!." << std::endl;
            }
        };
};

std::unique_ptr<WeaponBag> makeStarterBag(){
    auto bag = std::make_unique<WeaponBag>(3);
    return bag;
}


int main(){
    auto newBag = makeStarterBag();
    newBag->add(std::make_unique<Item>(1));
    newBag->add(std::make_unique<Item>(1));
    newBag->add(std::make_unique<Item>(1));
    newBag->add(std::make_unique<Item>(1));
}