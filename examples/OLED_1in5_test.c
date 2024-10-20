/*****************************************************************************
* | File      	:   OLED_1in5_test.c
* | Author      :   Waveshare team
* | Function    :   1.5inch OLED Module test demo
* | Info        :
*----------------
* |	This version:   V2.0
* | Date        :   2020-08-15
* | Info        :
* -----------------------------------------------------------------------------
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "test.h"
#include "OLED_1in5.h"
#include <unistd.h>

void printSpecifiedBouncingSquare(UBYTE *BlackImage, int size, int x, int y) {
	for(int i = 0; i < 40; i++) {
		Paint_SelectImage(BlackImage);
        		// Clear only the part of the image where the square was
        		Paint_DrawRectangle(x + i - 1, y, x + i + size - 1, y + size, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);

        		// Draw a rectangle at a new position
        		Paint_DrawRectangle(x + i, y, x + i + size, y + size, WHITE, DOT_PIXEL_1X1, DRAW_FILL_FULL);

        		// Show the updated image
        		OLED_1in5_Display(BlackImage);
        		DEV_Delay_ms(1);  // Reduce delay to speed up movement		
	}
}

void printBouncingSquare(UBYTE *BlackImage){
	printSpecifiedBouncingSquare(BlackImage, 10, 50, 30);
}

int OLED_1in5_test(void)
{
	printf("1.5inch OLED test demo\n");
	if(DEV_ModuleInit() != 0) {
		return -1;
	}
	  
	printf("OLED Init...\r\n");
	OLED_1in5_Init();
	DEV_Delay_ms(500);	
	// 0.Create a new image cache
	UBYTE *BlackImage;
	UWORD Imagesize = ((OLED_1in5_WIDTH%2==0)? (OLED_1in5_WIDTH/2): (OLED_1in5_WIDTH/2+1)) * OLED_1in5_HEIGHT;
	if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
			printf("Failed to apply for black memory...\r\n");
			return -1;
	}
	printf("Paint_NewImage\r\n");
	Paint_NewImage(BlackImage, OLED_1in5_WIDTH, OLED_1in5_HEIGHT, 0, BLACK);	
	Paint_SetScale(16);
	printf("Drawing\r\n");
	//1.Select Image
	Paint_SelectImage(BlackImage);
	DEV_Delay_ms(500);
	Paint_Clear(BLACK);
		
	// 2.Drawing on the image		
	printf("Drawing: Bouncing square\r\n");

	printBouncingSquare(BlackImage);
	
	OLED_1in5_Clear();
	return 0;
}
