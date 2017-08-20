#include <psp2/kernel/processmgr.h>

#include <stdio.h>
#include <stdlib.h>

#include <psp2/ctrl.h>
#include <psp2/io/fcntl.h>
#include <psp2/io/stat.h>

#include "graphics.h"

#define printf psvDebugScreenPrintf
#define COLOR_MAGENTA 0xFFFF00FF

int sceRegMgrSetKeyInt(const char*, const char*, int);
int sceRegMgrSetKeyStr(const char*, const char*, const char*, int);

void menu() {
	psvDebugScreenClear(COLOR_BLACK);
    psvDebugScreenSetFgColor(COLOR_MAGENTA);
	printf("3G Disabler by Chihir0_\n\n");	
	psvDebugScreenSetFgColor(COLOR_WHITE);
	printf("https://twitter.com/Chihir0_\n\n");
	psvDebugScreenSetFgColor(COLOR_RED);
	printf("WARNING! Keep in mind this will disable the 3G Feature!\nYou will not be able to use Mobile Network!\n\n");
	psvDebugScreenSetFgColor(COLOR_WHITE);
	printf("Enable or disable the 3G Feature\n\n");
	printf("Press CROSS to disable the 3G Feature\n");
	printf("Press CIRCLE to enable the 3G Feature\n\n");
	printf("Press R to reboot\n");
	printf("Press START to exit\n");
}

int main(int argc, const char *argv[]) 
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
/////////////////////Registry Edit begin///////////////////////////////////
    sceRegMgrSetKeyInt("/CONFIG/TEL/", "use_debug_settings", 1);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "is_com_exist", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "target_operator", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "product_target_operator", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "enable_wwan", 0);
	//sceRegMgrSetKeyInt("/CONFIG/TEL/", "apn_name", 1);
	//sceRegMgrSetKeyInt("/CONFIG/TEL/", "apn_password", 1);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "is_apn_init", 0);
	//sceRegMgrSetKeyInt("/CONFIG/TEL/", "sim_unique_id", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "billing_plan", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "mcc", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "mnc", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "rat", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "network_selection", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "enable_data_roaming", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "antenna_disp_type", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "operator_site", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "show_operator_info", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "usb_setting", 1);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "forbidden_phone0", 0);
    sceRegMgrSetKeyInt("/CONFIG/TEL/", "dbg_log_tel", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "dbg_log_bbmc", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "dbg_log_net", 0);
/////////////////////Registry Edit end///////////////////////////////////			
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
		
/////////////////////Registry Edit begin///////////////////////////////////
    sceRegMgrSetKeyInt("/CONFIG/TEL/", "use_debug_settings", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "is_com_exist", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "target_operator", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "product_target_operator", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "enable_wwan", 0);
	//sceRegMgrSetKeyInt("/CONFIG/TEL/", "apn_name", 1);
	//sceRegMgrSetKeyInt("/CONFIG/TEL/", "apn_password", 1);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "is_apn_init", 0);
	//sceRegMgrSetKeyInt("/CONFIG/TEL/", "sim_unique_id", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "billing_plan", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "mcc", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "mnc", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "rat", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "network_selection", 1);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "enable_data_roaming", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "antenna_disp_type", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "operator_site", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "show_operator_info", 1);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "usb_setting", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "forbidden_phone0", 0);
    sceRegMgrSetKeyInt("/CONFIG/TEL/", "dbg_log_tel", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "dbg_log_bbmc", 0);
	sceRegMgrSetKeyInt("/CONFIG/TEL/", "dbg_log_net", 0);
/////////////////////Registry Edit end///////////////////////////////////
		
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