# 1 资料

## 1.1 参考文档

https://www.cnblogs.com/fluidog/p/15176680.html

https://pypi.org/project/kconfiglib/#installation-with-pip

https://www.kernel.org/doc/html/latest/kbuild/kconfig-language.html

## 1.2 示例代码

https://github.com/viys/kconfig

# 2 环境配置

## 2.1 Windows

### 2.1.1 依赖

- cmake
- make
- MinGW
- python

```PowerShell
# 安装号 python 后用下面命令安装 kconfiglib 工具链
python -m pip install windows-curses
python -m pip install kconfiglib
```

### 2.1.2 Cmake 构建

```PowerShell
# 在 CMakeLists.txt 目录下执行下面命令
mkdir build
cd .\build\
cmake -G "MinGW Makefiles" ..
```

![screenshot_1.PNG](https://oss-club.rt-thread.org/uploads/20240913/f29cacf8ca2dd2bb668e5ac3ad8bc4b6.png)

### 2.1.3 打开 Kconfig

```PowerShell
# 开启 CMakeLists.txt 文件中的 CMAKE_HOST_WIN32 menuconfig 注释可以切换 menuconfig 工具
# kconfiglib 的 menuconfig.exe 比较容易有残影
# mconf-idf.exe 有乱码，切换为 utf-8 编码后并使用英文菜单可以减少乱码带来的问题缺失
# 在 build 目录下执行下面命令,即可对工程进行配置
make menuconfig
```

![screenshot_image.png](https://oss-club.rt-thread.org/uploads/20240913/1904e5b606a00c55c151451b6875b1cb.png.webp)

### 2.1.4 编译

```PowerShell
# 在 build 目录下执行下面命令,即可对工程进行编译
make
```

## 2.2 linux

### 2.1.1 依赖

- cmake
- make
- gxx
- python

```Shell
# 更新 apt
sudo apt update
sudo apt upgrade
# UNIX 可供选择的 kconfig 工具也有两种
# 第一种: 安装 kconfig-frontends (好用)
sudo apt-get install libncurses-dev kconfig-frontends
# 第一种: apt 直接安装 python3-kconfiglib
sudo apt install python3-kconfiglib
```

### 2.1.2 修改 CMakeListsxtxt

![screenshot_2.png](https://oss-club.rt-thread.org/uploads/20240913/b9d8f2579f69cb710d7a5c31153d295e.png)

将 python 修改为自己系统上已有的 python 版本,如 python3  (可以直接略过此步,本工程已更新中 CmakeLists.txt 在不同系统中做了预处理)

![screenshot_3.png](https://oss-club.rt-thread.org/uploads/20240913/ea53e6c628be30bf550b2ad654e11d0e.png)

### 2.1.3 Cmake 构建

```Shell
# 在 CMakeLists.txt 目录下执行下面命令
mkdir build
cd build/
cmake ..
```

### 2.1.4 打开 Kconfig

```Shell
# 在 build 目录下执行下面命令,即可对工程进行配置
make menuconfig
```

![screenshot_image.png](https://oss-club.rt-thread.org/uploads/20240913/4f982b294f4bfc074bc0f40bbfb24736.png.webp)

### 2.1.5 编译

```PowerShell
# 在 build 目录下执行下面命令,即可对工程进行编译
make
```

# 3 管理脚本

后期可以根据自己的系统使用脚本来实现项目的管理.
