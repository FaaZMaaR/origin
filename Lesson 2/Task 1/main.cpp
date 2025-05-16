#include <string>
#include <iostream>
#include <algorithm>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
    virtual ~Text() {}
};

class DecoratedText : public Text {
protected:
    std::unique_ptr<Text> text_;
public:
    explicit DecoratedText(std::unique_ptr<Text>&& text) {
        text_ = std::move(text);
    }
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(std::unique_ptr<Text>&& text) : DecoratedText(std::move(text)) {}
    void render(const std::string& data) const {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(std::unique_ptr<Text>&& text) : DecoratedText(std::move(text)) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public DecoratedText {
public:
    explicit Paragraph(std::unique_ptr<Text>&& text) : DecoratedText(std::move(text)) {}
    void render(const std::string& data) const {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public DecoratedText {
public:
    explicit Reversed(std::unique_ptr<Text>&& text) : DecoratedText(std::move(text)) {}
    void render(const std::string& data) const {
        std::string rdata = data;
        std::reverse(rdata.begin(), rdata.end());
        text_->render(rdata);
    }
};

class Link : public DecoratedText {
public:
    explicit Link(std::unique_ptr<Text>&& text) : DecoratedText(std::move(text)) {}
    void render(const std::string& link, const std::string& data) const {
        std::cout << "<a href=" << link << ">";
        text_->render(data);
        std::cout << "</a>";
    }
};

int main() {
    auto text_block = std::make_unique<ItalicText>(std::make_unique<BoldText>(std::make_unique<Text>()));
    text_block->render("Hello world");
    std::cout << std::endl;
    auto text_block2 = std::make_unique<Paragraph>(std::make_unique<Text>());
    text_block2->render("Hello world");
    std::cout << std::endl;
    auto text_block3 = std::make_unique<Reversed>(std::make_unique<Text>());
    text_block3->render("Hello world");
    std::cout << std::endl;
    auto text_block4 = std::make_unique<Link>(std::make_unique<Text>());
    text_block4->render("netology.ru", "Hello world");
    std::cout << std::endl;
}