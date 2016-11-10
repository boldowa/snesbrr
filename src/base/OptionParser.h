/* The contents of this file are subject to the terms of the
   Common Development and Distribution License, Version 1.0 only. */

#ifndef libbase_OptionParser_h
#define libbase_OptionParser_h

#include "basetypes.h"
#include "noncopyable.h"


namespace base
{

class OptionParser : noncopyable
{
public:
 struct Option
 {
 uint id;
 const char* sname;
 const char* lname;
 const char* desc;
 };

private:
 int argc;
 const char* const* argv;
 const Option* options;
 int index;
 const char* cmd;

public:
 OptionParser (int ac, const char* const* av, const Option* o)
 {
 argc = ac;
 argv = av;
 options = o;
 index = 0;
 next();
 }

 void FASTCALL print_help (const char* usage) const;

 bool FASTCALL next ();
 uint FASTCALL parse () const;

 void stop ()
 { index = argc; }

 const char* get () const
 { return cmd; }
};

} // base


#endif
