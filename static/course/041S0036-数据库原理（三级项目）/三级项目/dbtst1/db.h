#ifndef DB_H
#define DB_H

#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "qstring.h"

extern QSqlDatabase db;

bool DatabaseInitialize();
bool SQLTest(QString);

#endif // DB_H
