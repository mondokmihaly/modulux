/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for STMicroelectronics STM32F4-Discovery board.
 */

/*
 * Board identifier.
 */
#define BOARD_MODULUX
#define BOARD_NAME                  "modulux"

/*
 * Board oscillators-related settings.
 * NOTE: LSE not fitted.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                0U
#endif

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                8000000U
#endif

/*
 * Board voltages.
 * Required for performance limits calculation.
 */
#define STM32_VDD                   300U

/*
 * MCU type as defined in the ST header.
 */
#define STM32F407xx

/*
 * IO pins assignments.
 */
#define GPIOA_BUT1                  0U
#define GPIOA_BUT2                  1U
#define GPIOA_BUT3                  2U
#define GPIOA_BUT4                  3U
#define GPIOA_UBAT_DIV              4U
#define GPIOA_PO5                   6U
#define GPIOA_PO6                   7U
#define GPIOA_USB_VBUS              9U
#define GPIOA_USB_ID                10U
#define GPIOA_USB_DM                11U
#define GPIOA_USB_DP                12U
#define GPIOA_J_TMS                 13U
#define GPIOA_J_TCK                 14U
#define GPIOA_J_TDI                 15U

#define GPIOB_3V3_LOAD              0U
#define GPIOB_X_5V_LOAD             1U
#define GPIOB_J_TDO                 3U
#define GPIOB_J_RST                 4U
#define GPIOB_TXD1                  6U
#define GPIOB_RXD1                  7U
#define GPIOB_I2C1_C                8U
#define GPIOB_I2C1_D                9U

#define GPIOC_AIN1                  0U
#define GPIOC_AIN2                  1U
#define GPIOC_AIN3                  2U
#define GPIOC_AIN4                  3U
#define GPIOC_TXD6                  6U
#define GPIOC_RXD6                  7U
#define GPIOC_SD_D0                 8U
#define GPIOC_SD_D1                 9U
#define GPIOC_SD_D2                 10U
#define GPIOC_SD_D3                 11U
#define GPIOC_SD_CLK                12U

#define GPIOD_CAN_RX                0U
#define GPIOD_CAN_TX                1U
#define GPIOD_SD_CMD                2U
#define GPIOD_POX_ST                3U
#define GPIOD_X_5V_EN               4U
#define GPIOD_CARD_IN               5U
#define GPIOD_LS_1                  12U
#define GPIOD_LS_2                  13U
#define GPIOD_LS_3                  14U
#define GPIOD_LS_4                  15U

#define GPIOE_ONEWIRE1              0U
#define GPIOE_ONEWIRE2              1U
#define GPIOE_LD1                   2U
#define GPIOE_LD2                   3U
#define GPIOE_PO1                   9U
#define GPIOE_PO2                   11U
#define GPIOE_PO3                   13U
#define GPIOE_PO4                   14U

#define GPIOH_OSC_IN                0U
#define GPIOH_OSC_OUT               1U

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2U))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2U))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2U))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2U))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_2M(n)            (0U << ((n) * 2U))
#define PIN_OSPEED_25M(n)           (1U << ((n) * 2U))
#define PIN_OSPEED_50M(n)           (2U << ((n) * 2U))
#define PIN_OSPEED_100M(n)          (3U << ((n) * 2U))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2U))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2U))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2U))
#define PIN_AFIO_AF(n, v)           ((v) << (((n) % 8U) * 4U))

/*
 * Port A setup.
 * All input with pull-up except:
 * PA11 - USB DM     (alternate 10).
 * PA12 - USB DP     (alternate 10).
 */
#define VAL_GPIOA_MODER             (PIN_MODE_ALTERNATE(GPIOA_USB_DM) | \
                                     PIN_MODE_ALTERNATE(GPIOA_USB_DP) | \
                                     PIN_MODE_ALTERNATE(GPIOA_USB_ID) | \
                                     PIN_MODE_INPUT(GPIOA_USB_VBUS)   | \
                                     PIN_MODE_ANALOG(GPIOA_UBAT_DIV)  | \
                                     PIN_MODE_ANALOG(GPIOA_BUT1)      | \
                                     PIN_MODE_ANALOG(GPIOA_BUT2)      | \
                                     PIN_MODE_ANALOG(GPIOA_BUT3)      | \
                                     PIN_MODE_ANALOG(GPIOA_BUT4))
#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOA_USB_ID) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_DM) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_DP) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_VBUS))
#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_100M(GPIOA_USB_VBUS)|   \
                                     PIN_OSPEED_100M(GPIOA_USB_ID) |     \
                                     PIN_OSPEED_100M(GPIOA_USB_DM) |     \
                                     PIN_OSPEED_100M(GPIOA_USB_DP))
#define VAL_GPIOA_PUPDR             (PIN_PUPDR_PULLDOWN(GPIOA_USB_VBUS) |\
                                     PIN_PUPDR_FLOATING(GPIOA_USB_ID)   | \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_DM)   |  \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_DP))
#define VAL_GPIOA_ODR               (PIN_ODR_HIGH(GPIOA_USB_VBUS) |      \
                                     PIN_ODR_HIGH(GPIOA_USB_ID) |        \
                                     PIN_ODR_HIGH(GPIOA_USB_DM) |        \
                                     PIN_ODR_HIGH(GPIOA_USB_DP))
#define VAL_GPIOA_AFRL              0x00000000
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(GPIOA_USB_DM, 10)    | \
                                     PIN_AFIO_AF(GPIOA_USB_DP, 10)    | \
                                     PIN_AFIO_AF(GPIOA_USB_VBUS, 0) |    \
                                     PIN_AFIO_AF(GPIOA_USB_ID, 10))

/*
 * Port B setup.
 * All input with pull-up except:
 * PB6 - Serial1 TX     (alternate 7)
 * PB7 - Serial1 RX     (alternate 7)
 */
#define VAL_GPIOB_MODER             (PIN_MODE_ALTERNATE(GPIOB_TXD1)       | \
                                     PIN_MODE_ALTERNATE(GPIOB_RXD1))
#define VAL_GPIOB_OTYPER            0x00000000
#define VAL_GPIOB_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOB_PUPDR             0xFFFFFFFF
#define VAL_GPIOB_ODR               0xFFFFFFFF
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(GPIOB_TXD1, 7)           | \
                                     PIN_AFIO_AF(GPIOB_RXD1, 7))
#define VAL_GPIOB_AFRH              0x00000000

/*
 * Port C setup.
 * All input with pull-up except:
 * PC6 - Serial6 TX     (alternate 8)
 * PC7 - Serial6 RX     (alternate 8)
 *
 */
#define VAL_GPIOC_MODER             (PIN_MODE_ANALOG(GPIOC_AIN1)          | \
                                     PIN_MODE_ANALOG(GPIOC_AIN2)          | \
                                     PIN_MODE_ANALOG(GPIOC_AIN3)          | \
                                     PIN_MODE_ANALOG(GPIOC_AIN4)          | \
                                     PIN_MODE_ALTERNATE(GPIOC_TXD6)       | \
                                     PIN_MODE_ALTERNATE(GPIOC_RXD6))
#define VAL_GPIOC_OTYPER            0x00000000
#define VAL_GPIOC_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOC_PUPDR             0xFFFFFFFF
#define VAL_GPIOC_ODR               0xFFFFFFFF
#define VAL_GPIOC_AFRL              (PIN_AFIO_AF(GPIOB_TXD1, 8)           | \
                                     PIN_AFIO_AF(GPIOB_RXD1, 8))
#define VAL_GPIOC_AFRH              0x00000000

/*
 * Port D setup.
 * All input with pull-up except:
 * PD6 - CAN RX     (alternate 9)
 * PD7 - CAN TX     (alternate 9)
 * PD7 - X_5V_EN    (output)
 */
#define VAL_GPIOD_MODER             (PIN_MODE_ALTERNATE(GPIOD_CAN_RX)     | \
                                     PIN_MODE_ALTERNATE(GPIOD_CAN_TX)      | \
                                     PIN_MODE_OUTPUT(GPIOD_X_5V_EN)       | \
                                     PIN_MODE_ALTERNATE(GPIOD_LS_1))
#define VAL_GPIOD_OTYPER            0x00000000
#define VAL_GPIOD_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOD_PUPDR             0xFFFFFFFF
#define VAL_GPIOD_ODR               0xFFFFFFFF
#define VAL_GPIOD_AFRL              (PIN_AFIO_AF(GPIOD_CAN_RX, 9)          | \
                                     PIN_AFIO_AF(GPIOD_CAN_TX, 9))
#define VAL_GPIOD_AFRH              PIN_AFIO_AF(GPIOD_LS_1, 2)

/*
 * Port E setup.
 * All input with pull-up except:
 * PE2  - LD1     (output)
 * PE3  - LD2     (output)
 * PE9  - PO1     (alternate 1)
 * PE11 - PO2     (alternate 1)
 * PE13 - PO3     (alternate 1)
 */
#define VAL_GPIOE_MODER             (PIN_MODE_OUTPUT(GPIOE_LD1)             | \
                                     PIN_MODE_OUTPUT(GPIOE_LD2)             | \
                                     PIN_MODE_OUTPUT(GPIOE_PO1)          | \
                                     PIN_MODE_ALTERNATE(GPIOE_PO2)          | \
                                     PIN_MODE_ALTERNATE(GPIOE_PO3))
#define VAL_GPIOE_OTYPER            0x00000000
#define VAL_GPIOE_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOE_PUPDR             0xFFFFFFFF
#define VAL_GPIOE_ODR               0xFFFFFFFF
#define VAL_GPIOE_AFRL              0x00000000
#define VAL_GPIOE_AFRH             (PIN_AFIO_AF(GPIOE_PO1, 1)              | \
                                    PIN_AFIO_AF(GPIOE_PO2, 1)              | \
                                    PIN_AFIO_AF(GPIOE_PO3, 1))

/*
 * Port F setup.
 * All input with pull-up except:
 */
#define VAL_GPIOF_MODER             0x00000000
#define VAL_GPIOF_OTYPER            0x00000000
#define VAL_GPIOF_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOF_PUPDR             0xFFFFFFFF
#define VAL_GPIOF_ODR               0xFFFFFFFF
#define VAL_GPIOF_AFRL              0x00000000
#define VAL_GPIOF_AFRH              0x00000000

/*
 * Port G setup.
 * All input with pull-up except:
 */
#define VAL_GPIOG_MODER             0x00000000
#define VAL_GPIOG_OTYPER            0x00000000
#define VAL_GPIOG_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOG_PUPDR             0xFFFFFFFF
#define VAL_GPIOG_ODR               0xFFFFFFFF
#define VAL_GPIOG_AFRL              0x00000000
#define VAL_GPIOG_AFRH              0x00000000

/*
 * Port H setup.
 * All input with pull-up except:
 * PH0 - OSC_IN         (input floating).
 * PH1 - OSC_OUT        (input floating).
 */
#define VAL_GPIOH_MODER             0x00000000
#define VAL_GPIOH_OTYPER            0x00000000
#define VAL_GPIOH_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOH_PUPDR             (PIN_PUPDR_FLOATING(GPIOH_OSC_IN) |     \
                                     PIN_PUPDR_FLOATING(GPIOH_OSC_OUT))
#define VAL_GPIOH_ODR               0xFFFFFFFF
#define VAL_GPIOH_AFRL              0x00000000
#define VAL_GPIOH_AFRH              0x00000000

/*
 * Port I setup.
 * All input with pull-up except:
 */
#define VAL_GPIOI_MODER             0x00000000
#define VAL_GPIOI_OTYPER            0x00000000
#define VAL_GPIOI_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOI_PUPDR             0xFFFFFFFF
#define VAL_GPIOI_ODR               0xFFFFFFFF
#define VAL_GPIOI_AFRL              0x00000000
#define VAL_GPIOI_AFRH              0x00000000

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
