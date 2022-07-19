#include <vector>
#include<string>
#include<utility>

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

    //bigInt(std::basic_string<char> basicString);

    //bigInt& operator=(std::string& b);

    //bigInt(size_t s);

    bigInt &operator-=(const bigInt &b);

    friend bigInt operator-(bigInt f, bigInt s);

    friend bigInt operator-(bigInt b);

    bigInt &operator+=(const bigInt &buf);

    friend bigInt operator+(bigInt f, bigInt s);

    bigInt &operator*=(const bigInt &b);

    friend bigInt operator*(bigInt f, bigInt s);

    bigInt &operator/=(const bigInt &b);

    friend bigInt operator/(bigInt f, bigInt s);

    friend std::ostream &operator<<(std::ostream &out, const bigInt &var);

    friend std::istream &operator>>(std::istream &in, bigInt &var);

    char &operator[](int pos);

    friend bool operator==(bigInt f, bigInt s);

    friend bool operator!=(bigInt f, bigInt s);

    friend bool operator<(bigInt f, bigInt s);

    friend bool operator>(bigInt f, bigInt s);

    friend bool operator<=(bigInt f, bigInt s);

    friend bool operator>=(bigInt f, bigInt s);

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

std::vector<std::pair<int, int>>
lee(const std::pair<int, int> start, const std::pair<int, int> end, std::vector<std::vector<int>> &field, int WALL = -1,
    int SPACE = 0);

#endif //UNTITLED2_LIBRARY_H
