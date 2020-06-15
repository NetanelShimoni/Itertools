//
// Created by netanel & Or on 6/15/2020.
//

#ifndef C___ACCUMULATE_HPP
#define C___ACCUMULATE_HPP

#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace itertools{
    class plus
    {
    public:
        template <typename T>
        T operator()(T a, T b) { return a + b; }
    };
    template <typename T, typename func = plus>
    class accumulate
    {
    private:
        T bin;
        func function;
    public:
        accumulate(T c , func f=plus()):bin(c),function(f){}

        class iterator {
            typename T::iterator start_it;
            typename T::iterator end_it;
            decltype(*(bin.begin())) sum;
            func function;
        public:
            iterator(typename T::iterator s_it,typename T::iterator e_it,func f):
                    start_it(s_it),end_it(e_it), sum(*s_it), function(f){}

            decltype(*(bin.begin())) operator*() const {
                return sum;
            }

            iterator& operator++() {
                ++start_it;
                if(start_it!=end_it)
                    sum= function(sum,*start_it);
                return *this;
            }

            const iterator operator++(int) {
                iterator tmp= *this;
                ++start_it;
                if(start_it!=end_it)
                    sum= function(sum,*start_it);
                return tmp;
            }

            bool operator==(const iterator& other) const {
                return start_it == other.start_it;
            }

            bool operator!=(const iterator& other) const {
                return start_it != other.start_it;
            }
        }; // END OF CLASS ITERATOR

        iterator begin() {
            return iterator{bin.begin(),bin.end(),function};
        }

        iterator end() {
            return iterator{bin.end(),bin.end(),function};
        }
    };
}

#endif //C___ACCUMULATE_HPP
