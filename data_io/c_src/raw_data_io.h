/**
 * @file    raw_data_io.h
 *
 * @brief   Description
 *  
 * @par
 * Created On:
 * Created By:
 */

#ifndef __RAW_DATA_IO_H__
#define __RAW_DATA_IO_H__

#ifdef __cplusplus
extern "C" {
#endif

/*------------------- INCLUDES -----------------------------------*/

#include <stdio.h>
#include <stdint.h>

/*------------------- MACROS AND DEFINES -------------------------*/
/*------------------- TYPEDEFS -----------------------------------*/

typedef enum
{
	RD_IO_OK,
	RD_IO_ERR
} RD_IO_Status;

/*------------------- EXPORTED VARIABLES -------------------------*/
/*------------------- GLOBAL FUNCTION PROTOTYPES -----------------*/

RD_IO_Status RD_IO_Read_Uint32(char *fname, uint32_t *data, uint32_t len);
RD_IO_Status RD_IO_Write_Uint32(char *fname, uint32_t *data, uint32_t len);
RD_IO_Status RD_IO_Read_Float(char *fname, float *data, uint32_t len);
RD_IO_Status RD_IO_Write_Float(char *fname, float *data, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif /* __RAW_DATA_IO_H__ */
