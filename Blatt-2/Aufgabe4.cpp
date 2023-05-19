#include <iostream>
using namespace std;

void swapi(int& a, int& b) {
    int rm  = a;
    a = b;
    b = rm;
}

int main() {
    int x, y;
    cout << "Geben Sie den Wert von x ein: ";
    cin >> x;
    cout << "Geben Sie den Wert von y ein: ";
    cin >> y;
    cout << "Vor dem Tausch: x = " << x << ", y = " << y << endl;
    swapi(x, y);
    std::cout << "Nach dem Tausch: x = " << x << ", y = " << y << std::endl;
    return 0;
}
