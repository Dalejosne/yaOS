/*
*
*
*
*
* Si une exception est déclenchée, on affiche un message d'erreur et l'on fait boucler le kernel en rond
*
*
*
*
*
*/

#include "exception.h"
#include "../../lib/kio.h"

void _defaultException()
{
	write("Default exception\n");
	while(1);
}

void _divideByZeroExcept()
{
	write("Division by zero exception\n");
	while(1);
}
void _debugExcept()
{
	write("Debug exception\n");
	while(1);
}

void _nonMaskIntExcept()
{
	write("Non maskable interrupt exception\n");
	while(1);
}

void _bpExcept()
{
	write("#BP exception\n");
	while(1);
}

void _overflowExcept()
{
	write("Overflow exception\n");
	while(1);
}

void _invalidOpcodeExcept() // except 6
{
	write("Debug exception\n");
	while(1);
}

void _nmExcept()
{
	write("Device not available exception\n");
	while(1);
}

void _tsExcept()//10
{
	write("Invalid TSS\n");
	while(1);
}

void _npExcept()
{
	write("Segment not present\n");
	while(1);
}

void _ssExcept()
{
	write("Stack segment fault\n");
	while(1);
}

void _gpExcept()
{
	write("general protection fault\n");
	while(1);
}

void _pageExcept()
{
	write("Page fault\n");
	while(1);
}

void _mfExcept() //17
{
	write("Floating point fault\n");
	while(1);
}

void _acExcept()
{
	write("Alignement check fault\n");
	while(1);
}

void _mcExcept()
{
	write("Machine check fault\n");
	while(1);
}

void _xmExcept()
{
	write("SIMD floating point exception\n");
	while(1);
}

void _veExcept()
{
	write("Virtualisation exception\n");
	while(1);
}

void _sxExcept() //30
{
	write("Security fault\n");
	while(1);
}
