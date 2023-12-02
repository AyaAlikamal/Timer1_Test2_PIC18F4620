/* 
 * File:   application.c
 * Author: AyaAli
 * Created on September 22, 2023, 10:24 AM
 */
#include "application.h"

volatile uint_16 Freq = ZERO_INIT;
timer1_config_t timer1_obj;
timer1_config_t counter1_obj;
void Timer1_Defualt_Interrupt_Hundeller(void);
void Timer0_Defualt_Interrupt_Hundeller(void);


timer0_config_t timer0_timer_obj ={
  .TMR0_Interrupt_Hundeler = Timer0_Defualt_Interrupt_Hundeller,
  .timer0_mode = TIMER0_TIMER_MODE_CFG,
  .timer0_register_size = TIMER0_16BIT_MODE_CFG,
  .timer0_prescaler_enable = TIMER0_PRESCALLER_ENABLE_COUNTER_CFG,
  .prescaler_value = TIMER0_PRESACLER_VALUE_16,
  .timer0_preload_value = 3036
};


timer1_config_t counter1_obj ={
.TMR1_Interrupt_Hundeler = Timer1_Defualt_Interrupt_Hundeller,
.Timer_priority = Interrupt_Periority_LOW,
.timer1_mode = TIMER1_COUNTER_MODE_CFG,
.timer1_prescaller = TIMER1_PRESACLER_VALUE_1,
.timer1_preload_value = 0,
.timer1_register_size = TIMER1_REG_16BIT_MODE_CFG,
.timer1_counter_mode = TIMER1_SYNC_Counter_CFG,
};


int main() {
   
Std_ReturnType ret = E_NOT_OK;
//application_initialize();
ret = Timer1_Init(&counter1_obj);
ret = Timer0_Init(&timer0_timer_obj);

while(1){

}
 return (EXIT_SUCCESS);
}
void application_initialize(void){
   Std_ReturnType ret = E_NOT_OK;

}
void Timer1_Defualt_Interrupt_Hundeller(){
     Std_ReturnType ret = E_NOT_OK;
    ret = Timer1_Read_Value(&counter1_obj, &Freq);
    ret = Timer1_Write_Value(&counter1_obj, 0);
    
}

void Timer0_Defualt_Interrupt_Hundeller(void){

}