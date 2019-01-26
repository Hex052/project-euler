#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct list {
	struct item* start;
	struct item* last;
};
struct item {
	struct item* prev;
	struct item* next;
	int data;
};
struct list* list_new(void) {
	struct list* list = malloc(sizeof(struct list));
	list->start = NULL;
	list->last = NULL;
	return list;
}
void list_add(const int data, struct list* list) {
	if (list->start == NULL) {
		list->start = malloc(sizeof(struct item));
		list->last = list->start;
		list->start->prev = NULL;
		list->start->next = NULL;
		list->start->data = data;
		return;
	}
	else if (list->last == NULL) {
		struct item* item = list->start;
		while (item->next != NULL) {
			item = item->next;
		}
		item->next = malloc(sizeof(struct item));
		list->last = item->next;
		list->last->data = data;
		list->last->prev = item;
		list->last->next = NULL;
		return;
	}
	list->last->next = malloc(sizeof(struct item));
	list->last->next->prev = list->last;
	list->last = list->last->next;
	list->last->next = NULL;
	list->last->data = data;
}
bool list_contains(const int data, const struct list* list) {
	if (list->start == NULL) {
		return false;
	}
	struct item* item = list->start;
	while (item != NULL) {
		if (item->data == data) {
			return true;
		}
		item = item->next;
	}
	return false;
}

int numlen(int i) {
	int count = 0;
	while (i > 0) {
		count++;
		i /= 10;
	}
	return count;
}

int main(int argc, char const *argv[]) {
	FILE* logfile = NULL;
	if (argc > 1) {
		logfile = fopen(argv[1], "w");
	}
	struct list* list = list_new();
	for (int i = 0; i < 10000; i++) {
		for (int j = i; j < 10000; j++) {
			if (numlen(i) + numlen(j) >= 8)
				break;
			if (numlen(i) + numlen(j) + numlen(i * j) == 9) {
				char* str = malloc(sizeof(char) * 30);
				sprintf(str, "%d * %d = %d", i, j, i * j);
				if (strchr(str, '0') != NULL) {
					if (logfile) fprintf(logfile, "%s contains 0s\n",str );
					label_not_pandigital:
					free(str);
					continue;
				}
				for (int index = 0; index < strlen(str); index++) {
					if (str[index] < '0' || str[index] > '9') {
						continue; //skip the nonnumbers
					}
					if (str+index != strchr(str, str[index])) {
						if (logfile) fprintf(logfile, "%s contains duplicate %c\n", str, str[index]);
						goto label_not_pandigital; //Probably refactor later.
					}
				}
				if (list_contains(i*j, list)) {
					if (logfile) fprintf(logfile, "%s already appeared\n", str);
					free(str);
					continue;
				}
				list_add(i*j, list);
				if (logfile) fprintf(logfile, "%s passed checks\n", str);
				printf("%s\n", str);
				free(str);
			}
		}
	}
	return 0;
}
