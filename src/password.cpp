/**************************************************************************/
// password.cpp - handles password checking
/***************************************************************************
 * The Dawn of Time v1.69s.beta6 (c)1997-2010 Kalahn                       *
 * >> A number of people have contributed to the Dawn codebase, with the   *
 *    majority of code written by Kalahn - www.dawnoftime.org              *
 * >> To use this source code, you must fully comply with the dawn license *
 *    in licenses.txt... In particular, you may not remove this copyright  *
 *    notice.                                                              *
 **************************************************************************/
#include "include.h"

/**************************************************************************/
char *ey_crypt(char *buf,char *salt); // in crypt.c
char *sha256_crypt( const char *pwd );
/**************************************************************************/
char *dot_crypt(const char *buf, const char *salt)
{
#ifdef NOCRYPT
	return (char *)buf;
#endif
	char crypt_buf[25];
	memset(crypt_buf, 0, 25);
	strncpy(crypt_buf, buf, 24);

	char salt_buf[1024];
	memset(salt_buf, 0, 1024);
	strncpy(salt_buf, salt, 2);

	return ey_crypt(crypt_buf,salt_buf);
};

/**************************************************************************/
// return true if the password is considered correct
bool is_valid_password(const char *attempt, const char *password, connection_data *c)
{
	if(strcmp( sha256_crypt( attempt), password) )
	{
		// check if it is an old DOT password
		if(!strcmp( dot_crypt( attempt, password ), password))
		{
			return true;
		}
		return false;
	}
	return true;
}
/**************************************************************************/
