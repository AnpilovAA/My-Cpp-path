#include <memory>
#include <iostream>



class Item{
    private:
        size_t item_size_ = 0;
    public:
        Item() = default;
        explicit Item(size_t item_size)
            :item_size_(item_size)
            {
            }
        size_t getSize() const{
            return item_size_;
        }
};


std::unique_ptr<Item> craftItem(size_t size){
    auto newItem = std::make_unique<Item>(size);
    return newItem;
};


class Chest{
    std::unique_ptr<Item> item_;
    public:
        void store(std::unique_ptr<Item> item){
            item_ = std::move(item);
        }
        std::unique_ptr<Item> loot(){
            std::unique_ptr<Item> stored_item = std::move(item_);
            return stored_item;
        }
        bool empty() const{
            if (item_){
                std::cout << " Chest is not empty" << std::endl;
                return false;
            } else {
                std::cout << " Chest is Empty!" << std::endl;
                return true;
            }
        }
        std::unique_ptr<Item> replace(std::unique_ptr<Item> newItem){
            auto oldItem = std::move(item_);
            item_ = std::move(newItem);
            return oldItem;
        }
};


void transfer(Chest& from, Chest& to){
    to.store(from.loot());
}

int main(){
    auto item = craftItem(7);
    auto newChest = std::make_unique<Chest>();
    newChest->store(std::move(item));
    auto olditem = newChest->replace(std::move(craftItem(9)));
    auto backItem = newChest->loot();
    std::cout << olditem->getSize() << std::endl;
    std::cout << backItem->getSize() << std::endl;

    auto anotherChest = std::make_unique<Chest>();
    anotherChest->store(craftItem(3));
    auto chestItem = anotherChest->loot();
    std::cout << chestItem->getSize() << std::endl;
}