cmake_minimum_required(VERSION 3.15)

#c99
set(CMAKE_C_FLAGS "-std=c99")

# set the project name
set (PROJECT_NAME "hello1")
project(${PROJECT_NAME})

#scripts
set(KCONFIG_DIR "${CMAKE_SOURCE_DIR}/scripts/kconfig")

#release
set(KCONFIG_CONFIG_H "my_config.h")
set(RElEASE_DIR "${CMAKE_SOURCE_DIR}/release")

# 将可执行文件输出到指定路径
# set(HOME ..)
# set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)

# 添加一个自定义命令来生成 config.h
# add_custom_command(
#     OUTPUT ${KCONFIG_CONFIG_H}
#     DEPENDS menuconfig
#     COMMAND python ${KCONFIG_DIR}/kconfig.py ${KCONFIG_DIR}/kconfig .config ${RElEASE_DIR}/${KCONFIG_CONFIG_H} ${RElEASE_DIR}/log.txt ${RElEASE_DIR}/.config
#     COMMENT "Generating config.h"
# )

# 添加一个依赖于 .config 目标的自定义命令
# add_custom_target(
#     generate_autoconfig_h ALL
#     DEPENDS menuconfig
# )

# 添加一个自定义目标来运行 menuconfig
add_custom_target(
    menuconfig
    WORKING_DIRECTORY ${RElEASE_DIR}
    COMMAND menuconfig.exe ${KCONFIG_DIR}/Kconfig
    COMMAND python ${KCONFIG_DIR}/kconfig.py ${KCONFIG_DIR}/Kconfig .config ${RElEASE_DIR}/${KCONFIG_CONFIG_H} ${RElEASE_DIR}/log.txt ${RElEASE_DIR}/.config
    COMMENT "Running menuconfig"
)

# 确保生成 autoconfig.h 的命令在构建时被调用
# add_dependencies(generate_autoconfig_h menuconfig)

# add the executable
file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR}/project/app/*.c)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/app/bsp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/release)

add_executable(${PROJECT_NAME} ${SRC})



