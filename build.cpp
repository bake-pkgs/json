import bake.build;
import std;

// json — nlohmann/json for bake.
//
// Module strategy: compile upstream's own C++20 module file when the
// pinned release ships one (src/modules/json.cppm — upstream keeps it
// on develop, unreleased as of 3.12.0); otherwise fall back to the
// local wrapper in module/ (a trimmed copy of the same file). The
// switch is automatic per upstream release.

int main() {
    bake::Builder b;
    namespace fs = std::filesystem;
    const auto upstream = std::string(b.dep_src_dir("upstream"));

    const fs::path upstream_module =
        fs::path(upstream) / "src/modules/json.cppm";
    if (fs::is_regular_file(upstream_module)) {
        b.include_dirs(upstream);
        b.public_modules(upstream_module.generic_string());
    } else {
        b.include_dirs(upstream + "/single_include");
        b.public_modules("module/*.cppm");
    }
    b.public_headers(upstream + "/single_include");
    return b.build();
}
