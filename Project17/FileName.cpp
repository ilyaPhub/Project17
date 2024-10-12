#include <iostream>
using namespace std;

class MyString {
private:
    char* str;
    size_t length;

    size_t calcLength(const char* s) const {
        size_t len = 0;
        while (s[len] != '\0') {
            ++len;
        }
        return len;
    }

    void copyString(char* dest, const char* src) {
        size_t i = 0;
        while (src[i] != '\0') {
            dest[i] = src[i];
            ++i;
        }
        dest[i] = '\0'; 
    }

public:
    MyString() : str(nullptr), length(0) {}
    MyString(const char* s) {
        length = calcLength(s);
        str = new char[length + 1];
        copyString(str, s);
    }

    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        copyString(str, other.str);
    }

    ~MyString() {
        delete[] str;
    }

    MyString& operator=(const MyString& other) {
        if (this == &other) return *this; 

        delete[] str; 
        length = other.length;
        str = new char[length + 1];
        copyString(str, other.str);
        return *this;
    }

    const char* getString() const {
        return str;
    }

    size_t getLength() const {
        return length;
    }

    friend istream& operator>>(istream& in, MyString& obj) {
        char buffer[1024]; 
        in >> buffer;
        obj = MyString(buffer); 
        return in;
    }

    friend ostream& operator<<(ostream& out, const MyString& obj) {
        out << obj.getString(); 
        return out;
    }
};

int main() {
    MyString s1("Hello");
    MyString s2;

    cout << "Введіть рядок: ";
    cin >> s2;

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    s2 = s1; 
    cout << "Після присвоєння s2 = s1: " << s2 << endl;

    return 0;
}
