#include <iostream>

class Car {
protected:
    char* brand;
    int cylinders;
    int power;

public:

    Car() : brand(nullptr), cylinders(0), power(0) {}


    Car(const char* b, int c, int p) {
        int length = 0;
        while (b[length] != '\0') {
            length++;
        }
        brand = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            brand[i] = b[i];
        }
        brand[length] = '\0';
        cylinders = c;
        power = p;
    }

    virtual ~Car() {
        delete[] brand;
    }


    virtual void print() const {
        std::cout << "Brand: " << brand << ", Cylinders: " << cylinders << ", Power: " << power << " HP" << std::endl;
    }


    void setBrand(const char* b) {
        delete[] brand;
        int length = 0;
        while (b[length] != '\0') {
            length++;
        }
        brand = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            brand[i] = b[i];
        }
        brand[length] = '\0';
    }
};

class Truck : public Car {
private:
    int loadCapacity;

public:

    Truck() : Car(), loadCapacity(0) {}


    Truck(const char* b, int c, int p, int l) : Car(b, c, p), loadCapacity(l) {}


    ~Truck() {}


    void print() const override {
        Car::print();
        std::cout << "Load Capacity: " << loadCapacity << " kg" << std::endl;
    }


    void setLoadCapacity(int l) {
        loadCapacity = l;
    }
};

int main() {

    Car car("Toyota", 4, 150);
    Truck truck("Volvo", 6, 300, 5000);

    std::cout << "Initial car and truck details:\n";
    car.print();
    truck.print();


    car.setBrand("Honda");
    truck.setBrand("Scania");
    truck.setLoadCapacity(7000);

    std::cout << "\nUpdated car and truck details:\n";
    car.print();
    truck.print();

    return 0;
}
