#include <stdio.h>
#include <stdlib.h>

#include <psp2/ctrl.h>
#include <psp2/io/fcntl.h>
#include <psp2/io/stat.h>
#include "graphics.h"
#include <psp2/kernel/processmgr.h>

#define printf psvDebugScreenPrintf
#define COLOR_MAGENTA 0xFFFF00FF

void menu() {
	psvDebugScreenClear(COLOR_BLACK);
    psvDebugScreenSetFgColor(COLOR_MAGENTA);
	printf("History Deleter v2 by Chihir0_\n\n");	
	psvDebugScreenSetFgColor(COLOR_WHITE);
	printf("Removes Game Launch / Error History\nhttps://twitter.com/Chihir0_\n\n");
	printf("Press CROSS to clean the History (semi-permanent)\n");
	printf("Press SQUARE to undo the semi-permanent trick\n\n");
	printf("Press START to exit\n\n");
}


int main()
{
	int remain = 5;
	psvDebugScreenInit();
    
	menu();
	
	SceIoStat stat;
	SceCtrlData pad;
			
while (1) {
		sceCtrlPeekBufferPositive(0, &pad, 1);
if (pad.buttons == SCE_CTRL_START) {
			sceKernelExitProcess(0);
		}
if (pad.buttons == SCE_CTRL_CROSS) {
            sceIoRemove("vd0:/history/data.bak"); //stores Error Codes and Game ID's from crashed Apps 
            sceIoRemove("vd0:/history/data.bin"); //
			sceIoMkdir("vd0:/history/data.bak", 0777);
			sceIoMkdir("vd0:/history/data.bin", 0777);
			
			sceIoRemove("ur0:/ci/file/m.log"); //stores Game ID's like MLCL00001 from MolecularShell
			sceIoMkdir("ur0:/ci/file/m.log", 0777);
			
			sceIoRemove("ur0:/user/00/shell/playlog/playlog.dat"); //stores Game ID's from ALL launched Apps
			sceIoMkdir("ur0:/user/00/shell/playlog/playlog.dat", 0777);
			sceIoRemove("ur0:/temp/rif/work.bin"); // License of the launched games, Homebrews has of course a fake license
			psvDebugScreenSetFgColor(COLOR_GREEN);
			printf("Completed!\n\n");
			sceKernelDelayThread(1 * 1000 * 1000);
            while(remain-->0){
		    printf("Your Vita will restart in %i s...\r", remain);
		    sceKernelDelayThread(1000*1000);
	}
			break;
		}
if (pad.buttons == SCE_CTRL_SQUARE) {
			sceIoRmdir("vd0:/history/data.bak");
			sceIoRmdir("vd0:/history/data.bin");
			sceIoRmdir("ur0:/ci/file/m.log");
			sceIoRmdir("ur0:/user/00/shell/playlog/playlog.dat");
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