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
