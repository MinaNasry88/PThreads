#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>

int main()
{
    
    
        int i = 0, j = 0;
        int height = 0;
        printf("Enter the height of the pyramid: ");
        scanf("%i", &height);
       
        
            //Asks user for the height of the pyramid
            do
            {
                printf("Enter the height of the pyramid: ");
                scanf("%i", &height);
            } while (height < 1 || height > 8);



            for (i = 1; i <= height, i++)
            {
                //print spaces
                for (j = i; j < height; j++)
                {
                    printf(" ");
                }

                //print hash symbols
                for (j = 1; j <= i; j++)
                {
                    printf("#");
                }

                //print new line
                printf("\n");
            }

        
        
    
    
    

        
        
    
}
    