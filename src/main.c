/*
 * @Author: q1lon<keyron.zhang@gmail.com>
 * @Date: 2021-01-14 10:10:13
 * @LastEditTime: 2021-01-18 13:16:39
 * @FilePath: /sqlite-test/src/main.c
 */
#include <stdio.h>
#include <sqlite3.h>
#include "static/hello.h"
#include "shared/first.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char **argv) {
//     sqlite3 *db;
//     char *zErrMsg = 0;
//     int rc;

//     if (argc != 3)
//     {
//         fprintf(stderr, "Usage: %s DATABASE SQL-STATEMENT\n", argv[0]);
//         return (1);
//     }
//     rc = sqlite3_open(argv[1], &db);
//     if (rc)
//     {
//         fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//         sqlite3_close(db);
//         return (1);
//     }
//     rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);
//     if (rc != SQLITE_OK)
//     {
//         fprintf(stderr, "SQL error: %s\n", zErrMsg);
//         sqlite3_free(zErrMsg);
//     }
//     sqlite3_close(db);
//     return 0;

    test_print('l');
    test_print('z');
    return 0;
}