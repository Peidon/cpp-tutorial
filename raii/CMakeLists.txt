set(SOURCES src/shape.cpp src/obj.cpp)
add_executable(raii ${SOURCES})

target_include_directories(raii
        PRIVATE
        ${PROJECT_SOURCE_DIR}/raii/include
)