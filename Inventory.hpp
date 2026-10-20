#pragma once
#include <cstddef>

class Inventory {
private:
    size_t capacity_ = 0;
    int* items_ = nullptr;

public:
    Inventory(size_t capacity);

    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;

    ~Inventory();

    void set_item(size_t index, int item_id);
    size_t get_capacity() const;
};