#ifndef __EXCEPTION__
	#define __EXCEPTION__
	/**
	*All these exception write a message on the screen and stop the kernel
	* */
	/***/
	void _defaultException();
	/***/
	void _divideByZeroExcept();
	/***/
	void _debugExcept();
	/***/
	void _nonMaskIntExcept();
	/***/
	void _bpExcept();
	/***/
	void _overflowExcept();
	/***/
	void _invalidOpcodeExcept();
	/***/
	void _nmExcept();
	/***/
	void _tsExcept();
	/***/
	void _npExcept();
	/***/
	void _ssExcept();
	/***/
	void _gpExcept();
	/***/
	void _pageExcept();
	/***/
	void _mfExcept();
	/***/
	void _acExcept();
	/***/
	void _mcExcept();
	/***/
	void _xmExcept();
	/***/
	void _veExcept();
	/***/
	void _sxExcept();
#endif
