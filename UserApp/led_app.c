#include "common.h"

void led_thread_entry(void *parameter);

int led_init(void)
{
     rt_thread_t  led_thread = rt_thread_create("led",
                                             led_thread_entry,
                                             RT_NULL,
                                              512,
                                               10,
                                                10
                                            ); //创建线程
	rt_thread_startup(led_thread);
    return 0;
}
INIT_APP_EXPORT(led_init);
void led_thread_entry(void *parameter){

    while(1){
        HAL_GPIO_TogglePin(LED_ERR_GPIO_Port,LED_ERR_Pin);
//		rt_kprintf("hello rtthread\n");
        rt_thread_delay(1000);
    }
}
