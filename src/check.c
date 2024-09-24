#include <check.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
check_t check_create(type)
{
    check_t check;
    char computerName[CHECK_NAME_LEN];
    char timestamp[CHECK_DATE_TIME_LEN];
    time_t now = time(NULL);

    getComputerName(computerName, sizeof(computerName));
    getCurrentTimestamp(timestamp, sizeof(timestamp));

    check.timestamp = mktime(localtime(&now));

    strncpy(check.computer_name, computerName, CHECK_NAME_LEN);
    strncpy(check.date_time, timestamp, CHECK_DATE_TIME_LEN);

    check.type_check = type;
    if (type == 2)
    {
        printf("Descreva o que foi trabalhado hoje: ");
        fgets(check.description, CHECK_DESCRIPTION_LEN - 1, stdin);
        check.description[strlen(check.description) - 1] = 0;
    }

    return check;
}

char *check_input_name(void)
{
    char *name = calloc(1, CHECK_NAME_LEN + 1);
    printf("Type a name to modify: ");
    fgets(name, CHECK_NAME_LEN - 1, stdin);
    name[strlen(name) - 1] = 0;
    return name;
}

void check_parser(char *buffer, check_t *check)
{
    if (check == NULL || buffer == NULL)
        return;

    char *data = strtok(buffer, ",");
    strncpy(check->computer_name, data, CHECK_NAME_LEN);
    data = strtok(NULL, ",");
    strncpy(check->date_time, data, CHECK_DATE_TIME_LEN);
    data = strtok(NULL, ",");
    check->timestamp = atoi(data);
    data = strtok(NULL, ",");
    check->type_check = atoi(data);;
    data = strtok(NULL, ",");
    strncpy(check->description, data, CHECK_DESCRIPTION_LEN);
}
