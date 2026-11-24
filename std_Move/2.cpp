#include <memory>
#include <iostream>


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


std::unique_ptr<Item> craftItem(size_t size){
    auto newItem = std::make_unique<Item>(size);
    return newItem;
};


void inspect(const std::unique_ptr<Item>& item){
    if (item){
        std::cout << item->getSize() << std::endl;
    } else {
        std::cout << "empty" << std::endl;
    }
    
};

void consume(std::unique_ptr<Item> item){
      std::cout<< "consumed: " << item->getSize() << std::endl;
}


int main(){
    auto item = craftItem(7);
    inspect(item);
    consume(std::move(item));
    inspect(item);
};