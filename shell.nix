{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    # Compilers
    gcc
    clang
    
    # Build systems
    cmake
    gnumake
    ninja
    meson
    
    # Debuggers
    gdb
    lldb
    valgrind
    
    # Build essentials
    pkg-config
    autoconf
    automake
    libtool
    m4
    
    # Common libraries
    ncurses
    ncurses.dev
    readline
    zlib
    zlib.dev
    openssl
    openssl.dev
    
    # Development tools
    ccache
    clang-tools  # includes clang-format, clang-tidy
    cppcheck
    
    # Version control
    git
    
    # Additional utilities
    bear  # generates compile_commands.json
    gtest  # Google Test framework
    boost  # Boost C++ libraries
  ];

  shellHook = ''
    echo "🔧 C/C++ Development Environment"
    echo "================================"
    echo ""
    echo "Compilers:"
    echo "  - GCC: $(gcc --version | head -n1)"
    echo "  - Clang: $(clang --version | head -n1)"
    echo ""
    echo "Build Systems:"
    echo "  - CMake: $(cmake --version | head -n1)"
    echo "  - Make: $(make --version | head -n1)"
    echo "  - Ninja: $(ninja --version)"
    echo "  - Meson: $(meson --version)"
    echo ""
    echo "Debuggers:"
    echo "  - GDB: $(gdb --version | head -n1)"
    echo "  - Valgrind: $(valgrind --version)"
    echo ""
    echo "Useful commands:"
    echo "  - bear -- make          : Generate compile_commands.json"
    echo "  - clang-format -i *.cpp : Format source files"
    echo "  - clang-tidy *.cpp      : Run static analysis"
    echo "  - cppcheck --enable=all : Run additional static analysis"
    echo ""
    echo "Development ready! 🚀"
    echo ""
  '';

  # Environment variables for proper C/C++ development
  hardeningDisable = [ "all" ];  # Disable hardening for development flexibility
  
  # Set library and include paths
  NIX_CFLAGS_COMPILE = "-O2";
  LIBRARY_PATH = "${pkgs.lib.makeLibraryPath [
    pkgs.ncurses
    pkgs.readline
    pkgs.zlib
    pkgs.openssl
  ]}";
  
  # Help pkg-config find libraries
  PKG_CONFIG_PATH = "${pkgs.lib.concatStringsSep ":" [
    "${pkgs.ncurses.dev}/lib/pkgconfig"
    "${pkgs.readline.dev}/lib/pkgconfig"
    "${pkgs.zlib.dev}/lib/pkgconfig"
    "${pkgs.openssl.dev}/lib/pkgconfig"
  ]}";

  CPATH = "${pkgs.lib.makeSearchPath "include" [
    pkgs.glibc.dev
    pkgs.gcc.cc.lib
    pkgs.gcc.cc
    pkgs.ncurses.dev
  ]}";
  
  CPLUS_INCLUDE_PATH = "${pkgs.lib.makeSearchPath "include" [
    pkgs.glibc.dev
    pkgs.gcc.cc.lib
    pkgs.gcc.cc
  ]}";
}
