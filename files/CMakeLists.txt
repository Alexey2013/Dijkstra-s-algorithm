set(target ${MP2_FILES})

file(GLOB txts "*.txt")

add_executable(${target} ${txts})
target_link_libraries(${target} gtest ${MP2_LIBRARY} ${MP2_INCLUDE} )