# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.
set(HEADER_LIST "${PROJECT_SOURCE_DIR}/include/hatlib/hatlib.h")

# Make an automatic library - will be static or dynamic based on user setting
add_library(hatlib hatlib.c ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(hatlib PUBLIC ../include)

# All users of this library will need at least C++11
# target_compile_features(HatLib PUBLIC c11)

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
