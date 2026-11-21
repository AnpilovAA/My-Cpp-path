#include <memory>


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


std::unique_ptr