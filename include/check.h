#ifndef CHECK_H
#define CHECK_H

#define CHECK_DATETIME_LEN 21
#define CHECK_TYPE_LEN 8
#define CHECK_DESCRIPTION_LEN 120
#define CHECK_COMPUTER_NAME_LEN 256

typedef enum
{
    check_in = 1,
    check_out
} type_check_t;

typedef struct
{
    char computer_name[CHECK_COMPUTER_NAME_LEN];
    char date_time[CHECK_DATETIME_LEN];
    long timestamp;
    type_check_t type;
    char description[CHECK_DESCRIPTION_LEN];
} check_t;

check_t check_create(type_check_t type);
check_t check_create_m(type_check_t type);
check_t *check_input_date(void);

#endif /* CHECK_H */
