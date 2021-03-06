/* Copyright 2013-2015 IBM Corp.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * 	http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * This file is run with the skiboot libc files rather than system libc.
 * This means we have a bit of "fun" with actually executing the tests on
 * the host.
 * Patches to make this less ugly are very welcome.
 */

#include <config.h>
#include <stdarg.h>

#include "../string/memchr.c"
#include "../string/memcmp.c"
#include "../string/memcpy.c"
#include "../string/memmove.c"
#include "../string/memset.c"
#include "../string/strcasecmp.c"
#include "../string/strcat.c"
#include "../string/strchr.c"
#include "../string/strcmp.c"
#include "../string/strcpy.c"
/* #include "../string/strdup.c" */
#include "../string/strlen.c"
#include "../string/strncasecmp.c"
#include "../string/strncmp.c"
#include "../string/strncpy.c"
#include "../string/strstr.c"
#include "../string/strtok.c"
