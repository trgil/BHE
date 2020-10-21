/************************************************************************
 * Copyright (c) 2020, Gil Treibush
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * A copy of the full GNU General Public License is included in this
 * distribution in a file called "COPYING" or "LICENSE".
 ***********************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#define BHE_VERSION     0.1

static void print_usage(void)
{
    printf( "Usage: bhe [OPTIONS] [Input File]\n"
            "Options:\n"
            "\t-h, --help           - Print this help menu and quit.\n"
            "\t-v, --version        - Print program version and quit.\n");
}

static void print_version(void)
{
    printf("bhe - Basic Hex Editor, version %.1f\n", BHE_VERSION);
}

int main(int argc, char** argv)
{
    while (1) {

        int c, ret_val = 0;
        int opt_index = 0;
        static struct option long_options[] = {
            {"help",        no_argument,    0, 'h'},
            {"version",     no_argument,    0, 'v'},
            {0, 0, 0, 0}
        };

        c = getopt_long(argc, argv, "hv", long_options, &opt_index);
        if (c == -1)
            break;

        switch (c)
        {
            case 'v':
                print_version();
                return ret_val;

            case 'h':
                ret_val--;

            default:
                print_usage();
                ret_val++;
                return ret_val;
        }
    }

    if (argc == 1)
        printf("%s: No input file specified\n", argv[0]);
    else if (argc > 2)
        printf("%s: Only single input file supported\n", argv[0]);

    /* Run editor */

    return 0;
}
