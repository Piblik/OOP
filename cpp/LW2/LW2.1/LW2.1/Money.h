#pragma once
#include <string>

void inputInfo(int& s, int& f);

class Money {
private:
    int first_ = 0; 
    int second_ = 0; 
public:
    Money() = default;
    Money(int first, int second);

    int get_first() const noexcept { return first_; }
    int get_second() const noexcept { return second_; }

    void set_first(int first);
    void set_second(int second);

    void print() const;

    Money& operator++();   
    Money operator++(int); 
    Money& operator--();  
    Money operator--(int);  

    bool operator!() const;

    Money operator+(int scalar) const;

    operator std::string() const;

    static Money fromString(const std::string& str);
};
