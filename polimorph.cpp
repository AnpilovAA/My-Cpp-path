#include <iostream>
#include <string>

class ILogger {
public:
    ILogger() = default;
    virtual void log(const std::string& message) = 0;

    virtual ~ILogger() {
        std::cout << "~ILogger destructed\n";
    }
};

class FileLogger : public ILogger {
private:
    char* buffer_ = nullptr;
    size_t buffer_size_ = 0;

public:
    FileLogger(size_t buffer_size)
        : buffer_(new char[buffer_size]()), buffer_size_(buffer_size) {}

    // Запрещаем копирование, так как класс владеет сырым указателем
    FileLogger(const FileLogger&) = delete;
    FileLogger& operator=(const FileLogger&) = delete;

    void log(const std::string& message) override {
        std::cout << "[File] " << message << '\n';
    }

    ~FileLogger() override {
        delete[] buffer_;
        std::cout << "~FileLogger: buffer (" << buffer_size_ << " bytes) freed\n";
    }
};


class IDevice{
    public:
        IDevice()
        {
        }
        virtual void print_status() const = 0;
        virtual ~IDevice()
        {
        }
};

class Sensor: public IDevice{
    private:
        double* readings_ = nullptr;
        size_t count_ = 0; 
    public:
        Sensor(size_t count)
            :count_(count), readings_(new double[count]())
            {
            }
        Sensor(const Sensor&) = delete;
        Sensor& operator=(const Sensor&) = delete;
        
        void set_reading(size_t index, double value){
            if(index < count_){
                readings_[index] = value;
            }
        }        
        void print_status() const override{
            std::cout << count_ << std::endl;
            if(count_ > 0){
                std::cout << readings_[0] << std::endl;
            }
        }
        virtual ~Sensor(){
            delete[] readings_;
            std::cout << count_ << " Is free from memory" << std::endl;
        }
    };


int main() {
    ILogger* logger = new FileLogger(256);
    logger->log("Game started");

    delete logger; // Вызовет ~FileLogger(), а затем ~ILogger()
    return 0;
}