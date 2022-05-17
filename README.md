# OOP_Vector

### Spartos analize
| Ints        | 100.000  | 1.000.000   | 10.000.000   | 100.000.000   |
| :---------- | :------- | :-------    | :---------   | :----------   | 
| std::vector | 0 s      | 0.0239843 s | 0.213842 s   | 2.02593 s     |
| Vector      | 0 s      | 0.0239825 s | 0.232263 s   | 1.99267 s     |

### rbegin() test
Std vector
16 8 4 2 1
Sum of nums: 31
First fruit: raspberry
vector 'empty' is indeed empty.

My vector
16 8 4 2 1 
Sum of nums: 31
First fruit: raspberry
vector 'empty' is indeed empty.

### size() test
Std vector
nums contains 4 elements.

My vector
nums contains 4 elements.
### max_size() test
Std vector
Maximum size of a std::vector is 9223372036854775807

My vector
Maximum size of a std::vector is 9223372036854775807
### capacity() test
Std vector
Initial size: 0, capacity: 0

Demonstrate the capacity's growth policy.
Size:  Capacity:  Ratio:
1      1          inf
2      2          2
3      4          2
5      8          2
9      16         2
17     32         2
33     64         2
65     128        2

Final size: 100, capacity: 128

My vector
Initial size: 0, capacity: 0

Demonstrate the capacity's growth policy.
Size:  Capacity:  Ratio:
1      2          inf
3      4          2
5      8          2
9      16         2
17     32         2
33     64         2
65     128        2

Final size: 100, capacity: 128
### shrink_to_fit() test
Std vector
Default-constructed capacity is 0
Capacity of a 100-element vector is 100
Capacity after resize(50) is 100
Capacity after shrink_to_fit() is 50
Capacity after clear() is 50
Capacity after shrink_to_fit() is 0
Capacity after adding 300 elements is 512
Capacity after shrink_to_fit() is 300

My vector
Default-constructed capacity is 0
Capacity of a 100-element vector is 100
Capacity after resize(50) is 100
Capacity after shrink_to_fit() is 50
Capacity after clear() is 50
Capacity after shrink_to_fit() is 0
Capacity after adding 300 elements is 512
Capacity after shrink_to_fit() is 300

