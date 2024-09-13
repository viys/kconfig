#include <stdio.h>
#include "my_config.h"
int main()
{
    printf("BSL\n");
    printf("固件版本号: %s\n", CONFIG_FIRMWARE_VERSION);

#ifdef CONFIG_ENABLE_SLEEP
    printf("启用休眠功能\n");
#endif

#ifdef CONFIG_ENABLE_VERIFY
    printf("启用身份验证\n");
#endif

#ifdef CONFIG_DEBUG
    printf("启用调试功能\n");
#endif
#ifdef CONFIG_DEBUG_COLOR_MODE
    printf("    开启日志颜色\n");
#endif
#ifdef CONFIG_DEBUG_LEVEL
    printf("    日志等级 LEVEL:%d\n", CONFIG_DEBUG_LEVEL);
#endif


#ifdef CONFIG_ENABLE_USB_CDC
    printf("启用 USB CDC 功能\n");
#endif
#ifdef CONFIG_ENABLE_USB_CDC_DBG
    printf("    启用 USB 日志\n");
#endif

#ifdef CONFIG_ENABLE_PROACTIVE_NOTIFY
    printf("启用蓝牙消息主动上报功能\n");
#endif
	
    return 0;
}
