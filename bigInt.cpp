#include "library.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

//constructors \/ \/ \/
bigInt::bigInt() {
    num = "0";
    is_neg = false;
}

bigInt::bigInt(const string &s) {
    (s[0] == '-' ? is_neg = true : is_neg = false);
    num = s;
    if (is_neg) num.erase(num.begin());
}

bigInt::bigInt(const char *s) {
    (s[0] == '-' ? is_neg = true : is_neg = false);
    num = s;
    if (is_neg) num.erase(num.begin());

}

bigInt::bigInt(int n) {
    string s = to_string(n);
    is_neg = false;
    if (s[0] == '-') {
        s.erase(s.begin());
        num = s;
        is_neg = true;
    }
}
//constructors /\ /\ /\



//functions \/ \/ \/
void bigInt::debug() {
    cout << num;
}

string::iterator bigInt::begin() {
    return this->num.begin();
}

string::iterator bigInt::end() {
    return this->num.end();
}

int bigInt::length() {
    return this->num.length();
}
//functions /\ /\ /\



//operators \/ \/ \/
bigInt &bigInt::operator-=(const bigInt &b) {
    *this = *this - b;
    return *this;
}

bigInt operator-(bigInt f, bigInt s) {
    if (!f.is_neg && s.is_neg) {
        s.is_neg = false;
        return f + s;
    }
    else if (f.is_neg && !s.is_neg) {
        s.is_neg = true;
        return f + s;
    }
    else{

        if(f.num>s.num) {
            bigInt *buf = new bigInt;
            *buf = s;
            s = f;
            f = *buf;
            f.is_neg = true;
            delete buf;
        }
        int buf, cof = f.length() - s.length();
        for (int i = s.length() - 1; i >= 0; i--) {
            if (f[i + cof] >= s[i]) f[i + cof] -= (s[i] - 48);
            else {
                f[i + cof] -= (s[i] - 48);
                f[i + cof] += 10;
                buf = i;
                while (f[buf - 1 + cof] == '0') {
                    f[buf - 1 + cof] = '9';
                    buf--;
                }
                f[buf - 1 + cof] -= 1;
            }
        }
        while (f[0] == '0' && f.length()>1) f.num.erase(f.begin());
        return f;
    }
}

bigInt operator-(bigInt b){
    b.is_neg = !b.is_neg;
    return b;
}

bigInt &bigInt::operator+=(const bigInt &b) {
    *this = *this + b;
    return *this;
}

bigInt operator+(bigInt f, bigInt s) {
    if ((!f.is_neg && !s.is_neg) || (f.is_neg && s.is_neg)) {
        reverse(f.num.begin(), f.num.end());
        reverse(s.num.begin(), s.num.end());
        std::string buf;
        if (s.num.length() > f.num.length()) {
            buf = s.num;
            s.num = f.num;
            f.num = buf;
        }
        for (int i = 0; i < s.num.length(); i++) {
            if (f.num[i] + s.num[i] - 48 < 58) f.num[i] += s.num[i] - 48;
            else {
                f.num[i] += s.num[i] - 58;
                if (i == f.num.length() - 1) {
                    f.num += '1';
                    continue;
                }
                int ii = i + 1;
                while (f.num[ii] + 1 == 58) {
                    f.num[ii] = '0';
                    if (ii == f.num.length() - 1) {
                        ii++;
                        f.num += '0';
                        break;
                    }
                    ii++;
                }
                f.num[ii] += 1;
            }
        }
        reverse(f.num.begin(), f.num.end());
        return f;
    }
    if (f.is_neg && !s.is_neg) {
        f.is_neg = false;
        return s - f;
    }
    else if (!f.is_neg && s.is_neg) {
        s.is_neg = false;
        return f - s;
    }
}

bigInt &bigInt::operator*=(const bigInt &b) {
    *this = *this * b;
    return *this;
}

bigInt operator*(bigInt f, bigInt s) {

    reverse(f.begin(), f.end());
    reverse(s.begin(), s.end());
    string buf;

    bigInt res;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < f.length(); j++) {
            if (s[i] != '0' && f[j] != '0') {
                buf = "";
                if ((f[j] - 48) * (s[i] - 48) > 9) buf += (f[j] - 48) * (s[i] - 48) / 10 + 48;
                buf += (f[j] - 48) * (s[i] - 48) % 10 + 48;
                for (int ss = 0; ss < i + j; ss++) { buf += '0'; }
                res += bigInt(buf);
            }
        }
    }
    if (s.is_neg && !f.is_neg) res.is_neg = true;
    else if (s.is_neg && f.is_neg) res.is_neg = false;
    return res;
}

bigInt& bigInt::operator/=(const bigInt &b){
    *this = *this / b;
    return *this;
}

bigInt operator/(bigInt f, bigInt s){
    if(f.num<s.num) return bigInt(0);
    bigInt res;



    if (s.is_neg && !f.is_neg) res.is_neg = true;
    else if (s.is_neg && f.is_neg) res.is_neg = false;
    return res;

}


ostream &operator<<(ostream &out, const bigInt &var) {
    if (var.is_neg) out << '-';
    return out << var.num;
}

istream &operator>>(istream &in, bigInt &var) {
    in >> var.num;
    var.is_neg = false;
    if (var.num[0] == '-') {
        var.num.erase(var.num.begin());
        var.is_neg = true;
    }
    return in;
}

char &bigInt::operator[](int pos) {
    return this->num[pos];
}

bool operator==(bigInt &f, bigInt &s) {
    if (f.is_neg == s.is_neg && f.num == s.num) return true;
    return false;
}

bool operator!=(bigInt &f, bigInt &s) {
    if (f.is_neg != s.is_neg || f.num != s.num) return true;
    return false;
}

bool operator<(bigInt &f, bigInt &s) {
    if (f.is_neg && !s.is_neg) return true;
    else if (f.is_neg && s.is_neg) return f.num > s.num;
    else if (!f.is_neg && !s.is_neg) return f.num < s.num;
    return false;
}

bool operator>(bigInt &f, bigInt &s) {
    if (!f.is_neg && s.is_neg) return true;
    else if (f.is_neg && s.is_neg) return f.num < s.num;
    else if (!f.is_neg && !s.is_neg) return f.num > s.num;
    return false;
}

bool operator<=(bigInt &f, bigInt &s) {
    if (f == s) return true;
    if (f.is_neg && !s.is_neg) return true;
    else if (f.is_neg && s.is_neg) return f.num > s.num;
    else if (!f.is_neg && !s.is_neg) return f.num < s.num;
    return false;
}

bool operator>=(bigInt &f, bigInt &s) {
    if (f == s) return true;
    if (!f.is_neg && s.is_neg) return true;
    else if (f.is_neg && s.is_neg) return f.num < s.num;
    else if (!f.is_neg && !s.is_neg) return f.num > s.num;
    return false;
}
//operators /\ /\ /\