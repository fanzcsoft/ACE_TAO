#define ACE_BUILD_SVC_DLL

#include "Today.h"
#include "ace/Log_Msg.h"
#include "ace/svc_export.h"
#include "ace/OS_Memory.h"

// Implementation of the abstract class method which describes the
// magazine.
void
Today::title ()
{
  ACE_DEBUG ((LM_DEBUG,
              "Today: XML Special Apr 02\n"));
}

void *
Today::operator new (size_t bytes)
{
  return ::new char[bytes];
}
void *
Today::operator new (size_t bytes, const std::nothrow_t&)
{
  return ::new (std::nothrow) char[bytes];
}
void
Today::operator delete (void *p, const std::nothrow_t&) throw ()
{
  delete [] static_cast <char *> (p);
}
void
Today::operator delete (void *ptr)
{
  delete [] static_cast <char *> (ptr);
}

// Returns the pointer to the Today class.
// The ACE_BUILD_SVC_DLL and ACE_Svc_Export directives are necessary to
// take care of exporting the function for Win32 platforms.
extern "C" ACE_Svc_Export Magazine *create_magazine ();

Magazine *create_magazine ()
{
  Magazine *mag = 0;
  ACE_NEW_RETURN (mag, Today, 0);
  return mag;
}
