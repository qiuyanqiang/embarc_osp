/* ------------------------------------------
 * Copyright (c) 2017, Synopsys, Inc. All rights reserved.

 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:

 * 1) Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.

 * 2) Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.

 * 3) Neither the name of the Synopsys, Inc., nor the names of its contributors may
 * be used to endorse or promote products derived from this software without
 * specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * \version 2017.12
 * \date 2017-11-30
 * \author Shuai Wang(Shuai.Wang1@synopsys.com)
--------------------------------------------- */
/**
 * \file
 * \ingroup	BOARD_PERIPHER_DRV_PMODI2S
 * \brief	header file of Pmod I2S CS4344 peripheral driver
 */

/**
 * \addtogroup	BOARD_PERIPHER_DRV_PMODI2S
 * @{
 */
#ifndef _PMI2S_H_
#define _PMI2S_H_

#include "dev_i2s.h"
#include "dw_i2s.h"
#include "embARC_error.h"
#include "stdio.h"

#define MCLK_FREQUENCY_KHZ		24576	/*!< The frequency of main clock and the unit is khz>*/
#define I2S_MODE_ISR			1
#define I2S_MODE_POL			0

/**
 * \brief	I2S init data definition
 * \details	define I2S device interface which is used to set some parameters of i2s
 * \note	all this details are implemented by user in user porting code
 */
typedef struct cs_i2s_init
{
	bool pll_isr_sel;			/*!< Select the working mode of i2s .0,polling mode.1,isr mode*/
	uint32_t sample_rate;	/*!< Set the frequency of audio/sample,the unit must be khz */
	uint32_t data_format;	/*!< Set the length of a audio/sample data */
	uint32_t ope_device;	/*!< Set the device as trans mode or receive mode */
	uint32_t mode;			/*!< Set the i2s as master or slave */
	uint32_t num_sclk;		/*!< the number of sclk cycles in half ws cycle which must be larger than data_format.16/24/32 */
}CS_I2S_INIT;

/**
 * \defgroup	SAMPLE_FREQUENCY_E	I2S Audio Sampling Rate
 * \brief		definitions for I2S audio sampling rate
 */
typedef enum sample_frequency_e
{
	I2S_SAMPLE_FREQ_192 = 192,
	I2S_SAMPLE_FREQ_96 = 96,
	I2S_SAMPLE_FREQ_48 = 48,
	I2S_SAMPLE_FREQ_32 = 32,
	I2S_SAMPLE_FREQ_16 = 16
}SAMPLE_FREQUENCY_E;

/**
 * \defgroup	DATA_FORMAT_E	the data format of audio
 * \brief		definitions for data format of audio
 */
typedef enum data_format_e
{
	I2S_DATA_FORMAT_32 = 32,
	I2S_DATA_FORMAT_24 = 24,
	I2S_DATA_FORMAT_20 = 20,
	I2S_DATA_FORMAT_16 = 16
}DATA_FORMAT_E;

#ifdef __cplusplus
extern "C" {
#endif
/* !<Across the data of structue CS_I2S_INIT to init the i2s.*/

extern uint32_t i2s_init_func(DEV_I2S *pdev_i2s,const CS_I2S_INIT *cs_i2s_init,DEV_BUFFER *dev,void (*i2s_isr)(void));
/* ！<Write data through i2s>*/
extern uint32_t i2s_write_data(DEV_I2S *pdev_i2s,const void *data,uint32_t len,uint32_t channel);
extern uint32_t i2s_read_data(DEV_I2S *pdev_i2s,void *data,uint32_t len,uint32_t channel);
/* ! <Flus the transmitter fifo>*/
extern void i2s_tx_flush_fifo(DEV_I2S *pdev_i2s);
extern void i2s_rx_flush_fifo(DEV_I2S *pdev_i2s);
#ifdef __cplusplus
}
#endif

#endif /* _PMI2S_H_ */

/** @} end of group BOARD_PERIPHER_DRV_PMODI2S */