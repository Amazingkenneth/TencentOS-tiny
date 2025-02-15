/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v10.0
processor: MIMXRT1062xxxxA
package_id: MIMXRT1062DVL6A
mcu_data: ksdk2_0
processor_version: 10.0.0
board: MIMXRT1060-EVK
pin_labels:
- {pin_num: G11, pin_signal: GPIO_AD_B0_03, label: 'USB_OTG1_OC/J24[1]', identifier: LPSPI3_CS}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: L14, peripheral: LPUART1, signal: RX, pin_signal: GPIO_AD_B0_13}
  - {pin_num: K14, peripheral: LPUART1, signal: TX, pin_signal: GPIO_AD_B0_12}
  - {pin_num: M14, peripheral: LPSPI3, signal: SCK, pin_signal: GPIO_AD_B0_00}
  - {pin_num: M11, peripheral: LPSPI3, signal: SDI, pin_signal: GPIO_AD_B0_02}
  - {pin_num: H10, peripheral: LPSPI3, signal: SDO, pin_signal: GPIO_AD_B0_01}
  - {pin_num: G11, peripheral: GPIO1, signal: 'gpio_io, 03', pin_signal: GPIO_AD_B0_03, direction: OUTPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           

  /* GPIO configuration of LPSPI3_CS on GPIO_AD_B0_03 (pin G11) */
  gpio_pin_config_t LPSPI3_CS_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_AD_B0_03 (pin G11) */
  GPIO_PinInit(GPIO1, 3U, &LPSPI3_CS_config);

  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_00_LPSPI3_SCK, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_01_LPSPI3_SDO, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_02_LPSPI3_SDI, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_03_GPIO1_IO03, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_12_LPUART1_TX, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_13_LPUART1_RX, 0U); 
  IOMUXC_GPR->GPR26 = ((IOMUXC_GPR->GPR26 &
    (~(BOARD_INITPINS_IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL_MASK))) 
      | IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL(0x00U) 
    );
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
