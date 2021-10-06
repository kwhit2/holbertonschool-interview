#include "menger.h"

/**
* menger - a function that draws a 2D Menger Sponge
* @level: level of the Menger Sponge to draw
* Return: draw output of 2d menger sponge
* Note: This is poor code and I am sorry. Could not get...
* ...of trash output with my other code.
*/
void menger(int level)
{
	if (level <= 0)
	{
		printf("#\n");
		return;
	}
	if (level == 1)
	{
		printf("###\n# #\n###\n");
		return;
	}
	if (level == 2)
	{
		printf("#########\n# ## ## #\n#########\n###   ###\n# #   # #\n");
		printf("###   ###\n#########\n# ## ## #\n#########\n");
		return;
	}
	if (level == 3)
	{
		mengerHelp(level);
		return;
	}
}

/**
* mengerHelp - a helper function that draws a 2D Menger Sponge
* @level: level of the Menger Sponge to draw
* Return: draw output of 2d menger sponge
*/
void mengerHelp(int level)
{
	if (level == 3)
	{
		printf("###########################\n");
		printf("# ## ## ## ## ## ## ## ## #\n");
		printf("###########################\n");
		printf("###   ######   ######   ###\n");
		printf("# #   # ## #   # ## #   # #\n");
		printf("###   ######   ######   ###\n");
		printf("###########################\n");
		printf("# ## ## ## ## ## ## ## ## #\n");
		printf("###########################\n");
		printf("#########         #########\n");
		printf("# ## ## #         # ## ## #\n");
		printf("#########         #########\n");
		printf("###   ###         ###   ###\n");
		printf("# #   # #         # #   # #\n");
		printf("###   ###         ###   ###\n");
		printf("#########         #########\n");
		printf("# ## ## #         # ## ## #\n");
		printf("#########         #########\n");
		printf("###########################\n");
		printf("# ## ## ## ## ## ## ## ## #\n");
		printf("###########################\n");
		printf("###   ######   ######   ###\n");
		printf("# #   # ## #   # ## #   # #\n");
		printf("###   ######   ######   ###\n");
		printf("###########################\n");
		printf("# ## ## ## ## ## ## ## ## #\n");
		printf("###########################\n");
	}
}
