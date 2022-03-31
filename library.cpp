#include "library.h"
#include <string>
#include <random>
#include <algorithm>
#include <iostream>

using namespace std;

long long int degree(long long int num, int d) {
    int buf(num);
    num = 1;
    for (int i = 0; i < d; i++) num *= buf;
    return num;
}

int from_anyone(const string &num, int c) {
    if (c > 1 && c < 37) {
        long long int dec_num(0);
        int ii(num.length() - 1);
        for (char id: num) {

            if (id > 47 && id < 58) {
                dec_num += (id - 48) * pow(c, ii);
            } else if (id > 64 && id < 91) {
                dec_num += (id - 55) * pow(c, ii);
            } else if (id > 96 && id < 123) {
                dec_num += (id - 87) * pow(c, ii);
            }
            ii--;
        }
        return dec_num;
    } else if (c == 1) return num.length();
    else {
        cerr << "Incorrect number system";
        exit(-1);
        return 0;
    }
}

string to_anyone(long long int num, int c) {
    string n = "";
    if (c > 1 && c < 37) {
        while (num > c) {
            if (num % c > 9) n += static_cast<char>((num % c) + 55);
            else n += static_cast<char>((num % c) + 48);
            num /= c;
        }
        if (num % c > 9) n += static_cast<char>((num % c) + 55);
        else n += static_cast<char>((num % c) + 48);
        reverse(n.begin(), n.end());
        return n;
    } else if (c == 1) {
        for (int i = 0; i < num; i++) n += '|';
        return n;
    } else {
        cerr << "Incorrect number system";
        return "0";
    }
}

int to_int(const string &str) {
    long long int num = 0;
    for (int i = 0; i < str.length(); i++) {
        num += (str[i] - 48) * degree(10, str.length() - i - 1);
    }
    return num;
}

int randint(int a, int b) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(a, b);
    return dist(gen);
}

vector<string> permutations(string s) {
    const int n = s.size();
    int j, k, l, r;
    vector<string> v;
    v.push_back(s);
    while (true) {
        j = n - 2;
        while (j != -1 && s[j] >= s[j + 1]) j--;
        if (j == -1) break;
        k = n - 1;
        while (s[j] >= s[k]) k--;
        swap(s[j], s[k]);
        l = j + 1;
        r = n - 1;
        while (l < r) swap(s[l++], s[r--]);
        v.push_back(s);
    }
    return v;
}