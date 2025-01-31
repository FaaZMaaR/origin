#include <iostream>

template<typename T>
class UniquePtr {
private:
    T* data;

public:
    UniquePtr(T* ptr = nullptr) : data{ ptr } {}
    ~UniquePtr() {
        delete data;
    }

    UniquePtr(const UniquePtr& uniquePtr) = delete;
    UniquePtr& operator=(const UniquePtr& uniquePtr) = delete;

    T& operator*() {
        if (data == nullptr) {
            throw std::runtime_error("UniquePtr is empty");
        }
        return *data;
    }
    T* release() {
        T* tmp = data;
        data = nullptr;
        return tmp;
    }
};

struct TestStruct {
    int num1, num2, num3;
    ~TestStruct() {
        std::cout << "TestStruct deleted" << std::endl;
    }
};

int main() {
    UniquePtr<TestStruct> unique_ptr(new TestStruct{ 1,2,3 });
    (*unique_ptr).num1 = 10;
    std::cout << (*unique_ptr).num1 << " " << (*unique_ptr).num2 << " " << (*unique_ptr).num3 << " " << std::endl;
    //TestStruct* ptr = unique_ptr.release();
    //delete ptr;    
}