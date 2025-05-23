#include <fstream>

class HTMLPrintable
{
public:
    virtual ~HTMLPrintable() = default;

    virtual std::string printAsHTML() const = 0;
};

class TextPrintable
{
public:
    virtual ~TextPrintable() = default;

    virtual std::string printAsText() const = 0;
};

class JSONPrintable
{
public:
    virtual ~JSONPrintable() = default;

    virtual std::string printAsJSON() const = 0;
};

class Data
{
protected:
    std::string data_;

public:
    Data(std::string data) : data_(std::move(data)) {}

    virtual std::string print() const = 0;
};

class HTMLData : public Data, public HTMLPrintable {
private:
    std::string printAsHTML() const override {
        return "<html>" + data_ + "</html>";
    }

public:
    HTMLData(std::string data) : Data(std::move(data)) {}    

    std::string print() const override {
        return printAsHTML();
    }
};

class TextData : public Data, public TextPrintable {
private:
    std::string printAsText() const override {
        return data_;
    }

public:
    TextData(std::string data) : Data(std::move(data)) {}

    std::string print() const override {
        return printAsText();
    }
};

class JSONData : public Data, public JSONPrintable {
private:
    std::string printAsJSON() const override {
        return "{ \"data\": \"" + data_ + "\"}";
    }

public:
    JSONData(std::string data) : Data(std::move(data)) {}

    std::string print() const override {
        return printAsJSON();
    }
};

void saveToFile(std::ofstream& file, const Data& data) {
    file << data.print();
}