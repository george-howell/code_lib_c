/**
 * @file    main.c
 *
 * @brief  	
 *  
 * @par
 * Created On: 1 May 2023
 * Created By: ghowell
 */

/*------------------- INCLUDES -----------------------------------*/

#include <stdio.h>
#include "wav_file_io.h"

/*------------------- EXTERN VARIABLES ---------------------------*/
/*------------------- PRIVATE MACROS AND DEFINES -----------------*/

#define NO_SAMPLES		1024

/*------------------- PRIVATE TYPEDEFS ---------------------------*/
/*------------------- STATIC VARIABLES ---------------------------*/
/*------------------- GLOBAL VARIABLES ---------------------------*/
/*------------------- STATIC FUNCTION PROTOTYPES -----------------*/
/*------------------- STATIC FUNCTIONS ---------------------------*/
/*------------------- GLOBAL FUNCTIONS ---------------------------*/

int main(void)
{
	WAV_IO_Header header = {0};
	uint16_t buff[NO_SAMPLES] = {0};

	if(WF_IO_Read_Int16("../../models/data/tone_input.wav", buff, NO_SAMPLES, &header) != WAV_IO_OK)
	{
		printf("Error reading file\n");
		return -1;
	}

	if(WF_IO_Write_Int16("../../models/data/tone_output.wav", buff, NO_SAMPLES, &header) != WAV_IO_OK)
	{
		printf("Error reading file\n");
		return -1;
	}

	return 0;

}
