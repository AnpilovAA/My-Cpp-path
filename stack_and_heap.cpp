#include <iostream>

class AudioBuffer {
private:
    float* samples_ = nullptr;
    size_t capacity_ = 0;

public:
    // Конструктор выделяет память и зануляет сэмплы
    AudioBuffer(size_t capacity)
        : samples_(new float[capacity]{}), capacity_(capacity) {}

    // Запрет копирования (защита от двойного удаления)
    AudioBuffer(const AudioBuffer&) = delete;
    AudioBuffer& operator=(const AudioBuffer&) = delete;

    // Деструктор гарантирует возврат памяти в кучу
    ~AudioBuffer() {
        delete[] samples_;
    }

    void set_sample(size_t index, float value) {
        if (index < capacity_) {
            samples_[index] = value;
        } else {
            std::cerr << "Error: Index " << index << " out of bounds!\n";
        }
    }

    float get_sample(size_t index) const {
        if (index < capacity_) {
            return samples_[index];
        }
        return 0.0f;
    }

    size_t get_capacity() const {
        return capacity_;
    }
};


int main(){
    AudioBuffer buffer(10);
    buffer.set_sample(5, 4);
    std::cout << buffer.get_sample(2) << std::endl;
    std::cout << buffer.get_capacity() << std::endl;
}