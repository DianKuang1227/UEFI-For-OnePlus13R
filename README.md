# Project Silicium UEFI for OnePlus 13R (giulia)

> **⚠️ 警告：这是一个实验性 UEFI 固件移植项目，可能会有不可预料的问题！**

---

## 📱 设备信息

| 项目 | 详情 |
|------|------|
| **设备代号** | `giulia` |
| **商业名称** | OnePlus 13R |
| **SoC** | Snapdragon 8 Gen 3 (SM8650) |
| **架构** | ARM64 (AArch64) |

---

## 🏗 仓库结构

```text
UEFI-For-OnePlus13R/
├── Binaries/                 # 预编译二进制依赖 (ArmPkg, QcomPkg, MdeModulePkg 等)
├── BootShim/                 # Linux Boot Shim (内核加载器)
├── Common/                   # 公共子模块配置
├── Mu_Basecore/              # Project Mu 核心库 (子模块)
├── Platforms/                # 平台包
│   └── OnePlus/
│       └── giuliaPkg/        # OnePlus 13R 设备包
├── Resources/
│   ├── Configs/              # 设备 TOML 配置 (giulia.toml)
│   ├── DTBs/                 # 设备树文件 (giulia.dtb/.dts)
│   ├── MuPatches/            # Mu 仓库补丁
│   └── Scripts/              # 辅助脚本 (mkbootimg.py 等)
├── Silicon/                  # Silicon 包
├── Silicium-ACPI/            # ACPI 表生成
├── build_uefi.py             # 主构建脚本
├── setup_env.sh              # 环境配置脚本
└── pip-requirements.txt      # Python 依赖
```

---

## ✨ 功能特性

- ✅ **完整 UEFI Shell** 环境
- ✅ **Android Boot Image (v4)** 生成，支持 `boot.img` 直接启动
- ✅ **GZIP 内核压缩** 支持
- ✅ **DTB 内嵌/外挂** 双模式
- ✅ **Secure Boot** 可选支持
- ✅ **BootShim** 加载 Linux 内核 (需内核头部)
- ✅ **Fastboot / EDL** 双刷写路径
- ✅ **CLANGPDB** 工具链优化构建

---

## 🛠 构建环境要求

| 组件 | 推荐版本 |
|------|----------|
| **宿主 OS** | Ubuntu 22.04+ / Arch Linux / Fedora 39+ |
| **Python** | 3.10+ |
| **工具链** | `clang` + `lld` + `aarch64-linux-gnu-gcc` |
| **其他** | `git`, `nasm`, `uuid-dev`, `mono`, `nuget`, `pip` |

### 一键安装依赖

```bash
# Ubuntu / Debian
sudo ./setup_env.sh -p apt

# Fedora / RHEL
sudo ./setup_env.sh -p dnf

# Arch Linux / Manjaro
sudo ./setup_env.sh -p pacman
```

> 脚本会自动安装系统包、Python 依赖、克隆并编译 AUR `uuid` 包 (Arch)。

---

## 🚀 快速开始

### 1. 克隆仓库

```bash
git clone https://github.com/DianKuang1227/UEFI-For-OnePlus13R.git
cd UEFI-For-OnePlus13R
```

### 2. 配置环境 (首次)

```bash
./setup_env.sh -p apt   # 或 dnf / pacman
```

### 3. 构建 UEFI

```bash
# 基础构建 (RELEASE 模式)
./build_uefi.py -d giulia -r RELEASE

# DEBUG 模式 (带调试符号)
./build_uefi.py -d giulia -r DEBUG

# 启用 Secure Boot
./build_uefi.py -d giulia -r RELEASE -s

# 清理重新构建
./build_uefi.py -d giulia -r RELEASE -c
```

#### 参数说明

| 参数 | 说明 | 可选值 |
|------|------|--------|
| `-d, --device` | 设备代号 | `giulia` (必填) |
| `-m, --model` | 设备型号变体 | `0` (默认) |
| `-r, --release` | 构建类型 | `RELEASE` / `DEBUG` (默认 RELEASE) |
| `-s, --enable-secureboot` | 启用 Secure Boot | 无 (flag) |
| `-c, --clean` | 清理旧构建产物 | 无 (flag) |

---

## 📦 构建产物

构建成功后，根目录会生成：

| 文件 | 说明 | 启动方式 |
|------|------|----------|
| `Mu-giulia-0.img` | **Android Boot Image (v4)** | `fastboot boot Mu-giulia-0.img` |
| `Mu-giulia-0.bin` | 原始 UEFI Payload (BootShim + FD) | EDL / 专用工具 |
| `Build/giuliaPkg/RELEASE_CLANGPDB/FV/SILICIUM_UEFI.fd` | 纯 UEFI FD 镜像 | 二次打包/调试 |

---

## 📲 启动指南

```bash
# 进入 Fastboot Mode
adb reboot bootloader

# 从Mu-giulia-0.img启动
fastboot boot Mu-giulia-0.img
```

---

> **免责声明**  
> 本项目仅供学习研究使用。刷写第三方 UEFI 可能导致设备保修失效、数据丢失或永久损坏。**操作前请务必备份重要数据，并确保掌握 EDL 救砖技能。** 作者不承担任何责任。

---

**⭐ 如果这个项目对你有帮助，请给个 Star 支持一下！**