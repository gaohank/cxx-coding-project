#include <stdio.h>
#include <stdlib.h>

#define DEBUG	1

typedef struct _seqlist_{
	int *buff;
	int c_len;
	int m_len;
}seqlist_t;

seqlist_t *init_seqlist(int len);
int free_seqlist(seqlist_t *list);
int insert_seqlist(seqlist_t *list, int value);
int modify_seqlist(seqlist_t *list, int obj, int value);
int delet_seqlist(seqlist_t *list, int obj);
int search_seqlist(seqlist_t *list, int obj);
int show_seqlist(seqlist_t *list);
int _locat_seqlist_(seqlist_t *list, int obj);

int main(void)
{
	seqlist_t *list = NULL;
	int value;
	
	list = init_seqlist(10);
	
	for (value = 100; ; value ++) {
		if (0 > insert_seqlist(list, value))
			break;
	}
#if DEBUG
	show_seqlist(list);
#endif
	modify_seqlist(list, 109, 205);
#if DEBUG
	show_seqlist(list);
#endif
	delet_seqlist(list, 1000);
#if DEBUG
	show_seqlist(list);
#endif
	printf("%d->%d\n", 2005, search_seqlist(list, 2005));

	free_seqlist(list);
	return 0;
}

seqlist_t *init_seqlist(int len)
{
	seqlist_t *list = NULL;

	list = (seqlist_t *)malloc(sizeof(seqlist_t));
	list->buff = (int *)malloc(sizeof(int) * len);
	list->c_len = 0;
	list->m_len = len;

	return list;
}

int free_seqlist(seqlist_t *list)
{
	free(list->buff);
	free(list);
	
	return 0;
}

int insert_seqlist(seqlist_t *list, int value)
{
	int index;

	if (list->c_len >=  list->m_len)
		return -1;

	for (index = list->c_len; index > 0; index --) {
		list->buff[index] = list->buff[index - 1];
	}

	list->buff[0] = value;
	list->c_len ++;
	
	return 0;
}

int show_seqlist(seqlist_t *list)
{
	int index;

	for (index = 0; index < list->c_len; index ++) {
		printf("%5d", list->buff[index]);
	}
	putchar(10);

	return 0;
}

int _locat_seqlist_(seqlist_t *list, int obj)
{
	int index;

	for (index = 0; index < list->c_len; index ++) {
		if (obj == list->buff[index])
			return index;
	}
	return -1;
}

int modify_seqlist(seqlist_t *list, int obj, int value)
{
	int posit;
	
	if (-1 == (posit = _locat_seqlist_(list, obj)))
		return -1;
	list->buff[posit] = value;

	return 0;
}

int delet_seqlist(seqlist_t *list, int obj)
{
	int posit;
	int index;

	if (list->c_len <= 0)
		return -1;

	if (-1 == (posit = _locat_seqlist_(list, obj)))
		return -1;
	for (index = posit; index < list->c_len; index ++) {
		list->buff[index] = list->buff[index + 1];
	}
	list->c_len --;

	return 0;
}

int search_seqlist(seqlist_t *list, int obj)
{
	return _locat_seqlist_(list, obj);
}
