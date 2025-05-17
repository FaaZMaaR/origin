#include <iostream>
#include <fstream>
#include <vector>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class PrintLog : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << "Message: " << message << std::endl;
    }
};

class WriteLog : public LogCommand {
private:
    std::string filePath;
public:
    WriteLog(const std::string& filePath) : filePath(filePath) {}
    void print(const std::string& message) override {
        std::ofstream file(filePath, std::ios::app);
        if (!file.is_open()) {
            std::cout << "Failed to open " << filePath << std::endl;
            return;
        }
        file << message << std::endl;
    }
};

void print(LogCommand& log, const std::string& message) {
    log.print(message);
}

int main() {
    PrintLog printLog;
    WriteLog writeLog("messages.log");
    std::string message = "test message";
    print(printLog, message);
    print(writeLog, message);
}