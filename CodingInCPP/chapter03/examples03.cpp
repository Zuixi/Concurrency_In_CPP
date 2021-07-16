#include <iostream>
#include <thread>
#include <mutex>
#include <string>

// 交换数据的类
class Person{
private:
    std::string m_name;
    unsigned int m_age;
    std::string m_address;

public:
    explicit Person() = default;
    explicit Person(std::string name, int age, std::string address): m_name(name), m_age(age), m_address(address){}
    explicit Person(std::string name, int age): m_name(name), m_age(age){}

    friend void swap(Person &lhs, Person &rhs);
};

class TP{
private:
    Person m_people;
    std::mutex m_mutex;

public:
    explicit TP()=default;
    explicit TP(Person const& p): m_people(p){}

    friend void swapPeople(TP &lhs, TP &rhs){
        if (&lhs == &rhs){
            return;
        }

        std::lock(lhs.m_mutex, rhs.m_mutex);    // 1
        std::lock_guard<std::mutex> lock_a(lhs.m_mutex, std::adopt_lock);   // 2
        std::lock_guard<std::mutex> lock_n(rhs.m_mutex, std::adopt_lock);   // 3
        swap(lhs.m_people, rhs.m_people);
    }
};

void swap(Person &lhs, Person &rhs){

}

int main(){
    Person *a = new Person(std::string("www"), 12, std::string("wqw"));

    return 0;
}

