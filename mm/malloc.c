// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */

	void *start = mem_list_head.prev->start + mem_list_head.prev->len;
	void *ptr;

	ptr = mmap(start, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	
	if (ptr == MAP_FAILED) {
		return NULL;
	}

	mem_list_add(ptr, size);
	return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	int *ptr = (int *)malloc(nmemb * size);

	if (ptr == NULL) {
		return NULL;
	}
	memset(ptr, 0, nmemb * size);
	return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL) {
		return;
	}

	struct mem_list *loc = mem_list_find(ptr);

	if (loc == NULL) {
		return;
	}

	munmap(ptr, loc->len);
	mem_list_del(ptr);


}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (ptr == NULL) {
		return malloc(size);
	}

	if (size == 0) {
		free(ptr);
		return NULL;
	}

	void *cpy = ptr;
	void *new = malloc(size);

	if (new == NULL) {
		return NULL;
	}

	struct mem_list *loc = mem_list_find(ptr);
	if (loc == NULL) {
		return NULL;
	}

	memcpy(new, ptr, loc->len);

	free(cpy);
	return new;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	
	if ((int)(nmemb * size) < 0) {
		return NULL; //check for integer overflow
	}

	void *new = realloc(ptr, nmemb * size);

	return new;
}
