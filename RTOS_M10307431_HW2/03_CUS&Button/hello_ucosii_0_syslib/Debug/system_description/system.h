/* system.h
 *
 * Machine generated for a CPU named "cpu" as defined in:
 * c:\Altera\80\kits\cycloneIII_3c120_dev\examples\cycloneIII_3c120_dev_niosII_standard\software\hello_ucosii_0_syslib\..\..\cycloneIII_3c120_dev_niosII_standard_sopc.ptf
 *
 * Generated: 2015-11-02 22:31:48.845
 *
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_
#define SCALE   100
/*

DO NOT MODIFY THIS FILE

   Changing this file will have subtle consequences
   which will almost certainly lead to a nonfunctioning
   system. If you do modify this file, be aware that your
   changes will be overwritten and lost when this file
   is generated again.

DO NOT MODIFY THIS FILE

*/

/******************************************************************************
*                                                                             *
* License Agreement                                                           *
*                                                                             *
* Copyright (c) 2003 Altera Corporation, San Jose, California, USA.           *
* All rights reserved.                                                        *
*                                                                             *
* Permission is hereby granted, free of charge, to any person obtaining a     *
* copy of this software and associated documentation files (the "Software"),  *
* to deal in the Software without restriction, including without limitation   *
* the rights to use, copy, modify, merge, publish, distribute, sublicense,    *
* and/or sell copies of the Software, and to permit persons to whom the       *
* Software is furnished to do so, subject to the following conditions:        *
*                                                                             *
* The above copyright notice and this permission notice shall be included in  *
* all copies or substantial portions of the Software.                         *
*                                                                             *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,    *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER      *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING     *
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER         *
* DEALINGS IN THE SOFTWARE.                                                   *
*                                                                             *
* This agreement shall be governed in all respects by the laws of the State   *
* of California and by the laws of the United States of America.              *
*                                                                             *
******************************************************************************/

/*
 * system configuration
 *
 */

#define ALT_SYSTEM_NAME "cycloneIII_3c120_dev_niosII_standard_sopc"
#define ALT_CPU_NAME "cpu"
#define ALT_CPU_ARCHITECTURE "altera_nios2"
#define ALT_DEVICE_FAMILY "CYCLONEIII"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN_BASE 0x0c021098
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_PRESENT
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT_BASE 0x0c021098
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_PRESENT
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDERR_BASE 0x0c021098
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_PRESENT
#define ALT_CPU_FREQ 85000000
#define ALT_IRQ_BASE NULL
#define ALT_LEGACY_INTERRUPT_API_PRESENT

/*
 * processor configuration
 *
 */

#define NIOS2_CPU_IMPLEMENTATION "small"
#define NIOS2_BIG_ENDIAN 0
#define NIOS2_INTERRUPT_CONTROLLER_ID 0

#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_FLUSHDA_SUPPORTED

#define NIOS2_EXCEPTION_ADDR 0x0c010020
#define NIOS2_RESET_ADDR 0x0c010000
#define NIOS2_BREAK_ADDR 0x0c020820

#define NIOS2_HAS_DEBUG_STUB

#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0

/*
 * A define for each class of peripheral
 *
 */

#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_CFI_FLASH
#define __ALTERA_AVALON_TRI_STATE_BRIDGE
#define __ALTERA_AVALON_LCD_16207
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_TIMER
#define __ALTERA_AVALON_SYSID
#define __ALTERA_AVALON_PLL
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_CLOCK_CROSSING
#define __DDR2_HIGH_PERF

/*
 * onchip_ram configuration
 *
 */

#define ONCHIP_RAM_NAME "/dev/onchip_ram"
#define ONCHIP_RAM_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_RAM_BASE 0x0c010000
#define ONCHIP_RAM_SPAN 65536
#define ONCHIP_RAM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_RAM_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_RAM_INIT_CONTENTS_FILE "onchip_ram"
#define ONCHIP_RAM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_RAM_GUI_RAM_BLOCK_TYPE "Automatic"
#define ONCHIP_RAM_WRITEABLE 1
#define ONCHIP_RAM_DUAL_PORT 0
#define ONCHIP_RAM_SIZE_VALUE 65536
#define ONCHIP_RAM_SIZE_MULTIPLE 1
#define ONCHIP_RAM_USE_SHALLOW_MEM_BLOCKS 0
#define ONCHIP_RAM_INIT_MEM_CONTENT 1
#define ONCHIP_RAM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_RAM_INSTANCE_ID "NONE"
#define ONCHIP_RAM_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_RAM_IGNORE_AUTO_BLOCK_TYPE_ASSIGNMENT 1
#define ONCHIP_RAM_CONTENTS_INFO ""
#define ALT_MODULE_CLASS_onchip_ram altera_avalon_onchip_memory2

/*
 * ext_flash configuration
 *
 */

#define EXT_FLASH_NAME "/dev/ext_flash"
#define EXT_FLASH_TYPE "altera_avalon_cfi_flash"
#define EXT_FLASH_BASE 0x00000000
#define EXT_FLASH_SPAN 67108864
#define EXT_FLASH_SETUP_VALUE 80
#define EXT_FLASH_WAIT_VALUE 40
#define EXT_FLASH_HOLD_VALUE 20
#define EXT_FLASH_TIMING_UNITS "ns"
#define EXT_FLASH_UNIT_MULTIPLIER 1
#define EXT_FLASH_SIZE 67108864
#define ALT_MODULE_CLASS_ext_flash altera_avalon_cfi_flash

/*
 * flash_tristate_bridge configuration
 *
 */

#define FLASH_TRISTATE_BRIDGE_NAME "/dev/flash_tristate_bridge"
#define FLASH_TRISTATE_BRIDGE_TYPE "altera_avalon_tri_state_bridge"
#define ALT_MODULE_CLASS_flash_tristate_bridge altera_avalon_tri_state_bridge

/*
 * lcd configuration
 *
 */

#define LCD_NAME "/dev/lcd"
#define LCD_TYPE "altera_avalon_lcd_16207"
#define LCD_BASE 0x0c021060
#define LCD_SPAN 16
#define ALT_MODULE_CLASS_lcd altera_avalon_lcd_16207

/*
 * led_pio configuration
 *
 */

#define LED_PIO_NAME "/dev/led_pio"
#define LED_PIO_TYPE "altera_avalon_pio"
#define LED_PIO_BASE 0x0c021070
#define LED_PIO_SPAN 16
#define LED_PIO_DO_TEST_BENCH_WIRING 0
#define LED_PIO_DRIVEN_SIM_VALUE 0
#define LED_PIO_HAS_TRI 0
#define LED_PIO_HAS_OUT 1
#define LED_PIO_HAS_IN 0
#define LED_PIO_CAPTURE 0
#define LED_PIO_DATA_WIDTH 8
#define LED_PIO_RESET_VALUE 0
#define LED_PIO_EDGE_TYPE "NONE"
#define LED_PIO_IRQ_TYPE "NONE"
#define LED_PIO_BIT_CLEARING_EDGE_REGISTER 0
#define LED_PIO_FREQ 85000000
#define ALT_MODULE_CLASS_led_pio altera_avalon_pio

/*
 * button_pio configuration
 *
 */

#define BUTTON_PIO_NAME "/dev/button_pio"
#define BUTTON_PIO_TYPE "altera_avalon_pio"
#define BUTTON_PIO_BASE 0x0c021080
#define BUTTON_PIO_SPAN 16
#define BUTTON_PIO_IRQ 0
#define BUTTON_PIO_IRQ_INTERRUPT_CONTROLLER_ID 0
#define BUTTON_PIO_DO_TEST_BENCH_WIRING 1
#define BUTTON_PIO_DRIVEN_SIM_VALUE 15
#define BUTTON_PIO_HAS_TRI 0
#define BUTTON_PIO_HAS_OUT 0
#define BUTTON_PIO_HAS_IN 1
#define BUTTON_PIO_CAPTURE 1
#define BUTTON_PIO_DATA_WIDTH 4
#define BUTTON_PIO_RESET_VALUE 0
#define BUTTON_PIO_EDGE_TYPE "ANY"
#define BUTTON_PIO_IRQ_TYPE "EDGE"
#define BUTTON_PIO_BIT_CLEARING_EDGE_REGISTER 0
#define BUTTON_PIO_FREQ 85000000
#define ALT_MODULE_CLASS_button_pio altera_avalon_pio

/*
 * sys_clk_timer configuration
 *
 */

#define SYS_CLK_TIMER_NAME "/dev/sys_clk_timer"
#define SYS_CLK_TIMER_TYPE "altera_avalon_timer"
#define SYS_CLK_TIMER_BASE 0x0c021000
#define SYS_CLK_TIMER_SPAN 32
#define SYS_CLK_TIMER_IRQ 1
#define SYS_CLK_TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SYS_CLK_TIMER_ALWAYS_RUN 0
#define SYS_CLK_TIMER_FIXED_PERIOD 0
#define SYS_CLK_TIMER_SNAPSHOT 1
#define SYS_CLK_TIMER_PERIOD 10.0
#define SYS_CLK_TIMER_PERIOD_UNITS "ms"
#define SYS_CLK_TIMER_RESET_OUTPUT 0
#define SYS_CLK_TIMER_TIMEOUT_PULSE_OUTPUT 0
#define SYS_CLK_TIMER_LOAD_VALUE 849999
#define SYS_CLK_TIMER_COUNTER_SIZE 32
#define SYS_CLK_TIMER_MULT 0.0010
#define SYS_CLK_TIMER_TICKS_PER_SEC 100
#define SYS_CLK_TIMER_FREQ 85000000
#define ALT_MODULE_CLASS_sys_clk_timer altera_avalon_timer

/*
 * high_res_timer configuration
 *
 */

#define HIGH_RES_TIMER_NAME "/dev/high_res_timer"
#define HIGH_RES_TIMER_TYPE "altera_avalon_timer"
#define HIGH_RES_TIMER_BASE 0x0c021020
#define HIGH_RES_TIMER_SPAN 32
#define HIGH_RES_TIMER_IRQ 2
#define HIGH_RES_TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define HIGH_RES_TIMER_ALWAYS_RUN 0
#define HIGH_RES_TIMER_FIXED_PERIOD 0
#define HIGH_RES_TIMER_SNAPSHOT 1
#define HIGH_RES_TIMER_PERIOD 10.0
#define HIGH_RES_TIMER_PERIOD_UNITS "us"
#define HIGH_RES_TIMER_RESET_OUTPUT 0
#define HIGH_RES_TIMER_TIMEOUT_PULSE_OUTPUT 0
#define HIGH_RES_TIMER_LOAD_VALUE 849
#define HIGH_RES_TIMER_COUNTER_SIZE 32
#define HIGH_RES_TIMER_MULT "1.0E-6"
#define HIGH_RES_TIMER_TICKS_PER_SEC 100000
#define HIGH_RES_TIMER_FREQ 85000000
#define ALT_MODULE_CLASS_high_res_timer altera_avalon_timer

/*
 * sysid configuration
 *
 */

#define SYSID_NAME "/dev/sysid"
#define SYSID_TYPE "altera_avalon_sysid"
#define SYSID_BASE 0x0c021090
#define SYSID_SPAN 8
#define SYSID_ID 712662328u
#define SYSID_TIMESTAMP 1219701055u
#define SYSID_REGENERATE_VALUES 0
#define ALT_MODULE_CLASS_sysid altera_avalon_sysid

/*
 * sys_pll configuration
 *
 */

#define SYS_PLL_NAME "/dev/sys_pll"
#define SYS_PLL_TYPE "altera_avalon_pll"
#define SYS_PLL_BASE 0x0c021040
#define SYS_PLL_SPAN 32
#define SYS_PLL_ARESET "None"
#define SYS_PLL_PFDENA "None"
#define SYS_PLL_LOCKED "None"
#define SYS_PLL_PLLENA "None"
#define SYS_PLL_SCANCLK "None"
#define SYS_PLL_SCANDATA "None"
#define SYS_PLL_SCANREAD "None"
#define SYS_PLL_SCANWRITE "None"
#define SYS_PLL_SCANCLKENA "None"
#define SYS_PLL_SCANACLR "None"
#define SYS_PLL_SCANDATAOUT "None"
#define SYS_PLL_SCANDONE "None"
#define SYS_PLL_CONFIGUPDATE "None"
#define SYS_PLL_PHASECOUNTERSELECT "None"
#define SYS_PLL_PHASEDONE "None"
#define SYS_PLL_PHASEUPDOWN "None"
#define SYS_PLL_PHASESTEP "None"
#define SYS_PLL_CONFIG_DONE 0
#define ALT_MODULE_CLASS_sys_pll altera_avalon_pll

/*
 * jtag_uart configuration
 *
 */

#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_BASE 0x0c021098
#define JTAG_UART_SPAN 8
#define JTAG_UART_IRQ 3
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_READ_CHAR_STREAM ""
#define JTAG_UART_SHOWASCII 1
#define JTAG_UART_READ_LE 0
#define JTAG_UART_WRITE_LE 0
#define JTAG_UART_ALTERA_SHOW_UNRELEASED_JTAG_UART_FEATURES 0
#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart

/*
 * altmemddr_bridge configuration
 *
 */

#define ALTMEMDDR_BRIDGE_NAME "/dev/altmemddr_bridge"
#define ALTMEMDDR_BRIDGE_TYPE "altera_avalon_clock_crossing"
#define ALTMEMDDR_BRIDGE_BASE 0x08000000
#define ALTMEMDDR_BRIDGE_SPAN 67108864
#define ALTMEMDDR_BRIDGE_UPSTREAM_FIFO_DEPTH 64
#define ALTMEMDDR_BRIDGE_DOWNSTREAM_FIFO_DEPTH 8
#define ALTMEMDDR_BRIDGE_DATA_WIDTH 32
#define ALTMEMDDR_BRIDGE_NATIVE_ADDRESS_WIDTH 24
#define ALTMEMDDR_BRIDGE_USE_BYTE_ENABLE 1
#define ALTMEMDDR_BRIDGE_USE_BURST_COUNT 0
#define ALTMEMDDR_BRIDGE_MAXIMUM_BURST_SIZE 8
#define ALTMEMDDR_BRIDGE_UPSTREAM_USE_REGISTER 0
#define ALTMEMDDR_BRIDGE_DOWNSTREAM_USE_REGISTER 0
#define ALTMEMDDR_BRIDGE_DEVICE_FAMILY "CYCLONEIII"
#define ALT_MODULE_CLASS_altmemddr_bridge altera_avalon_clock_crossing

/*
 * altmemddr configuration
 *
 */

#define ALTMEMDDR_NAME "/dev/altmemddr"
#define ALTMEMDDR_TYPE "ddr2_high_perf"
#define ALTMEMDDR_BASE 0x08000000
#define ALTMEMDDR_SPAN 67108864
#define ALTMEMDDR_DEVICE_FAMILY "Cyclone III"
#define ALTMEMDDR_DATAWIDTH 16
#define ALTMEMDDR_MEMTYPE "DDR2 SDRAM"
#define ALTMEMDDR_LOCAL_BURST_LENGTH 1
#define ALTMEMDDR_NUM_CHIPSELECTS 1
#define ALTMEMDDR_CAS_LATENCY 5.0
#define ALTMEMDDR_ADDR_WIDTH 23
#define ALTMEMDDR_BA_WIDTH 2
#define ALTMEMDDR_ROW_WIDTH 13
#define ALTMEMDDR_COL_WIDTH 10
#define ALTMEMDDR_CLOCKSPEED 7518
#define ALTMEMDDR_DATA_WIDTH_RATIO 4
#define ALTMEMDDR_REG_DIMM "false"
#define ALTMEMDDR_DQ_PER_DQS 8
#define ALT_MODULE_CLASS_altmemddr ddr2_high_perf

/*
 * MicroC/OS-II configuration
 *
 */

#define ALT_MAX_FD 32
#define OS_MAX_TASKS 10
#define OS_LOWEST_PRIO 63
#define OS_FLAG_EN 1
#define OS_THREAD_SAFE_NEWLIB 1
#define OS_MUTEX_EN 1
#define OS_SEM_EN 1
#define OS_MBOX_EN 1
#define OS_Q_EN 1
#define OS_MEM_EN 1
#define OS_FLAG_WAIT_CLR_EN 1
#define OS_FLAG_ACCEPT_EN 1
#define OS_FLAG_DEL_EN 1
#define OS_FLAG_QUERY_EN 1
#define OS_FLAG_NAME_SIZE 32
#define OS_MAX_FLAGS 20
#define OS_FLAGS_NBITS 16
#define OS_MUTEX_ACCEPT_EN 1
#define OS_MUTEX_DEL_EN 1
#define OS_MUTEX_QUERY_EN 1
#define OS_SEM_ACCEPT_EN 1
#define OS_SEM_SET_EN 1
#define OS_SEM_DEL_EN 1
#define OS_SEM_QUERY_EN 1
#define OS_MBOX_ACCEPT_EN 1
#define OS_MBOX_DEL_EN 1
#define OS_MBOX_POST_EN 1
#define OS_MBOX_POST_OPT_EN 1
#define OS_MBOX_QUERY_EN 1
#define OS_Q_ACCEPT_EN 1
#define OS_Q_DEL_EN 1
#define OS_Q_FLUSH_EN 1
#define OS_Q_POST_EN 1
#define OS_Q_POST_FRONT_EN 1
#define OS_Q_POST_OPT_EN 1
#define OS_Q_QUERY_EN 1
#define OS_MAX_QS 20
#define OS_MEM_QUERY_EN 1
#define OS_MEM_NAME_SIZE 32
#define OS_MAX_MEM_PART 60
#define OS_ARG_CHK_EN 1
#define OS_CPU_HOOKS_EN 1
#define OS_DEBUG_EN 1
#define OS_SCHED_LOCK_EN 1
#define OS_TASK_STAT_EN 0
#define OS_TASK_STAT_STK_CHK_EN 1
#define OS_TICK_STEP_EN 1
#define OS_EVENT_NAME_SIZE 32
#define OS_MAX_EVENTS 60
#define OS_TASK_IDLE_STK_SIZE 512
#define OS_TASK_STAT_STK_SIZE 512
#define OS_TASK_CHANGE_PRIO_EN 1
#define OS_TASK_CREATE_EN 1
#define OS_TASK_CREATE_EXT_EN 1
#define OS_TASK_DEL_EN 1
#define OS_TASK_NAME_SIZE 32
#define OS_TASK_PROFILE_EN 1
#define OS_TASK_QUERY_EN 1
#define OS_TASK_SUSPEND_EN 1
#define OS_TASK_SW_HOOK_EN 1
#define OS_TIME_TICK_HOOK_EN 1
#define OS_TIME_GET_SET_EN 1
#define OS_TIME_DLY_RESUME_EN 1
#define OS_TIME_DLY_HMSM_EN 1
#define OS_TMR_EN 0
#define OS_TMR_CFG_MAX 16
#define OS_TMR_CFG_NAME_SIZE 16
#define OS_TMR_CFG_TICKS_PER_SEC 10
#define OS_TMR_CFG_WHEEL_SIZE 2
#define OS_TASK_TMR_STK_SIZE 512
#define OS_TASK_TMR_PRIO 1
#define ALT_SYS_CLK SYS_CLK_TIMER
#define ALT_TIMESTAMP_CLK none
#define OS_TICKS_PER_SEC 100

/*
 * Devices associated with code sections.
 *
 */

#define ALT_TEXT_DEVICE       ALTMEMDDR
#define ALT_RODATA_DEVICE     ALTMEMDDR
#define ALT_RWDATA_DEVICE     ALTMEMDDR
#define ALT_EXCEPTIONS_DEVICE ONCHIP_RAM
#define ALT_RESET_DEVICE      ONCHIP_RAM


#endif /* __SYSTEM_H_ */
