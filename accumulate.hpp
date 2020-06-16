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
    class ADD
    {
    public:
        template <typename T>
        T operator()(T a, T b) { return a + b; }
    };
    template <typename T, typename func = ADD>
    class accumulate
    {
    private:
        T bin;
        func function;
    public:
        accumulate(T c , func f=ADD()):
        bin(c),
        function(f){}

        class iterator {
        public:
//            typename T::iterator start_index;
//            typename T::iterator end_index;
            int start_index;
            int end_index;
            decltype(*(bin.begin())) sum;
            func function;
        public:
            iterator(typename T::iterator s_it,typename T::iterator e_it,func f):
                    start_index(s_it),end_index(e_it), sum(*s_it), function(f){}

            decltype(*(bin.begin())) operator*() const {
                return sum;
            }

            iterator& operator++() {
                ++start_index;
                if(start_index!=end_index)
                    sum= function(sum,*start_index);
                return *this;
            }

            const iterator operator++(int) {
                iterator tmp= *this;
                ++start_index;
                if(start_index!=end_index)
                    sum= function(sum,*start_index);
                return tmp;
            }

            bool operator==(const iterator& other) const {
                return start_index == other.start_index;
            }

            bool operator!=(const iterator& other) const {
                return start_index != other.start_index;
            }
        };

        template <typename U>
        typename accumulate::iterator accumulate::begin()
        {
            return iterator{iterator::start_index, iterator::end_index,this->function };
        }

        template <typename U>
        typename accumulate::iterator accumulate::end()
        {
            return iterator{iterator::start_index, iterator::end_index,this->function };
        }
    };
}

#endif //C___ACCUMULATE_HPP
