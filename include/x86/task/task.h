#ifndef __TASK_H__
	#define __TASK_H__
	#include "../../lib/ktypes.h"
/**
* Task segment structure (x86)
*/
	typedef struct Tss_{
    	u16    previous_task, __previous_task_unused;
    	u32    esp0;
    	u16    ss0, __ss0_unused;
    	u32    esp1;
    	u16    ss1, __ss1_unused;
    	u32    esp2;
    	u16    ss2, __ss2_unused;
    	u32    cr3;
    	u32    eip, eflags, eax, ecx, edx, ebx, esp, ebp, esi, edi;
    	u16    es, __es_unused;
    	u16    cs, __cs_unused;
    	u16    ss, __ss_unused;
    	u16    ds, __ds_unused;
    	u16    fs, __fs_unused;
    	u16    gs, __gs_unused;
    	u16    ldt_selector, __ldt_sel_unused;
    	u16    debug_flag, io_map;
	}__attribute__((packed)) Tss;
	
	typedef struct TaskInfo_{
		u32 size;
		u32 memory_emplacement;
	}TaskI;
	
	#ifdef __TASK__
    	Tss Default_Tss;
    	TaskI Default_Task_I;
	#else
		extern Tss Default_Tss;
		extern TaskI Default_Task_I;
	#endif

	void task1(void);
/**
 * Call for mono task kernel
 */
	void callTask();
	void initTaskGdt();
#endif
