#define ACE_BUILD_SVC_DLL

#include "Newsweek.h"
#include "ace/Log_Msg.h"
#include "ace/svc_export.h"
#include "ace/OS_Memory.h"

// Implementation of the abstract class method which describes
// the magazine.
void Newsweek::title ()
{
  ACE_DEBUG ((LM_DEBUG,
              "Newsweek: Vol. 44923 Stardate: 12.3054\n"));
}

void *
Newsweek::operator new (size_t bytes)
{
  return ::new char[bytes];
}
void *
Newsweek::operator new (size_t bytes, const std::nothrow_t&)
{
  return ::new (std::nothrow) char[bytes];
}
void
Newsweek::operator delete (void *p, const std::nothrow_t&) throw ()
{
  delete [] static_cast <char *> (p);
}
void
Newsweek::operator delete (void *ptr)
{
  delete [] static_cast <char *> (ptr);
}

// Returns the Newsweek class pointer.
// The ACE_BUILD_SVC_DLL and ACE_Svc_Export directives are necessary to
// take care of exporting the function for Win32 platforms.
extern "C" ACE_Svc_Export Magazine *create_magazine ();

Magazine *
create_magazine ()
{
  Magazine *mag = 0;
  ACE_NEW_RETURN (mag, Newsweek, 0);
  return mag;
}
