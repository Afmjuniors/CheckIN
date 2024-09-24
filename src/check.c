#include <check.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

check_t check_create(type_check_t type)
{
    check_t check;
    char computerName[CHECK_COMPUTER_NAME_LEN];
    char timestamp[CHECK_DATETIME_LEN];
    time_t now = time(NULL);

    getComputerName(computerName, sizeof(computerName));
    getCurrentTimestamp(timestamp, sizeof(timestamp));

    check.timestamp = mktime(localtime(&now));
    strncpy(check.computer_name, computerName, CHECK_COMPUTER_NAME_LEN);
    strncpy(check.date_time, timestamp, CHECK_DATETIME_LEN);

    check.type = type;
    if (type == check_out)
    {
        printf("Descreva o que foi trabalhado hoje: ");
        fgets(check.description, CHECK_DESCRIPTION_LEN - 1, stdin);
        check.description[strlen(check.description) - 1] = 0;
    }

    return check;
}

check_t check_create_m(type_check_t type)
{
    check_t check;
    char computerName[CHECK_COMPUTER_NAME_LEN];
    char timestamp[CHECK_DATETIME_LEN];
    time_t now = time(NULL);

    printf("Digite um horário para inserir manualmente: ");
    fgets(check.date_time, CHECK_DATETIME_LEN - 1, stdin);
    check.date_time[strlen(check.date_time) - 1] = 0;

    getComputerName(computerName, sizeof(computerName));
    getCurrentTimestamp(timestamp, sizeof(timestamp));

    check.timestamp = mktime(localtime(&now));
    strncpy(check.computer_name, computerName, CHECK_COMPUTER_NAME_LEN);
    strncpy(check.date_time, timestamp, CHECK_DATETIME_LEN);

    check.type = type;
    if (type == check_out)
    {
        printf("Descreva o que foi trabalhado hoje: ");
        fgets(check.description, CHECK_DESCRIPTION_LEN - 1, stdin);
        check.description[strlen(check.description) - 1] = 0;
    }

    return check;
}
