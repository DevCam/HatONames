
find_package(raylib 3.0 REQUIRED)

add_executable(HatONamesGUI HatONamesGUI.c)
add_executable(HatONamesCLI HatONamesCLI.c)

# GUI
# Consider flagging this so it is only built on demand
target_link_libraries(HatONamesGUI PRIVATE hatlib)
target_link_libraries(HatONamesGUI PRIVATE raylib)

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
  target_link_libraries(HatONamesGUI PRIVATE "-framework IOKit")
  target_link_libraries(HatONamesGUI PRIVATE "-framework Cocoa")
  target_link_libraries(HatONamesGUI PRIVATE "-framework OpenGL")
endif()

# CLI
target_link_libraries(HatONamesCLI PRIVATE hatlib)
