include(ExternalProject)

ExternalProject_Add(
    ext_civetweb
    PREFIX civetweb
    URL https://github.com/civetweb/civetweb/archive/refs/tags/v1.14.tar.gz
    UPDATE_COMMAND ""
    CMAKE_ARGS
        -DCIVETWEB_BUILD_TESTING=OFF
        -DCIVETWEB_ENABLE_CXX=ON
        -DCIVETWEB_SSL_OPENSSL_API_1_0=OFF
        -DCIVETWEB_SSL_OPENSSL_API_1_1=ON
        -DCIVETWEB_ENABLE_SERVER_EXECUTABLE=OFF
        -DCIVETWEB_ENABLE_ASAN=OFF
        -DCIVETWEB_ENABLE_DEBUG_TOOLS=OFF
        -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_POLICY_DEFAULT_CMP0091:STRING=NEW
        -DCMAKE_MSVC_RUNTIME_LIBRARY:STRING=${CMAKE_MSVC_RUNTIME_LIBRARY}
        -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
        -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
        -DCMAKE_C_COMPILER_LAUNCHER=${CMAKE_C_COMPILER_LAUNCHER}
        -DCMAKE_CXX_COMPILER_LAUNCHER=${CMAKE_CXX_COMPILER_LAUNCHER}
        -DCMAKE_POSITION_INDEPENDENT_CODE=ON
        -DCMAKE_CXX_FLAGS="-D_GLIBCXX_USE_CXX11_ABI=$<BOOL:${GLIBCXX_USE_CXX11_ABI}> $<$<PLATFORM_ID:Windows>:/EHsc>"
    BUILD_BYPRODUCTS
        <INSTALL_DIR>/${Open3D_INSTALL_LIB_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}civetweb${CMAKE_STATIC_LIBRARY_SUFFIX}
        <INSTALL_DIR>/${Open3D_INSTALL_LIB_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}civetweb-cpp${CMAKE_STATIC_LIBRARY_SUFFIX}
)

ExternalProject_Get_Property(ext_civetweb INSTALL_DIR)
set(CIVETWEB_INCLUDE_DIRS ${INSTALL_DIR}/include/) # "/" is critical.
set(CIVETWEB_LIB_DIR ${INSTALL_DIR}/${Open3D_INSTALL_LIB_DIR})
set(CIVETWEB_LIBRARIES civetweb civetweb-cpp)
