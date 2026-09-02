import bake.build;
import std;

int main() {
    bake::Builder b;
    const auto upstream = std::string(b.dep_src_dir("upstream"));
    b.public_headers(upstream + "/include");
    return b.build();
}
