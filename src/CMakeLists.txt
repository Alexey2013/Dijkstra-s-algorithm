set(target ${MP2_LIBRARY})

file(GLOB hdrs "*.h*" "${MP2_INCLUDE}/*.h*")
file(GLOB srcs "*.cpp")

include_directories("${MP2_INCLUDE}" ${MP2_FILES} )

add_library(${target} STATIC ${srcs} ${hdrs})
