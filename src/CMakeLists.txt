find_package(dav1d)

add_executable(decode main.c)

target_include_directories(decode PRIVATE ${dav1d_LIBRARIES})
target_link_libraries(decode PRIVATE ${dav1d_LIBRARIES})
