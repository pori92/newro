// basictest.cpp : Définit le point d'entrée pour l'application console.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _WIN32
#include <unistd.h>
#endif

#include "../common/core.h"
#include "test_thread.hpp"
#include "test_spinlock.hpp"

using namespace ra::unit_tests;

int do_init( int, char** )
{
  test_thread_creation_and_wait();
  test_thread_spinlock();
  return 0;
}

//just some empty function to comply link
void do_abort(void) {}
void do_final(void) {}
void set_server_type(void) {}

