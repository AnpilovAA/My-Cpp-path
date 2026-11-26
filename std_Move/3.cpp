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
                std::cout<< "Not empty" << std::endl;
                return false;
            } else {
                std::cout << "Chest Empty!" << std::endl;
                return true;
            }
        };

};


int main(){
    auto newChest = std::make_unique<Chest>();
    auto branch = craftItem(7);
    newChest->store(std::move(branch));
    newChest->empty();
    auto lootedBranch = newChest->loot();
    newChest->empty();
    auto anotherItem = newChest->loot();
}