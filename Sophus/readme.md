https://zxl19.github.io/sophus-note/

```bash
~/HPC/vio$ tree -L 2
.
├── CMakeLists.txt
├── build
│   ├── CMakeCache.txt
│   ├── CMakeFiles
│   ├── Makefile
│   ├── cmake_install.cmake
│   └── vio
├── main.cpp
├── src
└── third_party
    └── sophus

```
```cmakelist.txt
cmake_minimum_required(VERSION 3.10)
project(vio)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加 Eigen3
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})

# 添加 Sophus 源码目录
include_directories(${PROJECT_SOURCE_DIR}/third_party/sophus)

# 添加可执行文件
add_executable(vio main.cpp)

# 如果你使用了 Sophus 需要链接的东西，可以加上（不过通常 header-only 不需要）
# target_link_libraries(vio_opt Sophus::Sophus)

# 如果 Sophus 中用到了 fmt（有些新版本用），需要链接 fmt
# find_package(fmt REQUIRED)
# target_link_libraries(vio_opt fmt::fmt)
```
