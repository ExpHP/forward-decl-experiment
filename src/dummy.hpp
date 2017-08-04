#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "dummy.tpp"

// NOTE: This file WAS supposed to be irrelevant to the demonstration,
//       but now it's an example of a file that might be forced to have
//       a TPP simply because another TPP needs it. (even without cycles)
//
//       It is possible that the "no HPP imports in TPP" rule is too strict.
//       Only time will tell.

template<typename>
struct dummy{
    void silence_unused_warning() {}
};

#endif // DUMMY_HPP
