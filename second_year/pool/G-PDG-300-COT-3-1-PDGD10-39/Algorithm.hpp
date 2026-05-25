/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
    #include <iostream>
    #include <string>
    #define ALGORITHM_HPP_

template < typename x >
const x max(x a, x b) {
    return (b < a) ? a : b;
};
template < typename n>
const n min(n a, n b) {
    return (a < b) ? a : b;
};
template < typename s >
void swap(s& a, s& b) {
    s temp = a;
    a = b;
    b = temp;
};
template < typename c >
const c clamp(c value, c a, c b) {
    if (value < a) {
        return a;
    } else if (b < value) {
        return b;
    } else {
        return value;
    }
};

#endif /* !ALGORITHM_HPP_ */
