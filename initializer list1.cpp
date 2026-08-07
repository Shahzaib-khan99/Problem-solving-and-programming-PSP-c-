#include<iostream>
using namespace std;

class Point {
private:
    int x, y, z, e, f, g;
public:
    Point(int i=0, int j=0, int k=0, int l=0, int m=0, int n=0)
        : x(i), y(j), z(k), e(l), f(m), g(n) {}

    int getX() const { return x; }
    int getY() const { return y; }
    int getZ() const { return z; }
    int getE() const { return e; }
    int getF() const { return f; }
    int getG() const { return g; }
};

int main() {
    Point t1(10, 15, 16);
    Point t2(2, 9, 8);

    cout << "t1 -> x = " << t1.getX() << ", y = " << t1.getY() << ", z = " << t1.getZ() << endl;
    cout << "t2 -> x = " << t2.getX() << ", y = " << t2.getY() << ", z = " << t2.getZ() << endl;

    return 0;
}
