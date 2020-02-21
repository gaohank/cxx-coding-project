#include "sqlite3.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <error.h>

#define DB_PATH		"./student.db"
#define BUFF_SIZE	1024

#define error_exit(_errmsg_)	error(EXIT_FAILURE, errno, _errmsg_)

typedef struct _student_info {
	char name[64];
	int id;
	int score;
}student_st;


int db_select_callback(void *arg, int argc, char **values, char **name);

int main(int argc, const char **argv)
{
	sqlite3 *db = NULL;
	char *errmsg = NULL;
	char sql[BUFF_SIZE];
	FILE *fp;
	char buff[BUFF_SIZE];
	char *word = NULL;
	student_st stu_info;

	if (2 != argc) {
		puts("using './student stu.info'");
		return -1;
	}

	if (NULL == (fp = fopen(argv[1], "r")))
		error_exit("fopen");

	/* open or create database */
	if (SQLITE_OK != sqlite3_open(DB_PATH, &db))
		return -1;
	/* open or create student table */
	if (SQLITE_OK != sqlite3_exec(db, 
				"create table if not exists student (id int, name char, score int)", 
				NULL, NULL, &errmsg)) {
		printf("sqlite3_exec: %s\n", errmsg);
		sqlite3_free(errmsg);
	}

	while (1) {
		if (NULL == fgets(buff, BUFF_SIZE, fp))
			break;
		if (NULL == (word = strtok(buff, ":")))
			break;
		strcpy(stu_info.name, word);

		if (NULL == (word = strtok(NULL, ":")))
			break;
		stu_info.id = atoi(word);
		
		if (NULL == (word = strtok(NULL, ":")))
			break;
		stu_info.score = atoi(word);

		sprintf(sql, "insert into %s values (%d, \"%s\", %d)", "student", 
				stu_info.id, stu_info.name, stu_info.score);
		if (SQLITE_OK != sqlite3_exec(db, sql, NULL, NULL, &errmsg)) {
			printf("sqlite3_exec: %s\n", errmsg);
			sqlite3_free(errmsg);
		}
	}
	
	if (SQLITE_OK != sqlite3_exec(db, "select * from student order by score DESC",
				db_select_callback, NULL, &errmsg)) {
		printf("sqlite3_exec: %s\n", errmsg);
		sqlite3_free(errmsg);
	}

	sqlite3_close(db);

	return 0;


}

int db_select_callback(void *arg, int argc, char **values, char **name)
{
	int index;
#if 0
	for (index = 0; index < argc; index ++)
		printf("%s", name[index]);
	putchar('\n');
#endif
	for (index  = 0; index < argc; index ++) {
		printf("%5s  |", values[index]);
	}
	puts("\b ");

	return 0;
}
