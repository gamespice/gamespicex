%module gamespice_static

%{
#include "FacebookCallback.h"
%}
%include "std_string.i"
%include "std_vector.i"

namespace std {
   %template(vectorS) vector<string>;
};

%include "FacebookCallback.h"
