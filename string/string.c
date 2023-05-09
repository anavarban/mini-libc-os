// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */

	if (source == NULL || destination == NULL) {
		return NULL;
	}

	int i;
	for (i = 0; i < strlen(source); i++) {
		destination[i] = source[i];
	}
	destination[i] = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */

	if (source == NULL || destination == NULL) {
		return NULL;
	}

	int i;
	for (i = 0; i < len; i++) {
		destination[i] = source[i];
	}

	if (strlen(source) < len) {
		destination[i] = '\0';
	}
	

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */

	if (source == NULL || destination == NULL) {
		return NULL;
	}

	int i, dlen;
	dlen = strlen(destination);
	for (i = 0; i < strlen(source); i++) {
		destination[i + dlen] = source[i];
	}
	destination[i + dlen] = '\0';


	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */

	if (source == NULL || destination == NULL) {
		return NULL;
	}

	int i, dlen;
	dlen = strlen(destination);
	for (i = 0; i < len; i++) {
		destination[i + dlen] = source[i];
	}
	destination[i + dlen] = '\0';


	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	if (str1 == NULL) {
		return -1;
	}
	
	if (str2 == NULL) {
		return 1;
	}

	if (strlen(str1) < strlen(str2)) {
		return -1;
	}

	if (strlen(str1) > strlen(str2)) {
		return 1;
	}

	for (int i = 0; i < strlen(str1); i++) {
		if (str1[i] > str2[i]) {
			return 1;
		}

		if (str1[i] < str2[i]) {
			return -1;
		}
	}

	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	if (str1 == NULL) {
		return -1;
	}
	
	if (str2 == NULL) {
		return 1;
	}

	for (int i = 0; i < len; i++) {
		if (str1[i] > str2[i]) {
			return 1;
		}

		if (str1[i] < str2[i]) {
			return -1;
		}
	}

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */

	if (str == NULL) {
		return NULL;
	}

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == c) {
			return (str + i);
		}
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	if (str == NULL) {
		return NULL;
	}

	for (int i = strlen(str) - 1; i >= 0; i--) {
		if (str[i] == c) {
			return (str + i);
		}
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */

	if (haystack == NULL || needle == NULL) {
		return NULL;
	}


	for (int i = 0; i < strlen(haystack) - strlen(needle) + 1; i++) {
		int found = 1;
		for (int j = 0; j < strlen(needle); j++) {
			if (haystack[i + j] != needle[j]) {
				found = 0;
			}
		}
		if (found == 1) {
			return (haystack + i);
		}
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	if (haystack == NULL || needle == NULL) {
		return NULL;
	}

	int begin = -1;
	for (int i = 0; i < strlen(haystack) - strlen(needle) + 1; i++) {
		int found = 1;
		for (int j = 0; j < strlen(needle); j++) {
			if (haystack[i + j] != needle[j]) {
				found = 0;
			}
		}
		if (found == 1) {
			begin = i;
		}
	}

	if (begin != -1) {
		return haystack + begin;
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */

	if (destination == NULL || source == NULL) {
		return NULL;
	}

	int i;

	for (i = 0; i < num; i++) {
		*(char *)(destination + i) = *(char *)(source + i);
	}


	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */

	char buf[num + 1];

	memcpy(buf, source, num);

	for (int i = 0; i < num; i++) {
		*(char *)(destination + i) = buf[i];
	}
	
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	if (ptr1 == NULL) {
		return -1;
	}

	if (ptr2 == NULL) {
		return 1;
	}

	for (int i = 0; i < num; i++) {
		if (*(unsigned char*)(ptr1 + i) != *(unsigned char*)(ptr2 + i)) {
			return *(unsigned char*)(ptr1 + i) - *(unsigned char*)(ptr2 + i);
		}
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */

	if (source == NULL) {
		return NULL;
	}

	for (int i = 0; i < num; i++) {
		*(char *)(source + i) = value;
	}

	return source;
}
