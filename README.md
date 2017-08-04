
### TPP file rules

* TPPs' main role are to eliminate *harmful* dependency cycles.
  * a **harmful dependency cycle** is one that causes successful compilation to depend on inclusion order.
  * most cycles are harmless. TPPs should be rarely needed.
  * Harmful cycles tend to arise near heavy use of C++ templates.
* TPPs must NOT have definitions.
  * This includes explicit instantiations
  * This includes anything that would error if it appeared multiple times in the source code.
* TPPs are absolutely **forbidden** from forming dependency cycles.
  * They use a **different style of header guard** that aims to detect cycles.
  * TPPs are not allowed to include HPP files other than system headers, as this could cause a cycle
    to become hidden again. (I think)
    
### TPP include guard

**`diagnostic/forward-dependency-cycle`**

```c++
#error Dependency cycle in forward declarations! \
 (or, you forgot to #undef at the end of the file)
```

**`foo.tpp`**

```c++
#ifdef  FOO_TPP
#include "diagnostic/forward-dependency-cycle"
#else
#define FOO_TPP

// ... declarations ONLY ...

// end of tpp extra bits
#undef FOO_TPP
#endif
```
    
### example code include graph

![Graph](https://g.gravizo.com/source/svg?https%3A%2F%2Fraw.githubusercontent.com%2FExpHP%2Fforward-decl-experiment%2Fmaster%2Fres%2Fincludes.dot)
