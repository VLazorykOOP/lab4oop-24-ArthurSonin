 // OOPLab4T.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №4. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//


#include <iostream>
#include <map>
#include <string>


using namespace std;

//---------------------------------------task1---------------------------------------

class  VectorDouble {
    double* d;
    int size;
    int err;
public:
    VectorDouble();
    VectorDouble(int s);
    VectorDouble(int s, double dd);
    ~VectorDouble();

    void operator++();
    void operator--();

    bool operator!();

    void operator-();

    VectorDouble& operator=(VectorDouble& b);
    //  VectorDouble& operator=(VectorDouble&& b);

    VectorDouble& operator+=(VectorDouble& b);
    VectorDouble& operator-=(VectorDouble& b);
    VectorDouble& operator*=(double b);
    VectorDouble& operator/=(double b);
    VectorDouble& operator%=(int b);

    VectorDouble& operator+(VectorDouble& b);
    VectorDouble& operator-(VectorDouble& b);
    VectorDouble& operator*(double b);
    VectorDouble& operator/(double b);
    VectorDouble& operator%(int b);

    friend istream& operator>>(istream& is, VectorDouble& b);
    friend ostream& operator<<(ostream& is, VectorDouble& b);

    bool operator==(VectorDouble& b);
    bool operator!=(VectorDouble& b);

    double operator[](int b);

    void* operator new(std::size_t size);
    void  operator delete(void* ptr);

    void operator()();

    bool operator>(const VectorDouble& b);
    bool operator>=(const VectorDouble& b);
    bool operator<(const VectorDouble& b);
    bool operator<=(const VectorDouble& b);

    void Print();
};

VectorDouble::VectorDouble() {
    size = 1;
    d = new double[1];
    d[0] = 0;
}

VectorDouble::VectorDouble(int s) {
    size = s;
    d = new double[s];
    for (int i = 0; i < s; i++) {
        d[i] = 0;
    }
}

VectorDouble::VectorDouble(int s, double dd) {
    size = s;
    d = new double[s];
    for (int i = 0; i < s; i++) {
        d[i] = dd;
    }

}

VectorDouble::~VectorDouble() noexcept {
    if (d) delete[] d;
}

void VectorDouble::operator++() {
    for (int i = 0; i < size; i++) {
        d[i] = d[i] + 1;
    }
}

void VectorDouble::operator--() {
    for (int i = 0; i < size; i++) {
        d[i] = d[i] - 1;
    }
}

bool VectorDouble::operator!() {
    if (size != 0) return true;
    else return false;
}

void VectorDouble::operator-() {
    for (int i = 0; i < size; i++) {
        d[i] = -d[i];
    }
}

VectorDouble& VectorDouble::operator=(VectorDouble& b) {
    if (d) delete[] d;
    size = b.size;
    d = new double[size];
    for (int i = 0; i < size; i++) {
        d[i] = b.d[i];
    }
    return *this;
}

VectorDouble& VectorDouble::operator+=(VectorDouble& b) {
    int t;
    if (size < b.size) t = size;
    else t = b.size;
    for (int i = 0; i < t; i++) {
        d[i] = d[i] + b.d[i];
    }
    return *this;
}

VectorDouble& VectorDouble::operator-=(VectorDouble& b) {
    int t;
    if (size < b.size) t = size;
    else t = b.size;
    for (int i = 0; i < t; i++) {
        d[i] = d[i] - b.d[i];
    }
    return *this;
}

VectorDouble& VectorDouble::operator*=(double b) {
    for (int i = 0; i < size; i++) {
        d[i] = d[i] * b;
    }
    return *this;
}

VectorDouble& VectorDouble::operator/=(double b) {
    for (int i = 0; i < size; i++) {
        d[i] = d[i] / b;
    }
    return *this;
}

VectorDouble& VectorDouble::operator%=(int b) {
    for (int i = 0; i < size; i++) {
        d[i] = int(d[i]) % b;
    }
    return *this;
}

VectorDouble& VectorDouble::operator+(VectorDouble& b) {
    int t;
    if (size < b.size) t = size;
    else t = b.size;
    VectorDouble* tt = new VectorDouble(t);
    for (int i = 0; i < t; i++) {
        tt->d[i] = d[i] + b.d[i];
    }
    return *tt;
}

VectorDouble& VectorDouble::operator-(VectorDouble& b) {
    int t;
    if (size < b.size) t = size;
    else t = b.size;
    VectorDouble* tt = new VectorDouble(t);
    for (int i = 0; i < t; i++) {
        tt->d[i] = d[i] - b.d[i];
    }
    return *tt;
}

VectorDouble& VectorDouble::operator*(double b) {
    VectorDouble* tt = new VectorDouble(size);
    for (int i = 0; i < size; i++) {
        tt->d[i] = d[i] * b;
    }
    return *tt;
}

VectorDouble& VectorDouble::operator/(double b) {
    VectorDouble* tt = new VectorDouble(size);
    for (int i = 0; i < size; i++) {
        tt->d[i] = d[i] / b;
    }
    return *tt;
}


VectorDouble& VectorDouble::operator%(int b) {
    VectorDouble* tt = new VectorDouble(size);
    for (int i = 0; i < size; i++) {
        tt->d[i] = int(d[i]) % b;
    }
    return *tt;
}

istream& operator>>(istream& is, VectorDouble& b)
{
    int i;
    for (i = 0; i < b.size; i++) is >> b.d[i];
    return is;
}

ostream& operator<<(ostream& is, VectorDouble& b)
{
    int i;
    for (i = 0; i < b.size; i++) is << " " << b.d[i] << " ";
    return is;
}

bool VectorDouble::operator==(VectorDouble& b) {
    if (size != b.size) return false;
    for (int i = 0; i < b.size; i++) {
        if (d[i] != b.d[i]) return false;
    }
    return true;
}

bool VectorDouble::operator!=(VectorDouble& b) {
    if (size != b.size) return true;
    for (int i = 0; i < b.size; i++) {
        if (d[i] != b.d[i]) return true;
    }
    return false;
}

double VectorDouble::operator[](int b) {
    if (b >= size) { err = -1; return d[size - 1]; }
    return d[b];
}

void* VectorDouble::operator new(std::size_t size) {
    void* ptr = std::malloc(size);
    if (!ptr) {
        throw std::bad_alloc();
    }
    return ptr;
}

void VectorDouble::operator delete(void* ptr) noexcept {
    free(ptr);
}

void VectorDouble::operator()() {
    for (int i = 0; i < size; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
}

bool VectorDouble::operator>(const VectorDouble& b) {
    int t;
    if (size < b.size) t = size;
    else t = b.size;
    if (size <= b.size) return false;
    for (int i = 0; i < t; i++) {
        if (d[i] <= b.d[i]) {
            cout << "> ";
            return false;
        }
        else cout << "< ";
    }
    return true;
}

bool VectorDouble::operator>=(const VectorDouble& b) {
    if (size < b.size) return false;
    return true;
}

bool VectorDouble::operator<(const VectorDouble& b) {
    if (size >= b.size) return false;
    return true;
}

bool VectorDouble::operator<=(const VectorDouble& b) {
    if (size > b.size) return false;
    return true;
}

void VectorDouble::Print() {
    for (int i = 0; i < size; i++) {
        cout << d[i] << "  ";
    }
    cout << endl;

}

//---------------------------------------task2---------------------------------------

class Country {
    map < string, string > capital;
    int err;
public:
    Country();

    friend istream& operator>>(istream& is, Country& b);
    friend ostream& operator<<(ostream& is, Country& b);

    string operator[](string b);


};

Country::Country() {
    capital["Ukr"] = "Kyiv";

}

istream& operator>>(istream& is, Country& b)
{
    std::string a, d;
    cout << "Введiть назву країни ";
    cin >> a;
    cout << "Введiь назву столицi ";
    cin >> d;
    // b.capital.insert({ a, b });
    b.capital[a] = d;
    cout << endl;
    return is;
}

ostream& operator<<(ostream& is, Country& b)
{
    //   b.capital.begin();
    for (auto i = b.capital.begin(); i != b.capital.end(); ++i) {
        is << "Country: " << i->first << ", Capital: " << i->second << std::endl;
    }
    return is;
}

string Country::operator[](string b) {
    string t;
    t = capital[b];
    if (t == "") {
        err = -1;
        cout << "Не знайдено";
    }
    return t;
}

//===================================================

void MenuTask()
{
    cout << "    Menu Task \n";
    cout << "    1.  task1 \n";
    cout << "    2.  task2 \n";
    cout << "    3.  Exit  \n";
}

// Ваші файли загловки 
//
#include "Lab4Exmaple.h"
int main()
{
    cout << " Lab #4  task chain  !\n";
    setlocale(LC_CTYPE, "ukr");

    char ch = '3';
    do {
        system("cls");
        MenuTask();
        ch = cin.get();

        cin.get();

        switch (ch) {
        case '1': {
            int i = 0, ee;
            VectorDouble o1;
            o1.Print();
            cout << "---------------------" << endl;

            VectorDouble o2(5);
            o2.Print();
            cout << "---------------------" << endl;

            VectorDouble o3(5, 9);
            o3.Print();
            cout << "---------------------" << endl;

            VectorDouble o4(5, 6);
            o4.Print();
            cout << "---------------------" << endl;

            // VectorDouble a, b, c, d, e, f, g;

            --o3;
            o3();
            cout << endl << "---------------------\n";

            ++o3;
            o3();
            cout << endl << "---------------------\n";

            -o3;
            o3();
            cout << endl << "---------------------\n";

            o2 = o3;
            o2();
            cout << endl << "---------------------\n";

            o2 += o3;
            o2();
            cout << endl << "---------------------\n";

            o2 -= o3;
            o2();
            cout << endl << "---------------------\n";

            o2 *= 5;
            o2();
            cout << endl << "---------------------\n";

            o2 /= 5;
            o2();
            cout << endl << "---------------------\n";

            o2 %= 5;
            o2();
            cout << endl << "---------------------\n";

            o2 = o3 + o2;
            o2();
            cout << endl << "---------------------\n";

            o2 = o3 - o2;
            o2();
            cout << endl << "---------------------\n";

            o2 = o3 * 6;
            o2();
            cout << endl << "---------------------\n";

            o2 = o3 / 6;
            o2();
            cout << endl << "---------------------\n";

            o2 = o3 % 5;
            o2();
            cout << endl << "---------------------\n";

            VectorDouble a(5);
            cout << "Введiть 5 значень вектора: ";
            cin >> a;
            cout << endl << "---------------------\n";

            cout << a;
            cout << endl << "---------------------\n";

            if (o2 == o3) cout << "=\n";
            else cout << "!=\n";
            cout << endl << "---------------------\n";

            o2 = o3;

            if (o2 == o3) cout << "=\n";
            else cout << "!=\n";
            cout << endl << "---------------------\n";

            cout << "         " << o2[4] << endl;
            cout << endl << "---------------------\n";

            cout << "         " << o2[15] << endl;
            cout << endl << "---------------------\n";

            VectorDouble* d;
            d = new VectorDouble(20, 5);
            cout << *d;
            cout << endl << "---------------------\n";

            if (*d > a) cout << "\n>\n";
            else cout << "<=\n";
            cout << endl << "---------------------\n";

            if (*d >= a) cout << ">\n";
            else cout << "<=\n";
            cout << endl << "---------------------\n";

            if (*d < a) cout << ">\n";
            else cout << "<=\n";
            cout << endl << "---------------------\n";

            if (*d <= a) cout << ">\n";
            else cout << "<=\n";
            cout << endl << "---------------------\n";

            cin >> ee;

            delete d;
        }break;
        case '2': {
            setlocale(LC_CTYPE, "ukr");
            int e;
            Country c;

            cin >> c;

            cout << c;
            cout << endl << "---------------------\n";

            cout << c["Ukr"];
            cin >> e;


        }break;
        case '3': return 0;
        }
        cout << " Press any key and enter\n";
        ch = cin.get();
    } while (ch != '4');
    //  Код виконання завдань
    //  Головне меню завдань
    //  Функції та класи можуть знаходитись в інших файлах проекту
    return 0;
    int chain = 1;
    if (chain == 1) chain = mainExample1();
    if (chain == 2) chain = mainExample2();
    if (chain == 3) chain = mainExample3();

}