/** 
******************************************************************************
* \file    command_list.h
* \brief   command list for CLI.
******************************************************************************
*/
#ifndef COMMAND_LIST
#define COMMAND_LIST

enum{
/*turn on leds commands */
 cmd_turn                 =   0x7b,
 cmd_sub_off              =   0x78,
 cmd_sub_on               =   0xA4,
 cmd_sub_red              =   0x73,
 cmd_sub_blue             =   0x43,
 cmd_sub_green            =   0x55,

/*gpio commands : "gpio lo pinnumber", "gpio lo 8"*/
 cmd_gpio                 =   0x4d ,
 cmd_gpio_lo              =   0xA3,
 cmd_gpio_hi              =   0x93,
 cmd_sample               =   0xd4,
 cmd_send                 =   0x26,
 cmd_cip                  =   0x285,
 cmd_dcip                 =   0x34,
/*random key generation */
 cmd_sub_random_key       =   0x89,
 cmd_ble                  =   0x269,
 cmd_rgb                  =   0x266,
 cmd_help                 =   0x45 ,
 cmd_clear                =   0x237,
/*TWI DEBUG*/
 cmd_write_twi            =   0x88,
 cmd_read_twi             =   0x74,
 cmd_twi_read_saved_buffer=   0x64,
 cmd_twiapp               =   0x10f,
 cmd_accinit              =   0x3da,
 cmd_cmdtest              =   0x3d,
 /*hex convertion*/
 cmd_hex2dec              =   0x287,
 /*adc*/
 cmd_adc                  =   0x252,
 cmd_fet                  =   0x28c,
 cmd_pwm		  =   0x2a5,
 cmd_duty                 =   0x9d,
 cmd_spi_send             =  0x28e,
 cmd_spip                 =  0x5d,
 cmd_servo                = 0x150,	
};
#endif
