cmake_minimum_required(VERSION 3.15)

#c99
set(CMAKE_C_FLAGS "-std=c99")

# set the project name
set (PROJECT_NAME "demo")
project(${PROJECT_NAME})

#scripts
set(KCONFIG_DIR "${CMAKE_SOURCE_DIR}/scripts/kconfig")

#release
set(KCONFIG_CONFIG_H "my_config.h")
set(RElEASE_DIR "${CMAKE_SOURCE_DIR}/release")

# 将可执行文件输出到指定路径
# set(HOME ${CMAKE_SOURCE_DIR})
# set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)

# 添加一个自定义目标来运行 menuconfig
if(CMAKE_HOST_WIN32)
  # Windows
  add_custom_target(
        menuconfig
        WORKING_DIRECTORY ${RElEASE_DIR}
        COMMAND ${CMAKE_SOURCE_DIR}/scripts/kconfig/win-tools/mconf-idf.exe ${KCONFIG_DIR}/Kconfig
        COMMAND python ${KCONFIG_DIR}/kconfig.py ${KCONFIG_DIR}/Kconfig .config ${RElEASE_DIR}/${KCONFIG_CONFIG_H} ${RElEASE_DIR}/log.txt ${RElEASE_DIR}/.config
        COMMENT "Running menuconfig"
    )
elseif(CMAKE_HOST_APPLE)
    # macOS
    add_custom_target(
        menuconfig
        WORKING_DIRECTORY ${RElEASE_DIR}
        COMMAND menuconfig.exe ${KCONFIG_DIR}/Kconfig
        COMMAND python3 ${KCONFIG_DIR}/kconfig.py ${KCONFIG_DIR}/Kconfig .config ${RElEASE_DIR}/${KCONFIG_CONFIG_H} ${RElEASE_DIR}/log.txt ${RElEASE_DIR}/.config
        COMMENT "Running menuconfig"
    )
elseif(CMAKE_HOST_UNIX)
    # UNIX
    add_custom_target(
        menuconfig
        WORKING_DIRECTORY ${RElEASE_DIR}
        COMMAND menuconfig.exe ${KCONFIG_DIR}/Kconfig
        COMMAND python3 ${KCONFIG_DIR}/kconfig.py ${KCONFIG_DIR}/Kconfig .config ${RElEASE_DIR}/${KCONFIG_CONFIG_H} ${RElEASE_DIR}/log.txt ${RElEASE_DIR}/.config
        COMMENT "Running menuconfig"
    )
endif()

# add the executable
file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR}/project/app/*.c)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/app/bsp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/release)

add_executable(${PROJECT_NAME} ${SRC})
