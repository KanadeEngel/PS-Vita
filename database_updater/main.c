#include <psp2/kernel/processmgr.h>

#include <stdio.h>
#include <stdlib.h>

#include <psp2/ctrl.h>
#include <psp2/io/fcntl.h>
#include <psp2/io/stat.h>

#include "graphics.h"

#define printf psvDebugScreenPrintf

void menu() {
	psvDebugScreenClear(COLOR_BLACK);
	psvDebugScreenSetFgColor(COLOR_WHITE);
	printf("Database Updater by KanadeEngel\n\n");
	psvDebugScreenSetFgColor(COLOR_RED);
	printf("WARNING! Rebuilding Database will NOT keep icon layout!\n\n");
	psvDebugScreenSetFgColor(COLOR_WHITE);
	printf("Rebuild or update your Database!\n\n");
	printf("Press CROSS to update your Database\n");
	printf("Press CIRCLE to rebuild your Database\n\n");
	printf("Press R to reboot..\n");
	printf("Press START to exit\n");
}

int main()
{
	int remain = 3;
	psvDebugScreenInit();
	
	menu();
	SceCtrlData pad;
	SceIoStat stat;

	while (1) {
		sceCtrlPeekBufferPositive(0, &pad, 1);

if (pad.buttons == SCE_CTRL_RTRIGGER) {
			break;
		}
		
if (pad.buttons == SCE_CTRL_START) {
			sceKernelExitProcess(0);
		}
		
if (pad.buttons == SCE_CTRL_CROSS) {
			sceIoRemove("ux0:/id.dat");
			psvDebugScreenSetFgColor(COLOR_GREEN);
			printf("Completed!\n\n");
			sceKernelDelayThread(1 * 1000 * 1000);
	while(remain-->0){
		printf("Your Vita will restart in %i s...\r", remain);
		sceKernelDelayThread(1000*1000);
	}
			break;
		}
		
if (pad.buttons == SCE_CTRL_CIRCLE) {
			sceIoRemove("ur0:/shell/db/app.db");
			psvDebugScreenSetFgColor(COLOR_GREEN);
			printf("Completed!\n\n");
			sceKernelDelayThread(1 * 1000 * 1000);
				while(remain-->0){
		printf("Your Vita will restart in %i s...\r", remain);
		sceKernelDelayThread(1000*1000);
	}
			break;
		}
	}
		

	
	return scePowerRequestColdReset();
}