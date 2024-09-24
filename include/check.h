#ifndef CHECK_H
#define CHECK_H

#define CHECK_NAME_LEN         120
#define CHECK_DATE_TIME_LEN      25
#define CHECK_DESCRIPTION_LEN      95

typedef struct 
{
    char computer_name[CHECK_NAME_LEN];
    char date_time[CHECK_DATE_TIME_LEN];
    int type_check;
    int timestamp;
    char description[CHECK_DESCRIPTION_LEN];
} check_t;

check_t check_create(void);
char *check_input_name(void);
void check_parser(char *buffer, check_t *check);

#endif /* CHECK_H */
