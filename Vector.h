#pragma once
#include <iostream>
#include <assert.h>
#include <memory>
#include <stdexcept>
#include <limits>

using std::cout;
using std::endl;

template <typename T>
class Vector
{
public:
    typedef T value_type;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef value_type *iterator;
    typedef const value_type *const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

private:
    iterator v_Data = nullptr;
    size_type v_size = 0;
    size_type v_capacity = 0;

public:
    Vector()
    {
        ReAlloc(2);
    };
    Vector(const Vector &other)
    {
        this->v_size = other.v_size;
        this->v_capacity = other.v_capacity;
        this->v_Data = new value_type[v_size];
        for (size_type i = 0; i < v_size; i++)
            v_Data[i] = other.v_Data[i];
    }
    Vector(Vector &&other)
    {
        this->v_size = other.v_size;
        this->v_capacity = other.v_capacity;
        this->v_Data = new value_type[v_size];
        for (size_type i = 0; i < v_size; i++)
            v_Data[i] = std::move(other.v_Data[i]);
    }
    Vector(std::initializer_list<value_type> ilist)
    {
        ReAlloc(ilist.size());
        v_size = ilist.size();
        std::move(ilist.begin(), ilist.end(), v_Data);
    }
    Vector &operator=(const Vector &other)
    {
        if (&other == this)
            return *this;
        this->v_size = other.v_size;
        this->v_capacity = other.v_capacity;
        this->v_Data = new value_type[v_size];
        for (size_type i = 0; i < v_size; i++)
            v_Data[i] = std::move(other.v_Data[i]);
        return *this;
    }
    ~Vector()
    {
        for (iterator it = begin(); it != end(); it++)
            it->~T();
        //     delete it;
        delete[] v_Data;
    };
    void assign(size_type count, const value_type &value)
    {
        this->v_capacity = count;
        this->v_size = count;
        this->v_Data = new value_type[count];
        for (size_type i = 0; i < count; i++)
            v_Data[i] = value;
    }

    reference at(size_type pos)
    {
        if (pos >= v_size)
            throw std::out_of_range("out of boundries (v_size: " + std::to_string(v_size) + ", pos: " + std::to_string(pos) + ")");
        return v_Data[pos];
    }
    const_reference at(size_type pos) const
    {
        if (pos >= v_size)
            throw std::out_of_range("out of boundries (v_size: " + std::to_string(v_size) + ", pos: " + std::to_string(pos) + ")");
        return v_Data[pos];
    }
    reference operator[](size_type i)
    {
        return v_Data[i];
    }
    const_reference operator[](size_type i) const
    {
        return v_Data[i];
    }
    reference front()
    {
        if (v_size == 0)
            throw std::invalid_argument("vector is empty");
        return v_Data[0];
    }
    const_reference front() const
    {
        if (v_size == 0)
            throw std::invalid_argument("vector is empty");
        return v_Data[0];
    }
    reference back()
    {
        if (v_size == 0)
            throw std::invalid_argument("vector is empty");
        return v_Data[v_size - 1];
    }
    const_reference back() const
    {
        if (v_size == 0)
            throw std::invalid_argument("vector is empty");
        return v_Data[v_size - 1];
    }
    iterator data()
    {
        return v_Data;
    }
    const_iterator data() const
    {
        return v_Data;
    }

    iterator begin()
    {
        return v_Data;
    }
    const_iterator begin() const
    {
        return v_Data;
    }
    iterator end()
    {
        return v_Data + v_size;
    }
    const_iterator end() const
    {
        return v_Data + v_size;
    }
    reverse_iterator rbegin()
    {
        return reverse_iterator(end());
    }
    const_reverse_iterator rbegin() const
    {
        return const_reverse_iterator(end());
    }
    reverse_iterator rend()
    {
        return reverse_iterator(begin());
    }
    const_reverse_iterator rend() const
    {
        return reverse_iterator(begin());
    }

    bool empty() const
    {
        return v_size == 0;
    }
    size_type size() const
    {
        return v_size;
    }
    size_type max_size() const
    {
        return std::numeric_limits<difference_type>::max() / sizeof(value_type);
    }
    void reserve(size_type new_cap)
    {
        if (new_cap > this->v_capacity)
            this->v_capacity = new_cap;
    }
    size_type capacity() const
    {
        return this->v_capacity;
    }
    void shrink_to_fit()
    {
        if (v_size < v_capacity)
            ReAlloc(v_size);
    }

    void clear()
    {
        for (iterator it = begin(); it != end(); it++)
            it->~T();
        // delete it;
        v_size = 0;
        // delete[] v_Data;
    }
    iterator insert(iterator pos, const_reference value)
    {
        if (pos > end() || pos < begin())
            throw std::out_of_range("Out of range");
        if (v_size >= v_capacity)
            ReAlloc(v_capacity * 2);
        v_size++;
        iterator new_data = new value_type[v_capacity];

        iterator last = std::move(begin(), pos, new_data);
        *last = value;
        std::move(pos, end(), last + 1);

        v_Data = new_data;
        return last;
    }
    iterator insert(iterator pos, size_type count, const_reference value)
    {
        if (count == 0)
            return pos;
        if (pos > end() || pos < begin())
            throw std::out_of_range("Out of range");
        v_size += count;
        if (v_size > v_capacity)
            ReAlloc(v_size);
        iterator new_data = new value_type[v_capacity];

        iterator last = std::move(begin(), pos, new_data);
        for (size_type i = 0; i < count; i++)
            *(last + i) = value;
        std::move(pos, end(), last + count);

        v_Data = new_data;
        return last;
    }
    iterator insert(iterator pos, iterator first, iterator last)
    {
        if (std::distance(first, last) == 0)
            return pos;
        if (pos > end() || pos < begin())
            throw std::out_of_range("Out of range");
        v_size += std::distance(first, last);
        if (v_size > v_capacity)
            ReAlloc(v_size);
        iterator new_data = new value_type[v_capacity];

        iterator lastPos = std::move(begin(), pos, new_data);
        std::move(first, last, lastPos);
        std::move(pos, end(), lastPos + std::distance(first, last));

        v_Data = new_data;
        return pos;
    }
    iterator insert(iterator pos, std::initializer_list<value_type> ilist)
    {
        if (std::distance(ilist.begin(), ilist.end()) == 0)
            return pos;
        if (pos > end() || pos < begin())
            throw std::out_of_range("Out of range");
        v_size += std::distance(ilist.begin(), ilist.end());
        if (v_size > v_capacity)
            ReAlloc(v_size);
        iterator new_data = new value_type[v_capacity];
        iterator lastPos = std::move(begin(), pos, new_data);
        std::move(ilist.begin(), ilist.end(), lastPos);
        std::move(pos, end(), lastPos + std::distance(ilist.begin(), ilist.end()));

        v_Data = new_data;
        return lastPos;
    }
    template <typename... Args>
    iterator emplace(iterator pos, Args &&...args)
    {
        if (pos > end() || pos < begin())
            throw std::out_of_range("Out of range");
        if (v_size >= v_capacity)
            ReAlloc(v_capacity * 2);
        v_size++;
        iterator new_data = new value_type[v_capacity];

        iterator last = std::move(begin(), pos, new_data);
        new (last) T(args...);
        std::move(pos, end(), last + 1);

        v_Data = new_data;
        return last;
    }
    iterator erase(iterator pos)
    {
        std::move(pos + 1, end(), v_Data + std::distance(v_Data, pos));
        v_size--;
        return pos;
    }
    iterator erase(iterator first, iterator last)
    {
        std::move(last, end(), v_Data + std::distance(v_Data, first));
        v_size -= std::distance(first, last);
        return first;
    }
    void push_back(const_reference val)
    {
        if (v_size >= v_capacity)
            ReAlloc(v_capacity * 2);
        v_Data[v_size++] = val;
    }
    void push_back(value_type &&val)
    {
        if (v_size >= v_capacity)
            ReAlloc(v_capacity * 2);
        v_Data[v_size++] = std::move(val);
    }
    template <typename... Args>
    void emplace_back(Args &&...args)
    {
        if (v_size >= v_capacity)
            ReAlloc(v_capacity * 2);
        new (&v_Data[v_size++]) T(args...);
    }
    void pop_back()
    {
        if (v_size > 0)
        {
            --v_size;
            v_Data[v_size].~T();
        }
    }
    void resize(size_type count)
    {
        if (count < 0)
            throw std::invalid_argument("Invalid argument");
        ReAlloc(count);
        v_size = count;
    }
    void resize(size_type count, const_reference value)
    {
        if (count < 0)
            throw std::invalid_argument("Invalid argument");
        ReAlloc(count);
        if (count > v_size)
            for (size_type i = v_size; i < count; i++)
                v_Data[i] = std::move(value);
        v_size = count;
    }
    void swap(Vector &other)
    {
        iterator temp;
        temp = this->v_Data;
        this->v_Data = other.v_Data;
        other.v_Data = temp;

        size_type tempS = this->v_size;
        this->v_size = other.v_size;
        other.v_size = tempS;

        tempS = this->v_capacity;
        this->v_capacity = other.v_capacity;
        other.v_capacity = tempS;
    }

    bool operator==(const Vector &other) const
    {
        if (v_size != other.v_size)
            return false;

        for (size_type i = 0; i < v_size; i++)
            if (v_Data[i] != other.v_Data[i])
                return false;

        return true;
    }
    bool operator!=(const Vector &other) const
    {
        if (v_size != other.v_size)
            return true;

        for (size_type i = 0; i < v_size; i++)
            if (v_Data[i] != other.v_Data[i])
                return true;

        return false;
    }
    bool operator<(const Vector &other) const
    {
        for (size_type i = 0; i < std::min(v_size, other.size()); i++)
            if (at(i) != other.at(i))
                return (at(i) < other.at(i));
        if (v_size < other.size())
            return true;
        return false;
    }
    bool operator>(const Vector &other) const
    {
        for (size_type i = 0; i < std::min(v_size, other.size()); i++)
            if (at(i) != other.at(i))
                return (at(i) > other.at(i));
        if (v_size > other.size())
            return true;
        return false;
    }
    bool operator<=(const Vector &other) const
    {
        for (size_type i = 0; i < std::min(v_size, other.size()); i++)
            if (at(i) != other.at(i))
                return (at(i) < other.at(i));
        if (v_size <= other.size())
            return true;
        return false;
    }
    bool operator>=(const Vector &other) const
    {
        for (size_type i = 0; i < std::min(v_size, other.size()); i++)
            if (at(i) != other.at(i))
                return (at(i) > other.at(i));
        if (v_size >= other.size())
            return true;
        return false;
    }

private:
    void ReAlloc(size_type newCapacity)
    {
        v_capacity = newCapacity;
        T *newData = new T[newCapacity];
        for (size_type i = 0; i < v_size; i++)
            newData[i] = std::move(v_Data[i]);
        delete[] v_Data;
        v_Data = newData;
    }
};

// nuo erase
// reik patikrint emplace
// parasyti paskutini inserta su initializer list