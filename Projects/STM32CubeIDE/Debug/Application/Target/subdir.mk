################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/sarahalyaa/Documents/TSM/STM32_Testing/STM32_Antares/STM32CubeExpansion_LRWAN_V2.0.0/Projects/B-L072Z-LRWAN1/Applications/LoRaWAN/LoRaWAN_End_Node/LoRaWAN/Target/b_l072z_lrwan1_bus.c 

OBJS += \
./Application/Target/b_l072z_lrwan1_bus.o 

C_DEPS += \
./Application/Target/b_l072z_lrwan1_bus.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Target/b_l072z_lrwan1_bus.o: /Users/sarahalyaa/Documents/TSM/STM32_Testing/STM32_Antares/STM32CubeExpansion_LRWAN_V2.0.0/Projects/B-L072Z-LRWAN1/Applications/LoRaWAN/LoRaWAN_End_Node/LoRaWAN/Target/b_l072z_lrwan1_bus.c Application/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DUSE_B_L072Z_LRWAN1 -DCMWX1ZZABZ0XX -c -I../../../LoRaWAN/App -I../../../LoRaWAN/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/packages -I../../../../../../../../Drivers/BSP/IKS01A2 -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/hts221 -I../../../../../../../../Drivers/BSP/Components/lps22hb -I../../../../../../../../Drivers/BSP/Components/lsm6dsl -I../../../../../../../../Drivers/BSP/Components/lsm303agr -I"/Users/sarahalyaa/Documents/TSM/STM32_Testing/STM32_Antares/STM32CubeExpansion_LRWAN_V2.0.0/Projects/B-L072Z-LRWAN1/Applications/LoRaWAN/LoRaWAN_End_Node/STM32CubeIDE/cmwx1zzabz_0xx/Application/Core" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Application/Target/b_l072z_lrwan1_bus.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

