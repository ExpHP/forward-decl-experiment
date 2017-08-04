#ifdef  DUMMY_TPP
#include "diagnostic/forward-dependency-cycle"
#else
#define DUMMY_TPP

/// This is just a dumb workaround for my current ineptitude at templates.
///
/// The point is to let a function have an argument that represents the
/// return type, because reasoning about function overloads requires far less
/// mental energy than reasoning about template specialization and SFINAE.
template<typename>
struct dummy;

#undef DUMMY_TPP
#endif