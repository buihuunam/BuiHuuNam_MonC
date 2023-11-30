#include <iostream>
#include <mutex>

using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static mutex mutex_;

    // Private constructor to prevent instantiation from outside.
    Singleton() {}

public:
    // Public method to get the instance of the Singleton class.
    static Singleton* getInstance() {
        // Check if an instance already exists.
        if (instance == nullptr) {
            lock_guard<mutex> lock(mutex_); // Ensure thread safety.

            // Check again inside the lock to prevent multiple instantiations.
            if (instance == nullptr) {
                instance = new Singleton();
            }
        }

        return instance;
    }

    // Other methods and members can be added as needed.

    // Delete copy constructor and assignment operator to prevent duplication.
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

// Initialization of static members.
Singleton* Singleton::instance = nullptr;
mutex Singleton::mutex_;

int main() {
    // Get the singleton instance.
    Singleton* singletonInstance = Singleton::getInstance();

    // Use the singleton instance as needed.

    return 0;
}
