set(DEMO demo)

add_executable(${DEMO} log_sink.cpp)
target_include_directories(${DEMO} PRIVATE ../vendor/spdlog/include)