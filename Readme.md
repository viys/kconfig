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

![img](https://z1eac6eifxs.feishu.cn/space/api/box/stream/download/asynccode/?code=ZTFhNTQ5MWI4NDdjYzM1MmU3MzA5MWNhZWFiOWI1MWZfVnRkcTQ1TThnQ1VjMWY2Z0JUcTZKTm9jVUNKRTc1QjBfVG9rZW46VHh3OWJ6aTBLb21DTjR4YUpFbmNqZzlVbmZmXzE3MjYxMjIzOTQ6MTcyNjEyNTk5NF9WNA)

### 2.1.3 打开 Kconfig

```PowerShell
# 在 build 目录下执行下面命令,即可对工程进行配置
make menuconfig
```

![img](https://z1eac6eifxs.feishu.cn/space/api/box/stream/download/asynccode/?code=OTMwMGUxYzJmNTMzY2M5YTM0Yjg4MThmZjc1YmJiYjdfV2tqbEhpMzJ6a3dMcjZBTDBsbmFuN1FTbzNnTXZPYzJfVG9rZW46WTMyUGI3M3psb1pNNkF4RVd4aGM3N3I2bkplXzE3MjYxMjIzOTQ6MTcyNjEyNTk5NF9WNA)

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
# 下载 pip
sudo apt install python3-pip
# 下面使用一种即可
# 第一种:apt直接安装
sudo apt install python3-kconfiglib
# 第二种:创建虚拟环境安装
sudo apt install python3-venv
python3 -m venv myenv
source myenv/bin/activate
pip install kconfiglib
```

### 2.1.2 修改 CMakeListsxtxt

![img](https://z1eac6eifxs.feishu.cn/space/api/box/stream/download/asynccode/?code=ZjM4ZTE1ZGU2ODEwOTlkMzU1Nzc4N2QxNGNjNmRmMzFfNXlyNGxHV0g2eVZteVZEV09teXNmdGxlT0NHOXVzNzdfVG9rZW46WnNUUGJZdEpLb2NoZmt4Z0p4UGNUUXpibkFPXzE3MjYxMjIzOTQ6MTcyNjEyNTk5NF9WNA)

将 python 修改为自己系统上已有的 python 版本,如 python3  (可以直接略过此步,本工程已更新中 CmakeLists.txt 在不同系统中做了预处理)

![img](https://z1eac6eifxs.feishu.cn/space/api/box/stream/download/asynccode/?code=ZDk1ZjU2OTNlZDhlNmJkY2E4Y2Q0YzA2NTBkNjM4ZTJfYkxiV1pIRjFlR0Jiazk2bTVkQ1FLRlVXaFBQQXd2akdfVG9rZW46V3Zjb2JhSlVTb3FLY014N2ZqTWNFRnIxbllkXzE3MjYxMjIzOTQ6MTcyNjEyNTk5NF9WNA)

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

![img](https://z1eac6eifxs.feishu.cn/space/api/box/stream/download/asynccode/?code=NDYwOThkODNhNjExN2Y2MDNiYTJhOWY5NDA0N2EwMTJfTTdxejRvS1Q0UFdCa1ZmUm5GSElvVVNZUUp5dnVJaFVfVG9rZW46UWFyR2JTTkVUb2g5anB4UU5NSGMwUGVDbkNkXzE3MjYxMjIzOTQ6MTcyNjEyNTk5NF9WNA)

### 2.1.5 编译

```PowerShell
# 在 build 目录下执行下面命令,即可对工程进行编译
make
```

# 3 管理脚本

后期可以根据自己的系统使用脚本来实现项目的管理.

原飞书链接:https://z1eac6eifxs.feishu.cn/docx/RmpzdsPoeo0qxux5I5yclfxvnob
