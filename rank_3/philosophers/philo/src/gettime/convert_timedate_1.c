/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_timedate_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:01:20 by srussame          #+#    #+#             */
/*   Updated: 2025/05/07 14:01:21 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void year_count(t_datetime *time);
void month_count(t_datetime *time);
void	dayhour_count(t_datetime *time);

/*to convert the value got from gettimeofday()
	in a form of [struct timeval] (in seconds and usec) 
	the calculation counts the since of EPOCH (1970-01-01_00:00:00 +0000 (UTC))
*/
int	convert_timedate(t_datetime *time)
{
	if (time == NULL)
		return (0);
	year_count(time);
	month_count(time);
	dayhour_count(time);
	return (1);
}
/*
	count day and hour from tv.sec
	day = 86400
	hour = 3600
	minute = 60
*/
void	dayhour_count(t_datetime *time)
{
	time->snap_time.tv_sec += (UTC_TIMEZONE_PHILO * 3600);
	time->day = 1 + (time->snap_time.tv_sec / 86400);
	time->snap_time.tv_sec = time->snap_time.tv_sec % 86400;
	time->hour = (time->snap_time.tv_sec / 3600);
	time->snap_time.tv_sec = time->snap_time.tv_sec % 3600;
	time->minute = (time->snap_time.tv_sec / 60);
	time->sec = time->snap_time.tv_sec % 60;
	time->ms = time->snap_time.tv_usec / 1000;
}

/*
	count the months from tv.sec 
	operate after year_count() function 
	JAN MAR MAY JUL AUG OCT DEC = 2678400 sec
	APR JUN SEP NOV = 2592000 sec
	FEB = Non-leap[2419200 sec] Leap[2505600 sec]
*/
void month_count(t_datetime *time)
{
	unsigned int deduct;

	time->month = 1;
	while (1)
	{
		if (time->month == 1 || time->month == 3 || time->month == 5 \
		|| time->month == 7 || time->month == 8 || time->month == 10 \
		|| time->month == 12)
			deduct = 2678400;
		else if (time->month == 4 || time->month == 6 || time->month == 9 \
		|| time->month == 11)
			deduct = 2592000;
		else
		{
			if (time->year % 4 == 0 \
			&& (time->year % 100 != 0 || time->year % 400 == 0))
				deduct = 2505600;
			else
				deduct = 2419200;
		}
		if (time->snap_time.tv_sec < deduct)
			break;
		time->snap_time.tv_sec -= deduct;
		time->month += 1;
	}
}

/*
	count how much year from the 1970 by looping and minus by the seconds
	of a whole year
		- also need to consider to leap year which has 366 days
		This formula takes account of the facts that all years that are evenly
		divisible by 4 are leap years, but years that are evenly divisible by
		100 are not leap years unless they are also evenly divisible by 400,
		in which case they are leap years.
	- 365 days = 31536000 sec
	- 366 days = 31622400 sec
*/
void year_count(t_datetime *time)
{
	unsigned int	deduct;

	time->year = 1970;
	while (1)
	{
		if (time->year % 4 == 0 \
		&& (time->year % 100 != 0 || time->year % 400 == 0))
			deduct = 31622400;
		else
			deduct = 31536000;
		if (time->snap_time.tv_sec < deduct)
			break;
		time->snap_time.tv_sec -= deduct;
		time->year += 1;
	}
}
