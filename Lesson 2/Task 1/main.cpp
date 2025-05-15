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
    std::shared_ptr<Text> text_;
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    explicit DecoratedText(std::shared_ptr<Text> text) : text_(text) {}
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    explicit ItalicText(std::shared_ptr<Text> text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    explicit BoldText(std::shared_ptr<Text> text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public DecoratedText {
public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}
    explicit Paragraph(std::shared_ptr<Text> text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public DecoratedText {
public:
    explicit Reversed(Text* text) : DecoratedText(text) {}
    explicit Reversed(std::shared_ptr<Text> text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::string rdata = data;
        std::reverse(rdata.begin(), rdata.end());
        text_->render(rdata);
    }
};

class Link : public DecoratedText {
public:
    explicit Link(Text* text) : DecoratedText(text) {}
    explicit Link(std::shared_ptr<Text> text) : DecoratedText(text) {}
    void render(const std::string& link, const std::string& data) const {
        std::cout << "<a href=" << link << ">";
        text_->render(data);
        std::cout << "</a>";
    }
};

int main() {
    auto text = std::make_shared<Text>();
    auto text_block = ItalicText(new BoldText(text));
    text_block.render("Hello world");
    std::cout << std::endl;
    auto text_block2 = Paragraph(text);
    text_block2.render("Hello world");
    std::cout << std::endl;
    auto text_block3 = Reversed(text);
    text_block3.render("Hello world");
    std::cout << std::endl;
    auto text_block4 = Link(text);
    text_block4.render("netology.ru", "Hello world");
    std::cout << std::endl;
}