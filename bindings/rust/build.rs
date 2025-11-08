fn main() {
    let src_dir = std::path::Path::new("src");

    let mut c_config = cc::Build::new();
    c_config.include(&src_dir);

    // MEMORY SAFETY: Enable comprehensive warnings and error checking
    c_config
        // Enable all standard warnings
        .flag_if_supported("-Wall")
        .flag_if_supported("-Wextra")
        // Disable specific warnings that are too noisy but harmless
        .flag_if_supported("-Wno-unused-parameter")
        .flag_if_supported("-Wno-unused-but-set-variable")
        .flag_if_supported("-Wno-trigraphs")
        // MEMORY SAFETY: Enable stack protection against buffer overflows
        .flag_if_supported("-fstack-protector-strong")
        // MEMORY SAFETY: Enable bounds checking on string/memory functions
        .flag_if_supported("-D_FORTIFY_SOURCE=2");

    // MEMORY SAFETY: For debug builds, enable sanitizers to catch memory bugs
    // Note: Sanitizers have performance overhead, so only use in debug/dev builds
    #[cfg(debug_assertions)]
    {
        c_config
            // Catch use-after-free, buffer overflows, memory leaks
            .flag_if_supported("-fsanitize=address")
            // Catch undefined behavior (integer overflow, null deref, etc)
            .flag_if_supported("-fsanitize=undefined")
            // Needed for better sanitizer stack traces
            .flag_if_supported("-fno-omit-frame-pointer");
    }

    let parser_path = src_dir.join("parser.c");
    c_config.file(&parser_path);

    // If your language uses an external scanner written in C,
    // then include this block of code:

    let scanner_path = src_dir.join("scanner.c");
    c_config.file(&scanner_path);
    println!("cargo:rerun-if-changed={}", scanner_path.to_str().unwrap());

    c_config.compile("parser");
    println!("cargo:rerun-if-changed={}", parser_path.to_str().unwrap());

    // If your language uses an external scanner written in C++,
    // then include this block of code:

    /*
    let mut cpp_config = cc::Build::new();
    cpp_config.cpp(true);
    cpp_config.include(&src_dir);
    cpp_config
        .flag_if_supported("-Wno-unused-parameter")
        .flag_if_supported("-Wno-unused-but-set-variable");
    let scanner_path = src_dir.join("scanner.cc");
    cpp_config.file(&scanner_path);
    cpp_config.compile("scanner");
    println!("cargo:rerun-if-changed={}", scanner_path.to_str().unwrap());
    */
}
