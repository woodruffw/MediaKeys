/*	MediaKeys.c
	Author: William Woodruff
	------------------------
	
	Provides media key functionality on computers running Windows without actual media keys
	MAP:
	Ctrl-Up - VOLUME UP
	Ctrl-Down - VOLUME DOWN
	Ctrl-Left - MEDIA PREVIOUS
	Ctrl-Right - MEDIA NEXT
	Ctrl-F11 - VOLUME MUTE/UNMUTE
	Ctrl-F12 - MEDIA PLAY/PAUSE
*/

#include <Windows.h>
#include <Winuser.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	while (1)
	{
		if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_DOWN))
			keybd_event(0xAE, 0, 0, 0); /* volume down */
		else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_UP))
			keybd_event(0xAF, 0, 0, 0); /* volume up */
		else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_RIGHT))
			keybd_event(0xB0, 0, 0, 0); /* media next */
		else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_LEFT))
			keybd_event(0xB1, 0, 0, 0); /* media prev */
		else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_F11))
			keybd_event(0xAD, 0, 0, 0); /* mute/unmute */
		else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_F12))
			keybd_event(0xB3, 0, 0, 0); /* play/pause */
		
		Sleep(300);
	}
	return EXIT_SUCCESS;
}
