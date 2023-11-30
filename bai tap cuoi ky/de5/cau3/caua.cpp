#include <iostream>
#include <vector>

using namespace std;

class ShopRent {
protected:
    int shopNumber;
    double area;

public:
    ShopRent(int num, double a) : shopNumber(num), area(a) {}

    virtual double calculateRent() const = 0;

    void displayInfo() const {
        cout << "Shop Number: " << shopNumber << ", Area: " << area << "m^2";
    }
};

class FoodShop : public ShopRent {
private:
    double coldStorageCost;

public:
    FoodShop(int num, double a, double coldCost) : ShopRent(num, a), coldStorageCost(coldCost) {}

    double calculateRent() const override {
        return 40000000 * area + calculateTax() + coldStorageCost;
    }

    double calculateTax() const {
        return 0.05 * calculateRevenue();
    }

    virtual double calculateRevenue() const {
        // Assume some revenue calculation for food shops
        return 0;
    }
};

class ClothingShop : public ShopRent {
public:
    ClothingShop(int num, double a) : ShopRent(num, a) {}

    double calculateRent() const override {
        return 40000000 * area + calculateTax();
    }

    double calculateTax() const {
        return 0.1 * calculateRevenue();
    }

    virtual double calculateRevenue() const {
        // Assume some revenue calculation for clothing shops
        return 0;
    }
};

int main() {
    vector<ShopRent*> shops;

    shops.push_back(new FoodShop(1, 50, 1000000)); // Example food shop
    shops.push_back(new ClothingShop(2, 30)); // Example clothing shop

    for (const auto& shop : shops) {
        shop->displayInfo();
        cout << ", Annual Rent: " << shop->calculateRent() << " VND\n";
    }

    // Clean up dynamic memory
    for (const auto& shop : shops) {
        delete shop;
    }

    return 0;
}
