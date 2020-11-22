/* La fonction memcopy permet de copier n octets de src vers dest.
 * Les adresses sont lineaires.
 */
void kmemcpy(char *source, char *destination, int n)
{
	while (n--)
		*destination++ = *source++;
	return;
}
