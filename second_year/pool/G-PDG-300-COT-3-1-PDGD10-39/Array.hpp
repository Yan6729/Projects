/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Array
*/

#ifndef ARRAY_HPP_
    #include <iostream>
    #include <string>
    #include <functional>
#define ARRAY_HPP_

template < typename Type, std::size_t Size >
class Array {
    public:
        Type operator[](unsigned int index) const {
            if (index >= Size)
                throw std::runtime_error("Out of range");
            return array[index];
        };
        Type& operator[](unsigned int index) {
            if (index >= Size)
                throw std::runtime_error("Out of range");
            return array[index];
        }
        std::size_t size() const {
            return Size;
        };
        void forEach(const std::function<void(const Type&)>& task) const
        {
            for (std::size_t index = 0; index < Size; index++) {
                task(array[index]);
            }
        }
        template < typename U>
        Array<U, Size> convert(const std::function<U(const Type&)>& converter) const
        {
            Array<U, Size> result;

            for (std::size_t index = 0; index < Size; index++) {
                result[index] = converter(array[index]);
            }
            return result;
        }

    private:
        Type *array = new Type[Size];
};

template < typename Type, std::size_t Size >
std::ostream& operator<<(std::ostream& redirect, const Array<Type, Size> other)
{
    redirect << "[";

    std::size_t index;
    for (index = 0; index < Size - 1;  index++) {
        redirect << other[index] << ", ";
    }
    redirect << other[index] << "]";
    return redirect;
}
#endif /* !ARRAY_HPP_ */
