# OOP_Vector

### Spartos analize
| Ints        | 100.000  | 1.000.000   | 10.000.000   | 100.000.000   |
| :---------- | :------- | :-------    | :---------   | :----------   | 
| std::vector | 0 s      | 0.0239843 s | 0.213842 s   | 2.02593 s     |
| Vector      | 0 s      | 0.0239825 s | 0.232263 s   | 1.99267 s     |

### Perskirstymai uzpildants 100000000 elementu
- std vector – 31
- Vector – 30

### rbegin() test
- Std vector
- 16 8 4 2 1
- Sum of nums: 31
- First fruit: raspberry
- vector 'empty' is indeed empty.
- 
- My vector
- 16 8 4 2 1 
- Sum of nums: 31
- First fruit: raspberry
- vector 'empty' is indeed empty.

### size() test
- Std vector
- nums contains 4 elements.
- 
- My vector
- nums contains 4 elements.
### max_size() test
- Std vector
- Maximum size of a std::vector is 9223372036854775807
- 
- My vector
- Maximum size of a std::vector is 9223372036854775807
### end() test
- Std vector
- 1 2 4 8 16
- Sum of nums: 31
- First fruit: orange
- vector 'empty' is indeed empty.
- 
- My vector
- 1 2 4 8 16
- Sum of nums: 31
- First fruit: orange
- vector 'empty' is indeed empty.
### shrink_to_fit() test
- Std vector
- Default-constructed capacity is 0
- Capacity of a 100-element vector is 100
- Capacity after resize(50) is 100
- Capacity after shrink_to_fit() is 50
- Capacity after clear() is 50
- Capacity after shrink_to_fit() is 0
- Capacity after adding 300 elements is 512
- Capacity after shrink_to_fit() is 300
- 
- My vector
- Default-constructed capacity is 0
- Capacity of a 100-element vector is 100
- Capacity after resize(50) is 100
- Capacity after shrink_to_fit() is 50
- Capacity after clear() is 50
- Capacity after shrink_to_fit() is 0
- Capacity after adding 300 elements is 512
- Capacity after shrink_to_fit() is 300

### Testavimas v2.0 uzduotyje su 100.000 studentu

| Container              | std::vector  | Vector      |
| :----------            | :-------     | :-------    |
| Atminties perskirstymu | 18           | 17          |
| Failo skaitymas        | 0.627489   s | 0.607803  s |
| Studentu dalinima      | 0.0518088  s | 0.0505579 s |
| Studentu isvedimas     | 0.20844    s | 0.204456  s |
| Programos laikas       | 1.09528    s | 1.06645   s |