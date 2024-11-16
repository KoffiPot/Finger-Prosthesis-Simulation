#include <cstdlib>
// #include <octave/octave.h>
#include <julia.h>
JULIA_DEFINE_FAST_TLS // only define this once, in an executable (not in a shared library) if you want fast code.

#include "prosthesis-model.hpp"

using namespace std::chrono_literals;

// Adapted from Blana et al. 2017
namespace prosthesis_controller
{
  void Dynamics::print_julia()
  {
    /* required: setup the Julia context */
    jl_init();

    /* run Julia commands */
    jl_eval_string("print(sqrt(2.0))");

    /* strongly recommended: notify Julia that the
         program is about to terminate. this allows
         Julia time to cleanup pending write requests
         and run all finalizers
    */
    jl_atexit_hook(0);
  }
}
