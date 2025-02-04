#include <iostream>
#include <vector>

class big_integer {
private:
    std::vector<int>* number;

private:
    big_integer(std::vector<int>* aNumber = nullptr) : number{ aNumber } {}

    std::vector<int>* sumNumbers(const std::vector<int>& other, int begin) const {
        std::vector<int>* result=new std::vector<int>;
        int digitSum{ 0 };
        int extra{ 0 };
        auto numIter = number->begin();
        while (begin > 0) {
            result->push_back(*numIter);
            ++numIter;
            --begin;
        }
        for (auto i = other.begin(); i != other.end(); i++) {
            digitSum += *i;
            if (numIter != number->end()) {
                digitSum += *numIter;
                ++numIter;
            }
            digitSum += extra;
            result->push_back(digitSum % 10);
            extra = digitSum / 10;
            digitSum = 0;
        }
        while (numIter != number->end()) {
            digitSum += *numIter;
            digitSum += extra;
            result->push_back(digitSum % 10);
            extra = digitSum / 10;
            digitSum = 0;
            ++numIter;
        }
        if (extra != 0) {
            result->push_back(extra);
        }
        return result;
    }

    std::vector<int>* multDigit(int digit) const {
        std::vector<int>* result = new std::vector<int>;
        int digitMult{ 0 };
        int extra{ 0 };
        for (auto i = number->begin(); i != number->end(); i++) {
            digitMult = *i * digit;
            digitMult += extra;
            result->push_back(digitMult % 10);
            extra = digitMult / 10;
        }
        if (extra != 0) {
            result->push_back(extra);
        }
        return result;
    }

public:
    big_integer(const std::string& aNumber) : number{ new std::vector<int>() } {
        for (auto symb : aNumber) {
            number->insert(number->begin(), symb - '0');
        }
    }
    ~big_integer() {
        delete number;
    }

    big_integer(const big_integer& other) = delete;
    big_integer& operator=(const big_integer& other) = delete;

    big_integer(big_integer&& other) noexcept : number{ std::exchange(other.number,nullptr) } {}
    big_integer& operator=(big_integer&& other) noexcept {
        std::swap(number, other.number);
        return *this;
    }

    big_integer operator+(const big_integer& other) const {        
        return big_integer(sumNumbers(*other.number, 0));
    }

    big_integer operator*(const big_integer& other) const {
        big_integer result;
        std::vector<int>* tmp{};
        auto otherNumIter = other.number->begin();
        result.number = multDigit(*otherNumIter);
        for (auto i = otherNumIter+1; i != other.number->end(); i++) {
            tmp = multDigit(*i);
            tmp = std::exchange(result.number, result.sumNumbers(*tmp, i - otherNumIter));
            delete tmp;
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& out, const big_integer& bigInt) {
        for (auto i = bigInt.number->rbegin(); i != bigInt.number->rend(); ++i) {
            out << *i;
            if ((i - bigInt.number->rbegin()) % 3 == (bigInt.number->size() - 1) % 3) {
                out << ' ';
            }
        }
        return out;
    }
};

int main() {
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    std::cout << number1 << std::endl;
    std::cout << number2 << std::endl;
    auto sumResult = number1 + number2;
    auto multResult = number1 * number2;
    std::cout << "sum: " << sumResult << "\nmult: " << multResult << std::endl;
}