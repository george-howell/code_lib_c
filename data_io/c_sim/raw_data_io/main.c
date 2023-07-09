/**
 * @file    main.c
 *
 * @brief  	
 *  
 * @par
 * Created On: 30 Apr 2023
 * Created By: ghowell
 */

/*------------------- INCLUDES -----------------------------------*/

#include "raw_data_io.h"

/*------------------- EXTERN VARIABLES ---------------------------*/
/*------------------- PRIVATE MACROS AND DEFINES -----------------*/

//#define DEBUG

#define LEN 			3

/*------------------- PRIVATE TYPEDEFS ---------------------------*/
/*------------------- STATIC VARIABLES ---------------------------*/
/*------------------- GLOBAL VARIABLES ---------------------------*/
/*------------------- STATIC FUNCTION PROTOTYPES -----------------*/
/*------------------- STATIC FUNCTIONS ---------------------------*/
/*------------------- GLOBAL FUNCTIONS ---------------------------*/

int main()
{
    /*
     * uint32_t
     */

	char filename[15] = "data/test.dat";
    uint32_t dataIn[] = {1,2,4};
    uint32_t dataOut[LEN] = {0};
    uint32_t ni;
	uint8_t err = 0;

    // write data to file
    if (RD_IO_Write_Uint32(filename, dataIn, LEN) != RD_IO_OK)
    {
        printf("Error writing raw data to file\n");
        return -1;
    }

    // read data from file
    if (RD_IO_Read_Uint32(filename, dataOut, LEN) != RD_IO_OK)
    {
        printf("Error reading raw data from file\n");
        return -1;
    }

    // print read data to console
    for (ni=0; ni<LEN; ni++)
    {
    	if (dataIn[ni]!=dataOut[ni])
    	{
    		err = 1;
    		printf("ERR: data is not equal\n");
    		break;
    	}
#ifdef DEBUG
        printf("Readback Data [%d]: %d\n", ni, dataOut[ni]);
#endif
    }

    if (!err)
    {
    	printf("Int data is equal!\n");
    }

    /*
	 * float
	 */

    char filenameF[] = "data/testF.dat";
	float dataInF[] = {1.2, 2.3, 4.8};
	float dataOutF[LEN] = {0};

	// write data to file
	if (RD_IO_Write_Float(filenameF, dataInF, LEN) != RD_IO_OK)
	{
		printf("Error writing raw data to file\n");
		return -1;
	}

	// read data from file
	if (RD_IO_Read_Float(filenameF, dataOutF, LEN) != RD_IO_OK)
	{
		printf("Error reading raw data from file\n");
		return -1;
	}

    // print read data to console
    for (ni=0; ni<LEN; ni++)
    {
    	if (dataInF[ni]!=dataOutF[ni])
    	{
    		err = 1;
    		printf("ERR: data is not equal\n");
    		break;
    	}
#ifdef DEBUG
        printf("Readback Data [%d]: %.2f\n", ni, dataOutF[ni]);
#endif
    }

    if (!err)
    {
    	printf("Float data is equal!\n");
    }

    return 0;
}
