#ifndef MY_VECTOR_T_CLASS
#define MY_VECTOR_T_CLASS

#include <cstring>
#include <string>

namespace my_stl {
    template <typename Type>
    class vector {
    private:
        Type * arr = nullptr;
        size_t v_capacity{};
        size_t v_size{};

        static size_t calculate_capacity(const size_t n) {
            if (!n) return 0;

            size_t c = 1;
            while (c < n)
                c *= 2;
            return c;
        }

    public:
        [[nodiscard]] size_t size() const
        { return v_size; }
        [[nodiscard]] size_t capacity() const
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

        ~vector() {
            delete[] arr;
        }
    };
}

#endif // MY_VECTOR_T_CLASS