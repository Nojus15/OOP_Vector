#include <iostream>
#include <vector>
#include <chrono>
#include "Vector.h"
#include <iterator>
#include <algorithm>
#include <numeric>
#include <string>
#include <iomanip>

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

void test_at()
{
    cout << "Std vecor" << endl;
    std::vector<int> data = {1, 2, 4, 5, 5, 6};

    // Set element 1
    data.at(1) = 88;
    // Read element 2
    std::cout << "Element at index 2 has value " << data.at(2) << '\n';
    std::cout << "data size = " << data.size() << '\n';
    try
    {
        // Set element 6
        data.at(6) = 666;
    }
    catch (std::out_of_range const &exc)
    {
        std::cout << exc.what() << '\n';
    }
    // Print final values
    std::cout << "data:";
    for (int elem : data)
        std::cout << " " << elem;
    std::cout << '\n';

    cout << endl;
    cout << "My vector" << endl;
    { // at() test
        Vector<int> data = {1, 2, 4, 5, 5, 6};

        // Set element 1
        data.at(1) = 88;
        // Read element 2
        std::cout << "Element at index 2 has value " << data.at(2) << '\n';
        std::cout << "data size = " << data.size() << '\n';
        try
        {
            // Set element 6
            data.at(6) = 666;
        }
        catch (std::out_of_range const &exc)
        {
            std::cout << exc.what() << '\n';
        }
        // Print final values
        std::cout << "data:";
        for (int elem : data)
            std::cout << " " << elem;
        std::cout << '\n';
    }
}
void test_front()
{
    cout << "Std vector" << endl;
    std::vector<char> letters{'o', 'm', 'g', 'w', 't', 'f'};

    if (!letters.empty())
    {
        std::cout << "The first character is '" << letters.front() << "'.\n";
    }
    cout << endl;
    cout << "My vector" << endl;
    {
        Vector<char> letters{'o', 'm', 'g', 'w', 't', 'f'};

        if (!letters.empty())
        {
            std::cout << "The first character is '" << letters.front() << "'.\n";
        }
    }
}
void test_back()
{
    cout << "Std vector" << endl;
    std::vector<char> letters{'a', 'b', 'c', 'd', 'e', 'f'};

    if (!letters.empty())
    {
        std::cout << "The last character is '" << letters.back() << "'.\n";
    }
    cout << endl;
    cout << "My vector" << endl;
    {
        Vector<char> letters{'a', 'b', 'c', 'd', 'e', 'f'};

        if (!letters.empty())
        {
            std::cout << "The last character is '" << letters.back() << "'.\n";
        }
    }
}
void test_begin()
{
    cout << "Std vector" << endl;
    std::vector<int> nums{1, 2, 4, 8, 16};
    std::vector<std::string> fruits{"orange", "apple", "raspberry"};
    std::vector<char> empty;

    // Print vector.
    std::for_each(nums.begin(), nums.end(), [](const int n)
                  { std::cout << n << ' '; });
    std::cout << '\n';

    // Sums all integers in the vector nums (if any), printing only the result.
    std::cout << "Sum of nums: "
              << std::accumulate(nums.begin(), nums.end(), 0) << '\n';

    // Prints the first fruit in the vector fruits, checking if there is any.
    if (!fruits.empty())
        std::cout << "First fruit: " << *fruits.begin() << '\n';

    if (empty.begin() == empty.end())
        std::cout << "vector 'empty' is indeed empty.\n";

    cout << endl;
    cout << "My vector" << endl;
    {
        Vector<int> nums{1, 2, 4, 8, 16};
        Vector<std::string> fruits{"orange", "apple", "raspberry"};
        Vector<char> empty;

        // Print vector.
        std::for_each(nums.begin(), nums.end(), [](const int n)
                      { std::cout << n << ' '; });
        std::cout << '\n';

        // Sums all integers in the vector nums (if any), printing only the result.
        std::cout << "Sum of nums: "
                  << std::accumulate(nums.begin(), nums.end(), 0) << '\n';

        // Prints the first fruit in the vector fruits, checking if there is any.
        if (!fruits.empty())
            std::cout << "First fruit: " << *fruits.begin() << '\n';

        if (empty.begin() == empty.end())
            std::cout << "vector 'empty' is indeed empty.\n";
    }
}
void test_end()
{
    cout << "Std vector" << endl;
    std::vector<int> nums{1, 2, 4, 8, 16};
    std::vector<std::string> fruits{"orange", "apple", "raspberry"};
    std::vector<char> empty;

    // Print vector.
    std::for_each(nums.begin(), nums.end(), [](const int n)
                  { std::cout << n << ' '; });
    std::cout << '\n';

    // Sums all integers in the vector nums (if any), printing only the result.
    std::cout << "Sum of nums: "
              << std::accumulate(nums.begin(), nums.end(), 0) << '\n';

    // Prints the first fruit in the vector fruits, checking if there is any.
    if (!fruits.empty())
        std::cout << "First fruit: " << *fruits.begin() << '\n';

    if (empty.begin() == empty.end())
        std::cout << "vector 'empty' is indeed empty.\n";

    cout << endl;
    cout << "My vector" << endl;
    {
        Vector<int> nums{1, 2, 4, 8, 16};
        Vector<std::string> fruits{"orange", "apple", "raspberry"};
        Vector<char> empty;

        // Print vector.
        std::for_each(nums.begin(), nums.end(), [](const int n)
                      { std::cout << n << ' '; });
        std::cout << '\n';

        // Sums all integers in the vector nums (if any), printing only the result.
        std::cout << "Sum of nums: "
                  << std::accumulate(nums.begin(), nums.end(), 0) << '\n';

        // Prints the first fruit in the vector fruits, checking if there is any.
        if (!fruits.empty())
            std::cout << "First fruit: " << *fruits.begin() << '\n';

        if (empty.begin() == empty.end())
            std::cout << "vector 'empty' is indeed empty.\n";
    }
}
void test_rbegin()
{
    {
        cout << "Std vector" << endl;
        std::vector<int> nums{1, 2, 4, 8, 16};
        std::vector<std::string> fruits{"orange", "apple", "raspberry"};
        std::vector<char> empty;

        // Print vector.
        std::for_each(nums.rbegin(), nums.rend(), [](const int n)
                      { std::cout << n << ' '; });
        std::cout << '\n';

        // Sums all integers in the vector nums (if any), printing only the result.
        std::cout << "Sum of nums: "
                  << std::accumulate(nums.rbegin(), nums.rend(), 0) << '\n';

        // Prints the first fruit in the vector fruits, checking if there is any.
        if (!fruits.empty())
            std::cout << "First fruit: " << *fruits.rbegin() << '\n';

        if (empty.rbegin() == empty.rend())
            std::cout << "vector 'empty' is indeed empty.\n";
    }

    cout << endl;
    cout << "My vector" << endl;
    Vector<int> nums{1, 2, 4, 8, 16};
    Vector<std::string> fruits{"orange", "apple", "raspberry"};
    Vector<char> empty;

    // Print vector.
    std::for_each(nums.rbegin(), nums.rend(), [](const int n)
                  { std::cout << n << ' '; });
    std::cout << '\n';

    // Sums all integers in the vector nums (if any), printing only the result.
    std::cout << "Sum of nums: "
              << std::accumulate(nums.rbegin(), nums.rend(), 0) << '\n';

    // Prints the first fruit in the vector fruits, checking if there is any.
    if (!fruits.empty())
        std::cout << "First fruit: " << *fruits.rbegin() << '\n';

    if (empty.rbegin() == empty.rend())
        std::cout << "vector 'empty' is indeed empty.\n";
}
void test_rend()
{
    {
        cout << "Std vector" << endl;
        std::vector<int> nums{1, 2, 4, 8, 16};
        std::vector<std::string> fruits{"orange", "apple", "raspberry"};
        std::vector<char> empty;

        // Print vector.
        std::for_each(nums.rbegin(), nums.rend(), [](const int n)
                      { std::cout << n << ' '; });
        std::cout << '\n';

        // Sums all integers in the vector nums (if any), printing only the result.
        std::cout << "Sum of nums: "
                  << std::accumulate(nums.rbegin(), nums.rend(), 0) << '\n';

        // Prints the first fruit in the vector fruits, checking if there is any.
        if (!fruits.empty())
            std::cout << "First fruit: " << *fruits.rbegin() << '\n';

        if (empty.rbegin() == empty.rend())
            std::cout << "vector 'empty' is indeed empty.\n";
    }

    // my vector
    cout << endl;
    cout << "My vector" << endl;
    Vector<int> nums{1, 2, 4, 8, 16};
    Vector<std::string> fruits{"orange", "apple", "raspberry"};
    Vector<char> empty;

    // Print vector.
    std::for_each(nums.rbegin(), nums.rend(), [](const int n)
                  { std::cout << n << ' '; });
    std::cout << '\n';

    // Sums all integers in the vector nums (if any), printing only the result.
    std::cout << "Sum of nums: "
              << std::accumulate(nums.rbegin(), nums.rend(), 0) << '\n';

    // Prints the first fruit in the vector fruits, checking if there is any.
    if (!fruits.empty())
        std::cout << "First fruit: " << *fruits.rbegin() << '\n';

    if (empty.rbegin() == empty.rend())
        std::cout << "vector 'empty' is indeed empty.\n";
}
void test_empty()
{
    cout << "Std vector" << endl;
    std::cout << std::boolalpha;
    std::vector<int> numbers;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';

    numbers.push_back(42);
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';

    cout << endl;
    cout << "My vector" << endl;
    {
        std::cout << std::boolalpha;
        Vector<int> numbers;
        std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';

        numbers.push_back(42);
        std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
    }
}
void test_size()
{
    cout << "Std vector" << endl;
    std::vector<int> nums{1, 3, 5, 7};

    std::cout << "nums contains " << nums.size() << " elements.\n";
    cout << endl;
    cout << "My vector" << endl;
    {
        Vector<int> nums{1, 3, 5, 7};

        std::cout << "nums contains " << nums.size() << " elements.\n";
    }
}
void test_max_size()
{
    cout << "Std vector" << endl;
    std::vector<char> q;
    std::cout << "Maximum size of a std::vector is " << q.max_size() << '\n';

    cout << endl;
    cout << "My vector" << endl;
    {
        Vector<char> q;
        std::cout << "Maximum size of a std::vector is " << q.max_size() << '\n';
    }
}
void test_capacity()
{
    cout << "Std vector" << endl;
    int sz = 100;
    std::vector<int> v;

    auto cap = v.capacity();
    std::cout << "Initial size: " << v.size() << ", capacity: " << cap << '\n';

    std::cout << "\nDemonstrate the capacity's growth policy."
                 "\nSize:  Capacity:  Ratio:\n"
              << std::left;
    while (sz-- > 0)
    {
        v.push_back(sz);
        if (cap != v.capacity())
        {
            std::cout << std::setw(7) << v.size()
                      << std::setw(11) << v.capacity()
                      << std::setw(10) << v.capacity() / static_cast<float>(cap) << '\n';
            cap = v.capacity();
        }
    }

    std::cout << "\nFinal size: " << v.size() << ", capacity: " << v.capacity() << '\n';

    cout << endl;
    cout << "My vector" << endl;
    {
        int sz = 100;
        Vector<int> v;

        auto cap = v.capacity();
        std::cout << "Initial size: " << v.size() << ", capacity: " << cap << '\n';

        std::cout << "\nDemonstrate the capacity's growth policy."
                     "\nSize:  Capacity:  Ratio:\n"
                  << std::left;
        while (sz-- > 0)
        {
            v.push_back(sz);
            if (cap != v.capacity())
            {
                std::cout << std::setw(7) << v.size()
                          << std::setw(11) << v.capacity()
                          << std::setw(10) << v.capacity() / static_cast<float>(cap) << '\n';
                cap = v.capacity();
            }
        }

        std::cout << "\nFinal size: " << v.size() << ", capacity: " << v.capacity() << '\n';
    }
}
void test_shrink_to_fit()
{
    cout << "Std vector" << endl;
    std::vector<int> v;
    std::cout << "Default-constructed capacity is " << v.capacity() << '\n';
    v.resize(100);
    std::cout << "Capacity of a 100-element vector is " << v.capacity() << '\n';
    v.resize(50);
    std::cout << "Capacity after resize(50) is " << v.capacity() << '\n';
    v.shrink_to_fit();
    std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';
    v.clear();
    std::cout << "Capacity after clear() is " << v.capacity() << '\n';
    v.shrink_to_fit();
    std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';
    for (int i = 1000; i < 1300; ++i)
        v.push_back(i);
    std::cout << "Capacity after adding 300 elements is " << v.capacity() << '\n';
    v.shrink_to_fit();
    std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';

    cout << endl;
    cout << "My vector" << endl;
    {
        Vector<int> v;
        std::cout << "Default-constructed capacity is " << v.capacity() << '\n';
        v.resize(100);
        std::cout << "Capacity of a 100-element vector is " << v.capacity() << '\n';
        v.resize(50);
        std::cout << "Capacity after resize(50) is " << v.capacity() << '\n';
        v.shrink_to_fit();
        std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';
        v.clear();
        std::cout << "Capacity after clear() is " << v.capacity() << '\n';
        v.shrink_to_fit();
        std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';
        for (int i = 1000; i < 1300; ++i)
            v.push_back(i);
        std::cout << "Capacity after adding 300 elements is " << v.capacity() << '\n';
        v.shrink_to_fit();
        std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';
    }
}
int main()
{
    int reallocCounter = 0;
    auto start = std::chrono::high_resolution_clock::now();
    unsigned int sz = 1000000000; // 100000, 1000000, 10000000, 100000000
    std::vector<int> v1;
    for (int i = 0; i <= sz; ++i)
    {
        if (v1.size() == v1.capacity())
            reallocCounter++;
        v1.push_back(i);
    }

    auto time = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start);
    cout << time.count() << endl;
    cout << "Allocations: " << reallocCounter << endl;
    // Baigti v1 užpildymo laiko matavimą

    // Pradėti v2 užpildymo laiko matavimą
    reallocCounter = 0;
    auto start2 = std::chrono::high_resolution_clock::now();
    Vector<int> v2;
    for (int i = 0; i <= sz; ++i)
    {
        if (v2.size() == v2.capacity())
            reallocCounter++;
        v2.push_back(i);
    }
    // Baigti v2 užpildymo laiko matavimą
    auto time2 = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start2);
    cout << time2.count() << endl;
    cout << "Allocations: " << reallocCounter << endl;

    // cout << endl;
    // test_rbegin();
    // test_size();
    // test_max_size();
    // test_end();
    // test_shrink_to_fit();
    // cout << endl;
}
