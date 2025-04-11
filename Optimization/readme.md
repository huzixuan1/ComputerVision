```cpp
slam_optimizer/
├── main.cpp                  # 主程序入口，负责运行和调度各模块
├── optimizer/               # 优化核心模块
│   ├── qr_decomposition.cpp  # QR分解模块
│   ├── residual_block.cpp    # 残差块计算模块
│   └── optimizer.cpp         # 优化器模块，主要处理优化的核心逻辑
├── utils/                   # 辅助工具函数
│   ├── jacobian.cpp          # 雅可比矩阵计算
│   ├── hessian.cpp           # 海森矩阵计算（如需要）
│   └── helper.cpp            # 其他辅助函数（如矩阵操作）
├── tests/                   # 测试模块，包含单元测试
│   ├── test_optimizer.cpp    # 优化器测试
│   ├── test_qr.cpp           # QR分解测试
│   └── test_residual.cpp     # 残差块计算测试
└── README.md                # 项目文档说明
```

------------------
```cpp
slam_optimizer/
├── main.cpp                      # 主程序入口（运行 demo 或实验）
│
├── core/                        # 优化核心模块
│   ├── problem.cpp               # Problem类：管理变量块和残差块
│   ├── variable_block.cpp        # 优化变量（如 Pose, Point, etc）
│   ├── residual_block.cpp       # 残差基类 + 常见残差模型
│   ├── optimizer.cpp             # 优化器核心（GN / LM）
│   ├── marginalization.cpp       # 边缘化实现（如 QR, prior 处理）
│   └── qr_decomposition.cpp      # QR消元工具（用于变量消元）
│
├── math_utils/                  # 数学工具模块（矩阵、导数计算等）
│   ├── jacobian.cpp              # 雅可比矩阵计算或数值导数
│   ├── hessian.cpp               # 可选：稀疏海森矩阵构建
│   ├── linear_solver.cpp         # 稀疏求解器接口（LDLT / QR）
│   └── robust_loss.cpp           # 鲁棒核函数（Huber等）
│
├── factors/                     # 具体残差项模型（按类型组织）
│   ├── imu_factor.cpp            # IMU 残差
│   ├── reprojection_factor.cpp   # 重投影误差残差
│   ├── markov_blanket_factor.cpp # MarkovBlanketFactor实现
│   └── prior_factor.cpp          # 先验项（用于边缘化）
│
├── utils/                       # 辅助工具模块
│   ├── geometry.cpp              # SE3/ SO3 / log/exp 工具函数
│   ├── config.cpp                # 超参数配置
│   └── logger.cpp                # 日志和调试打印
│
├── tests/                       # 单元测试 & demo 实验
│   ├── test_optimizer.cpp
│   ├── test_factors.cpp
│   ├── test_qr.cpp
│   └── test_marginalization.cpp
│
└── README.md

```

```cpp
slam_optimizer_cpp/
├── include/
│   ├── optimizer/               # 核心优化模块头文件
│   │   ├── optimizer.h          # 优化器主接口，负责调度整个优化流程（如 GN 或 LM 迭代）
│   │   ├── qr_solver.h          # QR分解求解器接口，用于稀疏消元（特别是对3D点做消元）
│   │   ├── residual_block.h     # 残差块接口，封装每个观测项（如IMU、重投影）的残差计算逻辑
│   └── utils/
│       ├── jacobian.h           # 雅可比矩阵计算工具，定义通用模板和计算方法
│       ├── hessian.h            # 海森矩阵计算或构建（可选，主要用于GN形式）
│       └── helper.h             # 通用辅助函数，如矩阵拼接、调试输出等
├── src/
│   ├── main.cpp                 # 主程序入口，初始化数据、构建图、运行优化
│   ├── optimizer/
│   │   ├── optimizer.cpp        # 实现优化器核心逻辑，如线性化、构建矩阵、调用QR消元、更新变量等
│   │   ├── qr_solver.cpp        # 实现QR求解器，主要用于对稀疏变量（如3D点）进行消元
│   │   ├── residual_block.cpp   # 实现残差块的计算方式，包括 Reprojection、IMU 等因子的残差与雅可比
│   └── utils/
│       ├── jacobian.cpp         # 实现雅可比计算的具体函数
│       ├── hessian.cpp          # 实现海森矩阵的构建（根据雅可比），如需要用到 H = JᵀJ
│       └── helper.cpp           # 一些通用工具实现，例如打印矩阵、索引映射、维度检查等
├── tests/
│   ├── test_optimizer.cpp       # 对 Optimizer 的单元测试，验证优化收敛性、结果正确性
│   ├── test_qr_solver.cpp       # 对 QR 分解模块测试，验证稀疏消元是否正确
│   └── test_residual.cpp        # 对 ResidualBlock 测试，验证重投影/IMU 残差和雅可比计算正确性
├── thirdparty/                  # 可选，存放外部依赖，如 Eigen（矩阵库）、Sophus（位姿）、gtest 等
├── CMakeLists.txt               # 构建系统配置文件，定义项目结构、依赖和编译规则
└── README.md                    # 项目说明文档，介绍用途、架构、依赖、编译方法和示例用法

```
