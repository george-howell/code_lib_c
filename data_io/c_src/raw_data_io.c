/**
 * @file    raw_data_io.c
 *
 * @brief   Description
 *  
 * @par
 * Created On: 30 Apr 2023
 * Created By: G. Howell
 */

/*------------------- INCLUDES -----------------------------------*/

#include "raw_data_io.h"

/*------------------- EXTERN VARIABLES ---------------------------*/
/*------------------- PRIVATE MACROS AND DEFINES -----------------*/
/*------------------- PRIVATE TYPEDEFS ---------------------------*/
/*------------------- STATIC VARIABLES ---------------------------*/
/*------------------- GLOBAL VARIABLES ---------------------------*/
/*------------------- STATIC FUNCTION PROTOTYPES -----------------*/
/*------------------- STATIC FUNCTIONS ---------------------------*/

static RD_IO_Status openFile(FILE **fp, char *fname, char *mode);
static RD_IO_Status closeFile(FILE *fp);

/*------------------- GLOBAL FUNCTIONS ---------------------------*/

/**
 * @brief 	reads uint32_t data from a raw file
 *
 * @param   fname  filename
 * @param   data  data
 * @param   len  length of data to be read
 *
 * @return  status
 */
RD_IO_Status RD_IO_Read_Uint32(char *fname, uint32_t *data, uint32_t len)
{
    FILE *fp = NULL;

    if(openFile(&fp, fname, "r") != RD_IO_OK)
	{
		return RD_IO_ERR;
	}

    fread(data, sizeof(uint32_t), len, fp);

    closeFile(fp);

    return RD_IO_OK;
}

/**
 * @brief 	writes uint32_t data from a raw file
 *
 * @param   fname  filename
 * @param   data  data
 * @param   len  length of data to be read
 *
 * @return  status
 */
RD_IO_Status RD_IO_Write_Uint32(char *fname, uint32_t *data, uint32_t len)
{
	FILE *fp = NULL;

    if(openFile(&fp, fname, "w") != RD_IO_OK)
	{
		return RD_IO_ERR;
	}

    fwrite(data, sizeof(uint32_t), len, fp);

    closeFile(fp);

    return RD_IO_OK;
}

/**
 * @brief 	reads float data from a raw file
 *
 * @param   fname  filename
 * @param   data  data
 * @param   len  length of data to be read
 *
 * @return  status
 */
RD_IO_Status RD_IO_Read_Float(char *fname, float *data, uint32_t len)
{
    FILE *fp = NULL;

    if(openFile(&fp, fname, "r") != RD_IO_OK)
	{
		return RD_IO_ERR;
	}

    fread(data, sizeof(float), len, fp);

    closeFile(fp);

    return RD_IO_OK;
}

/**
 * @brief 	writes float data from a raw file
 *
 * @param   fname  filename
 * @param   data  data
 * @param   len  length of data to be read
 *
 * @return  status
 */
RD_IO_Status RD_IO_Write_Float(char *fname, float *data, uint32_t len)
{
	FILE *fp = NULL;

    if(openFile(&fp, fname, "w") != RD_IO_OK)
	{
		return RD_IO_ERR;
	}

    fwrite(data, sizeof(float), len, fp);

    closeFile(fp);

    return RD_IO_OK;
}

static RD_IO_Status openFile(FILE **fp, char *fname, char *mode)
{
	// open the file
	if((*fp = fopen(fname, mode)) == NULL)
	{
		return RD_IO_ERR;
	}

	return RD_IO_OK;
}

static RD_IO_Status closeFile(FILE *fp)
{
	fclose(fp);

	return RD_IO_OK;
}
