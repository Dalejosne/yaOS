#ifndef __MMU__
	#define __MMU__
	/**
	 * Init x86 mmu. Call by the kernel.
	 * This function exist for each arch.
	 */
	void initMmu(void);
	void initPaging(void);
#endif
