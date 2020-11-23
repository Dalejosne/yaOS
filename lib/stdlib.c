/* La fonction memcopy permet de copier n octets de src vers dest.
 * Les adresses sont lineaires.
 */
void kmemcpy(char *source, char *destination, int n)
{
	while (n--)
		*destination++ = *source++;
	return;
}

void intToStr(int nb, char chaine[])
{
	int pow = 1, size = 0;
	for(pow = 1; nb>pow; pow*=10)size++;
	pow/=10;
	chaine[size] = '\0';
	for(int i = size-1; i>=0; i--)
	{
		chaine[size-i-1] = nb/pow;
		nb%=pow;
		chaine[size-i-1]+='0';
		pow/=10;
	}
}
