/* La fonction memcopy permet de copier n octets de src vers dest.
 * Les adresses sont lineaires.
 */
void *memcpy(char *source, char *destination, int n)
{
	char *p = destination;
	while (n--)
		*destination++ = *source++;
	return;
}
