/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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

#include "ch.h"
#include "hal.h"
#include "uavcan/node.h"

/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  /*
  * Start UAVCAN node
  */
  unsigned int node_id = 100;
  const char *node_name = "Simple UAVCAN-Node";
  uavcan_start(node_id, node_name);

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  while (true) {
    palClearPad(GPIOA, GPIOA_LED_GREEN);
    chThdSleepMilliseconds(500);
    palSetPad(GPIOA, GPIOA_LED_GREEN);
    chThdSleepMilliseconds(500);
  }
}
