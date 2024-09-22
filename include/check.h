#ifndef CHECK_H
#define CHECK_H

#define CHECK_DATETIME_LEN 25
#define CHECK_TYPE_LEN 5
#define CHECK_DESCRIPTION_LEN 120
#define CHECK_CUMPUTER_NAME_LEN 25

typedef struct
{
    int id;
    char date_time[CHECK_DATETIME_LEN];
    long timestamp;
    char type[CHECK_TYPE_LEN];
    char description[CHECK_DESCRIPTION_LEN];
} check_t;

check_t check_create(void);
char *check_input_date(void);

#endif /* CHECK_H */