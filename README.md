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


## 📌 注意事项
- 本项目基于STM32G431RBT6开发，使用CubeMX生成基础工程，并添加RT-Thread Nano支持。
- 本项目使用立创EDA开源硬件平台开发，具体硬件设计请参考立创EDA开源硬件平台。

## 📚 参考资料
- [STM32G431xx Reference Manual](https://www.st.com/resource/en/reference_manual/dm00352174-stm32g431xx-and-stm32g441xx-advanced-arm-based-32-bit-mcus-stmicroelectronics.pdf)
- [STM32CubeMX](https://www.st.com/content/st_com/en/products/development-tools/software-development-tools/stm32-software-development-tools/stm32-configurators-and-code-generators/stm32cubemx.html)
- [RT-Thread](https://www.rt-thread.org/)