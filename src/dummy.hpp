#ifndef DUMMY_HPP
#define DUMMY_HPP

// NOTE: This is irrelevant to the demonstration.

/// This is just a dumb workaround for my current ineptitude at templates.
///
/// The point is to let a function have an argument that represents the
/// return type, because reasoning about function overloads requires far less
/// mental energy than reasoning about template specialization and SFINAE.
template<typename>
struct dummy{
    void silence_unused_warning() {}
};

#endif // DUMMY_HPP
