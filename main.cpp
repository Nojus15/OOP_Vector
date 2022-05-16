#include <iostream>
#include <vector>
#include <chrono>
#include "Vector.h"

using std::cout;
using std::endl;

class taskas
{
public:
    int x, y, z;

    taskas() : x(0.0f), y(0.0f), z(0.0f){};
    taskas(int x, int y, int z) : x(x), y(y), z(z){};
    ~taskas()
    {
        cout << "taskas destroy" << endl;
    }
};

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    unsigned int sz = 100000000; // 100000, 1000000, 10000000, 100000000
    std::vector<int> v1;
    for (int i = 0; i <= sz; ++i)
        v1.push_back(i);

    auto time = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start);
    cout << time.count() << endl;
    // Baigti v1 užpildymo laiko matavimą

    // Pradėti v2 užpildymo laiko matavimą
    auto start2 = std::chrono::high_resolution_clock::now();
    Vector<int> v2;
    for (int i = 0; i <= sz; ++i)
        v2.push_back(i);
    // Baigti v2 užpildymo laiko matavimą
    auto time2 = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start2);
    cout << time2.count() << endl;
}
