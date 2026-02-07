# xFOC - 基于STM32G431RBT6的FOC控制器
[硬件开源链接](https://oshwhub.com/summerleaf/xfoc)

[配置文档](https://flowus.cn/share/196ae1fd-b800-4e00-ad96-0d0e0801fd62?code=Q677GP)

基于立创EDA开源硬件平台开发的FOC控制器，采用STM32G4高性能系列MCU，支持RT-Thread Nano实时操作系统。

【FlowUs 息流】FOC学习
## 📜 更新

### [1] - 2025.3.22 - 基础驱动验证
- ⚡ 创建CubeMX基础工程
- 📌 添加RT-Thread Nano支持
- ✅ 完成GPIO驱动配置
- ✅ USART1通信测试通过
- ⚙️ 添加RCC时钟树说明
- 📝 补充工程结构说明
### [2] - 2025.3.24 - 基础驱动验证
- 添加三路互补PWM输出（未验证，手头没示波器）

## 📌 使用说明
### 1. 准备开发环境
- **STM32CubeMX**：用于查看/修改 `.ioc` 工程配置并重新生成代码。
- **Keil MDK-ARM**（或兼容的 ARM 编译环境）：用于编译与烧录工程。

### 2. 生成/更新代码（可选）
1. 使用 STM32CubeMX 打开根目录下的 `FOC_demo.ioc`。
2. 根据需要修改配置后生成代码（保持默认的工程路径即可）。

### 3. 编译与下载
1. 使用 Keil MDK 打开 `MDK-ARM/FOC_demo.uvprojx`。
2. 选择目标并编译。
3. 连接调试器后下载到板卡。

### 4. 目录结构说明
- `Core/`：CubeMX 生成的核心启动与外设初始化代码。
- `Drivers/`：STM32 HAL/CMSIS 驱动库。
- `Middlewares/`：第三方中间件（含 RT-Thread Nano）。
- `RT-Thread/`：RT-Thread 组件与适配层。
- `UserApp/`：用户应用层代码（业务逻辑入口）。
- `motor_control/`：FOC 电机控制相关实现。
- `MDK-ARM/`：Keil 工程与编译输出配置。
- `Common/`：通用工具与组件。


## 📌 注意事项
- 本项目基于STM32G431RBT6开发，使用CubeMX生成基础工程，并添加RT-Thread Nano支持。
- 本项目使用立创EDA开源硬件平台开发，具体硬件设计请参考立创EDA开源硬件平台。

## 📚 参考资料
- [STM32G431xx Reference Manual](https://www.st.com/resource/en/reference_manual/dm00352174-stm32g431xx-and-stm32g441xx-advanced-arm-based-32-bit-mcus-stmicroelectronics.pdf)
- [STM32CubeMX](https://www.st.com/content/st_com/en/products/development-tools/software-development-tools/stm32-software-development-tools/stm32-configurators-and-code-generators/stm32cubemx.html)
- [RT-Thread](https://www.rt-thread.org/)
