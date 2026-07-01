/**
  版权所有 (c) 2011-2012, ARM Limited。保留所有权利。
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include <Library/PlatformSecLib.h>
#include <Library/ArmSmmuDetachLib.h>

STATIC
ARM_CORE_INFO
mArmPlatformMpCoreInfoTable[] = {
  // Mpidr, 邮箱设置地址, 邮箱获取地址, 邮箱清除地址, 邮箱清除值

  // 簇 0
  { 0x000, 0, 0, 0, 0xFFFFFFFF },
  { 0x100, 0, 0, 0, 0xFFFFFFFF },
  { 0x200, 0, 0, 0, 0xFFFFFFFF },
  { 0x300, 0, 0, 0, 0xFFFFFFFF },

  // 簇 1
  { 0x400, 0, 0, 0, 0xFFFFFFFF },
  { 0x500, 0, 0, 0, 0xFFFFFFFF },
  { 0x600, 0, 0, 0, 0xFFFFFFFF },

  // 簇 2
  { 0x700, 0, 0, 0, 0xFFFFFFFF }
};

VOID
GetPlatformCoreTable (
  OUT ARM_CORE_INFO **ArmCoreTable,
  OUT UINTN          *CoreCount)
{
  // 传递数据
  *ArmCoreTable = mArmPlatformMpCoreInfoTable;
  *CoreCount    = ARRAY_SIZE (mArmPlatformMpCoreInfoTable);
}

VOID
PlatformInitialize ()
{
  // 设置 MDP SID
  CONST UINT16 MdpStreams[] = { 0x1C00, 0x1C01, 0x1C03, 0x1C04, 0x2801, 0x2C01 };

  // 分离 IOMMU 域
  ArmSmmuDetach (MdpStreams, ARRAY_SIZE (MdpStreams));
}
