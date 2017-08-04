
### TPP file rules

* A TPP is like a **"header header"**.
  * They hold **declarations** for definitions in headers.
  * If both file exist, then the **first include of `a.hpp` is `a.tpp`.**
  * Not every TPP needs an HPP.
* TPPs' main role are to eliminate *harmful* dependency cycles.
  * a **harmful dependency cycle** is one that causes successful compilation to depend on inclusion order.
  * most cycles are harmless. TPPs are **rarely needed**.
  * Harmful cycles tend to arise near heavy use of C++ templates.
* TPPs have **no definitions**.
  * No template explicit instantiations
  * None of anything that would error if it appeared multiple times in the source code.
* TPPs are absolutely **forbidden** from forming dependency cycles.
  * They use a **different style of header guard**
  * *(subject to change)* TPPs are **not allowed to include HPP files** other than system headers, as this could cause a harmful dependency cycle to become hidden. (I think) 
    
For ease of reasoning about where TPPs are necessary, I further propose the following limitation: (subject to change)

* A TPP is only included **by its own HPP** and **by other TPPs**

This requires to to produce more TPP files than strictly necessary for cycle resolution, but I believe it is easier to reason about dependency cycles that exist **solely between declarations** than it is to reason about dependency cycles between declarations (TPP) and definitions (HPP).
    
### TPP include guard

Two lines are added near the bottom of the standard guard:

**`foo.tpp`**

```c++
#ifndef FOO_TPP
#define FOO_TPP

// ... declarations ONLY ...

#undef FOO_TPP  // <-- NEW
#else           // <-- NEW
#include "diagnostic/forward-dependency-cycle"   // <-- NEW
#endif
```

**`diagnostic/forward-dependency-cycle`**

```c++
#error Dependency cycle in forward declarations! \
 (or, you forgot to #undef at the end of the file)
```

### example code include graph

![Graph](https://g.gravizo.com/source/svg?https%3A%2F%2Fraw.githubusercontent.com%2FExpHP%2Fforward-decl-experiment%2Fmaster%2Fres%2Fincludes.dot)

Actually, I was surprised to see that this is a DAG.  When I originally wrote the example, `parse.hpp` and `json.hpp` both included each other, but adding some TPPs forced me to break up json.hpp in a way that broke the cycle.
