#include <vector>
#include<string>

#ifndef UNTITLED2_LIBRARY_H
#define UNTITLED2_LIBRARY_H

class bigInt {
private:
    std::string num;
    bool is_neg;
public:
    bigInt();

    explicit bigInt(const std::string &s);

    explicit bigInt(const char *s);

    explicit bigInt(int n);

    //bigInt(size_t s);

    bigInt &operator+=(const bigInt &buf);

    friend bigInt operator+(bigInt f, bigInt s);

    bigInt &operator*=(const bigInt &b);

    friend bigInt operator*(bigInt f, bigInt s);

    friend std::ostream &operator<<(std::ostream &out, const bigInt &var);

    friend std::istream &operator>>(std::istream &in, bigInt &var);

    char operator[](int pos);

    friend bool operator==(bigInt &f, bigInt &s);

    friend bool operator!=(bigInt &f, bigInt &s);

    friend bool operator<(bigInt &f, bigInt &s);

    friend bool operator>(bigInt &f, bigInt &s);

    friend bool operator<=(bigInt &f, bigInt &s);

    friend bool operator>=(bigInt &f, bigInt &s);

    void debug();

    std::string::iterator begin();

    std::string::iterator end();

    int length();
};

long long int degree(long long int num, int d);

int randint(int a, int b);

int from_anyone(const std::string &num, int c = 2);

std::string to_anyone(long long int num, int c);

std::vector<std::string> permutations(std::string s);

int to_int(const std::string &str);

#endif //UNTITLED2_LIBRARY_H
