int	ft_strcmp(const char *cs, const char *ct)
{
	while (*cs && *cs == *ct)
	{
		++cs;
		++ct;
	}
	return (*(unsigned char *)cs - *(unsigned char *)ct);
}
