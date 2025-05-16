# Kconfig 教程：基于 CMake 和 menuconfig 的配置系统集成

本教程介绍如何在 C/C++ 项目中集成使用 Kconfig 配置系统，并通过 `menuconfig` 实现可视化配置界面。该方法适用于跨平台「Windows/Linux」环境。

------

## 目录

1. [简介](#简介)
2. [目录结构说明](#目录结构说明)
3. [Kconfig 语法示例](#kconfig-语法示例)
4. [环境配置](#环境配置)
5. [使用方法](#使用方法)
6. [常见问题](#常见问题)

------

## 简介

Kconfig 是 Linux 内核采用的一套灵活的配置系统。结合 `menuconfig` 工具，它可以为 C 项目提供强大的功能开关和参数配置支持。本项目集成了：

- `Kconfig` 主配置文件
- `sub.kconfig` 子模块配置
- `menuconfig` 工具（支持 Windows 和 Linux）
- `merge_config.py` 脚本生成头文件 `my_config.h`
- CMake 自定义构建规则集成

------

## 目录结构说明

```
├— CMakeLists.txt        # 构建脚本
├— Kconfig               # 主配置入口
├— prj.config            # 用户预配置项
├— scripts/kconfig       # 配套脚本和工具
│   └— merge_config.py
├— project/
│   ├— sub.kconfig       # 子模块配置
│   └— app/main.c        # 应用入口
├— build/                # 构建目录
└— my_config.h           # 由 merge_config.py 自动生成
```

------

## Kconfig 语法示例

以下是 `Kconfig` 和 `sub.kconfig` 的部分配置说明：

```kconfig
# 顶层菜单
mainmenu "Kconfig 示例主菜单"

menu "主功能配置"
config APP_VERSION
    string "应用版本号"
    default "v1.0.0"

config ENABLE_FEATURE
    bool "启用主要功能"
    default y
endmenu

source "project/sub.kconfig"
# project/sub.kconfig
menu "模块配置"

config MODULE_ENABLE
    bool "启用模块"
    default n

if MODULE_ENABLE
config MODULE_STRING
    string "模块字符串参数"
    default "hello"

config MODULE_INT
    int "整数参数"
    default 10
    range 1 100

choice
    prompt "模块工作模式"
    default MODULE_MODE_A

config MODULE_MODE_A
    bool "模式 A"
config MODULE_MODE_B
    bool "模式 B"
endchoice
endif

endmenu
```

------

## 环境配置

### Windows

#### 安装依赖

- CMake
- MinGW (make, gcc)
- Python 3.x
- Python 包：

```powershell
# 安装好 python 后用下面命令安装 kconfiglib 工具链
python -m pip install windows-curses
python -m pip install kconfiglib
```

#### 构建和配置

```powershell
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
make menuconfig
make
```

> 注意：`menuconfig.exe` 容易产生残影，推荐使用 `mconf-idf.exe` 并设置 UTF-8 编码和英文界面减少乱码。

------

### Linux

#### 安装依赖

```bash
sudo apt update
sudo apt install cmake make g++ python
# UNIX 可供选择的 kconfig 工具也有两种
# 第一种: 安装 kconfig-frontends (好用)
sudo apt-get install libncurses-dev kconfig-frontends
# 第一种: apt 直接安装 python3-kconfiglib
sudo apt install python3-kconfiglib
```

#### 构建和配置

```bash
mkdir build
cd build
cmake ..
make menuconfig
make
```

------

## 使用方法

1. 执行 `make menuconfig` 打开配置界面
2. 修改所需配置并保存 `.config`
3. `merge_config.py` 会合并生成 `my_config.h`
4. `main.c` 或其他源文件中引入并使用定义

```c
#include "my_config.h"

#ifdef CONFIG_MODULE_ENABLE
    printf("模块启用，模式：%s\n", CONFIG_MODULE_MODE_A ? "A" : "B");
#endif
```

------

## 常见问题

- **乱码**：Windows 下使用 `mconf-idf.exe`，需设置控制台编码为 UTF-8。
- **.config 丢失或无效**：确保已执行 `make menuconfig` 并保存退出。
- **定义未生成**：检查 `merge_config.py` 是否正确执行。

------

## 参考资料

- [Kconfig 官方文档](https://www.kernel.org/doc/html/latest/kbuild/kconfig-language.html)
- [Kconfiglib 文档](https://pypi.org/project/kconfiglib/) 
- [博客教程](https://www.cnblogs.com/fluidog/p/15176680.html)
- 示例项目：https://github.com/viys/kconfig

------
