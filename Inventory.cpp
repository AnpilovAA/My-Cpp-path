#include "Inventory.hpp"

Inventory::Inventory(size_t capacity)
    : capacity_(capacity), items_(new int[capacity_]()) {}

Inventory::~Inventory() {
    delete[] items_;
}

void Inventory::set_item(size_t index, int item_id) {
    if (index < capacity_) {
        items_[index] = item_id;
    }
}

size_t Inventory::get_capacity() const {
    return capacity_;
}