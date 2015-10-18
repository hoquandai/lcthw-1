/*-*- coding: utf-8 -*-

 Copyright (c) 2015 Zed A. Shaw <zedshaw@zedshaw.com>

 Permission to use, copy, modify, and distribute this software for any
 purpose with or without fee is hereby granted, provided that the above
 copyright notice and this permission notice appear in all copies.

 THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

/*
Exercise 46 : Ternary Search Tree
*/

#include "minunit.h"
#include <lcthw/tstree.h>
#include <string.h>
#include <assert.h>
#include <lcthw/bstrlib.h>

TSTree *node = NULL;
char *valueA = "VALUEA";
char *valueB = "VALUEB";
char *value1 = "VALUE1";
char *value4 = "VALUE4";
char *reverse = "VALUER";
int traverse_count = 0;

struct tagbstring test1 = bsStatic("TEST");
struct tagbstring test2 = bsStatic("TEST2");
struct tagbstring test3 = bsStatic("TSET");
struct tagbstring test4 = bsStatic("T");

char *test_insert()
{
  node = TSTree_insert(node, bdata(&test1), blength(&test1), valueA);
  mu_assert(node != NULL, "Failed to insert into tst.");

  node = TSTree_insert(node, bdata(&test2), blength(&test2), valueA);
  mu_assert(node != NULL, "Failed to insert into tst with second name.");

  node = TSTree_insert(node, bdata(&test3), blength(&test3), reverse);
  mu_assert(node != NULL, "Failed to insert into tst with reverse name.");

  node = TSTree_insert(node, bdata(&test4), blength(&test4), value4);
  mu_assert(node != NULL, "Failed to insert into tst with fourth name.");

  return NULL;
}

char *all_tests()
{
  mu_suite_start();

  mu_run_test(test_insert);

  return NULL;
}

RUN_TESTS(all_tests);
