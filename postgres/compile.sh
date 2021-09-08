# https://zetcode.com/db/postgresqlc/

gcc -o version.out version.c -I/usr/include/postgresql -lpq -std=c99
gcc -o server_version.out server_version.c -I/usr/include/postgresql -lpq -std=c99
gcc -o password_authetication.out password_authetication.c -I/usr/include/postgresql -lpq -std=c99
gcc -o create_table.out create_table.c -I/usr/include/postgresql -lpq -std=c99
gcc -o query_version.out query_version.c -I/usr/include/postgresql -lpq -std=c99
gcc -o multiple_rows.out multiple_rows.c -I/usr/include/postgresql -lpq -std=c99
gcc -o prepared_statement.out prepared_statement.c -I/usr/include/postgresql -lpq -std=c99
gcc -o column_headers.out column_headers.c -I/usr/include/postgresql -lpq -std=c99
gcc -o list_tables.out list_tables.c -I/usr/include/postgresql -lpq -std=c99
gcc -o transaction.out transaction.c -I/usr/include/postgresql -lpq -std=c99
