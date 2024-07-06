cmake_minimum_required(VERSION 3.28)
project(poobaloobie_party_hour C)

set(CMAKE_C_STANDARD 11)

add_executable(poobaloobie_party_hour build.c)

if (NOT ${CMAKE_C_COMPILER_ID} MATCHES "Clang")
    message(FATAL_ERROR "${CMAKE_C_COMPILER_ID} compiler is unsupported. Use Clang instead")
endif ()

target_compile_options(poobaloobie_party_hour PRIVATE -Wextra -Wno-incompatible-library-redeclaration -Wno-sign-compare -Wno-unused-parameter -Wno-builtin-requires-header -Wno-deprecated-declarations)
if (${CMAKE_BUILD_TYPE} MATCHES "Release")
    if (${CMAKE_C_SIMULATE_ID})
        target_compile_options(poobaloobie_party_hour PRIVATE /clang:-finline-functions /clang:-ffast-math /clang:-fno-math-errno /clang:-funsafe-math-optimizations /clang:-freciprocal-math /clang:-ffinite-math-only /clang:-fassociative-math /clang:-fno-signed-zeros /clang:-fno-trapping-math /clang:-ftree-vectorize  /clang:-fomit-frame-pointer /clang:-funroll-loops /clang:-fno-rtti)
    else ()
        target_compile_options(poobaloobie_party_hour PRIVATE -finline-functions -ffast-math -fno-math-errno -funsafe-math-optimizations -freciprocal-math -ffinite-math-only -fassociative-math -fno-signed-zeros -fno-trapping-math -ftree-vectorize  -fomit-frame-pointer -funroll-loops -fno-rtti -fno-exceptions)
    endif ()
endif ()

if (${CMAKE_C_SIMULATE_ID})
    target_link_libraries(poobaloobie_party_hour PUBLIC kernel32.lib gdi32.lib user32.lib winmm.lib d3d11.lib dxguid.lib d3dcompiler.lib shlwapi.lib)
else ()
    target_link_libraries(poobaloobie_party_hour PUBLIC -lkernel32 -lgdi32 -luser32 -lwinmm -ld3d11 -ldxguid -ld3dcompiler -lshlwapi)
endif ()

