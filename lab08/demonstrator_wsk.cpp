#include <iostream>

using namespace std;


enum Lab {
    PK,
    SW = 5,
    ADP
};

void test (Lab p) {

    switch (p) {
        case PK:
            // działanie A
            break;

        case SW:
            // działanie B
            break;
    }

    if (p == SW) {

    }
}

void f (int x) {
    x = 100;
}

void f_wsk (int* x, int* y, int* z) {
    *x = 10;
    *y = 10;
    *z = 10;

}

int main() {

    int x = 0, y = 0, z = 0;

    f_wsk(&x, &y, &z);
    cout << x << " " << y << " " << z << endl;

    f(x);
    cout << "bez wsk: " << x << endl;



    return 0;

}