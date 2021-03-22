

#core
file(GLOB_RECURSE src_pEngine_core
./src/pEngine/core/*.cpp
./src/pEngine/core/*.h
)

#event
file(GLOB src_pEngine_event
./src/pEngine/Event/*.cpp
./src/pEngine/Event/*.h
)

#head
file(GLOB head_pEngine
./src/*.h
)

message(STATUS ${head_pEngine})
#...

#----------------------------------thirdParty------------------------------
#spdlog
file(GLOB_RECURSE thirdSrc_pEngine_spdlog_code
./thirdParty/spdlog/src/*.cpp
./thirdParty/spdlog/include/*.h
)

#glfw
#glfw_window
set(thirdSrc_pEngine_glfw_window_code

./thirdParty/glfw/src/win32_init.c
./thirdParty/glfw/src/win32_joystick.c
./thirdParty/glfw/src/win32_monitor.c
./thirdParty/glfw/src/win32_time.c
./thirdParty/glfw/src/win32_thread.c
./thirdParty/glfw/src/win32_window.c
./thirdParty/glfw/src/wgl_context.c
./thirdParty/glfw/src/egl_context.c
./thirdParty/glfw/src/osmesa_context.c
)

#glfw_linux
set(thirdSrc_pEngine_glfw_linux_code

./thirdParty/glfw/src/src/x11_init.c
./thirdParty/glfw/src/src/x11_monitor.c
./thirdParty/glfw/src/src/x11_window.c
./thirdParty/glfw/src/src/xkb_unicode.c
./thirdParty/glfw/src/src/posix_time.c
./thirdParty/glfw/src/src/posix_thread.c
./thirdParty/glfw/src/src/glx_context.c
./thirdParty/glfw/src/src/egl_context.c
./thirdParty/glfw/src/src/osmesa_context.c
./thirdParty/glfw/src/src/linux_joystick.c
)

if(WIN32)
set(platform_code ${thirdSrc_pEngine_glfw_window_code})
set(platform_define 
-D_GLFW_WIN32
-D_CRT_SECURE_NO_WARNINGS
)
message(STATUS "current platform is window")
elseif(UNIX)
set(platform_code ${thirdSrc_pEngine_glfw_linux_code})
set(platform_define 
-D_GLFW_X11
)
message(STATUS "current platform is linux")
endif()

set(thirdSrc_pEngine_glfw_platform_code

./thirdParty/glfw/src/glfw_config.h
./thirdParty/glfw/src/context.c
./thirdParty/glfw/src/init.c
./thirdParty/glfw/src/input.c
./thirdParty/glfw/src/monitor.c
./thirdParty/glfw/src/vulkan.c
./thirdParty/glfw/src/window.c
${platform_code}
)
#-------------------------------------------------------------------------


add_definitions( 
-DPLATEFORM_WINDOWS 
-DBUILD_DLL 
-DSPDLOG_COMPILED_LIB     #spdlog
${platform_define}        #glfw
)


include_directories(
./src
./src/pEngine/core
./src/pEngine/event
./thirdParty/spdlog/include
./thirdParty/glfw/include
)

add_library(glfw STATIC 
${thirdSrc_pEngine_glfw_platform_code}
)

add_library(spdlog STATIC 
${thirdSrc_pEngine_spdlog_code}
)

add_library(pEngine SHARED 
${src_pEngine_core}
${src_pEngine_event}
)

target_link_libraries(pEngine opengl32 spdlog glfw)

source_group("src\\pEngine\\core" FILES ${src_pEngine_core})
source_group("src\\pEngine\\event" FILES ${src_pEngine_event})
source_group("src\\" FILES ${head_pEngine})

#thirdParty
source_group("thirdParty\\spdlog" FILES ${thirdSrc_pEngine_spdlog_code})
source_group("thirdParty\\glfw" FILES ${thirdSrc_pEngine_glfw_platform_code})

set_target_properties(pEngine PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
install(TARGETS pEngine RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/Debug/bin)
