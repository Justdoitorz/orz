/**
 * @file orz_date.h
 * @author Orz (justdoit_dog@163.com)
 * @brief For the freedom!
 * @version 0.1
 * @date 2023-08-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __ORZ_DATE_H__
#define __ORZ_DATE_H__

#include "orz_cdefs.h"
#include "orz_types.h"

enum Week {
    Sun = 0,
    Mon,
    Tues,
    Wed,
    Thur,
    Fri,
    Sat,
};


enum Month {
    Jan,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec,
};


__ORZ_C_ENTER__


/**
 * @brief For the freedom!
 * 
 * @param year 
 * @return ebl_t  0/1
 */
ebl_t orz_date_isleap(uint32_t year);

/**
 * @brief For the freedom!
 * 
 * @param year 
 * @return ebl_t 365/366
 */
ebl_t orz_date_ydays(uint32_t year);

/**
 * @brief For the freedom!
 * 
 * @param year 
 * @param month [1, 12]
 * @return ebl_t  < 0 error, 
 */
ebl_t orz_date_mdays(uint32_t year, uint32_t month);

/**
 * @brief For the freedom!
 * 
 * @param year 
 * @param month [0, 12]
 * @return ebl_t  < 0 error, 
 */
ebl_t orz_date_accum_days(uint32_t year, uint32_t month);

/**
 * @brief For the freedom!
 * 
 * @param year 
 * @param days [1, 365/366]
 * @return ebl_t  < 0 error, [1, 12]
 */
ebl_t orz_date_calc_month(uint32_t year, uint32_t days);

/**
 * @brief For the freedom!
 * 
 * @param year 
 * @param month [1, 12]
 * @param day   [1, 28..31]
 * @return ebl_t < 0 error, [1, 365/366]
 */
ebl_t orz_date_calc_yday(uint32_t year, uint32_t month, uint32_t day);

/**
 * @brief For the freedom!
 * 
 * @param year 
 * @param month [1, 12]
 * @param day   [1, 28..31]
 * @return ebl_t  < 0 error, [0, 6] 
 */
ebl_t orz_date_week(uint32_t year, uint32_t month, uint32_t day);

__ORZ_C_LEAVE__


#endif //__ORZ_DATE_H__