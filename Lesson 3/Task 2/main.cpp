#include <iostream>
#include <fstream>
#include <vector>

class Observer {
public:
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};

class WarningHandler : public Observer {
public:
    void onWarning(const std::string& message) override {
        std::cout << "Message: " << message << std::endl;
    }
};

class ErrorHandler : public Observer {
private:
    std::string filePath;
public:
    ErrorHandler(const std::string& filePath) : filePath{ filePath } {}
    void onError(const std::string& message) override {
        std::ofstream file(filePath, std::ios::app);
        if (!file.is_open()) {
            std::cout << "Failed to open " << filePath << std::endl;
            return;
        }
        file << message << std::endl;
    }
};

class FatalErrorHandler : public Observer {
private:
    std::string filePath;
public:
    FatalErrorHandler(const std::string& path) : filePath{ path } {}
    void onFatalError(const std::string& message) override {
        std::cout << "Message: " << message << std::endl;
        std::ofstream file(filePath, std::ios::app);
        if (!file.is_open()) {
            std::cout << "Failed to open " << filePath << std::endl;
            return;
        }
        file << message << std::endl;
    }
};

class Observed {
private:
    std::vector<std::weak_ptr<Observer>> observers;
public:
    void add_observer(std::weak_ptr<Observer> obsPtr) {
        observers.push_back(obsPtr);
    }
    void warning(const std::string& message) const {
        for (auto& observer : observers) {
            if (auto strong_ptr = observer.lock()) {
                strong_ptr->onWarning(message);
            }
        }
    }
    void error(const std::string& message) const {
        for (auto& observer : observers) {
            if (auto strong_ptr = observer.lock()) {
                strong_ptr->onError(message);
            }
        }
    }
    void fatalError(const std::string& message) const {
        for (auto& observer : observers) {
            if (auto strong_ptr = observer.lock()) {
                strong_ptr->onFatalError(message);
            }
        }
    }
};

int main() {
    Observed observed;
    auto warningPtr = std::make_shared<WarningHandler>();
    auto errorPtr = std::make_shared<ErrorHandler>("errors.log");
    auto fatalErrorPtr = std::make_shared<FatalErrorHandler>("fatal_errors.log");
    observed.add_observer(warningPtr);
    observed.add_observer(errorPtr);
    observed.add_observer(fatalErrorPtr);
    observed.warning("warning message");
    observed.error("error message");
    observed.fatalError("fatal error message");
}