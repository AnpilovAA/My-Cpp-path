#include <memory>
#include <iostream>



class Item{
    private:
        size_t item_size_;
    public:
        Item = default;
        explicit Item(size_t item)
            :item_size_(item);
            {
            }
        size_t getSize() const{
            return item_size_;
        }
};


class Chest{
    std::unique_ptr<Item> item_;
    public:
        void store(std::unique_ptr<Item> item){
            item_ = std::move(item);
        }
        std::unique_ptr<Item> loot(){
            auto stored_item = std::make_unique<Item>(item_);
            return std::move(stored_item);
        }
        bool empty(){
            if (item_){
                std::cout<< "Not empty" << std::endl;
            } else {
                std::cout "Chest Empty!" << std::endl;
            }
        };

};


int main(){
    std::unique_ptr<Chest> newChest;
    std::unique_ptr<Item> branch = std::make_unique<Item>(7);
    newChest->store(std::move(branch));
    newChest->empty();
    auto lootedBranch = newChest->loot();
    newChest->empty();
    
};