find_package(dav1d)

add_executable(decoder decoder.c)

target_include_directories(decoder PRIVATE ${dav1d_LIBRARIES})
target_link_libraries(decoder PRIVATE ${dav1d_LIBRARIES})
