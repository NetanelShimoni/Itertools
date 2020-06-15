//
// Created by netanel & Or on 6/15/2020.
//

#ifndef C___RANGE_HPP
#define C___RANGE_HPP

#include <iostream>
#include <string>

#pragma once

    namespace itertools{
        class range{
            int start_index, end_index ;
        public:
            range(int s, int e): start_index(s),end_index(e){}
            class iterator{
            private:
                int curr;

            public:

                iterator(int c)
                        : curr(c) {
                }
                int operator*() const {
                    return curr;
                }

                // ++i;
                iterator& operator++() {
                    ++this->curr;
                    return *this;
                  
                }
                const iterator operator++(int) {
                    iterator tmp= *this;
                    ++curr;
                    return tmp;
                }

                bool operator==(const iterator& r) const {
                    return curr == r.curr;
                }

                bool operator!=(const iterator& r) const {
                    return curr != r.curr;
                }
            };  // END OF CLASS iterator

            iterator begin() {
                return iterator{start_index};
            }

            iterator end() {
                return iterator{end_index};
            }
        };
    }



#endif //C___RANGE_HPP
