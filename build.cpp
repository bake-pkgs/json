import bake.build;
import std;

int main() {
    bake::Builder b;
    const auto upstream = std::string(b.dep_src_dir("upstream"));
    // Upstream headers back the module wrapper below; consumers may
    // still #include them directly.
    b.include_dirs(upstream + "/single_include");
    b.public_headers(upstream + "/single_include");
    b.public_modules("module/*.cppm");
    return b.build();
}
