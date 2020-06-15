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
            class Iterator{
            private:
                int curr;

            public:

                Iterator(int c)
                        : curr(c) {
                }
                int operator*() const {
                    return curr;
                }

                // ++i;
                Iterator& operator++() {
                    ++this->curr;
                    return *this;
                  
                }
                const Iterator operator++(int) {
                    Iterator tmp= *this;
                    ++curr;
                    return tmp;
                }

                bool operator==(const Iterator& r) const {
                    return curr == r.curr;
                }

                bool operator!=(const Iterator& r) const {
                    return curr != r.curr;
                }
            };  // END OF CLASS ITERATOR

            Iterator begin() {
                return Iterator{start_index};
            }

            Iterator end() {
                return Iterator{end_index};
            }
        };
    }



#endif //C___RANGE_HPP
