#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum class Type {
    WARNING,
    ERROR,
    FATAL_ERROR,
    UNKNOWN_MSG
};

class LogMessage {
private:
    Type messageType;
    std::string message_;
public:
    LogMessage(Type type, const std::string& message) : messageType{ type }, message_{ message } {}
    Type type() const {
        return messageType;
    }
    const std::string& message() const {
        return message_;
    }
};

class MessageHandler {
protected:
    std::unique_ptr<MessageHandler> nextHandler;
public:
    void set_next_handler(std::unique_ptr<MessageHandler> msgHandler) {
        if (!nextHandler) {
            nextHandler = std::move(msgHandler);
        }
        else {
            nextHandler->set_next_handler(std::move(msgHandler));
        }
    }
    virtual void handle_message(const LogMessage& msg) = 0;
};

class FatalErrorHandler : public MessageHandler {
public:
    void handle_message(const LogMessage& msg) override {
        if (msg.type() == Type::FATAL_ERROR) {
            throw std::runtime_error("Fatal Error: " + msg.message());
        }
        else if (nextHandler) {
            nextHandler->handle_message(msg);
        }
        else {
            std::cout << "Message was not handled" << std::endl;
        }
    }
};

class ErrorHandler : public MessageHandler {
private:
    std::string filePath;
public:
    ErrorHandler(const std::string& filePath) : filePath{ filePath } {}
    void handle_message(const LogMessage& msg) override {
        if (msg.type() == Type::ERROR) {
            std::ofstream file(filePath, std::ios::app);
            if (!file.is_open()) {
                std::cout << "Failed to open " << filePath << std::endl;
                return;
            }
            file << msg.message() << std::endl;
        }
        else if (nextHandler) {
            nextHandler->handle_message(msg);
        }
        else {
            std::cout << "Message was not handled" << std::endl;
        }
    }
};

class WarningHandler : public MessageHandler {
public:
    void handle_message(const LogMessage& msg) override {
        if (msg.type() == Type::WARNING) {
            std::cout << "Warning: " << msg.message() << std::endl;
        }
        else if (nextHandler) {
            nextHandler->handle_message(msg);
        }
        else {
            std::cout << "Message was not handled" << std::endl;
        }
    }
};

class UnknownMessageHandler : public MessageHandler {
public:
    void handle_message(const LogMessage& msg) override {
        if (msg.type() == Type::UNKNOWN_MSG) {
            throw std::runtime_error("Unknown type of message: " + msg.message());
        }
        else if (nextHandler) {
            nextHandler->handle_message(msg);
        }
        else {
            std::cout << "Message was not handled" << std::endl;
        }
    }
};

int main() {
    auto fatalErrHandPtr = std::make_unique<FatalErrorHandler>();
    fatalErrHandPtr->set_next_handler(std::make_unique<ErrorHandler>("errors.log"));
    fatalErrHandPtr->set_next_handler(std::make_unique<WarningHandler>());
    fatalErrHandPtr->set_next_handler(std::make_unique<UnknownMessageHandler>());
    try {
        fatalErrHandPtr->handle_message(LogMessage(Type::FATAL_ERROR, "fatal error test"));
    }
    catch (const std::exception& err) {
        std::cout << err.what() << std::endl;
    }    
    fatalErrHandPtr->handle_message(LogMessage(Type::ERROR, "error test"));
    fatalErrHandPtr->handle_message(LogMessage(Type::WARNING, "warning test"));
    try {
        fatalErrHandPtr->handle_message(LogMessage(Type::UNKNOWN_MSG, "unknown message test"));
    }
    catch (const std::exception& err) {
        std::cout << err.what() << std::endl;
    }    
}