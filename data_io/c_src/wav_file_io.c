/**
 * @file    wav_file_io.c
 *
 * @brief   Description
 *  
 * @par
 * Created On: 30 Apr 2023
 * Created By: G. Howell
 */

/*------------------- INCLUDES -----------------------------------*/

#include <stdio.h>
#include "wav_file_io.h"

/*------------------- EXTERN VARIABLES ---------------------------*/
/*------------------- PRIVATE MACROS AND DEFINES -----------------*/
/*------------------- PRIVATE TYPEDEFS ---------------------------*/
/*------------------- STATIC VARIABLES ---------------------------*/
/*------------------- GLOBAL VARIABLES ---------------------------*/
/*------------------- STATIC FUNCTION PROTOTYPES -----------------*/
/*------------------- STATIC FUNCTIONS ---------------------------*/
/*------------------- GLOBAL FUNCTIONS ---------------------------*/

/**
 * @brief 	reads uint16_t data and header info from a wav file
 *
 * @param   fname  filename
 * @param   pData  data
 * @param   len    length of data to be read
 * @param   pHead  header info
 *
 * @return  status
 */
WAV_IO_Status WF_IO_Read_Int16(char *fname, uint16_t *pData, uint32_t len, WAV_IO_Header *pHead)
{
	FILE *fp = NULL;

	if((fp = fopen(fname, "rb")) == NULL)
	{
		return WAV_IO_ERR;
	}

	// read header then data
	fread(pHead, sizeof(WAV_IO_Header), 1, fp);
	fread(pData, sizeof(int16_t), len, fp);

	fclose(fp);

	return WAV_IO_OK;
}

/**
 * @brief 	writes uint16_t data and header info from a wav file
 *
 * @param   fname  filename
 * @param   pData  data
 * @param   len    length of data to write
 * @param   pHead  header info
 *
 * @return  status
 */
WAV_IO_Status WF_IO_Write_Int16(char *fname, uint16_t *pData, uint32_t len, WAV_IO_Header *pHead)
{
	FILE *fp = NULL;

	if((fp = fopen(fname, "wb")) == NULL)
	{
		return WAV_IO_ERR;
	}

	// write header then data
	fwrite(pHead, sizeof(WAV_IO_Header), 1, fp);
	fwrite(pData, sizeof(int16_t), len, fp);

	fclose(fp);

	return WAV_IO_OK;
}
