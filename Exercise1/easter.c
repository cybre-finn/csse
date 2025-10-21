#include <stdio.h>
#include <stdlib.h>

int calculate_Easter_date(int year) {
    /* input range check */
    if (year < 1582 || year > 39999) {
        fprintf(stderr, "Year %d out of range (1582-39999)\n", year);
        return 0;
    }

   /* E1: golden year in the 19-year metoinic cycle */
    int metonic_cycle = (year % 19) + 1;

    /* E2: Century */
    int century = (year / 100) + 1;

    /* E3: Skipped leap years and moons orbit correction */
    int skipped_leap_years = (3 * century / 4) - 12;
    int moon_orbit_correction = ((8 * century + 5) / 25) - 5;

    /* E4: Adj for Sunday offset */
    int sunday_offset = (5 * year / 4) - skipped_leap_years - 10;

    /* E5: epact (age of moon on Jan 1) */
    int epact = (11 * metonic_cycle + 20 + moon_orbit_correction - skipped_leap_years) % 30;
    if (epact < 0) epact += 30;
    if ((epact == 25 && metonic_cycle > 11) || epact == 24)
        epact++;

    /* E6: Calendar full moon (March N) */
    int calendar_full_moon = 44 - epact;
    if (calendar_full_moon < 21)
        calendar_full_moon += 30;

    /* E7: Sunday after full moon */
    int sunday_after_full_moon = (sunday_offset + calendar_full_moon) % 7;
    if (sunday_after_full_moon < 0)
        sunday_after_full_moon += 7;
    int easter_day_in_march = calendar_full_moon + 7 - sunday_after_full_moon;

    /* E8: determine  month */
    if (easter_day_in_march > 31)
        return easter_day_in_march - 31;  /* April → positive day */
    else
        return -easter_day_in_march;      /* March → negative day */
}

int main(int argc, char *argv[])
{
    int in_year;
    while(1) {
        int ret = scanf("%d", &in_year);
        if(ret == EOF) break;
        int result = calculate_Easter_date(in_year);
        if (result == 0) { /*out of range*/
            continue;
        }
        if (result < 0) { /*negative sign means march*/
            printf("%d - March %d\n", in_year, -result);
        }
        else { /*positive sign means april*/
            printf("%d - April %d\n", in_year, result);
        }
        
    }
    
    return EXIT_SUCCESS;
}

