/**
 * @file      Buzzer_Interface.h
 * @author    Youssef
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface of the Buzzer Driver.
 * @details   This file contains the function prototypes and public APIs used by 
 *            upper layers to control the Buzzer module.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef BUZZER_INTERFACE_H
#define BUZZER_INTERFACE_H

#include "BUZZER_config.h"
#include "BUZZER_private.h"

void BUZZER_init();
void BUZZER_On(void);
void BUZZER_Off(void);
void BUZZER_Toggle(void);

#endif /* BUZZER_INTERFACE_H */
