/**
 * @file orz_date.c
 * @author Orz (justdoit_dog@163.com)
 * @brief For the freedom!
 * @version 0.1
 * @date 2023-08-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "orz_date.h"

static inline 
int32_t __calc_Feb_correct_days(uint32_t isleap, uint32_t month)
{
    int32_t correct = !!(month >> 1);
    correct += -correct & !isleap;

    return -correct;
}

static inline 
int32_t __calc_other_correct_days(uint32_t month)
{
    return (month + 1 + (month >> 3)) >> 1;
}

static inline 
int32_t __calc_correct_days(uint32_t isleap, uint32_t month)
{
    return __calc_other_correct_days(month) + __calc_Feb_correct_days(isleap, month);
}

static inline 
uint32_t __calc_mdays(uint32_t isleap, uint32_t month)
{
    if (month == 2) return 28 | isleap;

    return 30 | ((month & 1) ^ (month >> 3));
}

static inline
uint32_t __date_mdays(uint32_t year, uint32_t month)
{
    return __calc_mdays(orz_date_isleap(year), month);
}

static inline 
uint32_t __date_accum_days(uint32_t year, uint32_t month)
{
    uint32_t days = month * 30;
    int32_t correct = __calc_correct_days(orz_date_isleap(year), month);
    
    return days + correct;
}

static inline 
uint32_t __date_calc_month(uint32_t year, uint32_t days)
{
    uint32_t month = days / 30;
    int32_t remain = days % 30;

    int32_t correct = __calc_correct_days(orz_date_isleap(year), month);

    return month + (remain > correct);
}

static inline
uint32_t __date_week(uint32_t year, uint32_t month, uint32_t day)
{
    if (month <= 2) {
        year -= 1;
        month += 12;
    }

    uint32_t c = year / 100;
    uint32_t y = year % 100;

    uint32_t week = y + (y >> 2) + (c >> 2) + 6 * (c << 1) 
                    + 26 * (month + 1) / 10 + day - 1;

    return week % 7;
}


/* API ***********************************************/
__ORZ_EXPORT
ebl_t orz_date_isleap(uint32_t year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

__ORZ_EXPORT
ebl_t orz_date_ydays(uint32_t year)
{
    return 365 + orz_date_isleap(year);
}

__ORZ_EXPORT
ebl_t orz_date_calc_month(uint32_t year, uint32_t days)
{
    if ((days - 1) >= orz_date_ydays(year)) {
        return -3;
    }

    return __date_calc_month(year, days);
}

__ORZ_EXPORT
ebl_t orz_date_accum_days(uint32_t year, uint32_t month)
{
    if (month > 12) {
        return -4;
    }

    return __date_accum_days(year, month);
}

__ORZ_EXPORT
ebl_t orz_date_calc_yday(uint32_t year, uint32_t month, uint32_t day)
{
    if ((month - 1) >= 12) {
        return -1;
    } else if ((day - 1) >= __date_mdays(year, month)) {
        return -2;
    }

    return __date_accum_days(year, month - 1) + day; 
}

__ORZ_EXPORT
ebl_t orz_date_mdays(uint32_t year, uint32_t month)
{
    if ((month - 1) >= 12) {
        return -1;
    }

    return __date_mdays(year, month);
}

__ORZ_EXPORT
ebl_t orz_date_week(uint32_t year, uint32_t month, uint32_t day)
{
    if ((month - 1) >= 12) {
        return -1;
    } else if ((day - 1) >= __date_mdays(year, month)) {
        return -2;
    }

    return __date_week(year, month, day);
}
