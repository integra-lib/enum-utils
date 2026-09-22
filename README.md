# enum-utils

Enumerator to its underlying value.

Part of [integra-lib](https://gitlab.integrasources.com/internal-projects/integra-lib).
Header-only C++20, no exceptions, no RTTI.

## Use it

```bash
git submodule add ../enum-utils.git external/integra/enum-utils
```

```cmake
add_subdirectory(external/integra/enum-utils)
target_link_libraries(app PRIVATE Integra::enum_utils)
```

```cpp
#include <integra/enum_utils.hpp>
```

## Develop it

```bash
cmake -S . -B build && cmake --build build -j && ctest --test-dir build
```

Tests are built only when this repository is the top-level project, so a consumer
never builds them. Style and pipeline come from the `ci-shared` submodule; run
`git submodule update --init` before `pre-commit`.
