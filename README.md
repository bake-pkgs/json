# json — nlohmann/json for bake

[nlohmann/json](https://github.com/nlohmann/json) 3.12.0, packaged for
[bake](https://github.com/Ariaszzzhc/bake). Header-only.

## Use

```bash
bake add https://github.com/bake-pkgs/json --tag v3.12.0 json
```

```toml
[dependencies]
json = { url = "https://github.com/bake-pkgs/json", tag = "v3.12.0" }
```

```cpp
#include <nlohmann/json.hpp>
```

Nothing is vendored here: the pinned upstream release archive is fetched
and its `include/` is exposed as the public header root. License: MIT
(upstream).
