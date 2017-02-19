add_definitions(-DPRIME_DUMP_JSON=true)
add_subdirectory(PrimeMemoryDumping)

# NanoGUI (which has a bunch of warnings I want to not see)
add_definitions(-Wno-misleading-indentation -Wno-deprecated-declarations)
set(NANOGUI_BUILD_EXAMPLE OFF CACHE BOOL " " FORCE)
set(NANOGUI_BUILD_PYTHON  OFF CACHE BOOL " " FORCE)
set(NANOGUI_BUILD_SHARED  OFF CACHE BOOL " " FORCE)
set(NANOGUI_INSTALL       OFF CACHE BOOL " " FORCE)
add_subdirectory(nanogui)
# For reliability of parallel build, make the NanoGUI targets dependencies
set_property(TARGET glfw glfw_objects nanogui PROPERTY FOLDER "dependencies")

# Expose these up
set(NANOGUI_EXTRA_DEFS "${NANOGUI_EXTRA_DEFS}" PARENT_SCOPE)
set(NANOGUI_EXTRA_INCS "${NANOGUI_EXTRA_INCS}" PARENT_SCOPE)
set(NANOGUI_EXTRA_LIBS "${NANOGUI_EXTRA_LIBS}" PARENT_SCOPE)
