#include <stdio.h>
#include "my_config.h"
int main()
{

#define CONFIG_FIRMWARE_VERSION "H02-1.0.3"

    printf("BSL\n");
#ifdef CONFIG_MY_DEBUG
    printf("启用调试功能\n");
#endif
#ifdef CONFIG_COLOR_LOG_MODE
    printf("开启日志颜色\n");
#endif

#ifdef CONFIG_ENABLE_SLEEP
    printf("启用休眠功能\n");
#endif

#ifdef CONFIG_ENABLE_VERIFY
    printf("启用身份验证\n");
#endif

#ifdef CONFIG_ENABLE_USB_CDC
    printf("启用 USB CDC 功能\n");
#endif

#ifdef CONFIG_ENABLE_USB_CDC_DBG
    printf("启用 USB 日志\n");
#endif

#ifdef CONFIG_ENABLE_PROACTIVE_NOTIFY
    printf("启用蓝牙消息主动上报功能\n");
#endif

	printf("固件版本号: %s\n", CONFIG_FIRMWARE_VERSION);
	// printf("CONFIG_TEST_SHOW_INT: %d\n", CONFIG_TEST_SHOW_INT);
// #ifdef CONFIG_TEST_TOP_ENABLE
//     printf("CONFIG_TEST_TOP_ENABLE\n");
// #endif
// #ifdef CONFIG_TEST_SUB_0_ENABLE
//     printf("CONFIG_TEST_SUB_0_ENABLE\n");
// #endif
// #ifdef CONFIG_TEST_SUB_1_ENABLE
//     printf("CONFIG_TEST_SUB_1_ENABLE\n");
// #endif
// 	printf("CONFIG_TEST_SHOW_SUB_INT: %d\n", CONFIG_TEST_SHOW_SUB_INT);
    return 0;
}
