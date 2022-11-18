#ifndef MY_VECTOR_T_CLASS
#define MY_VECTOR_T_CLASS

#include <iostream>
#include <cstring>
#include <string>
#include <iterator>
#include <vector>
#include <functional>

/// пространство имён моей stl
/**
 * my first doxygen comment
*/
namespace my_stl {
    /// класс вектора
    /// 
    /**
     * @brief my class
    */
    template <typename Type>
    class vector {
    private:
        Type * arr = nullptr;
        size_t v_size{};
        size_t v_capacity{};

        static size_t calculate_capacity(const size_t n) {
            if (!n) return 0;

            size_t c = 1;
            while (c < n)
                c *= 2;
            return c;
        }

        template <bool IsConst>
        struct Iterator {
        private:
            std::conditional_t<IsConst, const Type, Type> * ptr;
        public:
            Iterator(Type * p) : ptr(p) {}

            Type& operator*()
            { return *ptr; }
            Type* operator->()
            { return ptr; }
            Iterator& operator++() {
                ++ptr;
                return *this;
            }
            Iterator operator++(int)
            { return *this++; }
            
            bool operator==(const Iterator & i) const 
            { return this->ptr == i.ptr; }
            bool operator!=(const Iterator & i) const 
            { return this->ptr != i.ptr; }
        };
    public:
        [[maybe_unused]] size_t size() const
        { return v_size; }
        [[maybe_unused]] size_t capacity() const
        { return v_capacity; }

        vector()  {
            std::cout << "default constructor" << std::endl;
        }

        vector(const size_t n) {
            std::cout << "n size constructor" << std::endl;
            v_size = n;
            arr = new Type[n];
            v_capacity = calculate_capacity(n);
        }

        vector(std::initializer_list<Type> list) {
            std::cout << "list size: " << list.size() << std::endl;
            v_size = list.size();
            v_capacity = calculate_capacity(v_size);
            arr = reinterpret_cast<Type *>(new char[v_capacity * sizeof(Type)]);
            std::cout << "new array has been allocated" << std::endl;
            std::memmove(arr, list.begin(), v_size * sizeof(Type));
        }

        vector(const vector & v) : v_size(v.v_size), v_capacity(v.v_capacity) {
            arr = reinterpret_cast<Type *>(new char[v_capacity * sizeof(Type)]);
            std::memmove(arr, v.arr, v_size*sizeof(Type));
        }
        vector(const std::vector<Type> & v) : v_size(v.size()), v_capacity(v.capacity()) {
            arr = reinterpret_cast<Type *>(new char[v_capacity * sizeof(Type)]);
            std::copy(v.begin(), v.end(), iterator(arr));
        }
        vector(vector && v) : v_size(v.v_size), v_capacity(v.v_capacity) {
            arr = v.arr;
            
            v.arr = nullptr;
            v.v_size = 0;
            v.v_capacity = 0;
        }
        vector(std::vector<Type> && v) : v_size(v.size()), v_capacity(v.capacity()) {
            std::copy(v.begin(), v.end(), iterator(arr));
            v.clear();
        }

        ~vector() {
            delete[] arr;
        }

        Type & operator[](size_t ind) {
            return arr[ind];
        }

        const Type & operator[](size_t ind) const {
            return arr[ind];
        }

        void push_back(Type new_el) {
            if (v_size < v_capacity) {
                arr[v_size] = new_el;
                ++v_size;
            } else {
                v_capacity = (v_capacity) ? v_capacity*2 : 1;
                Type * new_arr = reinterpret_cast<Type *>(new char[v_capacity * sizeof(Type)]);
                if (v_size)
                    std::memmove(new_arr, arr, v_size*sizeof(Type));
                delete[] arr;
                arr = new_arr;
                arr[v_size] = new_el;
                ++v_size;
            }
        }

        void pop_back() {
            if (!v_size) {
                std::cerr << "try to pop for empty vector.";
                throw std::runtime_error("this vector is empty.");
            }
            --v_size;
        }

        bool empty() const {
            return !v_size;
        }

        vector & operator=(const vector & v) {
            v_size = v.v_size;
            v_capacity = v.v_capacity;
            delete[] arr;
            arr = reinterpret_cast<Type *>(new char[v_capacity * sizeof(Type)]);
            std::memmove(arr, v.arr, v_size*sizeof(Type));
        }
        vector & operator=(vector && v) {
            if (&v != this) {
                v_size = v.v_size;
                v_capacity = v.v_capacity;
                delete[] arr;
                arr = v.arr;

                v.arr = nullptr;
                v.v_capacity = 0;
                v.v_size = 0;
            }
            return *this;
        }

        // итераторы
        using iterator = Iterator<false>;
        using const_iterator = Iterator<true>;

        iterator begin() const
        { return iterator(arr); }
        iterator end() const
        { return iterator(arr+v_size); }

        /// @brief  aggregate function
        /// @tparam T 
        /// @param seed 
        /// @param f 
        /// @return 
        template <typename T>
        T aggregate(T seed, std::function<T (T, Type&)> f) {
            T res = seed;
            for (auto el: *this)
                res = f(res, el);
            return res;
        }

        iterator insert(iterator position, std::move_iterator<iterator> first, std::move_iterator<iterator> last) {
            iterator p = position;
            for (; first != last; ++first) {
                *position = *first;
                ++position;
            }
            return p;
        }
    };
}

#endif // MY_VECTOR_T_CLASS